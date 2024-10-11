#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// template <typename T>

// class Pair{
//     T x; 
//     T y;

//     public: 
//     void setX(T x){
//         this->x=x;
//     }

//     T getX(){
//         return x;
//     }

//      void setY(T y){
//         this->y=y;
//     }

//     T getY(){
//         return y;
//     }
// };

template <typename T, typename V>    // for 3 template <typename T, typename V, typename W>

class Pair{
    T x; 
    V y;

    public: 
    void setX(T x){
        this->x=x;
    }

    T getX(){
        return x;
    }

     void setY(V y){
        this->y=y;
    }

    V getY(){
        return y;
    }
};

int main(){

    // Pair<int> p1;
    // p1.setX(10);
    // p1.setY(10);

    // cout<<p1.getX() <<" "<< p1.getY()<<endl;

    // Pair <double> p2;
    // p2.setX(12.2);
    // p2.setY(10.1);
    // cout<< p2.getX() <<" "<<p2.getY();

    Pair<int,double> p1;

    p1.setX(100.34);
    p1.setY(100.34);

    // cout<< p1.getX()<< " "<< p1.getY();

    //2nd option of making it 3 var

    Pair <Pair<int, int>, int> p2;

    Pair<int, int> p4;

    p4.setX(10);
    p4.setY(5);

    p2.setX(p4);
    p2.setY(10);

    cout<< p2.getX().getX()<<" "<<p2.getY()<<endl;

    return 0;

}