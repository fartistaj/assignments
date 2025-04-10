#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node* root;

    Node* insertRecursive(Node* current, int value)
    {
        if (current == nullptr)
        {
            return new Node(value);
        }

        if (value < current->data)
        {
            current->left = insertRecursive(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    void inorderTraversal(Node* node)
    {
        if (node == nullptr) return;

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    void displayInorder()
    {
        std::cout << "Inorder traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main()
{
    BinarySearchTree bst;

    int arr[] = { 1, 5, 9, 2, 4, 10, 6, 3, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Inserting elements: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
        bst.insert(arr[i]);
    }
    std::cout << std::endl;

    bst.displayInorder();

    return 0;
}
