#include <iostream>
#include <vector>

template <typename T>
struct Node{
    T data;
    Node *next;
};

template <typename T>
class Stack{
    private:
    Node<T> *top; // top of the stack

    public:
    Stack(){
        top = nullptr;
    }

    void push(const T& value){
        Node<T> *new_node = new Node<T>;
        new_node->data = value;
        new_node->next = top;
        top = new_node; // update the top to new node
    }

    T pop(){
        if(is_empty()){
            throw std::runtime_error("Stack is empty");
        }
        T top_element = top->data;
        Node<T> *temp = top;
        top = top->next;
        delete temp;
        return top_element;
    }

    T peek(){
        if(is_empty()){
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }

    bool is_empty(){
        return top == nullptr;
    }

    int stack_size(){
        int count = 0;
        Node<T> *current = top;
        while(current != nullptr){
            count++;
            // std::cout << current->data << " " << current->next << std::endl;
            current = current->next;
        }
        return count;
    }
};

