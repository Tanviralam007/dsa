#include <iostream>

struct Node{   
    int data;
    Node *next;
};

Node* top = nullptr;

bool is_empty(){
    return top == nullptr;
}

void push(int value){
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

int pop(){
    if(is_empty()) throw std::runtime_error("Stack is empty");
    
    int top_element = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return top_element;
}

int peek(){
    if(is_empty()) throw std::runtime_error("Stack is empty");
    return top->data;
}

int stack_size(){
    int count = 0;
    Node *current = top;
    while(current != nullptr){
        count++;
        std::cout << current->data << " " << current->next << std::endl;
        current = current->next;
    }
    return count;
}