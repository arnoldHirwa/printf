# 0x11. C - printf

This is a printf project. It functions similarly as the built-in printf function in C. 

# Overview of printf:

The printf function in C is used for formatted output. It’s part of the Standard Input/Output Library (stdio.h) and is responsible for printing data to the standard output (typically the console) in a specified format. It’s an essential tool for displaying information to users and debugging programs.

# The Format String:
At the core of printf is the format string. This string contains both text and format specifiers, which are placeholders for the values you want to print. Format specifiers start with a ‘%’ character, followed by a character that indicates the type of data to be printed (e.g., %d for integers, %s for strings).

Here’s a simple example:

int age = 30;
printf("I am %d years old.", age);
In this example, "I am %d years old." is the format string, and %d is the format specifier. The %d specifier tells printf to expect an integer value, which is provided as age.

The printf function processes the format string, replacing format specifiers with the actual values you provide as arguments.
