#include <iostream>
#include <memory>
#include <vector>

/* A O(n) program for construction of
BST from postorder traversal */


struct Node
{
    explicit Node(int d)
        : data(d)
    {
    }

    Node() = delete;

    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

// A recursive function to construct
// BST from a vector. postIndex is used
// to keep track of index in the vector.
std::unique_ptr<Node> constructTreeUtil(
    const std::vector<int>& elements,
    int& postIndex,
    int key,
    int min,
    int max,
    size_t size)
{
    // Base case
    if (postIndex < 0)
        return nullptr;

    std::unique_ptr<Node> root;

    // If current element of post[] is
    // in range, then only it is part
    // of current subtree
    if (key > min && key < max)
    {
        // Allocate memory for root of this
        // subtree and decrement *postIndex
        root.reset(new Node(key));
        postIndex = postIndex - 1;

        if (postIndex >= 0)
        {
            // All nodes which are in range {key..max}
            // will go in right subtree, and first such
            // node will be root of right subtree.
            root->right = constructTreeUtil(elements, postIndex,
                elements[postIndex],
                key, max, size);

            // Construct the subtree under root
            // All nodes which are in range {min .. key}
            // will go in left subtree, and first such
            // node will be root of left subtree.
            root->left = constructTreeUtil(elements, postIndex,
                elements[postIndex],
                min, key, size);
        }
    }
    return root;
}

// The main function to construct BST
// from given postorder traversal.
// This function mainly uses constructTreeUtil()
std::unique_ptr<Node> constructTree(const std::vector<int>& elements)
{
    int postIndex = static_cast<int>(elements.size()) - 1;
    return constructTreeUtil(elements, postIndex,
        elements[postIndex],
        INT_MIN, INT_MAX, elements.size());
}

/* Postorder right-left-root traversal. */
void printPostorder(const std::unique_ptr<Node>& node)
{
    if (node == nullptr)
        return;

    // first recur on right subtree
    printPostorder(node->right);

    // then recur on left subtree
    printPostorder(node->left);

    // now deal with the node
    std::cout << node->data << std::endl;
}

// Driver Code
int main()
{
    int N = 0;
    std::cin >> N;

    std::vector<int> elements;
    elements.reserve(N);

    for (int it = 0; it < N; ++it)
    {
        int num = 0;
        std::cin >> num;
        elements.push_back(num);
    }

    std::unique_ptr<Node> root = constructTree(elements);

    printPostorder(root);

    return 0;
}