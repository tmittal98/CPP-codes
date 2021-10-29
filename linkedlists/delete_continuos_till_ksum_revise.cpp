#include <iostream>
#include <unordered_map>
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

void printlist(node* head){
    
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    return;
}


node* removeKsumSequeuence(node* &head,int k){
    
    unordered_map<int,node*> mp;
    
    node* newNode = new node(0);
    
    newNode->next = head;
    head = newNode;
    
    node* temp = head;
    int presum = 0;
   
    while(temp->next != NULL){
        presum += temp->data;
        
        if(mp.find(presum-k) == mp.end()){
            mp[presum] = temp;
            temp = temp->next;
        }
        else{
            //remove the sequence of nodes found
            // 0 -3 3 1
            node* ptr = mp[presum-k];
            node* store = ptr->next;
            ptr->next = temp->next;
            
            while(store != temp){
                node* save = store;
                store = store->next;
                mp.erase(presum - k + (save->data));
                delete save;
            }
            delete store;
            //update presum  
            presum = presum - k;
            temp = ptr->next;
        }
    }
    
    head = head->next;
    return head;
}
int main() {
	
	node* head = new node(1);
	head->next = new node(2);
	head->next->next = new node(-3);
	head->next->next->next = new node(3);
	head->next->next->next->next = new node(-1);
	
	head = removeKsumSequeuence(head,3);
	printlist(head);
	return 0;
}