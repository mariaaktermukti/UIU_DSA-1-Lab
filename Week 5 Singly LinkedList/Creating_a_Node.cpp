#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;  //To store data
    Node* next; // next node er address
};

int main()
{
    Node* head= new Node;
    head->data= 10;
    head->next=NULL;

    cout << "New Data: " << head->data << endl;
    return 0;
}