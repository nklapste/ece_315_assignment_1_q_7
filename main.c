/**
 * ECE 315 Assignment #1 Question 7
 *
 * Copyright 2019 Nathan Klapstein
 */

#include <stdio.h>

#define CHAR_POINTER 1
#define INT_POINTER 2
#define DOUBLE_POINTER 3

int compare_int(const void *arg1, const void *arg2) {
    return *(int *) arg1 > *(int *) arg2;
}

int compare_char(const void *arg1, const void *arg2) {
    return *(char *) arg1 > *(char *) arg2;
}

int compare_double(const void *arg1, const void *arg2) {
    return *(double *) arg1 > *(double *) arg2;
}

/**
 * Determine the median value between three generic argument
 * @param arg1
 * @param arg2
 * @param arg3
 * @param compar comparison function between two values
 * @return the pointer to the middle argument
 */
void *find_mid(void *arg1, void *arg2, void *arg3, int (*compar)(const void *, const void *)) {
    if (compar(arg1, arg2)) {
        if (compar(arg3, arg2)) {
            if (compar(arg1, arg3)) {
                return arg3;
            } else {
                return arg1;
            }
        } else {
            return arg2;
        }
    } else {
        if (compar(arg2, arg3)) {
            if (compar(arg1, arg3)) {
                return arg1;
            } else {
                return arg3;
            }
        } else {
            return arg2;
        }
    }
}

/**
 * 7. Design a C function that receives four input arguments and returns a void * output value.
 * The last three inputs are to be void * values, which need to be cast to the appropriate typed
 * pointers and then dereferenced within the function to access three stored values. The first
 * input is to be an integer value that specifies the input pointer type as follows:
 * the value 1 specifies char *s,
 * 2 specifies int *s,
 * and 3 specifies double *s.
 *
 * If the first input is not a valid value, or if any of the three pointer inputs is NULL, then
 * the output value is to be NULL; otherwise, the output value is to be a void * that points to
 * the base address location that contains the middlemost value of the three values pointed to
 * by the three input pointers.
 *
 * If two or three of the memory referenced locations contain the same value, then the return
 * pointer points to any one of those locations
 */
void *question7(int pointer_type, void *arg1, void *arg2, void *arg3) {
    switch (pointer_type) {
        case CHAR_POINTER: {
            return find_mid(arg1, arg2, arg3, compare_char);
        }
        case INT_POINTER: {
            return find_mid(arg1, arg2, arg3, compare_int);
        }
        case DOUBLE_POINTER: {
            return find_mid(arg1, arg2, arg3, compare_double);
        }
        default: {
            return NULL;
        }
    }
}

int main() {
    // test char
    char arg1_char = 'a';
    char arg2_char = 'b';
    char arg3_char = 'c';
    printf("arg1_char: %p arg2_char: %p arg3_char %p\n", (void *) &arg1_char, (void *) &arg2_char, (void *) &arg3_char);
    printf("middle char: %p\n", question7(CHAR_POINTER, (void *) &arg1_char, (void *) &arg2_char, (void *) &arg3_char));

    // test int
    int arg1_int = 1;
    int arg2_int = 2;
    int arg3_int = 3;
    printf("arg1_int: %p arg2_int: %p arg3_int %p\n", (void *) &arg1_int, (void *) &arg2_int, (void *) &arg3_int);
    printf("middle int: %p\n", question7(INT_POINTER, (void *) &arg1_int, (void *) &arg2_int, (void *) &arg3_int));

    // test double
    double arg1_double = 1.0;
    double arg2_double = 2.0;
    double arg3_double = 3.0;
    printf("arg1_double: %p arg2_double: %p arg3_double %p\n", (void *) &arg1_double, (void *) &arg2_double, (void *) &arg3_double);
    printf("middle double: %p\n", question7(DOUBLE_POINTER, (void *) &arg1_double, (void *) &arg2_double, (void *) &arg3_double));

    // test null
    printf("middle char: %p", question7(0, (void *) &arg1_char, (void *) &arg2_char, (void *) &arg3_char));
    return 0;
}

