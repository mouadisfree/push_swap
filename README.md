# push_swap - My Sorting Algorithm


*My stack-based sorting algorithm project*
---
## What is this?
**push_swap** is a sorting program that uses two stacks and special moves that I wrote myself. It's a school project that helps me learn how to think about algorithms and solve problems efficiently. I'll use these problem-solving skills in other projects later.

---

## Operations I Built

### Stack Operations
- **Swap**: `sa`, `sb`, `ss` - swap top two numbers
- **Push**: `pa`, `pb` - move number between stacks
- **Rotate**: `ra`, `rb`, `rr` - shift all numbers up

### Advanced Operations
- **Reverse Rotate**: `rra`, `rrb`, `rrr` - shift all numbers down
- **Combo Moves**: `ss`, `rr`, `rrr` - do two operations at once
- **Error Handling**: check for bad input and duplicates

### Sorting Strategies
- `Small sets`: Special logic for 2-3-5 numbers
- `Large sets`: chunk algorithm for 20-100-500 numbers
- `Optimization`: Find the fewest moves to sort

---

## How to use it

### What you need
To use this sorting program, you need:
- A C compiler (like `gcc`) to turn code into programs.
- A computer with Linux or macOS.

### How to set it up
1. Download the code:
   ```bash
   git clone git@github.com:mouadisfree/push_swap.git
   cd push_swap


2. Build the program:
   ```bash
   make
   ```

   This makes a program called `push_swap` that sorts numbers.

---

## Who made this
Made by **mouadisfree** as a student at **1337 School** (part of the 42 coding schools).

---

## Thanks
Thanks to 1337 School and all my peers who helped me learn!
