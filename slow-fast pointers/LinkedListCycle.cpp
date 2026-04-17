#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int data1,ListNode* next1){
        data=data1;
        next=next1;
    }
    ListNode(int data1){
        data=data1;
        next=nullptr;
    }
};
void insertAtTail(ListNode* &head,ListNode* &tail,int data){
    ListNode* temp=new ListNode(data);

    if(head==nullptr){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

 bool hasCycle(ListNode* &head){
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
 }


int main(){
    ListNode* head=nullptr;
    ListNode* tail=nullptr;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);

    //creating cycle manually
    tail->next=head->next;

    bool res=hasCycle(head);
    if(res){
        cout<<"Linked List is Cycle"<<endl;
    }
    else{
        cout<<"Linked List is not Cycle"<<endl;
    }
    return 0;
}