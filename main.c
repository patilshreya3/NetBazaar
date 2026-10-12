#include <stdio.h>
#include "cart.h"
#include "calculation.h"
#include "display.h"

int main() {
    int choice;

    printf("============================================\n");
    printf("          ONLINE SHOPPING CART SYSTEM       \n");
    printf("============================================\n");

    do {
        printf("\n--- SHOPPING CART MENU ---\n");
        printf("1. Add Item to Cart\n");
        printf("2. Remove Item by Product ID\n");
        printf("3. Update Item Quantity\n");
        printf("4. Compute Final Bill\n");
        printf("5. Display Cart Items (Reverse Layout)\n");
        printf("6. Exit Shopping\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_item(); break;
            case 2: remove_item(); break;
            case 3: update_quantity(); break;
            case 4: compute_bill(); break;
            case 5: display_reverse(); break;
            case 6: printf("\nThank you for shopping with us!\n"); break;
            default: printf("\nInvalid option! Please select a valid code from 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}
