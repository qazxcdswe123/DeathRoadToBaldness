#include <iostream>

using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data = data;
        this->color = RED;
        left = right = parent = nullptr;
    }
};

class Red_Black_Tree
{
private:
    Node *root;

public:
    Red_Black_Tree();
    ~Red_Black_Tree();
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
};

Red_Black_Tree::Red_Black_Tree()
{
    root = nullptr;
}

Red_Black_Tree::~Red_Black_Tree()
{
}

Red_Black_Tree::rotateLeft()