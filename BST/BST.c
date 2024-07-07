//
// Created by Angel Zaragoza on 7/5/24.
//

#include "BST.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

bool isMember(NodePtr T, char *prodName) {
    if (T == NULL) {
        return false;
    } else if (strcmp(prodName, T->item.prodName) == 0) {
        return true;
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

int deleteMin(NodePtr *T) {
    NodePtr temp, *trav;
    char ret[20];

    for (trav = T; (*trav)->Left != NULL; trav = &(*trav)->Left) {}
    strcpy(ret, (*trav)->item.prodName);
    temp = *trav;
    *trav = temp->Right;
    free(temp);

    printf("Deleted min: %s\n", ret);
    return 0;
}

int deleteMax(NodePtr *T) {
    NodePtr temp, *trav;
    char ret[20];

    for (trav = T; (*trav)->Right != NULL; trav = &(*trav)->Right) {}
    strcpy(ret, (*trav)->item.prodName);
    temp = *trav;
    *trav = temp->Left;
    free(temp);

    printf("Deleted max: %s\n", ret);
    return 0;
}

void bfs(NodePtr T) {
    if (T == NULL) {
        return;
    }

    Queue q;
    initializeQueue(&q);

    enqueue(&q, T);

    while (!isQueueEmpty(q)) {
        NodePtr current = dequeue(&q);
        printf("%s, ", current->item.prodName);

        if (current->Left != NULL) {
            enqueue(&q, current->Left);
        }
        if (current->Right != NULL) {
            enqueue(&q, current->Right);
        }
    }
}

void printTree(NodePtr T, int space) {
    if (T == NULL)
        return;

    space += 10;

    printTree(T->Right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%s\n", T->item.prodName);
    printTree(T->Left, space);
}

void initializeQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

bool isQueueEmpty(Queue Q) {
    return (Q.front == NULL);
}

void enqueue(Queue *Q, NodePtr treeNode) {
    QueueNodePtr newQueueNode = (QueueNodePtr)malloc(sizeof(QueueNode));
    if (newQueueNode != NULL) {
        newQueueNode->treeNode = treeNode;
        newQueueNode->next = NULL;
        if (Q->rear == NULL) {
            Q->front = newQueueNode;
        } else {
            Q->rear->next = newQueueNode;
        }
        Q->rear = newQueueNode;
    }
}

NodePtr dequeue(Queue *Q) {
    if (!isQueueEmpty(*Q)) {
        QueueNodePtr temp = Q->front;
        NodePtr treeNode = temp->treeNode;
        Q->front = temp->next;
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        free(temp);
        return treeNode;
    }
    return NULL;
}
