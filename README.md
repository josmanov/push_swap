# 🏗️ Push Swap - Sorting with Style!
Push Swap is a sorting algorithm project for **42**. 

The goal is to sort a stack of numbers using a limited set of operations in the most efficient way possible.

---

## ⚙️ Installation

1. **Clone the repository**:

    ```bash
    git clone https://github.com/josmanov/push_swap.git
    ```

2. **Enter the project directory**:

    ```bash
    cd push_swap
    ```

3. **Compile the program**:

    ```bash
    make
    ```

    - To clean up compiled files:
      ```bash
      make clean
      ```
    - To fully clean up the repository:
      ```bash
      make fclean
      ```
    - To recompile from scratch:
      ```bash
      make re
      ```

---

## 🚀 Usage

Run the program by providing a sequence of numbers:

```bash
./push_swap 4 67 3 87 23
```

The program will output a series of operations to sort the numbers using two stacks (**Stack A** and **Stack B**).

---

## 🔧 Operations

Push Swap uses the following operations:

- **sa** – Swap the top two elements of stack A.
- **sb** – Swap the top two elements of stack B.
- **ss** – Perform sa and sb simultaneously.
- **pa** – Push the top element from stack B to stack A.
- **pb** – Push the top element from stack A to stack B.
- **ra** – Rotate stack A upwards.
- **rb** – Rotate stack B upwards.
- **rr** – Rotate both stacks A and B upwards.
- **rra** – Reverse rotate stack A.
- **rrb** – Reverse rotate stack B.
- **rrr** – Reverse rotate both stacks A and B.

---

## 🌍 Built With

- **C** – The entire program is written in pure **C**.
- **Libft** – Custom utility functions from **Libft**.
