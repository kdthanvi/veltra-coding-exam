const express = require('express');
const bodyparser = require('body-parser');
const urlvalidator = require('validator');
const shash = require('shorthash');
const configs = require('./config');

const redis = require('redis'),
            client = redis.createClient(configs.redis_port, configs.redis_url);
            client.on("error", (err)=>{
                console.log("[Error] " + err);
            })

const app = express();

app.use(bodyparser.urlencoded({extended : true}));
app.use(express.static('public'));
app.set('view engine', 'ejs');

app.get('/', (req, res)=>{
    res.render('index')
})

app.post('/', (req, res)=>{
    let base_url = "http://localhost:4000/"
    let url = req.body.url;
    
    if(urlvalidator.isURL(url)){
        console.log('valid url');

        // shorthash the url
        let shash_url_key = shash.unique(url);
        
        //check if already present
        client.get(shash_url_key, (err, replay)=>{
            if(err) console.log("[Error]Redis lookup failed!");

            if(replay == null){
                console.log("Entry not present");
                client.set(shash_url_key, url, (err, replay)=>{
                    if(err) console.log("[Error]Redis insert failed.");
                    console.log("Redis insert ok : " + replay);
                })
            }else{
                console.log("Entry present already");
            }
            res.render('index', 
                {
                    url: 'Shorten url : ' + base_url + shash_url_key, 
                    error:null
                });
        });
        
    }else{
        console.log('not valid url');
        res.render('index', 
            {
                url : url + ' is NOT a valid url.', 
                error : null
            });
    }
})

app.get('/:shashurlkey', (req, res)=>{
    let shash_url_key = req.params.shashurlkey;
    client.get(shash_url_key, (err, replay)=>{
        if(err) console.log("[Error]Redis lookup failed.");

        if(replay == null){
            console.log("No such url.")
            res.render('index', 
                {
                    url : null,
                    error : 'No such url.'
                });
        }
        else{
            console.log("Redis hit : "+ replay + ". Redirecting...");
            if(replay.match(/^http..*/))
                res.redirect(replay);
            else{
                replay = 'http://' + replay;
                res.redirect(replay);
            }          
        }
    });
})

app.listen(process.env.PORT || 4000, () => console.log('App running on port 4000!'));