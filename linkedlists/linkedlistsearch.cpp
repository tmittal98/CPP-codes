#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void printLL(node* head){

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}
bool search(node* head,int key){

    while(head != NULL){
        if(head->data == key)
            return true;
        head=head->next;
    }
    return false;
}

bool search2(node* head,int key){

    if(head == NULL){
        return false;
    }

    if(head->data == key){
        return true;
    }

    return search2(head->next,key);
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    printLL(head);
    if(search2(head,3)){
        cout<<"found";
    }
    else{
        cout<<"Not found";
    }
    return 0;
}
