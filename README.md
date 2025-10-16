## Project Overview

Push_swap is a 42 School project that involves sorting a stack of integers using two stacks and a limited set of operations.
The goal is to arrange the numbers in ascending order with the fewest moves possible. The choice of the algorithm was totally free.

## Allowed stacks operations

The project restricts you to a small set of predefined operations that manipulate the two stacks — A and B.
Each operation affects one or both stacks according to the following rules:

`Push`
→ Moves the top element from one stack to the other.  
pa : Push the top of B onto A.  
pb : Push the top of A onto B.  

`Swap`
→ Swaps the first two elements at the top of a stack.  
sa : Swap the top two elements of A.  
sb : Swap the top two elements of B.  
ss : Perform sa and sb simultaneously.  

`Rotate`
→ The top element becomes the last one.  
ra : Rotate stack A.  
rb : Rotate stack B.  
rr : Perform ra and rb simultaneously.  

`Reverse Rotate`
→ The bottom element becomes the first one.  
rra : Reverse rotate stack A.  
rrb : Reverse rotate stack B.  
rrr : Perform rra and rrb simultaneously.  


## Project Structure

```md
push_swap
├── checker_bonus
├── include
├── libft
├── src
│   ├── algo # implementation of the algorithm
│   ├── moves # all stack operations
│   ├── utils # utility functions
│   └── main.c
├── Makefile
└── README.md 
```


## Installation and Usage

1. Clone the repository:
```bash
git clone https://github.com/matthieugaudin/push_swap.git
cd push_swap
```

2. Compile the project
```bash
make        # Compile push_swap
make bonus  # Compile the checker
```

3. Run the sorter
```bash
./push_swap 4 2 1 3
```

6. Launch the checker
```bash
./checker ...
```

## Stack implmentation

First, to understand the algorithm, let’s look at how the stacks are represented. Each stack is implemented as a linked list of nodes, which allows efficient manipulation. Each node contains several pieces of data useful for the algorithm.

```bash
typedef struct s_stack
{
	int					value;
	int					pos;
	int					push_cost;
	int					above_median;
	struct s_stack		*target;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;
```


## How Push_swap Works

- the input data is parsed to check errors (signes, duplcate values, integer overflow, no-digit, etc.)
- each node is allocated in the heap and it's data is fulfilled
- the program doesn't compute the algorithm is the set of number is already sorted
- special sorts are performed if there are only 2 or 3 numbers
- the **Turk algorithm** is performed
- heap memory that has been allocated is freed


## What Algorithm I Used
I personnaly decieded to use the **Turk algorithm**. Here's a short explaination of it.
- d


+ visualisator


## Conclusion

...

