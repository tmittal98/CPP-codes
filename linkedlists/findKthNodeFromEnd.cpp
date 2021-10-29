// finding the kth element from the end of a linked list in single pass
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int findKthNodeFromEnd(node* head,int k){

    node* fast = head;

    for(int i=1;i<k;i++){
        fast = fast->next;
    }
            // s f
    //1 2 3 4 5  k=2 k<=n

    node* slow = head;

    while(fast->next != NULL and fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}
int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    cout<<findKthNodeFromEnd(head,4);

    return 0;
}

//    --------------------- -> n
//    ----------->             n-k+1
//    ------>                  k               
// 1 -> 2 -> 3 -> 4 -> 5

//k = 2
//n= 5 
//n-k+1 
// n + (n-k+1)
// T(n) = 2n-k+1
