# \_malloc

A C standard library function to dynamically allocate memory to the HEAP

## Description

This is an implimentation of malloc, a naive version and a version meant to work alongside \_free. The goal is to better understand memory allocation and to make a robust design able to operate similarly to the C standard library family of functions.

## Environment

\_malloc was designed in and to be run on POSIX compliant distros (specifically Ubuntu 22.04)

## How to Install and Run

1. Clone the repository `git clone https://github.com/DaveyCHaysIII/atlas-malloc`
2. In your terminal, run `gcc malloc.c free.c testing/test.c'
3. In your terminal, run `./a.out`

## Output

Example:
```
:~/Desktop/showcase/atlas-malloc$ gcc testing/test.c malloc.c free.c
:~/Desktop/showcase/atlas-malloc$ ./a.out
Block 1 allocated at address: 0x5c4eec7a1020
Block 2 allocated at address: 0x5c4eec7a3040
Block 3 allocated at address: 0x5c4eec7a5060
Block 4 allocated at address: 0x5c4eec7a1020
Block 5 allocated at address: 0x5c4eec7a1108
Block 6 allocated at address: 0x5c4eec7a1258
Test completed.
:~/Desktop/showcase/atlas-malloc$
```
