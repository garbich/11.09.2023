#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int value;
    Node* next;

    Node(){
        value = 0;
        next = nullptr;
    }

    Node(int value){
        this->value = value;
        this->next = nullptr;
    }
};


void putNodeToTail(Node*& head, int value){
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}

void display(Node* head){

    if (head == nullptr){
        cout << "Stack is empty";
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}



void NegativeStack(Node* head1, Node* head2, Node*& newStack){

    while (head1 != nullptr){
        if (head1->value < 0){

            putNodeToTail(newStack, head1->value);
        }
        head1 = head1->next;
    }

    while (head2 != nullptr){

        if (head2->value < 0){
            putNodeToTail(newStack, head2->value);
        }
        head2 = head2->next;
    }

    if (newStack != nullptr){

        cout << "Negative values: ";
        display(newStack);
        return;
    }
    cout << "There are no negative values in two stacks!";
    return;
}



void Inversion(Node*& head)
{
    vector<int> tempStack;

    while (head != nullptr){
        tempStack.push_back(head->value);
        head = head->next;
    }

    for (int i = 0; i < tempStack.size(); i++){
        putNodeToTail(head, tempStack[i]);
    }
    cout << "Inversion: " << endl;
}



bool theSame(Node* head1, Node* head2)
{
    while (head1 != nullptr && head2 != nullptr){
        if (head1->value == head2->value){

            head1 = head1->next;
            head2 = head2->next;
            continue;
        }
        return false;
    }
    return true;
}

void isTheSame(Node*& head1, Node*& head2)
{
    Node* head3 = nullptr;

    if (theSame(head1, head2) == NULL){

        cout << "The stacks aren't the same!" << endl;

        NegativeStack(head1, head2, head3);
        return;
    }
    cout << "The stacks are same!" << endl;
    Inversion(head2); 

    cout << "First stack: ";
    display(head1); 

    cout << "Second stack: ";
    display(head2);
    cout << endl;
    return;
}

int main()
{
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    putNodeToTail(head1, 8); 
    putNodeToTail(head1, 3); 
    putNodeToTail(head1, 9); 
    putNodeToTail(head1, 5); 
    

    putNodeToTail(head2, 8);  
    putNodeToTail(head2, 6);  
    putNodeToTail(head2, -9);  
    putNodeToTail(head2, -4);  
    

    cout << "First stack: ";
    display(head1);

    cout << "Second stack: ";
    display(head2);

    isTheSame(head1, head2);
}