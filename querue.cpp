# include <iostream>
using namespace std;

template <typename T>

class QueueArr{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
 
    public :
    QueueArr(int s){
        data = new T[s];
        nextIndex=0;
        capacity=s;
        firstIndex=-1;
        size=0;
    }

    void enqueue( T d){

        if( size == capacity){

            cout<< " Queue is Full "<< endl;
            return ;
        }
        if(nextIndex < capacity){
        data[nextIndex]=d;
        nextIndex++;
       
        }

        else{
          
            data[nextIndex] = d;
            nextIndex = (nextIndex +1)% capacity;

        }

        
        size++;
    }

    T dequeue(){
         if(size==0){

            return 0;
        }

        T ans = data[firstIndex];

        
        firstIndex=(firstIndex+1)% capacity;
        size--;
        
        return ans;

        
    }

    T front(){
        if(size==0){

            return 0;
        }
        return data[firstIndex];
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){

        return size == 0;
    }
};

int main(){
    QueueArr <int> q(5);

    q.enqueue(5);
    q.enqueue(10);

    q.enqueue(15);

    q.enqueue(20);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.front()<<endl;
   


    return 0;
}