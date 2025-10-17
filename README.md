## Project Overview

Push_swap is a 42 School project that involves sorting a stack of integers using two stacks and a limited set of operations.
The goal is to arrange the numbers in ascending order with the fewest moves possible. The choice of the algorithm was totally free.


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

- The input data is parsed and errors are checked such as invalid signs, duplicate values, integer overflows, or non-digit characters.
- Each node is allocated on the heap, and its data fields are properly initialized.
- The program skips the sorting algorithm if the set of numbers is already sorted.
- Special sorting routines are used when there are only two or three numbers, to ensure minimal moves.
- The **Turk algorithm** is then executed to sort the set.
- Finally, all allocated heap memory is freed to avoid memory leaks.


## What Algorithm I Used  

I personnaly decieded to use the **Turk algorithm**. Here's a short explaination of it.  

- The program begins with all the nodes in stack `a`.  
- Nodes are pushed from stack `a` to stack `b` until only three nodes remain in stack `a`.  
- During each push, stack `b` is kept **sorted in descending order**.  
- For every push, the program determines **which node from stack `a`** should be pushed to stack `b`.  
- First, a **target node** in stack `b` is computed for each node in stack `a`.  
  - A target node is the **closest smaller node** in stack `b` compared to the current node in `a`.  
  - If no smaller node exists, the **largest node** in stack `b` is chosen as the target.  
- Next, the program determines the **cheapest node in stack `a`** to push, based on the number of operations required to bring both the `a` node and its `b` target node to the top of their respective stacks.  
- Once the cheapest node is identified, the corresponding operations are performed.  
- When only three nodes remain in stack `a`, a **special sort** is applied to order them in ascending order.  
- For each node in stack `b`, the algorithm finds its **target node** in stack `a`, which is the **closest larger node**, or the **minimum node** if no larger one exists.  
- Then, the program calculates the **median position** to determine the most efficient rotation:  
  - If the node is below the median → perform `rra`.  
  - If the node is above the median → perform `ra`.  
- Finally, the **minimum node in stack `a`** is rotated to the top, completing the sorting process.

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
  
`Invalid values`  
```bash
./push_swap 1 ++2 3
./push_swap 1 2 3a
./push_swap 1.5 2 3
./push_swap 1 2 3 2
./push_swap 42 42
./push_swap 2147483648
./push_swap -2147483649
./push_swap ""
./push_swap "1    2    "
```
`Valid values`  
```bash
./push_swap 4 3 2 1
./push_swap 2 4 3 1
./push_swap 3 8 5 2 9 1
./push_swap 10 9 8 7 6 5 4 3 2 1
./push_swap 1 5 2 8 3 6 4 7
```

6. Launch the checker
```bash
./push_swap 3 8 5 2 9 1 | ./checker 3 8 5 2 9 1
-> OK
./push_swap 10 9 8 7 6 5 4 3 2 1 | ./checker 10 9 8 7 6 5 4 3 2 1
-> OK
./push_swap 1 5 2 8 3 6 4 7 | ./checker 1 5 2 8 3 6 4
-> KO (stacks are differents)
```

## Algorithm Visualizer

[🎥 Watch the demo video](assets/video.mp4)

## Conclusion  

I really enjoyed this project because it made me more comfortable with linked list management and helped me understand how to implement an algorithm. If you have any questions or need more details, feel free to contact me.

