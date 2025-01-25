# Libft - My Personal C Library

## 📜 Overview

**Libft** is my first personal C library, containing a collection of essential functions that are crucial for my C programming journey. The library includes re-implementations of various C standard library functions, as well as additional utility functions for string manipulation, memory handling, and linked list operations. This project allowed me to dive deeper into C, gain a better understanding of memory management, pointers, and how some of the most fundamental functions work behind the scenes.

---

## 🚀 Key Features

### Part 1: **Libc Function Reimplementations**

In this section, I’ve re-implemented a set of functions from the standard C library (`libc`). These functions replicate the behavior of their original counterparts, but with the `ft_` prefix. The functions are:

#### **Character Checks:**
- `ft_isalpha` – Checks if a character is an alphabetic letter.
- `ft_isdigit` – Checks if a character is a digit.
- `ft_isalnum` – Checks if a character is alphanumeric.
- `ft_isascii` – Checks if a character is ASCII.
- `ft_isprint` – Checks if a character is printable.

#### **String and Memory Handling:**
- `ft_strlen` – Returns the length of a string.
- `ft_memset` – Fills a block of memory with a specific value.
- `ft_bzero` – Sets a block of memory to zero.
- `ft_memcpy` – Copies memory from one location to another.
- `ft_memmove` – Moves memory from one location to another, handling overlap.
- `ft_strlcpy` – Safely copies a string with size protection.
- `ft_strlcat` – Safely appends a string with size protection.

#### **Case Conversion:**
- `ft_toupper` – Converts a character to uppercase.
- `ft_tolower` – Converts a character to lowercase.

#### **String Search:**
- `ft_strchr` – Locates the first occurrence of a character in a string.
- `ft_strrchr` – Locates the last occurrence of a character in a string.
- `ft_strncmp` – Compares two strings, with a length limit.
- `ft_strnstr` – Finds a substring within a string, with a length limit.

#### **Memory Comparison:**
- `ft_memchr` – Locates the first occurrence of a byte in memory.
- `ft_memcmp` – Compares two blocks of memory.
  
#### **String to Integer Conversion:**
- `ft_atoi` – Converts a string to an integer.

#### **Memory Allocation:**
- `ft_calloc` – Allocates memory and initializes it to zero.
- `ft_strdup` – Duplicates a string by allocating memory and copying its contents.

---

### Part 2: **Additional Utility Functions**

This section contains functions I’ve written to help with string manipulation and conversions that aren’t part of the C standard library but are incredibly useful for common tasks.

#### **String Manipulation:**
- `ft_substr` – Allocates and returns a substring of a given string.
- `ft_strjoin` – Allocates and returns a new string that is the concatenation of two strings.
- `ft_strtrim` – Allocates and returns a copy of a string with specified characters removed from the beginning and end.
- `ft_split` – Splits a string into an array of substrings based on a delimiter.

#### **Integer to String Conversion:**
- `ft_itoa` – Converts an integer to a string.

#### **String Iteration:**
- `ft_strmapi` – Applies a function to each character in a string, creating a new string from the results.
- `ft_striteri` – Applies a function to each character in a string by reference (modifies the original string).

#### **File Descriptor Output:**
- `ft_putchar_fd` – Writes a character to a specified file descriptor.
- `ft_putstr_fd` – Writes a string to a specified file descriptor.
- `ft_putendl_fd` – Writes a string followed by a newline to a specified file descriptor.
- `ft_putnbr_fd` – Writes an integer to a specified file descriptor.

---

### Bonus: **Linked List Functions**

For the bonus part of the project, I created a set of functions to manipulate linked lists, an essential data structure for dynamic memory management. Here’s the list of functions I implemented:

#### **Node Creation and Insertion:**
- `ft_lstnew` – Creates a new linked list node.
- `ft_lstadd_front` – Adds a new node at the beginning of the list.
- `ft_lstadd_back` – Adds a new node at the end of the list.

#### **List Traversal:**
- `ft_lstsize` – Returns the number of elements in a list.
- `ft_lstlast` – Returns the last node of the list.

#### **Node Removal:**
- `ft_lstdelone` – Deletes a node and frees its content.
- `ft_lstclear` – Clears the list by deleting all nodes and freeing their contents.

#### **List Iteration and Mapping:**
- `ft_lstiter` – Iterates through a list and applies a function to each node’s content.
- `ft_lstmap` – Creates a new list by applying a function to each node’s content.

---
## 🛠 Installation

To get started with **Libft**, follow the steps below:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Carlos688940/Libft.git
2. **Navigate to the project directory:**
   ```bash
    cd Libft
3. **Clone the repository:**
   ```bash
   make
## ⚙️ How to Use

Once Libft is compiled, you can use it in your C projects by following these steps:

1. **Include the libft.h header file in your C code:**
   ```c
   #include "libft.h"
---
## 📝 Requirements

- The project is written in C.
- Strict memory management (no memory leaks).
- Global variables are forbidden.





