#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
Node* Reverse(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* new_Head=Reverse(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;
    return new_Head;

}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Printing
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout<<endl;
    
    Node* new_Head=Reverse(head);

    Node* tp=new_Head;
    while(tp!=nullptr){
        cout<<tp->data<<"->";
        tp=tp->next;
    }
}