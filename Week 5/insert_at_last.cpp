#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head= NULL;

void InsertAtLast(int value)
{
    Node* newnode= new Node;
    newnode->data= value;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode; //if the list is empty
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next=newnode;//sesh node er next notun node
} 

void PrintList()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout<< endl;
} 
int main()
{
    InsertAtLast(10);
    InsertAtLast(20);
    InsertAtLast(30);

    PrintList(); //10 20 30 ( last e insert hoyar age)

    InsertAtLast(40);
    PrintList(); // 10 20 30 40  -->(40 insert hoilo last e)

    return 0;
}