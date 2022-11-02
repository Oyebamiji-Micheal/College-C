#include <stdio.h>
#include <math.h>
#include <complex.h>


void calculate(float, float, float);


int main () {
    float a, b, c;
    printf("A quadratic equation is of the form ax^2 + bx + c = 0\n");
    printf("Where a > 0\n");
    printf("Enter the value of a: ");
    scanf("%f", &a);
    printf("Enter the value of b: ");
    scanf("%f", &b);
    printf("Enter the value of c: ");
    scanf("%f", &c);
    calculate(a, b, c);
    
    return 0;
}


void calculate(float a, float b, float c) {
    float temp = -b / (2 * a);
    float determinant = (pow(b, 2)) - (4 * a * c);

    if (determinant == 0) {
        printf("The eqn has 2 equal roots: %f and %f \n", temp, temp);
    }

    else if(determinant > 0) {
        float val = (sqrt(determinant)) / (2 * a);
        float root1 = temp + val;
        float root2 = temp - val;
        printf("The eqn has 2 real roots: %f and %f \n", root1, root2);
    }
    
    else{
        float complex val = (csqrt(determinant)) / (2 * a);
        float complex root1 = temp + val;
        float complex root2 = temp - val;
        printf("The eqn has imaginary roots: %f + %fi", creal(root1), cimag(root1));
        printf(" and %f %fi\n", creal(root2), cimag(root2));
    }

}