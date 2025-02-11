// circular queue using linked list
#include <iostream>

template <typename T>
struct Node{
    T data;
    Node* next;
};

template <typename T>
class CircularQueue{
    private:
    Node<T>* front;
    Node<T>* rear;
    int count;

    public:
    CircularQueue(){
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool is_empty(){
        return count == 0;
    }

    int size(){
        return count;
    }

    void enqueue(T value){
        Node<T>* new_node = new Node<T>;
        new_node->data = value;
        new_node->next = nullptr;
        
        if(is_empty()){
            front = new_node;
            rear = new_node;
            rear->next = front;
        } else{
            rear->next = new_node;
            rear = new_node;
            rear->next = front;
        }
        count++;
    }

    T dequeue(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        T value = front->data;
        if(front == rear){
            front = nullptr;
            rear = nullptr;
        } else{
            Node<T>* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        count--;
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

    void traverse(){
        if(is_empty()){
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node<T>* temp = front;
        do{
            std::cout << temp->data << " ";
            temp = temp->next;
        } while(temp != front);
        std::cout << std::endl;
    }
};