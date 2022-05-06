#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#define RED 1
#define BLACK 0
using namespace std;

//template <typename T>
class Node {
    private:
        int color;
        int data;
        int count;
        Node *leftChild;
        Node *rightChild;
        Node *parent;
    public:
        Node(int color, int data) {
            this->color = color;
            this->data = data;
            this->count = 1;
            this->leftChild = NULL;
            this->rightChild = NULL;
            this->parent = NULL;
        }
        int getData() {
            return this->data; 
        }
    friend void _display_subtree(Node *q, vector<string> & output, int left, int top, int width);
    friend class RBTree;
};

//template <typename T>
class RBTree {
    public:
    private:
        Node *root;
    
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        void insertFix(Node *&);
        int getColor(Node *&);
        int _get_height(Node*);
        void setColor(Node *&, int color);
        int getCount(Node *&);
        void updateCount(Node *, int);
        void setCount(Node *&);
        void setParent(Node *&, Node *&);
        void eraseFix(Node *&, Node *);
        void _display_tree(Node *);
        Node* minimumRight(Node *);
        Node* maximumLeft(Node *);
        Node* getSibling(Node *);
        Node* otherChild(Node *, Node *);
        Node* find(int data);
        Node* minNode();
        Node* maxNode();
        void eraseNode(Node *&ptr);
    public:
        RBTree();
        ~RBTree();
        void _display_tree();
        void insert(int data);
        void erase(int data);
        void erasePos(int data);
        Node* upper_bound(int);
        Node* lower_bound(int);
        Node* findID(int pos);
        Node* end();
        Node* begin();
        Node* rend();
        Node* rbegin();
        Node* Next(Node *);
        Node* Prev(Node *);
};

