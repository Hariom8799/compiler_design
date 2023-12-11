#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class StackLL{
    public:
    Node* top;

    StackLL(){
        top = NULL;
    }

    void push(int data){
        Node *newNode = new Node(data); 
        if(this->top == NULL){
            newNode->next = NULL;
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(this->top == NULL){
            cout<<"There is nothing to pop" <<endl;
            return;
        }
        Node * temp;
        temp = this->top;
        top = temp->next;
        cout<<temp->data<<" poped";
        delete(temp);
    }

    void printStack(){
        if(this->top == NULL){
            cout<<"there is nothing to print "<<endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
        
    }
};

int main(){
    StackLL stk;
    cout<<"Enter the operation you want to perform"<<endl;
    cout<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Print"<<endl;
    cout<<"0. Exit"<<endl;
    int choice;
    cin>>choice;
    while(choice != 0){
        switch (choice)
        {
        case 1:
            cout<<"Enter the data you want to push"<<endl;
            int data;
            cin>>data;
            stk.push(data);
            break;
        case 2:
            stk.pop();
            break;
        case 3:
            stk.printStack();
            break;
        default:
            cout<<"Enter the correct choice"<<endl;
            break;
        }
        cout<<"Enter the operation you want to perform"<<endl;
        cin>>choice;
    }
    return 0;
}