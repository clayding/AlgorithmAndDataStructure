#include "bst.h"

int main(void)
{
    binarySearchTree bst;
    bst.addToTree(20);
    bst.addToTree(8);
    bst.addToTree(3);
    bst.addToTree(16);
    bst.addToTree(34);
    bst.addToTree(13);
    bst.addToTree(26);
    bst.addToTree(50);

    bst.listingTree();

    getchar();
    return 0;
}
