#!/bin/bash

gcc -c my_putchar.c
gcc -c *.c
ar rc libmy.a *.o
