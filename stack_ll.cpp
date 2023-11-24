#include<iostream>

using namespace std;

class LinkedList{
    public:
    int data;
    LinkedList* next;
};

LinkedList* head = NULL;
LinkedList* head1 = NULL;

void Push(int x){
    LinkedList* temp = new LinkedList;
    temp->data = x;
    temp->next = head;
    head = temp;   
}

void Push1(int x){
    LinkedList* temp2 = new LinkedList;
    temp2->data = x;
    temp2->next = head1;
    head1 = temp2;   
}

void Pop(){
    head = head->next;
}

void Pop1(){
    head1 = head1->next;
}

void Print(){
    cout<<"Last Element: "<<head->data<<'\n';
}

void Print1(){
    cout<<"Last Element: "<<head1->data<<'\n';
}

void Reverse(){
    LinkedList* temp1 = new LinkedList;
    while(head != NULL){
        Push1(head->data);
        Pop();
    }
}

int main(){
    Push(4);
    Push(7);
    Push(1);
    Push(8);
    Pop();
    Pop();
    Print();
    Push(18);
    Print();
    Pop();
    Print();

    Reverse();
    Print1();
    Pop1();
    Print1();
    return 0; 
    
}