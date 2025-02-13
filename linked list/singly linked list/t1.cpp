// singly linked list
#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;

// insert a new node
void append(int value){
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;

    if(head == nullptr){
        head = new_node;
    } else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void traverse_list(){
    Node* temp = head;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main(){
    append(1);
    append(2);
    append(3);

    traverse_list();
    return 0;
}