# push-swap

The Push swap project is a very simple and a highly straightforward algorithm project: **data must be sorted.**

We have at our disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.
We have to write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions,
that sorts the integers received as arguments.

## Project rules

We have 2 stacks named A and B. At the beginning:
- The stack A contains a random amount of negative and/or positive numbers
which cannot be duplicated.
- The stack B is empty.
- The goal is to sort in ascending order numbers into stack A.

To do so we have the following operations at our disposal:
- **sa (swap a)**: Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **sb (swap b)**: Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **ss** : **sa** and **sb** at the same time. 
- **pa (push a)**: Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb (push b)**: Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **ra (rotate a)**: Shift up all elements of stack a by 1. The first element becomes the last one.
- **rb (rotate b)**: Shift up all elements of stack b by 1. The first element becomes the last one.
- **rr** : **ra** and **rb** at the same time.
- **rra (reverse rotate a)**: Shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb (reverse rotate b)**: Shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr** : **rra** and **rrb** at the same time.

## How to use

You can clone the project and its modules and compile it with `make`.

Then, you can use it with `$> ./push_swap 4 2 0 1 92 -29 3`. It will provide the set of instructions that sort that stack of numbers.

Also, you can compile the checker program with `make bonus` and pipe the `push_swap` output into the `checker` you just compiled.

Example:

`$> export ARGS="12 93 23 48 -16 -2006 0 42"; ./push_swap $ARGS | ./checker $ARGS`

### Python tester

I also implemented a more complete tester in Python that runs multiple tests to check the average number of movements and the worst case, comparing it with a provided maximum.

Usage:

```
tester.py [-h] -n NUMBERS [-l LIMIT] [-v {INFO,WARNING}]

required arguments:
  -n NUMBERS, --numbers NUMBERS
                        How many numbers will be passed to push_swap

optional arguments:
  -h, --help            show this help message and exit
  
  -l LIMIT, --limit LIMIT
                        Maximum move limit

  -v {INFO,WARNING}, --verbose {INFO,WARNING}
                        Log level for the tester. WARNING gives info about incorrectly sorted sequences, and INFO
                        also prints the push_swap instructions for these sequences
```

## Benchmarks

### 3 numbers. Limit: 2 or 3 moves

```
python tester.py -n 3 -l 2

N of tests: 6
OK: 6
================================================================================
Size of the input: 3 numbers.
Average number of moves: 1.3333333333333333. Worse: 2
================================================================================
```

### 5 numbers. Limit: 12 moves

```
python tester.py -n 5 -l 12

N of tests: 120
OK: 120
================================================================================
Size of the input: 5 numbers.
Average number of moves: 8.025. Worse: 11
================================================================================
```

### 100 numbers. Limit: 700 moves

```
python tester.py -n 100 -l 700

N of tests: 100
OK: 100
================================================================================
Size of the input: 100 numbers.
Average number of moves: 620.06. Worse: 685
================================================================================
```

### 500 numbers. Limit: 5500 moves

```
python tester.py -n 500 -l 5500                            

N of tests: 100
OK: 100
================================================================================
Size of the input: 500 numbers.
Average number of moves: 5163.19. Worse: 5456
================================================================================
```
