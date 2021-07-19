
#ifndef ArrayBST_h
#define ArrayBST_h

#define MAX_NUM_NODES 5

#include "AbstractBST.h"

struct ArrayNode
{
    int key;
    int value;

    ArrayNode(int key, int value) : key(key), value(value) {}
};

class ArrayBinarySearchTree : public AbstractBST
{
public:
    ArrayBinarySearchTree();
    ~ArrayBinarySearchTree();

    // Checks if the BST is empty
    bool isEmpty();
    void add(int key, int value);

    void max(int &output);
    void min(int &output);

    bool search(int targetKey);

    int index_of_target_key(int targetKey);
    void remove(int targetKey);
    void inorder();

private:
    ArrayNode *nodes[MAX_NUM_NODES];

    void inorder(int index, char sep = ' ');
};

#endif /* ArrayBST_h */
