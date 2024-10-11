#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool red_brack(string str1){
    int count=0;
    int i=0;

    stack <char> st1;

    for( int i=0;i< str1.length(); i++){

        if( str1[i] == ')'  || str1[i]== '}'){

            while( !st1.empty()  && st1.top()!='('  && st1.top() != '{'){

                st1.pop();

                count++;
            }
            st1.pop();
            if (count == 0){
                return true;
            }

            count=0;

        }
        else{
            st1.push(str1[i]);
        }
    }

    return false;

   

}

int main(){

    string str1="{a+(a+b)}";  //redandent meaning if there is no info between bracker, here,  there is info bet { a + ()} and ()  , but on {(a+b)}, there is no info in between {} and info is their in between () so its redundent as {} don't have info.  

    cout<< red_brack(str1);

    
}