#include <iostream>
using namespace std;


class Stack{
private:
    int top=-1;
    int *stack_arr;
    int size;

public:

    Stack(int length){
        
        int arr[length];
        size = length;
        stack_arr = arr;
      

    }

    void push(int item){

        if(top==size-1){
            cout << "Error Stack Overflow";
            return;
        }
        ++top;

        *(stack_arr + top) = item;
        
       
        // for(int j=0; j<2; j++){
        //     cout << stack_arr[j]<<" ";
        // }
        // cout << endl;
        

        
        
       
    }

    void pop(){

        if(top==-1){
            cout << "Stack Underflow";
            return;
        }
        
        cout << *(stack_arr+top)<<endl;
        --top;
       


    }




};


int main(){

    Stack stk = Stack(10);
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();
    stk.pop();
    




    return 0;

}