#include <iostream>
#include <stack>
using namespace std;

void stack_reverse(stack<int> & st1, stack<int> & st2){
    if(st1.empty()){
        return ;
    }

    int n=st1.top();
    st1.pop();

    stack_reverse(st1, st2);

    st2.push(n);

}

void transfer_to_original(stack<int>& st1, stack<int>& st2) {
    while (!st2.empty()) {
        st1.push(st2.top());
        st2.pop();
    }
}


int main(){
    stack<int> stack1;
    stack<int> stack2;
    stack1.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack1.push(22);
    stack1.push(24);
    stack1.push(25);

    stack_reverse(stack1, stack2);
    transfer_to_original(stack1,stack2);

    cout << "Reversed Stack: ";
    while (!stack1.empty()) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;


}
