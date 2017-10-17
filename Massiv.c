#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <time.h>


int main(int argc, char *argv[])
{
int m = rand()%10 + 4;
int n = rand()%10 + 5;
int i, j;
int myArray[m][n];
srand(5);
for ( i = 0; i < m; i++ )
{
	for ( j = 0; j < n; j++ )
	myArray[i][j] = rand()%100;
}
printf( "Task 1:\n" );
for ( i = 0; i < m; i++ )
{
	for ( j = 0; j < n; j++ )
    {
    	printf( "[%d][%d]=%d ", i, j, myArray[i][j] );
    }
    printf( "\n" );
}
printf( "\n" );

int cup;
for ( j = 0; j < n; j++ )
	{
	cup = myArray[0][j];
	myArray[0][j] = myArray[m-1][j];
	myArray[m-1][j] = cup;
	}
for ( j = 0; j < (n/2); j++ )
	{
	cup = myArray[0][j];
	myArray[0][j] = myArray[0][n-1-j];
	myArray[0][n-1-j] = cup;
	}
for ( j = 0; j < (n/2); j++ )
	{
	cup = myArray[m-1][j];
	myArray[m-1][j] = myArray[m-1][n-1-j];
	myArray[m-1][n-1-j] = cup;
	}
printf( "Task 2:\n" );
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
        printf( "[%d][%d]=%d ", i, j, myArray[i][j] );
    }
    printf( "\n" );
  }
//____________________________________________
int min = myArray[0][0];
int I = 0;
int J = 0;
for ( i = 0; i < m; i++ )
{
    for ( j = 0; j < n; j++ )
    {
        if (min > myArray[i][j])
        {
        	min = myArray[i][j];
        	I=i;
        	J=j;
        }
    }
}
int k = m-1;
int l = n-1;
int myArray1[k][l];
for (i = 0; i < k; i++)
            {
                for (j = 0; j < l; j++)
                {
                    if (i >= I && j >= J)
                    {
                        myArray1[i][j] = myArray[i+1][j+1];
                    }
                    else if (i >= I && j < J)
                    {
                        myArray1[i][j] = myArray[i+1][j];
                    }
                    else if (i < I && j >= J)
                    {
                        myArray1[i][j+1] = myArray[i][j+1];
                    }
                    else
                    {
                        myArray1[i][j] = myArray[i][j];
                    }
                }
            }
printf( "Task 3:\n" );
  for ( i = 0; i < k; i++ )
  {
    for ( j = 0; j < l; j++ )
    {
        printf( "[%d][%d]=%d ", i, j, myArray1[i][j] );
    }
    printf( "\n" );
  }
//____________________________________________ 
  return 0;
}
