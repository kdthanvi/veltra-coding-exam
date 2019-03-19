## Distributed Systems
- In most simple language, distributed systems are multiple instance of any application working concurrently to server the end user resquest irrespecitve of the dependency on a single specific instance.

**A distributed system** _is an application that executes a collection of protocols to coordinate the actions of multiple processes on a network, such that all components cooperate together to perform a single or small set of related tasks._ [[Reference]](http://www.hpcs.cs.tsukuba.ac.jp/~tatebe/lecture/h23/dsys/dsd-tutorial.html)

### Common difficulties & their remedies
- Infratructure management
  - It becomes difficult to manage distributed instances if it is done manually because of it's distributed nature.
  - **Remedy:** Use infrastructure management tools such as terraform, chef, etc. to manage the whole infratstructure. (Or even cloud solutions like AWS, GCP, etc. have emerged to great extent these days.)
- Scalability
  - Scaling the distributed envrionment gets difficult when there are multiple dependencies. If you miss out on any then it can cause many troubles.
  - **Remedy:** Horizontal scalibity can be easily achieved by using infrastructure managmenet tools.
- Consistency
  - Data consistency between multiple instances is a big concern in case of distributed systems.
  - **Remedy:** Stateless application is resolve the problem of consistency. In case of stateful applications, common caches like redis/memcached can be helpful.
