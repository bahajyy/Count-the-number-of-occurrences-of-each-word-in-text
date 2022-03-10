#include <iostream>

using namespace std;

template<class T>
class LinkListNode {
public:
    T data;
    LinkListNode *next;

    LinkListNode(T data) {
        this->data = data;
        next = NULL;
    }
};

template<class T>
class LinkList {
public:
    LinkListNode<T> *head;

    LinkList() {
        head = NULL;
    }

    void insertFirst(LinkListNode<T> *node) {
        if (node != NULL) {
            if (head == NULL) { // if list is empty
                head = node;
            } else {
                node->next = head;
                head = node;
            }
        } else {
            cout << "Error NULL node" << endl;
        }
    }

    void insert(LinkListNode<T> *node, T searchData) {
        if (node != NULL) {
            //Stack is empty
            if (head == NULL) {
                head = node;
            } else {
                bool nodeFound = false;
                LinkListNode<T> *tempHead = head;
                while (tempHead != NULL) {
                    if (tempHead->data == searchData) {
                        //First set the next pointer, otherwise you will lose next node
                        node->next = tempHead->next;
                        tempHead->next = node;
                        nodeFound = true;
                        break;
                    }
                    tempHead = tempHead->next;
                }
                if (!nodeFound) {
                    cout << "Could not find element" << endl;
                }
            }
        } else {
            cout << "Error NULL node" << endl;
        }
    }

    void insertLast(LinkListNode<T> *node) {
        if (node != NULL) {
            //Stack is empty
            if (head == NULL) {
                head = node;
            } else {
                /*If you move head to the next instead of temp variable, you will lose the previous node positions
                 This loop also shows how to search an element */
                LinkListNode<T> *tempHead = head;
                while (tempHead->next != NULL) { // move to the last node
                    tempHead = tempHead->next;
                }
                tempHead->next = node; // insert node at the end
            }
        } else {
            cout << "Error NULL node" << endl;
        }
    }

    void deleteElement(T searchData) {
        LinkListNode<T> *tempHead = head;
        bool nodeFound = false;
        while (tempHead != NULL) {
            if (tempHead->next != NULL) {
                if (tempHead->next->data == searchData) {
                    tempHead->next = tempHead->next->next;
                    nodeFound = true;
                    break;
                }
            }
            tempHead = tempHead->next;
        }
        if (head->data == searchData) {
            head = head->next;
            nodeFound = true;
        }
        if (!nodeFound) {
            cout << "Could not find element" << endl;
        }
    }

    LinkListNode<T> *removeElement(T searchData) {
        LinkListNode<T> *tempHead = head;
        LinkListNode<T> *searchNode = NULL;
        bool nodeFound = false;
        while (tempHead != NULL) {
            //Check if next element is NULL
            if (tempHead->next != NULL) {
                if ((tempHead->next->data == searchData)) {
                    searchNode = tempHead->next;
                    tempHead->next = tempHead->next->next;
                    nodeFound = true;
                    break;
                }
            }
            tempHead = tempHead->next;
        }
        //If the removed data element belongs to the head
        if ((head->data == searchData)) {
            searchNode = head;
            head = head->next;
            nodeFound = true;
        }
        if (!nodeFound) {
            cout << "Could not find element" << endl;
        }
        return searchNode;
    }

    LinkListNode<T> *removeFirst() {
        LinkListNode<T> *searchNode = NULL;
        if (head != NULL) {
            searchNode = head;
            head = head->next;
        } else {
            cout << "Stack is empty " << endl;
        }
        return searchNode;
    }

    LinkListNode<T> *removeLast() {
        LinkListNode<T> *tempHead = head;
        LinkListNode<T> *searchNode = NULL;
        bool nodeFound = false;
        //While list is not empty
        while (tempHead != NULL) {
            //Check if next element is NULL
            if (tempHead->next != NULL) {
                //Check if next element is the last element
                if (tempHead->next->next == NULL) {
                    searchNode = tempHead->next;
                    tempHead->next = tempHead->next->next;
                    nodeFound = true;
                    break;
                }
            }
            tempHead = tempHead->next;
        }
        //Head is the only element and stack is not empty
        if ((!nodeFound) && (head != NULL)) {
            searchNode = head;
            head = head->next;
            nodeFound = true;
        }
        if (!nodeFound) {
            cout << "Could not find element" << endl;
        }
        return searchNode;
    }

    //Element on the tail, returned but did not removed from the linklist
    LinkListNode<T> *topElement() {
        LinkListNode<T> *tempHead = head;
        LinkListNode<T> *topElement = NULL;
        while (tempHead != NULL) {
            if (tempHead->next == NULL) {
                topElement = tempHead;
                break;
            }
            tempHead = tempHead->next;
        }
        return topElement;
    }

    void print() {
        cout<<"AAAAA";
        //You have to use temp node when you move the head temporarily,
        // otherwise the node position won't be correct
        cout << "Linklist Info" << endl;
        LinkListNode<T> *tempHead = head;
        while (tempHead != NULL) {
            cout << tempHead->data << "->";
            tempHead = tempHead->next;
        }
        cout << endl;
    }
};
