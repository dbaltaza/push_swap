*This project has been created as part of the 42 curriculum by dbaltaza.*

# 🔄 push_swap

A highly optimized sorting algorithm implementation using two stacks with a limited set of operations.

---

## 📋 Description

**push_swap** is a 42 School project that challenges students to sort a stack of integers using only two stacks (`a` and `b`) and a specific set of operations, while minimizing the total number of operations used.

### Goal
Sort a random list of integers in ascending order on stack `a`, using the minimum possible number of operations.

### The Challenge
- You receive a stack `a` with random integers
- Stack `b` starts empty
- You can only use 11 specific operations to manipulate the stacks
- The fewer operations used, the better the score

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack `a` |
| `sb` | Swap the first 2 elements at the top of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element of `b` to the top of `a` |
| `pb` | Push the top element of `a` to the top of `b` |
| `ra` | Rotate stack `a` - first element becomes the last |
| `rb` | Rotate stack `b` - first element becomes the last |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate `a` - last element becomes the first |
| `rrb` | Reverse rotate `b` - last element becomes the first |
| `rrr` | `rra` and `rrb` at the same time |

### Algorithm: Turk Sort

This implementation uses the **Turk algorithm**, a cost-based optimization approach that:

1. **For small stacks (≤5 elements)**: Uses hardcoded optimal solutions
2. **For larger stacks**: 
   - Pushes all but 3 elements to stack `b`, calculating the cheapest move each time
   - Sorts the remaining 3 elements in stack `a`
   - Pushes elements back to `a` in optimal positions
   - Performs a final rotation to place the minimum at the top

### Performance

| Stack Size | Operations | Target for 100% |
|------------|------------|-----------------|
| 3 elements | ≤ 2 | ≤ 3 |
| 5 elements | ≤ 8 | ≤ 12 |
| 100 elements | ~560 avg | < 700 |
| 500 elements | ~5100 avg | ≤ 5500 |

---

## 🛠️ Instructions

### Prerequisites

- GCC compiler
- Make
- A Unix-based system (Linux/macOS)

### Compilation

```bash
# Clone the repository
git clone https://github.com/dbaltaza/push_swap.git
cd push_swap

# Compile the project
make

# Clean object files
make clean

# Full clean (including binary)
make fclean

# Recompile
make re

# Check norminette
make norm
```

### Usage

```bash
# Basic usage
./push_swap 3 2 1

# With quoted string
./push_swap "5 4 3 2 1"

# Mixed arguments
./push_swap 5 "4 3" 2 1

# Count operations
./push_swap 3 2 1 | wc -l

# Verify sorting with checker (if available)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

### Examples

```bash
# Sort 3 numbers
$ ./push_swap 2 1 3
sa

# Sort 5 numbers
$ ./push_swap 5 4 3 2 1
rra
pb
rra
pb
sa
rra
pa
pa

# Count operations for 100 random numbers
$ ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 101), 100))))"); \
  ./push_swap $ARG | wc -l
     562
```

---

## 📁 Project Structure

```
push_swap/
├── Makefile
├── README.md
├── .gitignore
│
├── include/
│   └── push_swap.h          # Header file with prototypes
│
├── src/
│   ├── main.c               # Program entry point
│   │
│   ├── operations/          # Stack operations
│   │   ├── swap_ops.c       # sa, sb, ss
│   │   ├── push_ops.c       # pa, pb
│   │   ├── rotate_ops.c     # ra, rb, rr
│   │   └── rev_rotate_ops.c # rra, rrb, rrr
│   │
│   ├── sorting/             # Sorting algorithms
│   │   ├── sort.c           # Main sorting dispatcher
│   │   ├── turk_sort.c      # Turk algorithm main
│   │   ├── turk_utils.c     # Cost calculations
│   │   └── turk_rotate.c    # Rotation helpers
│   │
│   ├── parsing/             # Input handling
│   │   └── parse.c          # Argument parsing & validation
│   │
│   └── utils/               # Utility functions
│       ├── utils.c          # Stack init, free, helpers
│       └── stack.c          # Stack normalization
│
├── obj/                     # Compiled object files
│
└── libft/                   # Custom C library
```

---

## 📚 Resources

### Documentation & References

- [Push Swap Tutorial - Medium](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Comprehensive guide to the project
- [Turk Algorithm Explanation](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - The algorithm used in this implementation
- [Visualizer](https://github.com/o-reo/push_swap_visualizer) - Helpful tool for debugging

### AI Assistance Disclosure

AI tools (GitHub Copilot) were used in this project for:

- **Code structuring**: Helping organize files into a clean folder structure
- **Algorithm optimization**: Suggestions for improving the Turk algorithm implementation
- **Debugging**: Identifying edge cases in input parsing (INT_MAX/INT_MIN handling)
- **Documentation**: Assistance in writing this README
- **Norm compliance**: Splitting functions to meet 42's norminette requirements (max 5 functions per file, max 25 lines per function)

All code was reviewed, understood, and tested by the student. The core algorithm logic and problem-solving approach were developed with understanding of the underlying concepts.

---

## ✅ Validation Checklist

- [x] Compiles with `-Wall -Wextra -Werror`
- [x] No memory leaks
- [x] Handles edge cases (empty input, single number, already sorted)
- [x] Proper error handling (duplicates, non-numeric, overflow)
- [x] Norminette compliant
- [x] 100 numbers: < 700 operations ✓
- [x] 500 numbers: ≤ 5500 operations ✓

---

## 📄 License

This project is part of the 42 School curriculum. Feel free to use it as a reference, but please don't copy it directly for your own submissions.

---

*Made with ❤️ at 42 Lisboa*