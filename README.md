# Push Swap 🔄

## ℹ️ Overview

The goal of the **Push Swap** program is to find the lowest number of operations to sort the stack.

## 🛠️ Simplyfied overwiev of the allowed operations

- **sa (s):** Swap the first 2 elements at the top of a stack.
- **ss:** Perform sa and sb simultaneously.
- push (p):** Pushes the first stack element to the second stack.
- rotate (r):** Move up all elements of the stack by 1. First element becomes the last.
- **rr:** Perform ra and rb simultaneously.
- reverse rotate (rr):** Move down all elements of the stack by 1. Last element becomes the first.
- **rrr:** Perform rra and rrb simultaneously.

## 📝 Sorting Approach

The program uses a movement cost calculation approach to determine the most cost-effective moves for sorting the stack.
For each move it calculates the cheapest operation to minimize the total number of operations required for sorting.

## 🚀 Usage

1. Compile the program using the provided Makefile.
2. Run the program "push_swap" with a list of integers as arguments.
3. The program will display the instructions needed to sort the stack on the standard output.
