# Testie

A small unit test framework for embedded C, made for compilers where data RAM and program flash
are two separate memory maps.

## Why Testie exists

On PIC18 the data memory (RAM) and the program flash ("ROM") live in different address spaces. 
A plain `char *` cannot address both. MPLAB C18 therefore needs pointers qualified with the
correct map, for example the `rom` keyword, and it ships separate library routines for each map
(`strlenpgm`, `strcmpram2pgm`, `memcmpram2pgm`, ...).

The consequence is that a normal assertion cannot compare a string literal that the compiler placed
in flash against a buffer in RAM - the two arguments are read through different address spaces.
Testie solves exactly that by making the memory map part of the assertion:

| Assertion                                           | Expected operand   | Actual operand |
| --------------------------------------------------- | ------------------ | -------------- |
| `ASSERT_EQUAL_STRING(Expected, Actual)`             | RAM                | RAM            |
| `ASSERT_EQUAL_STRING_ROM(Expected, Actual)`         | ROM / flash        | RAM            |
| `ASSERT_EQUAL_MEMORY(Expected, Actual, Length)`     | RAM                | RAM            |
| `ASSERT_EQUAL_MEMORY_ROM(Expected, Actual, Length)` | ROM / flash        | RAM            |
