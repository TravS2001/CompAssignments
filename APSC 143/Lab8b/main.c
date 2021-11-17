#include <stdio.h>
double power(double x, int n);
int main(int argc, char **argv){
	printf("%f\n", power(2.0,3));
	printf("%f\n", power(3.0,2));
    return 0;
}


double power(double x, int n){
	double num;
    int i;
	num = 1.0;		
	for (i=1; i<=n; i++)    // this loop will
   	   num *=x;		    // compute xn  
	return num;
}