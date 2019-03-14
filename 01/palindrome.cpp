#include <iostream>

using namespace std;

// the function required!
bool palindrome(string str){
    int left = 0;
    int right = str.length()-1;

    for(int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
        
    while (left <= right){

        if ((str[left] < 'a' || str[left] > 'z') && (str[left] < '0' || str[left] > '9'))
            left++;
        else if((str[right] < 'a' || str[right] > 'z') && (str[right] < '0' || str[right] > '9'))
            right--;
        else if (str[left] != str[right])
            return false;
        else
            left++, right--;
    }
    return true;
}

// supporting main
int main(){
    string str;
    cout << "Enter the string : ";
    getline(cin, str);

    if(palindrome(str))
        cout << str << " is a palindrome!\n";
    else
        cout << str << " is NOT a palindrome!\n";
    
    return 0;
}