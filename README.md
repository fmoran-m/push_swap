# Push Swap

## Overview

Push_swap is a project that explores algorithmic complexity through the implementation of a sorting solution under strict constraints. It emphasizes optimization and efficiency, requiring a deep understanding of algorithm design to handle diverse configurations of numbers effectively.

## Description


The program starts with **two stacks**, `a` and `b`:  
- **Stack `a`**: Contains a random set of unique integers (positive and/or negative).  
- **Stack `b`**: Starts empty.  

The objective is to sort the integers in **stack `a`** in ascending order.  

### Available Operations  

To achieve the sorting, the following operations are provided:  

#### Swap Operations  
- `sa`: Swap the first two elements of stack `a` (no effect if fewer than two elements).  
- `sb`: Swap the first two elements of stack `b` (no effect if fewer than two elements).  
- `ss`: Perform `sa` and `sb` simultaneously.  

#### Push Operations  
- `pa`: Move the top element from stack `b` to the top of stack `a` (no effect if `b` is empty).  
- `pb`: Move the top element from stack `a` to the top of stack `b` (no effect if `a` is empty).  

#### Rotate Operations  
- `ra`: Rotate stack `a` upwards (the first element becomes the last).  
- `rb`: Rotate stack `b` upwards (the first element becomes the last).  
- `rr`: Perform `ra` and `rb` simultaneously.  

#### Reverse Rotate Operations  
- `rra`: Reverse rotate stack `a` (the last element becomes the first).  
- `rrb`: Reverse rotate stack `b` (the last element becomes the first).  
- `rrr`: Perform `rra` and `rrb` simultaneously.  

### Constraints  

The program must:  
- Sort the numbers in stack `a` using the provided operations.  
- Minimize the number of operations performed.  

This project focuses on algorithmic complexity and requires an efficient sorting algorithm that adheres to the rules while maintaining correctness.  

### Objectives  

- Develop an efficient algorithm to sort stack `a`.  
- Minimize the number of operations.  
- Adhere to the given constraints and available operations.  

## How to Use

### Compilation

Compile the push_swap program using the provided Makefile:

```bash
make
```

### Execution

Run the program with a list of integers as arguments:

```bash
./push_swap [list_of_numbers]
```

For example:

```bash
./push_swap 4 67 3 87 23
```

The program will output a sequence of operations to sort the provided numbers.

### Validation

To verify the correctness of the operations, use the checker_OS program:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
If the operations are correct, checker_OS will output OK; otherwise, it will output KO.

### Operation Count

To determine the number of operations used:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

This command will display the total number of operations performed to sort the stack.

### Error Handling

If invalid input is provided, such as non-integer values or duplicate numbers, the program will output Error and terminate.

Examples:
```bash
./push_swap 2 1 3 6 5 8
# Outputs the operations to sort the stack

./push_swap 0 one 2 3
Error
```
