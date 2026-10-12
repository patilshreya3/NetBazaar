#include <stdio.h>
#include <string.h>
#include "cart.h"
#include "calculation.h"

void compute_bill() {
    if (head == NULL) {
        printf("\nCart is empty! Bill amount is ₹0.00\n");
        return;
    }

    double total_bill = 0;
    struct CartNode *temp = head;

    while (temp != NULL) {
        total_bill += (temp->unit_price * temp->quantity);
        temp = temp->next;
    }

    printf("\nGross Total Amount: ₹%.2f\n", total_bill);

    char choice[10];
    printf("Do you have a 10%% discount coupon? (yes/no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0) {
        double discount = total_bill * 0.10;
        total_bill -= discount;
        printf("Coupon Applied! 10%% Discount: -₹%.2f\n", discount);
    }

    printf("Final Payable Bill Amount: ₹%.2f\n", total_bill);
}
