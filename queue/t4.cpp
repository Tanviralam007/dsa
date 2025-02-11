// circluar queue implementation using array
#include <iostream>
#include <vector>

template<typename T>
class CircularQueue{
    private:
    std::vector<T> data;
    int front;
    int rear;
    int capacity;
    int count;

    public:
    CircularQueue(int size){
        data.resize(size);
        front = -1;
        rear = -1;
        capacity = size;
        count = 0;
    }

    bool is_empty(){
        return count == 0;
    }

    bool is_full(){
        return count == capacity;
    }

    void enqueue(T value){
        if(is_full()) throw std::runtime_error("Queue is full");
        if(is_empty()){
            front = 0;
            rear = 0;
        } else{
            rear = (rear + 1) % capacity;
        }
        data[rear] = value;
        count++;
    }

    T dequeue(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        T value = data[front];
        if(front == rear){
            front = -1;
            rear = -1;
        } else{
            front = (front + 1) % capacity;
        }
        count--;
        return value;
    }

    T front_element(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        return data[front];
    }

    T rear_element(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        return data[rear];
    }

    int queue_size(){
        return count;
    }

    void traverse(){
        if(is_empty()){
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        int i = front;
        while(i != rear){
            std::cout << data[i] << " ";
            i = (i + 1) % capacity;
        }
        std::cout << data[rear] << std::endl;
    }
};