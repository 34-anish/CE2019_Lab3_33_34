

#include <iostream>

#include "ArrayBST.h"

ArrayBinarySearchTree::ArrayBinarySearchTree()
{
    for (int i = 0; i < MAX_NUM_NODES; i++)
    {
        this->nodes[i] = NULL;
    }
}
ArrayBinarySearchTree::~ArrayBinarySearchTree() //destructor
{
    int i;

    for (i = 1; i <= MAX_NUM_NODES; i++)
    {

        delete this->nodes[i];
        this->nodes[i] = NULL;
    }
}

bool ArrayBinarySearchTree::isEmpty()
{
    return this->nodes[1] == NULL;
}

void ArrayBinarySearchTree::add(int key, int value)
{
    ArrayNode *newData(new ArrayNode(key, value));

    for (int i = 1; i < MAX_NUM_NODES;)
    {
        ArrayNode *node = this->nodes[i];

        if (node == NULL)
        {
            this->nodes[i] = newData;
            break;
        }
        //shifting to the right if the current node's key is less than the new key
        else if (node->key < key)
        {
            i = 2 * i + 1;
        }

        //shifting to the right if the current node's key is less than the new key
        else
        {
            i = 2 * i;
        }
    }
}

void ArrayBinarySearchTree::remove(int targetKey)
{
    if (this->search(targetKey)) // if the target key exists in the BST
    {

        int n2d_i = this->index_of_target_key(targetKey);
        int min_nd_i = this->index_of_target_key(targetKey);
        int max_nd_i = min_nd_i;
        //has no child
        if (this->nodes[min_nd_i * 2] == NULL && this->nodes[min_nd_i * 2 + 1] == NULL)
        {
            this->nodes[min_nd_i] = NULL;
        }

        // except for the left skewed binary tree replacement is required

        //has right children atleast to its parent
        else if (this->nodes[min_nd_i * 2 + 1] != NULL)
        {
            min_nd_i = min_nd_i * 2 + 1;
            while (this->nodes[min_nd_i] != NULL)
            //while the leave is not found
            {
                if (this->nodes[min_nd_i * 2] != NULL)
                //checking if there is any  left child after the next right child
                //i.e. checking if left child exists or not for min_nd_i =3 if min_nd_i =1
                {
                    while (this->nodes[min_nd_i * 2] != NULL)
                    {
                        min_nd_i = min_nd_i * 2;
                        //keeping minimum node's index to the last left most leave as it is the minimum node
                    }
                }
                this->nodes[n2d_i] = this->nodes[min_nd_i];
                n2d_i = min_nd_i;
                this->nodes[min_nd_i] = NULL;
                if (this->nodes[min_nd_i * 2 + 1] != NULL)
                {
                    min_nd_i = min_nd_i * 2 + 1;
                }
            }
        }
        //has no right child from its parent
        else if (this->nodes[max_nd_i * 2 + 1] == NULL)
        {
            max_nd_i = max_nd_i * 2;
            while (this->nodes[max_nd_i] != NULL)
            //while the leave is not found
            {
                //if right child exist looping should be done
                if (this->nodes[max_nd_i * 2 + 1] != NULL)
                //checking if there is any  right child after the next left child
                //i.e. parent = 1 next left child = 2 if there is grand right child then
                //looping is required to find the maximum node

                {
                    while (this->nodes[max_nd_i * 2 + 1] != NULL)
                    {
                        max_nd_i = max_nd_i * 2 + 1;
                        //keeping minimum node's index to the last left most leave as it is the minimum node
                    }
                }

                this->nodes[n2d_i] = this->nodes[max_nd_i];
                n2d_i = max_nd_i;
                this->nodes[max_nd_i] = NULL;
                if (this->nodes[max_nd_i * 2] != NULL)
                {
                    max_nd_i = max_nd_i * 2;
                }
            }
        }
    }

    else
    {
        std::cout << "The targetkey doesnt exist" << std::endl;
    }
}

bool ArrayBinarySearchTree::search(int targetKey)
{

    int i = 1;
    bool found = false;
    while (i < MAX_NUM_NODES)
    {
        ArrayNode *node = this->nodes[i];
        if (node == NULL)
        {
            break;
        }
        else if (node->key == targetKey)
        {
            found = true;
            break;
        }
        else if (node->key < targetKey)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i;
        }
    }
    return found;
}

int ArrayBinarySearchTree::index_of_target_key(int targetKey)
{

    int i = 1;
    int index;
    while (i < MAX_NUM_NODES)
    {
        ArrayNode *node = this->nodes[i];
        if (node == NULL)
        {
            break;
        }
        else if (node->key == targetKey)
        {
            index = i;
            break;
        }
        else if (node->key < targetKey)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i;
        }
    }
    return index;
}

void ArrayBinarySearchTree::min(int &output)
{

    if (isEmpty())
    {
        std::cout << "The tree is empty!" << std::endl;
    }
    else
    {
        int i = 1;
        while (i < MAX_NUM_NODES)
        {
            if (nodes[2 * i] == NULL)
            {
                break;
            }
            else
            {
                i = 2 * i;
            }
        }
        if (i < MAX_NUM_NODES)
        {
            output = nodes[i]->key;
        }
    }
}

void ArrayBinarySearchTree::max(int &output)
{

    if (isEmpty())
    {
        std::cout << "The tree is empty!" << std::endl;
    }
    else
    {
        int i = 1;
        while (i < MAX_NUM_NODES)
        {
            if (nodes[2 * i + 1] == NULL)
            {
                break;
            }
            else
            {
                i = 2 * i + 1;
            }
        }
        if (i < MAX_NUM_NODES)
        {
            output = nodes[i]->key;
        }
    }
}

void ArrayBinarySearchTree::inorder()
{
    std::cout << "Inorder traversal yields " << std::endl;
    this->inorder(1);
    std::cout << std::endl;
}

void ArrayBinarySearchTree::inorder(int index, char sep)
{
    if (index < MAX_NUM_NODES && nodes[index] != NULL)
    {
        this->inorder(2 * index);
        std::cout << nodes[index]->key << sep;
        this->inorder(2 * index + 1);
    }
}
