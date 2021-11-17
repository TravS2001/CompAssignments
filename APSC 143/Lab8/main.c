#include <stdio.h>
double poly(double);

int main(int argc, char **argv)
{
    printf("%f\n%f\n", poly(1),poly(2));
}
double poly(double x){
        return (2*x*x-3*x+7);
}
