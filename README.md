# NetBazaar
A beginner-friendly C language microproject implementing an Online Shopping Cart using a Doubly Linked List data structure to manage items, process item quantity updates, apply discount coupons, and display elements in reverse sequence.
# Online Shopping Cart Matrix System

A modular Microproject developed in C Language using a Doubly Linked List data structure to track, manage, and process items added to an e-commerce shopping cart. The program stores individual product nodes and allows backward/forward traversal across device screens.

---

## Project Requirements Implemented

This project fully satisfies all structural operations and logic parameters specified:
* **Doubly Linked Structure:** Tracks items dynamically using standard node architectures containing specific property pointers (struct CartNode containing next and prev references).
* **Smart Node Appending:** Appends new operational nodes to the tail end or automatically increments item quantities if the product identity matches an existing item.
* **Precise Node Unlinking:** Locates targets by their product identification keys to safely decouple memory, correctly binding the neighboring front and back address fields.
* **Dynamic Quantity Updates:** Updates volume amounts using a pointer search loop, featuring built-in workflows that isolate and free the memory block if values drop to 0.
* **Financial Calculations:** Loops forward to process order sums by multiplying unit costs by amounts, adjusting calculations down by 10 percent if a coupon is valid.
* **Reverse Order Printing:** Iterates from the tail node back to the head reference using the prev property to instantly output most recently added elements first.

---

## Architecture Layout

The codebase isolates operations into clean functional divisions using separate script modules:
* main.c - The interactive command shell window governing user choices.
* cart.h & cart.c - Declares structure models and manages appending, item removals, and value updates.
* calculation.h & calculation.c - Handles monetary multiplication totals and executes coupon validation checks.
* display.h & display.c - Performs reverse sequence loops to output historical entries onto screens.

---

## Execution Instructions

To compile and execute this multi-file program inside your terminal environment, enter these terminal commands:

```bash
gcc main.c cart.c calculation.c display.c -o cart_app
./cart_app
```

