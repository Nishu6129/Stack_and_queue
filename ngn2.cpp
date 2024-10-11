#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement2(vector<int> arr)
    {
          stack<int> s1;
        int N=arr.size();
        vector<int>arr2(N,-1);


        for(int i=N*2-1;i>=0;i--){

            int index=i%N;
          while(!s1.empty()  && s1.top()<=arr[index]){
            s1.pop();

          }
          if(s1.empty() && i<N){
            s1.push(arr[index]);
            arr2[index]=-1;
          }
          else if(s1.empty()){
            s1.push(arr[index]);
          }
          else{
            int n=arr[index];
            arr2[index]=s1.top();
            s1.push(n);
            
          }
        }

        return arr2;
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
    // vector<int> result = sol.nextLargerElement2(arr);
    vector<int> result = sol.NLE2(arr);

    cout << "Next greater elements are: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
