#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cart.h"

struct CartNode *head = NULL;
struct CartNode *tail = NULL;

void add_item() {
    int id, qty;
    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    struct CartNode *temp = head;
    while (temp != NULL) {
        if (temp->product_id == id) {
            printf("Product already exists. Enter extra quantity to add: ");
            scanf("%d", &qty);
            temp->quantity += qty;
            printf("Quantity updated successfully!\n");
            return;
        }
        temp = temp->next;
    }

    struct CartNode *new_node = (struct CartNode *)malloc(sizeof(struct CartNode));
    new_node->product_id = id;
    
    printf("Enter Product Name: ");
    scanf("%s", new_node->product_name);
    printf("Enter Unit Price: ₹");
    scanf("%lf", &new_node->unit_price);
    printf("Enter Quantity: ");
    scanf("%d", &new_node->quantity);
    
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    printf("Item added to cart successfully!\n");
}

void remove_item() {
    if (head == NULL) {
        printf("\nCart is empty!\n");
        return;
    }

    int id;
    printf("\nEnter Product ID to remove: ");
    scanf("%d", &id);

    struct CartNode *temp = head;
    while (temp != NULL) {
        if (temp->product_id == id) {
            if (temp == head && temp == tail) {
                head = NULL;
                tail = NULL;
            } else if (temp == head) {
                head = head->next;
                head->prev = NULL;
            } else if (temp == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Product removed from cart successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Product ID not found!\n");
}

void update_quantity() {
    if (head == NULL) {
        printf("\nCart is empty!\n");
        return;
    }

    int id, new_qty;
    printf("\nEnter Product ID to update quantity: ");
    scanf("%d", &id);

    struct CartNode *temp = head;
    while (temp != NULL) {
        if (temp->product_id == id) {
            printf("Current quantity is %d. Enter new quantity: ", temp->quantity);
            scanf("%d", &new_qty);

            if (new_qty <= 0) {
                if (temp == head && temp == tail) {
                    head = NULL;
                    tail = NULL;
                } else if (temp == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                free(temp);
                printf("Quantity became 0 or less. Item deleted from cart!\n");
            } else {
                temp->quantity = new_qty;
                printf("Quantity updated successfully!\n");
            }
            return;
        }
        temp = temp->next;
    }
    printf("Product ID not found!\n");
}
