#include <iostream>

using namespace std;

template<class T>
class BinaryTreeNode {
public:
    T data;
    int counter=0;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data,int counter) {
        this->data = data;
        this->counter=counter;
        left = right = NULL;
    }
};


template<class T>
class BinaryTree {
public:
    BinaryTreeNode<T> *root;

    BinaryTree() {
        root = NULL;
    }

    bool isEmpty() {
        return root == NULL;
    }

    //Insertion Rule:Nodes(new) with a value less than the node value are added left, otherwise right.
    void insert(BinaryTreeNode<T> *treeNode) {
        if (treeNode != NULL) {
            //If tree is empty
            if (root == NULL) {
                root = treeNode;
            } else {
                bool isInserted = iterativeInsert(treeNode);
                if (!isInserted) {
                    cout << "Node is not inserted ! " << endl;
                }
            }
        } else {
            cout << "Error NULL node" << endl;
        }
    }

    bool iterativeInsert(BinaryTreeNode<T> *treeNode) {
        bool isInserted = false;
        BinaryTreeNode<T> *tempRoot = root;
        while (!isInserted) {
            //If data is smaller than node data
            if (treeNode->data < tempRoot->data) {
                //If space is available
                if (tempRoot->left == NULL) {
                    tempRoot->left = treeNode;
                    isInserted = true;
                } else {
                    tempRoot = tempRoot->left;
                }
            }//If data is greater or equal to node data
            else if (treeNode->data > tempRoot->data) {
                if (tempRoot->right == NULL) {
                    tempRoot->right = treeNode;
                    isInserted = true;
                } else {
                    tempRoot = tempRoot->right;
                }
            } else {
                cout << "Duplicate data !" << endl;
                break;
            }
        }
        return isInserted;
    }

    bool insertRecursive(BinaryTreeNode<T> *tempRoot, BinaryTreeNode<T> *treeNode) {
        if (treeNode->data < tempRoot->data) {
            //If space is available
            if (tempRoot->left == NULL) {
                tempRoot->left = treeNode;
                return true;
            } else {
                insertRecursive(tempRoot->left, treeNode);
            }
        }//If data is greater or equal to node data
        else if (treeNode->data > tempRoot->data) {
            if (tempRoot->right == NULL) {
                tempRoot->right = treeNode;
                return true;
            } else {
                insertRecursive(tempRoot->right, treeNode);
            }
        } else {
            cout << "Duplicate data !" << endl;
            return false;
        }
    }

    void deleteNode(T data) {
        //If removed node is root
        if (root->data == data) {
            //Self Study
        } else {
            BinaryTreeNode<T> *tempRoot = root;
            BinaryTreeNode<T> *parent = root;
            char choice = NULL;
            bool isFound = false;
            while (!isFound) {
                //Searching value on right side of tree
                if (data > tempRoot->data) {
                    parent = tempRoot;
                    choice = 'R';
                    tempRoot = tempRoot->right;
                }//Searching value on left side of tree
                else if (data < tempRoot->data) {
                    parent = tempRoot;
                    choice = 'L';
                    tempRoot = tempRoot->left;
                }// Node found
                else {
                    isFound = true;
                    //Case 1 - No children
                    if (tempRoot->left == NULL && tempRoot->right == NULL) {
                        if (choice == 'R') {
                            parent->right = NULL;
                        } else {
                            parent->left = NULL;
                        }
                    }
                        // Case 2 - 1 child and child on left
                    else if (tempRoot->left != NULL && tempRoot->right == NULL) {
                        if (choice == 'R') {
                            parent->right = tempRoot->left;
                        } else {
                            parent->left = tempRoot->left;
                        }
                    }// Case 2 - 1 child and child on right
                    else if (tempRoot->left == NULL && tempRoot->right != NULL) {
                        if (choice == 'R') {
                            parent->right = tempRoot->right;
                        } else {
                            parent->left = tempRoot->right;
                        }
                    }// Case 3 - 2 Children
                    else {
                        //Self Study
                    }
                }
            }
        }
    }

    BinaryTreeNode<T> *minNode() {
        BinaryTreeNode<T> *tempRoot = root;
        while (tempRoot->left != NULL) {
            tempRoot = tempRoot->left;
        }
        return tempRoot;
    }

    BinaryTreeNode<T> *maxNode() {
        BinaryTreeNode<T> *tempRoot = root;
        while (tempRoot->right != NULL) {
            tempRoot = tempRoot->right;
        }
        return tempRoot;
    }

    T minData() {
        T data = NULL;
        BinaryTreeNode<T> *tempRoot = root;
        while (tempRoot->left != NULL) {
            tempRoot = tempRoot->left;
        }
        //Empty Tree Check , prevent access to the data of NULL
        if (tempRoot != NULL) {
            data = tempRoot->data;
        }
        return data;
    }

    T maxData() {
        T data = NULL;
        BinaryTreeNode<T> *tempRoot = root;
        while (tempRoot->right != NULL) {
            tempRoot = tempRoot->right;
        }
        //Empty Tree Check , prevent access to the data of NULL
        if (tempRoot != NULL) {
            data = tempRoot->data;
        }
        return data;
    }

    BinaryTreeNode<T> *search(T data) {
        BinaryTreeNode<T> *tempRoot = root;
        while (tempRoot != NULL && tempRoot->data != data) {
            if (data > tempRoot->data) {
                tempRoot = tempRoot->right;
            } else {
                tempRoot = tempRoot->left;
            }
        }
        if (tempRoot == NULL) {
            cout << "Node not found !" << endl;
        }
        return tempRoot;

    }

    void printTree(BinaryTreeNode<T> *tempRoot, int gap = 0) {
        if (tempRoot != NULL) {
            printTree(tempRoot->right, gap + 1);
            for (int i = 0; i < gap; i++) {
                cout << "\t";
            }
            cout << tempRoot->data << endl;
            printTree(tempRoot->left, gap + 1);
        }
    }

};

