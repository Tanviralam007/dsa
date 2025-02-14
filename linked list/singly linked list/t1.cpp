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

/*
0 0x717900

1 0x717930
2 0x717940
3 0x717950

0x717950
0x717970
Linked list: 0 1 2 3 4 5
*/

// delete at the beginning
void delete_from_beginning(){
    if(head == nullptr){
        std::cout << "List is empty" << std::endl;
        return;
    } else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// delete the last node
void delete_from_end(){
    if(head == nullptr){
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    // if there is only one node
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    // std::cout << temp->data << " " << temp->next << std::endl << std::endl;
    while(temp->next->next != nullptr){
        temp = temp->next;
        // std::cout << temp->data << " " << temp->next << std::endl;
    }
    delete temp->next;
    temp->next = nullptr;
}
// head [1 | 0x1000] -> [1 | 0x1000] [2 | 0x1004] [3 | 0x1008] [4 | 0x100C] 
// head -> [1 | 0x1004] -> [2 | 0x1008] -> [3 | 0x100C] -> nullptr

// delete node at any position
void delete_at_position(int position){
    if(head == nullptr){
        std::cout << "List is empty" << std::endl;
        return;
    }

    // if there is only one node
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    for(int i = 1; temp != nullptr && i < position - 1; i++){
        temp = temp->next;
        //std::cout << temp->data << " " << temp->next << std::endl;
    }

    Node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    delete node_to_delete;
}
// head [1 | 0x1000] -> [1 | 0x1000] [2 | 0x1004] [3 | 0x1008] [4 | 0x100C] [5 | 0x1010]
// exp: after deletion at position (3)
// head -> [1 | 0x1004] -> [2 | 0x100C] -> [4 | 0x1010] -> nullptr

// search for a node in the list
void search_an_node(int value){
    Node* temp = head;
    int position = 0;
    while (temp != nullptr){
        if(temp->data == value){
            std::cout << "Node found at position: " << position << std::endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    std::cout << "Node not found" << std::endl;
}

// reverrse the list
void reverse_list(){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void traverse_list(){
    Node* temp = head;
    std::cout << "\nlist: " << std::endl;
    while(temp != nullptr){
        std::cout << temp->data << " " << temp->next << std::endl;
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main(){
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    traverse_list();

    // insert_at_beginning(0);
    // traverse_list();
    // std::cout << std::endl;

    // insert_at_position(4, 3);
    // traverse_list();
    // std::cout << std::endl;
    
    // delete_from_beginning();
    // traverse_list();
    // std::cout << std::endl;
    
    // delete_from_end();
    // traverse_list();
    // std::cout << std::endl;

    // delete_at_position(3);
    // traverse_list();
    // std::cout << std::endl;

    search_an_node(30);

    return 0;
}