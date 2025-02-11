#include <iostream>
#include <deque>

template <typename T>
class Queue{
    private:
    std::deque<T> data;

    public:
    Queue() {}

    bool is_empty(){
        return data.empty();
    }

    void enqueue(T value){
        data.push_back(value);
    }

    void dequeue(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        data.pop_front();
    }

    T front_element(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        return data.front();
    }

    T back_element(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        return data.back();
    }

    T queue_size(){
        return data.size();
    }

    void traverse(){
        std::cout << "Queue: ";
        for(int i = 0; i < data.size(); i++) {
            std::cout << data[i] << " ";
        }
    }
};