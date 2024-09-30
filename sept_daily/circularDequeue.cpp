#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int data) {
        this->val = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class MyCircularDeque {
	
private:

    int curr;
    int k;
    Node* head;
    Node* tail;

public:
    MyCircularDeque(int k) {
        this->curr = 0;
        this->k = k;
    }
    
    bool insertFront(int value) {
        if (curr == k)
            return false;
        
        Node* newNode = new Node(value);
        if (curr == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        curr++;
        return true;
    }
    
    bool insertLast(int value) {
        if (curr == k)
            return false;
        
        Node* newNode = new Node(value);
        if (curr == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        curr++;
        return true;
    }
    
    bool deleteFront() {
        if (curr == 0)
            return false;
        
        curr--;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return true;
    }
    
    bool deleteLast() {
        if (curr == 0)
            return false;
        
        curr--;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        delete temp;
        return true;
    }
    
    int getFront() {
        if (curr == 0)
            return -1;
        return head->val;
    }
    
    int getRear() {
        if (curr == 0)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return (curr == 0);
    }
    
    bool isFull() {
        return (curr == k);
    }
};

int main(int argc, char const *argv[]) {
	
	return 0;
}