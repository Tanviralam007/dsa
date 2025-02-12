// singly linked list
#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;

// insert a new node
void insert_at_first(int value){
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    // std::cout << "\nnew node address-> " << new_node << std::endl;
    // std::cout << "new node data-> " << new_node->data << std::endl;
    // std::cout << "new node next-> " << new_node->next << std::endl << std::endl;

    if(head == nullptr){
        head = new_node;
        // std::cout << "head address -> " << head << std::endl;
        // std::cout << "head data -> " << head->data << std::endl;
        // std::cout << "head next -> " << head->next << std::endl << std::endl;
    } else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
            // std::cout << "temp address1 -> " << temp << std::endl;
        }
        temp->next = new_node;
        // std::cout << "\ntemp address2 -> " << temp << std::endl;
        // std::cout << "temp data -> " << temp->data << std::endl;
        // std::cout << "temp next -> " << temp->next << std::endl;
    }
}

int main(){
    insert_at_first(1);
    insert_at_first(2);
    insert_at_first(3);

    return 0;
}