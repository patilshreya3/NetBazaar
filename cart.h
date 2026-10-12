#ifndef CART_H
#define CART_H

struct CartNode {
    int product_id;
    char product_name[50];
    double unit_price;
    int quantity;
    struct CartNode *next;
    struct CartNode *prev;
};

extern struct CartNode *head;
extern struct CartNode *tail;

void add_item();
void remove_item();
void update_quantity();

#endif
