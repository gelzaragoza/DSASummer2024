//
// Created by Angel Zaragoza on 7/5/24.
//

#include "BST.h"
#include <string.h>
#include <stdlib.h>

void initializeBST(NodePtr *T) {
    *T = NULL;
    printf("BST initialized successfully!\n\n");
}

void insertProduct(NodePtr *T, Product prod) {
    if (*T == NULL) {
        *T = (NodePtr)malloc(sizeof(NodeType));
        if (*T != NULL) {
            (*T)->item = prod;
            (*T)->Left = (*T)->Right = NULL;
        }
    } else {
        if (strcmp(prod.prodName, (*T)->item.prodName) < 0) {
            insertProduct(&(*T)->Left, prod);
        } else {
            insertProduct(&(*T)->Right, prod);
        }
    }
}

void deleteProduct(NodePtr *T, char *prodName) {
    if (*T == NULL) {
        return;
    }

    if (strcmp(prodName, (*T)->item.prodName) < 0) {
        deleteProduct(&(*T)->Left, prodName);
    } else if (strcmp(prodName, (*T)->item.prodName) > 0) {
        deleteProduct(&(*T)->Right, prodName);
    } else {
        if ((*T)->Left == NULL && (*T)->Right == NULL) {
            free(*T);
            *T = NULL;
        } else if ((*T)->Left == NULL) {
            NodePtr temp = *T;
            *T = (*T)->Right;
            free(temp);
        } else if ((*T)->Right == NULL) {
            NodePtr temp = *T;
            *T = (*T)->Left;
            free(temp);
        } else {
            NodePtr parent = NULL;
            NodePtr successor = (*T)->Right;
            while (successor->Left != NULL) {
                parent = successor;
                successor = successor->Left;
            }
            if (parent != NULL) {
                parent->Left = successor->Right;
            } else {
                (*T)->Right = successor->Right;
            }
            (*T)->item = successor->item;
            free(successor);
        }
    }
}

int isMember(NodePtr T, char *prodName) {
    if (T == NULL) {
        return 0;
    } else if (strcmp(prodName, T->item.prodName) == 0) {
        return 1;
    } else if (strcmp(prodName, T->item.prodName) < 0) {
        return isMember(T->Left, prodName);
    } else {
        return isMember(T->Right, prodName);
    }
}

void preorder(NodePtr T) {
    if (T != NULL) {
        printf("%s, ", T->item.prodName);
        preorder(T->Left);
        preorder(T->Right);
    }
}

void inorder(NodePtr T) {
    if (T != NULL) {
        inorder(T->Left);
        printf("%s, ", T->item.prodName);
        inorder(T->Right);
    }
}

void postorder(NodePtr T) {
    if (T != NULL) {
        postorder(T->Left);
        postorder(T->Right);
        printf("%s, ", T->item.prodName);
    }
}
