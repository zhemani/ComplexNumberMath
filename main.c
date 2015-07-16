//
//  main.c
//  ComplexNumbersTypedef
//
//  Created by Zain Hemani on 2014-11-26.
//  Copyright (c) 2014 Zain Hemani. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

//Create the typedef complex_t structure which would allow to not specify the type
typedef struct {
    double real, imaginary;
} complex_t;

//Declare prototypes to be used by function later on, type struct does not need to be specified
complex_t multiplication (complex_t c1, complex_t c2);
complex_t* division (complex_t* c1, complex_t* c2);

int main (void)
{
    //Create all complex_t structure to be used in the main program
    complex_t number1, number2, m, *d;
    
    //Request user to input all complex numbers
   /* printf("Fist number, enter (a1 + ib1) a1: ");
    scanf("%lf", &number1.real);
    printf("First number, enter (a1 + ib1)	b1: ");
    scanf("%lf", &number1.imaginary);
    printf("Second number, enter (a2 + ib2) a2: ");
    scanf("%lf", &number2.real);
    printf("Second number, enter (a2 + ib2) b2: ");
    scanf("%lf", &number2.imaginary);
    
    //Call the multiplcation function and get the value
    m = multiplication(number1, number2);
    if (m.imaginary == 0) { //If the imaginary part is 0 then only print the real value
        printf("Result of multiplication %lf", m.real);
    }
    else { //Print both real and imaginary if both are not 0
        printf("Result of multiplication: %lf + %lfi\n", m.real, m.imaginary);
    }
    //Call the division funcition and get the value
    d = division(&number1, &number2);
    if (d->imaginary == 0) { //If the imaginary part is 0 then only print the real value
        printf("Result of division %lf", d->real);
    }
    else { //Print both real and imaginary if both are not 0
        printf("Result of division: %lf + %lfi", d->real, d->imaginary);
    }*/
    
    int a[5] = {1,2,3,4,5};
        int n = 5;
    int key = 12;
    
    printf("%d\n", search(a,n,key));
    
    char *s[5] = {"ABCDEF","GHIJ", "KLMNOPQ", "RSTUV", "WXYZ"};
    char **p[5] = { &s[4], &s[3], &s[0], &s[2], &s[1] };
    printf("%s\n", &(**p[3]));
    printf("%s\n", *p[3]);
    printf("%s\n", &((**p)[3]));
    
    return 0;
} //End of main function

//Function that performs the multiplication of two complex numbers, type struct is not specified
complex_t multiplication (complex_t c1, complex_t c2)
{
    complex_t m; //Create a complex_t structure to hold the multiplcation value
    //Initialize and create double variables to hold the seperate parts of the complex numbers
    double c1r = c1.real, c2r = c2.real, c1i = c1.imaginary, c2i = c2.imaginary;
    //Conduct the multiplication and assign it to m
    m.real = (c1r * c2r) - (c1i * c2i);
    m.imaginary = (c1r * c2i) + (c1i * c2r);
    //Return the complex number m
    return m;
}//End of multiplication function

//Function that performs the division of two complex numbers, type struct is not specified
complex_t* division (complex_t *c1, complex_t *c2)
{
    //Create a pointer and allocate enough memory for that pointer to hold the division of the two values
    complex_t *d = malloc(sizeof(complex_t));
    if (d == NULL) { //If malloc failed that not enough memory was allocated
        printf("Requested memory was not allocated");
        exit(0);
    }
    //Initialize and create double variables to hold the seperate parts of the complex numbers
    double c1r=c1->real, c2r=c2->real, c1i=c1->imaginary, c2i=c2->imaginary;
    if ( c2r == 0 && c2i == 0 ) { //Ensure the second complex number is not all 0
        printf("Division by 0 + 0i is not allowed.");
        exit(0);
    }
    //Calculate the real and imaginary parts of the division
    d->real = ((c1r * c2r) + (c1i * c2i)) / (c2r * c2r + c2i * c2i);
    d->imaginary = ((c2r * c1i) - (c2i * c1r)) / (c2r * c2r + c2i * c2i);
    //Return a pointer to the division value
    return d;
}//End of division function
//End of program

int search(const int a[], int n, int key)
{
    int result=0;
    int *p;
    for (p=a; p<a+n; p++)
    {
        if(*p==key)
        {
            result = 1;
        }
    }
    return result;
}


