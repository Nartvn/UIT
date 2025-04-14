
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

 void insert_node(SinglyLinkedList* llist, int llist_item) {
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(llist_item);
    
    if (llist->head == nullptr) {
        llist->head = new_node;
        llist->tail = new_node;
    } else {
        llist->tail->next = new_node;
        llist->tail = new_node;
    }
}

void reverseLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = llist->head;
    SinglyLinkedListNode* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    llist->head = prev;
}

void printLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* current = llist->head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
