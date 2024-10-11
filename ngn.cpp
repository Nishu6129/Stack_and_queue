#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement(vector<int> arr)
    {
        stack<int> s1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!s1.empty() && s1.top() < arr[i])
            {
                s1.pop();
            }
            if (s1.empty())
            {
                int a = arr[i];
                arr[i] = -1;
                s1.push(a);
            }
            else
            {
                int a = arr[i];
                arr[i] = s1.top();
                s1.push(a);
            }
        }
        return arr;
    }

    vector<int> NLE2(vector<int> arr)
    {
        int n = arr.size();
        vector<int> arr2(n,-1);

        for (int i = 0; i < n; i++)
        {
            int mx = arr[i];
            for (int j = i; j <= i + n - 1; j++)
            {
                 int index = j % n;
                // cout << "index " << index << " " << arr[index] << endl;
                if (mx < arr[index])
                {
                    mx = arr[index];

                    break;
                }
            }

            if (mx == arr[i])
            {
                arr2[i] = -1;
                // cout <<"if "<<arr2[i] << endl;
            }
            else
            {

                arr2[i] = mx;
                // cout << "else"<< arr2[i] << endl;
            }
        }
        return arr2;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 7, 1, 7, 6, 0};
    // vector<int> result = sol.nextLargerElement(arr);
    vector<int> result = sol.NLE2(arr);

    cout << "Next greater elements are: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
