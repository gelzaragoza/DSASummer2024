#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXORDER 5
#define MAXCUSTOMER 10

typedef struct {
	char foodName[24];
	int foodPrice;
	int foodId;
}FoodInfo;

// store all orders in a stack linked list
typedef struct node{
	FoodInfo info[MAXORDER];
	int qty; 		// qty of orders
	struct node *next;
}OrderNode, *Order;

typedef struct {
	char customerName[24];
	Order customerOrder;
	int status; 	// 1 for served, 0 for not served
}Customer;

typedef struct {
	Customer cust[MAXCUSTOMER];
	int front;
	int rear;
}CircularQueue;

// Queue functions
void initQueue(CircularQueue *queue);                                           // initialize the queue to be empty
void enqueueCustomer(CircularQueue *queue, char *customerName, Order order);    // inserts new customer
Customer dequeueCustomer(CircularQueue *queue);                                 // returns the next customer

// Display customers in queue
void displayCustomers(CircularQueue queue);                                     // display the customers

// Stack functions              
Order createOrderNode(FoodInfo *foodItems, int count);                          // create a new order
void pushOrder(Order *order, FoodInfo *foodItems, int count);                   // insert a new order to the stack   
Order popOrder(Order *order);                                                   // returns the popped order

// Display orders in stack
void displayOrders(Order stack);                                                // display the stack orders
void displayServedOrder(Customer servedCustomer, Order servedOrder);            // display served orders, if status == 1 SERVED; else NOT SERVED

int main () {
	CircularQueue queue;
    initQueue(&queue);
    
    // Sample food items
    FoodInfo foodItems[] = {
        {"Burger", 50, 1},
        {"Fries", 30, 2},
        {"Soda", 20, 3}
    };

    // Create orders and enqueue customers
    Order order1 = createOrderNode(foodItems, 3);
    enqueueCustomer(&queue, "John", order1);

    Order order2 = createOrderNode(foodItems, 3);
    enqueueCustomer(&queue, "Jane", order2);

    // Display customers in queue
    displayCustomers(queue);

    // Serve an order and display it
    Customer servedCustomer = dequeueCustomer(&queue);
    servedCustomer.status = 1; // Update status to served
    displayServedOrder(servedCustomer, servedCustomer.customerOrder);

    // Display remaining customers in queue
    displayCustomers(queue);

    // Display all orders in stack
    displayOrders(order1); // Assuming order1 is the top of the stack

    return 0;
}

void initQueue(CircularQueue *queue) {
    queue->front = 0;
    queue->rear = MAXCUSTOMER-1;
}

void enqueueCustomer(CircularQueue *queue, char *customerName, Order order) {
    if((queue->rear + 2) % MAXCUSTOMER != queue->front) {
        queue->rear = (queue->rear + 1) % MAXCUSTOMER;
        strcpy(queue->cust[queue->rear].customerName, customerName);
        queue->cust[queue->rear].customerOrder = order;
        queue->cust[queue->rear].status = 0;
    }
}

Customer dequeueCustomer(CircularQueue *queue) {
    Customer nextCustomer; 
    if((queue->rear + 1) % MAXCUSTOMER != queue->front) {
        queue->front = (queue->front + 1) % MAXCUSTOMER;
    }
    nextCustomer = queue->cust[queue->front];
    return nextCustomer;
}

Order createOrderNode(FoodInfo *foodItems, int count) {
    Order newOrder = (Order)malloc(sizeof(OrderNode));
    if(newOrder != NULL) {
        newOrder->qty = 0;
        newOrder->next = NULL;
        pushOrder(&newOrder, foodItems, count);
    }
    return newOrder;
}

void pushOrder(Order *order, FoodInfo *foodItems, int count) {
    for (int i = 0; i < count; i++) {
        if ((*order)->qty < MAXORDER) {
            (*order)->info[(*order)->qty] = foodItems[i];
            (*order)->qty++;
        }
    }
}

void displayCustomers(CircularQueue queue) {
    printf("%-10s %-10s %-10s\n", "INDEX", "CUSTNAME", "STATUS");
    if((queue.rear + 1) % MAXCUSTOMER != queue.front) {     // if not empty
        int i;
        for(i = queue.front; i != (queue.rear + 1) % MAXCUSTOMER; i = (i + 1) % MAXCUSTOMER) {
            printf("%-10d", i);
            printf("%-10s", queue.cust[i].customerName);
            if(queue.cust[i].status == 0) {
                printf("%-10s\n", "NOT SERVED");
            } 
            if(queue.cust[i].status == 1) {
                printf("%-10s\n", "SERVED");
            } 
        }
    }
}

Order popOrder(Order *order) {
    if (*order != NULL) {
        Order temp = *order;
        *order = (*order)->next;
        temp->next = NULL; // Disconnect the popped order from the stack
        return temp;
    }
    return NULL; // Return NULL if stack is empty
}

void displayOrders(Order stack) {
    Order current = stack;
    int index = 0;
    while (current != NULL) {
        printf("Order %d: ", index);
        for (int i = 0; i < current->qty; ++i) {
            printf("%s ", current->info[i].foodName);
        }
        printf("\n");
        current = current->next;
        index++;
    }
}

void displayServedOrder(Customer servedCustomer, Order servedOrder) {
    if (servedCustomer.status == 1) {
        printf("Customer: %s\n", servedCustomer.customerName);
        printf("Status: SERVED\n");
        printf("Order: ");
        for (int i = 0; i < servedOrder->qty; ++i) {
            printf("%s ", servedOrder->info[i].foodName);
        }
        printf("\n");
    } else {
        printf("Customer: %s\n", servedCustomer.customerName);
        printf("Status: NOT SERVED\n");
    }
}
