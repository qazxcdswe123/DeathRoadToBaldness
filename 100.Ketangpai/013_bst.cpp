#include <bits/stdc++.h>
using namespace std;

// the bst structure
struct node
{
    int data;
    node *left, *right;
};

// the search function
node *search(node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

// minimum value in the bst
node *minValue(node *root)
{
    node *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// maximum value in the bst
node *maxValue(node *root)
{
    node *current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

// the insert function
node *insert(node *root, int key)
{
    if (root == NULL)
    {
        root = new node;
        root->data = key;
        root->left = root->right = NULL;
        return root;
    }
    if (root->data < key)
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);
    return root;
}

// the delete function
node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;
    if (root->data < key)
        root->right = deleteNode(root->right, key);
    else if (root->data > key)
        root->left = deleteNode(root->left, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // 此时的 root->data == key
        // 并且存在子节点

        // 找到其 successor
        node *temp = minValue(root->right);
        // root 的值替换成 successor 的值，完成值上的替换
        root->data = temp->data;
        // 删除 successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// find the key in the bst
bool find(node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (root->data < key)
        return find(root->right, key);
    return find(root->left, key);
}

// the inorder function
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// the preorder function
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// the postorder function
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// the main function with delete and insert
int main()
{
    node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "Inorder traversal of the given tree \n";
    inorder(root);
    cout << "\n";
    cout << "Preorder traversal of the given tree \n";
    preorder(root);
    cout << "\n";
    cout << "Postorder traversal of the given tree \n";
    postorder(root);
    cout << "\n";
    cout << "Deleting 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
    cout << "\n";
    cout << "Deleting 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
    cout << "\n";
    cout << "Deleting 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
    cout << "\n";
    cout << "Deleting 70\n";
    root = deleteNode(root, 70);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
    cout << "\n";
    cout << "Deleting 80\n";
    root = deleteNode(root, 80);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
    cout << "\n";
    cout << "Deleting 40\n";
    root = deleteNode(root, 40);
}