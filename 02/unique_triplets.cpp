#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct triplet{
    int f, s, t;
};

int print_triplets(int arr[], int size){

    int i, j, k;

    vector <triplet> triplets_vector;
    
    unordered_set <string> unique_triplet;
    string temp;
    triplet new_triplet;

    //sort
    sort(arr, arr+size);
    
    for(i=0; i<size-2; i++){

        j=i+1;  //second num
        k=size-1; //last num

        while(j < k){
            int result = arr[i] + arr[j] + arr[k];
            // check if this the triplet with sum as 0
            if(result == 0){
                
                // check uniqueness
                temp = to_string(arr[i]) + "_" + to_string(arr[j]) + "_" + to_string(arr[k]);

                if( unique_triplet.find(temp) == unique_triplet.end()){
                    unique_triplet.insert(temp);
                    new_triplet.f=arr[i];
                    new_triplet.s=arr[j];
                    new_triplet.t=arr[k];
                    triplets_vector.push_back(new_triplet);
                }

                // move the indexs
                j++, k--;

             }
             else if (result > 0)   // as the array is sorted
                k--;
            else        // sum is less
                j++;
        }       
    }
    //no unique triplet
    if (triplets_vector.size() == 0)
        return 0;

    for (i=0; i<triplets_vector.size(); i++){
        cout << "[" << triplets_vector[i].f << "," << triplets_vector[i].s <<"," << triplets_vector[i].t << "]";
    }
}


// supporting main function
int main(){

    //int arr[1000];  //random size
    //int size;
    int arr[] = {-4,-2,-1,0,1,3,4};
    int size = 7;
    //cout << " Enter number of elements : \n";
    //cin >> size;
    //cout << " Enter the array elements : \n";
    /*for(int i=0; i<size; i++){
        cin >> arr[i];
    }*/
    
    if (!print_triplets(arr, size))
        cout << " Not unique triplets found.";

    return 0;
}