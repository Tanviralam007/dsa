#include <iostream>
#include <vector>

int top = -1;
std::vector<int> stack;

bool is_empty(){
    return top == -1;
}

void push(int value){
    stack.push_back(value);
    top++;
}

int pop(){
    if(is_empty()) throw std::runtime_error("Stack is empty");
    
    int top_element = stack[top];
    stack.pop_back();
    top--;
    return top_element;
}

int peek(){
    if(is_empty()) throw std::runtime_error("Stack is empty");
    return stack[top];
}

int stack_size(){
    return stack.size();
}