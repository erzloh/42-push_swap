# 42-push_swap
Push_swap is a sorting algorithm project developed as part of the curriculum for School 42. The objective of this project is to sort a stack of integers in ascending order using two stacks and a limited set of operations.
## Algorithm
The algorithm I used to sort numbers is the radix sort algorithm. Radix sort is a non-comparative integer sorting algorithm that works on the individual digits which share the same significant position and value.

Here are the instructions, required by the subject, used for sorting:

- `sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : sa and sb at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : rra and rrb at the same time.
## Usage
To use Push_swap, follow these steps:

1. Clone the repository to your local machine:
``` bash
git clone https://github.com/erzloh/42-push_swap.git
```
2. Compile the program:
``` go
make
```
3. Run Push_swap with a list of integers as arguments:
``` bash
./push_swap 3 1 4 2
```
4. The program will output a list of operations required to sort the stack in ascending order.
