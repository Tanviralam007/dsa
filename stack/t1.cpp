#include <iostream>
#include <vector>

template <typename T>
class Stack{
    private:
    std::vector<T> data;
    int top;

    public:
    Stack(){
        top = -1;
    }

    void push(T value){
        data.push_back(value);
        top++;
    }

    T pop(){
        if(isEmpty()){
            throw std::runtime_error("Stack is empty");
        }
        T top_element = data[top];
        data.pop_back();
        top--;
        return top_element;
    }

    T peek(){
        if(isEmpty()){
            throw std::runtime_error("Stack is empty");
        }
        return data[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    int stack_size(){
        return data.size();
    }
};