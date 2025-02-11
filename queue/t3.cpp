// queue implementation using linked list
#include <iostream>
template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T>
class Queue{
    private:
    Node<T>* front;
    Node<T>* rear;

    public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    bool is_empty(){
        return front == nullptr;
    }

    void enqueue(T value){
        Node<T>* new_node = new Node<T>;
        new_node->data = value;
        new_node->next = nullptr;

        if(is_empty()){
            front = new_node;
            rear = new_node;
        } else{
            rear->next = new_node;
            rear = new_node;
        }
    }

    T dequeue(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        T value = front->data;
        Node<T>* temp = front;
        front = front->next;
        delete temp;

        if(front == nullptr) 
            rear = nullptr;
        
        return value;
    }

    T front_element(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        return front->data;
    }

    T rear_element(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        return rear->data;
    }

    T queue_size(){
        int count = 0;
        Node<T>* current = front;
        while(current != nullptr){
            count++;
            current = current->next;
        }
        return count;
    }

    void traverse(){
        Node<T>* current = front;
        while(current != nullptr){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
