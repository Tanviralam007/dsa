// singly linked list
#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;

// insert a new node or new node at the end
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

// insert a new node at the beginning
void insert_at_beginning(int value){
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}


// insert at a specific position
void insert_at_position(int value, int position){
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;

    if(position == 0){
        insert_at_beginning(value);
    } else{
        Node* temp = head;
        //std::cout << temp->data << " " << temp->next << std::endl << std::endl;
        for(int i = 0; i < position; i++){
            temp = temp->next;
            // std::cout << temp->data << " " << temp->next << std::endl;
        }
        std::cout << std::endl;

        new_node->next = temp->next;
        // std::cout << new_node->next << std::endl;

        temp->next = new_node;
        // std::cout << temp->next << std::endl;
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
    append(5);
    std::cout << "Linked list: "; traverse_list();
    std::cout << std::endl;

    insert_at_beginning(0);
    std::cout << "Linked list: "; traverse_list();
    std::cout << std::endl;

    insert_at_position(4, 3);
    std::cout << "Linked list: "; traverse_list();
    return 0;
}