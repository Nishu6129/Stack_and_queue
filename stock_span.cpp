#include <iostream>
#include <vector>
#include <stack>

using namespace std;


vector<int> stock_span( const vector<int>& arr){

    stack <int> st1;
    int n = arr.size();

    vector<int> arr2(n);
    int index=0;

    for(int i=0;i<n; i++){
        if (st1.empty()){
            arr2[i]=i+1;
            st1.push(i);
            index=i;
        }

        else{
            int count=1;
            while(!st1.empty() && arr[i]>arr[st1.top()]){

                cout<<"elem"<< arr[i]<<" "<<"poped"<<arr[st1.top()]<< endl;

                    st1.pop();
                    count++;
                    index =st1.top();

            }

            

            if(st1.empty()){
                cout<<"empty=="<<arr[i]<<endl;
                arr2[i]=i+1;
                index=i;
            }
            else{
                cout<<"added="<<arr[i]<<endl;
                arr2[i]=i-index;
                index=i;

            }

            st1.push(i);

          


        }

    }

    return arr2;






}

int main(){

     vector<int> stock_prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> spans = stock_span(stock_prices);

    cout << "Stock spans: ";
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;

    return 0;



}