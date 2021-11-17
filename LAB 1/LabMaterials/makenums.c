// MAKENUMS.C - Lab 1 - David Athersych
//
// Simple program to generate a set of numbers to test readnumsv2.

#include <stdio.h>

int main (int argc, char *argv[])
{
	int		i, maxndx;

	if (argc < 2)	{
		fprintf (stderr, "ERROR: Need to know how many\n");
		exit (-1);
		}

	maxndx = atoi (argv[1]);

	printf ("%d\n", maxndx);

	for (i=0; i<maxndx; i++)	{
		if (i > 0 && (i%12) == 0)	putchar ('\n');
		printf ("%6d", i);
		}
	exit (0);
}//main()
