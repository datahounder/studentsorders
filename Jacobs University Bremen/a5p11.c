/*
CH-230-A
a5p11.c
Zarina Abulkassova
zabulkasso@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int  ***inputmatrix(int r,int c,int d) //input the matrix

{
    int ***matrix=NULL; //declaring the matrix
    matrix = (int ***)malloc(r * sizeof(int **)); 
    if (matrix== NULL)
    {
    exit(1);
    }
    for (int i=0; i<r; i++) //loop to input the matrix

    {
    matrix[i] = (int **)malloc(c * sizeof(int*));
    if (matrix[i] == NULL)
    {
    exit(1);
    }
    for (int j = 0; j < c; j++)
    {
    matrix[i][j]= (int*)malloc(d*sizeof(int)); 
    if (matrix[i][j] == NULL)
    {
    exit(1);
    }
    }
        
    }

    for (int i = 0; i <  r; i++) 
    {
  for (int j = 0; j < c; j++) 
  {
  for (int k = 0; k < d; k++)
  {
  scanf("%d",&(matrix[i][j][k]));
  }  
  }
    }   
    return matrix;
    for (int i = 0; i < r; i++)
    {
    for (int j = 0; j < c; j++)
    {
    free(matrix[i][j]);
    }
    free (matrix[i]);
    }
    free (matrix);
}
void printmatrix(int*** matrix,int r,int c,int d) //print the matrix

{
    for (int k=0; k <d;k++)
    {
    printf("Section %d:\n",k+1);
    for (int i = 0; i < r; i++)
    {
    for (int j = 0; j < c; j++)
    {
  printf("%d ",matrix[i][j][k]);
    }
    printf("\n");
    }
    }
}
int main()
{
    int r,c,d; //declare the rows,columns and depth
    int ***matrix; //declare the matrix
    scanf("%d",&r);
    scanf("%d",&c);
    scanf("%d",&d);
    //Iinpute the rows, columns and depth
    matrix=inputmatrix(r,c,d);//input the matrix
    printmatrix(matrix,r,c,d);//print the matrix
}