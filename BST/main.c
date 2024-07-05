#include <stdio.h>
#include "BST.h"

int main(void) {
    NodePtr tree;
    initializeBST(&tree);

    Product prod1 = {"Apple", 1.99, 10, {1, 1, 2024}};
    Product prod2 = {"Banana", 0.99, 20, {1, 1, 2024}};
    Product prod3 = {"Cherry", 2.99, 15, {1, 1, 2024}};
    Product prod4 = {"Grape", 3.49, 12, {1, 1, 2024}};
    Product prod5 = {"Orange", 1.79, 18, {1, 1, 2024}};
    Product prod6 = {"Kiwi", 2.29, 22, {1, 1, 2024}};

    // Insert products into the BST
    insertProduct(&tree, prod1);
    insertProduct(&tree, prod2);
    insertProduct(&tree, prod3);
    insertProduct(&tree, prod4);
    insertProduct(&tree, prod5);
    insertProduct(&tree, prod6);

    // Display inorder traversal
    printf("Inorder traversal after insertion:\n");
    inorder(tree);
    printf("\n");

    deleteProduct(&tree, "Banana");

    // Display inorder traversal after deletion
    printf("\nInorder traversal after deletion of Banana:\n");
    inorder(tree);
    printf("\n");

    // Check membership
    if (isMember(tree, "Apple")) {
        printf("\nApple is in the tree.\n");
    } else {
        printf("\nApple is not in the tree.\n");
    }

    if (isMember(tree, "Banana")) {
        printf("Banana is in the tree.\n");
    } else {
        printf("Banana is not in the tree.\n");
    }

    // Display preorder traversal
    printf("\nPreorder traversal:\n");
    preorder(tree);
    printf("\n");

    // Display postorder traversal
    printf("\nPostorder traversal:\n");
    postorder(tree);
    printf("\n");

    return 0;
}