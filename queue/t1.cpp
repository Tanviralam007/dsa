// basic queue
#include <iostream>
#include <vector>

template <typename T>
class Queue{
    private:
    std::vector<T> data;

    public:
    Queue() {}

    bool is_empty(){
        return data.empty();
    }

    void enqueue(T value){
        data.push_back(value);
    }

    T dequeue(){
        if(is_empty()) throw std::runtime_error("Queue is empty");
        T value = data.front();
        data.erase(data.begin());
        return value;
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