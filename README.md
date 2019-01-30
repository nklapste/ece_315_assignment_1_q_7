# ECE 315 Assignment 1 Question 7

Design a C function that receives four input arguments and returns a `void *` 
output value. The last three inputs are to be `void *` values, which need to be 
cast to the appropriate typed pointers and then de-referenced within the 
function to access three stored values. The first input is to be an integer
value that specifies the input pointer type as follows: the value `1` specifies
`char *`, `2` specifies `int *`, and `3` specifies `double *`. If the first
input is not a valid value, or if any of the three pointer inputs is `NULL`,
then the output value is to be `NULL`; otherwise, the output value is to be a 
`void *` that points to the base address location that contains the middlemost 
value of the three values pointed to by the three input pointers. If two or 
three of the memory referenced locations contain the same value, then the 
return pointer points to any one of those locations.
