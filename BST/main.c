#include <stdio.h>
#include "BST.h"

int main(void) {
    NodePtr tree;
    initializeBST(&tree);

    Product prod1 = {"Apple", 1.99, 10, {1, 1, 2024}};
    Product prod2 = {"Banana", 0.99, 20, {1, 1, 2024}};
    Product prod3 = {"Cherry", 2.99, 15, {1, 1, 2024}};
    Product prod4 = {"Date", 3.99, 8, {1, 1, 2024}};
    Product prod5 = {"Elderberry", 5.99, 12, {1, 1, 2024}};
    Product prod6 = {"Fig", 2.49, 7, {1, 1, 2024}};
    Product prod7 = {"Grape", 3.49, 25, {1, 1, 2024}};

    insertProduct(&tree, prod1);
    insertProduct(&tree, prod2);
    insertProduct(&tree, prod3);
    insertProduct(&tree, prod4);
    insertProduct(&tree, prod5);
    insertProduct(&tree, prod6);
    insertProduct(&tree, prod7);

    printf("Inorder traversal after insertion:\n");
    inorder(tree);
    printf("\n");

    printf("Preorder traversal:\n");
    preorder(tree);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder(tree);
    printf("\n");

    printf("Breadth-First Search traversal:\n");
    bfs(tree);
    printf("\n");

    printf("Tree visualization:\n");
    printTree(tree, 0);
    printf("\n");

    deleteMin(&tree);
    deleteMax(&tree);

    printf("Tree visualization after deleting min and max:\n");
    printTree(tree, 0);
    printf("\n");

    printf("Inorder traversal after deleting min and max:\n");
    inorder(tree);
    printf("\n");



    return 0;
}
