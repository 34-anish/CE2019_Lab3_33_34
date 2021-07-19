#include <iostream>
#include "ArrayBST.h"

int main()
{
    ArrayBinarySearchTree a;
    std::cout << "The tree is empty:" << a.isEmpty() << std::endl;
    a.add(2, -1);
    a.add(1, -1);
    a.add(3, -1);
    a.inorder();
}
