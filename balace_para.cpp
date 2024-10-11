#include <iostream>
# include <stack>
using namespace std;


bool para( string& arr){
    stack <char> s1;

    for(int i=0; i<arr.size();i++){
        if( arr[i]=='{' || arr[i]=='[' || arr[i]=='('){
            s1.push(arr[i]);
        }
        if(s1.top()=='{' && arr[i]=='}'){

            s1.pop();
    
        }
        else  if(s1.top()=='[' && arr[i]==']'){

            s1.pop();
    
        }
         else if(s1.top()=='(' && arr[i]==')'){

            s1.pop();
    
        } 

    }

    return s1.empty();


}

int main(){
     string input;
    
    cin >> input;

    if (para(input)) {
        cout << "The brackets are balanced." << endl;
    } else {
        cout << "The brackets are not balanced." << endl;
    }

   
    return 0;
}