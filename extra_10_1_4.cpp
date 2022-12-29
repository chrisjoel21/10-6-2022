// extra_10_1_4
#include <iostream>
using namespace std;

template <class T>
struct node {
    T data;
    node* next;
};

template <class T>
class stack {
    private:
        node<T>* top;
    public:
        stack();
        void push(T val);
        int peek();
        void pop();
        bool isEmpty();
        void print();
};
template <class T>
stack<T>::stack() {
    // constructor
    top = nullptr;
}
template <class T>
void stack<T>::push(T val) {
    // pushes to top of the stack
    node<T> *temp = new node<T>;
    temp->data = val;
    temp->next = nullptr;
    temp->next = top;
    top = temp;
}
template <class T>
int stack<T>::peek() {
    // if stack is empty, return -1
    if(isEmpty()){
        return-1;
    }
    // otherwise, return the data of the top of the stack
    else{
        return top->data;
    }
}
template <class T>
void stack<T>::pop() {
    // if stack is not empty, delete the top node of the stack
    if(!(isEmpty())){

        //node *temp = new node();/// y don't we need a node
        //temp = top;
        node<T>* temp = top; //like here 
        top = top->next;
        delete temp; 
    }
}
template <class T>
bool stack<T>::isEmpty() {
    // return true if stack is empty, false otherwise
    if(top == nullptr){
        return true;
    }
    return false;
}
template <class T>
void stack<T>::print() {
    // print out every node of the stack
    // cannot traverse using a temp node, must pop
    while (!isEmpty())
    {
        cout << top->data << " ";
        pop();
    }
    cout << endl;
    
}

int main() {
    stack <int>s;
    stack <char>s1;
    for(int i = 2; i <= 10; i += 2) {
      s.push(i);
     }

     std::cout << s.peek() << std::endl;

     s.pop();
     s.pop();
     s.pop();

     std::cout << s.peek() << std::endl;

     s.push(20);

     s.print();
string name = "chrisisaactheradiyilsaby";
cout << name<<endl;
for(int i = 0; i <= 5; i ++) {
      s1.push(name[i]);
     }
std::cout << s1.peek() << std::endl;

     s1.pop();
     s1.pop();
     s1.pop();

     std::cout << s1.peek() << std::endl;

     s1.push('l');

     s1.print();

    return 0;
}