#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head= NULL; //list er 1st e kono node naii. 

void InsertAtFirst(int value)
{
    Node* newNode= new Node; // newNode nam e ekta node banaichi
    newNode->data=value;
    newNode->next=head; // new node puran head ke point korbe
    head= newNode; // head bar bar kore update hote thake
}

void PrintList()
{
    Node* temp= head;
    while(temp!= NULL)
    {
        cout << temp->data << " ";
        temp= temp->next;
    }
    cout<< endl;
}

int main()
{
    InsertAtFirst(10);
    InsertAtFirst(20);
    InsertAtFirst(30);

    PrintList();
    return 0;
}

//output: 30 20 10