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

void print(node* head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    return;
}


node* reverse(node* &head){
    
    //base case
    if(head == NULL or head->next == NULL){
        return head;
    }
    
    node* newHead = reverse(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}
int main() {
	
	node* head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	
	head = reverse(head);
	print(head);
	return 0;
}