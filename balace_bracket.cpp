#include <iostream>
#include <stack>
#include <string>
using namespace std;

int check_balance(string str1)
{
    if (str1.length() % 2 != 0)
    {
        return -1;
    }

    stack<char> stk1;

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == '{')
        {
            stk1.push(str1[i]);
        }

        else
        {

            while (!stk1.empty() && stk1.top() == '{' && str1[i] == '}')
            {

                stk1.pop();
                i++;
            }

            stk1.push(str1[i]);
        }
    }

    int count = 0;
    while (!stk1.empty())
    {
        char check1 = stk1.top();
        stk1.pop();
        char check2 = stk1.top();
        stk1.pop();

        if (check1 == '}' && check2 == '}')
        {
            count++;
        }
       

        else if (check1 == '{' && check2 == '{')
        {
            count++;
        }
        else if(check1=='{'  && check2 == '}'){
            count+=2;
        }
    }

    return count;
}

int main()
{

    // string str1="{{}}}}{{";
    string str1 = "}}}{";

    cout << check_balance(str1) << endl;

    return 0;
}