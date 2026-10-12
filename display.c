#include <stdio.h>
#include "cart.h"
#include "display.h"

void display_reverse() {
    if (tail == NULL) {
        printf("\nCart is empty! Nothing to show.\n");
        return;
    }

    printf("\n=== SHOPPING CART (Most Recently Added First) ===\n");
    struct CartNode *temp = tail;
    
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Price: ₹%.2f | Qty: %d | Subtotal: ₹%.2f\n",
               temp->product_id, temp->product_name, temp->unit_price, temp->quantity, 
               (temp->unit_price * temp->quantity));
        temp = temp->prev;
    }
    printf("=================================================\n");
}
