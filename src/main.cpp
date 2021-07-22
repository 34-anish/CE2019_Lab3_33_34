#include <iostream>
#include "ArrayBST.h"

int main()
{
    ArrayBinarySearchTree a;
    std::cout << "The tree is empty:" << a.isEmpty() << std::endl;
    a.add(20, 1);
    a.add(15, 2);
    a.add(30, -1);
    a.add(25, -1);
    
    a.add(35, -1);
    a.add(14, -1);
    a.add(17,9);
    
    a.inorder();
    a.remove(25);
    a.inorder();
    a.remove(14);
    a.inorder();
    a.remove(20);
    a.inorder();
}
