#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top=NULL;

void push(int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->next=top;
    top = temp;
    cout << x << " Pushed into stack." << endl;
}

void pop()
{
    if(top==NULL)
    {
        cout << "Stack Overflow. Can not pop." << endl;
        return;
    }

    Node* temp=top;
    top= top->next;
    delete temp;
}

void display()
{
    Node* temp= top;
    cout << " Stack elements are : ";
    while(temp!= NULL)
    {
        cout << temp->data << " ";
        temp= temp->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    pop();

    display();
    
    return 0;
}