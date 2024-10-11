# include <iostream>
using namespace std;

template <typename T>

class Node {
    public:
    T data;
    Node<T> * next;

    Node( T data){
        this->data=data;
        this->next=NULL;
    }
};

template <typename T>

class QueueLL{

    int size;

    Node <T> * head=NULL;
    Node <T> * tail = NULL;

    public:

    QueueLL(){
     
        head=NULL;
        tail=NULL;
        size=0;
        
    }

    void enqueue( T data){
         Node <T> * new_node= new Node<T>(data);
        if(head== NULL){
            head=new_node;
            tail=new_node;

        }
        else{
       
        tail->next= new_node;
        tail=new_node;
       
        }
         size++;
    }

    T dequeue(){
          if(head== NULL){
            return 0;
        }
        Node <T> * temp=head;
        head=head->next;

        T ans = temp->data;

        delete temp;

        return ans;

    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }

    T front(){
        if(head== NULL){
            return 0;
        }
        return head->data;
    }

};

int main(){

    QueueLL<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(10);
    q.enqueue(60);

    cout<< q.front()<<endl;
    cout<< q.dequeue()<< endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<< q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;


}