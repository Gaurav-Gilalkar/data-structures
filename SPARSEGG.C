PRACTICAL NO. 1

Aim:- A)Write a program to read a matrix. Check if it's   	   sparse or not. If yes, then represent that sparse      	   matrix in memory in format[row  column  value]
      B)Display Transpose of the sparse representation

Program :-

#include<stdio.h>
#include<conio.h>

// checking for sparse matrix and evaluating its transpose

void main()
{

 int a[10][10],i,j,count=0,k,b[10][10],l,r,c,t[10][10];
 clrscr();
 printf("Hello.Enter no. of rows and columns \n");
 scanf("%d %d",&r,&c);
 printf("\nEnter a matrix. The matrix will be checked if sparse or not and if not then the program will hault automatically  \n");
 for(i=0;i<=r-1;i++)
 {
  for(j=0;j<=c-1;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 //Matrix entered

 printf("\nThe Matrix entered is\n");
 for(i=0;i<=r-1;i++)
 {
  for (j=0;j<=c-1;j++)
  {
   printf("%d ",a[i][j]);
  }
  printf("\n");
 }
 //Matrix printed


 b[0][0]=r;//Inserting first row elements of the sparse matrix manually
 b[0][1]=c;

 printf("\nNow the program will check if its sparse or not\n");
 for(i=0;i<=r-1;i++)
 {
  for (j=0;j<=c-1;j++)
  {
   if(a[i][j]>0)
   {
    count++;
   }
   else if(a[i][j]<0)
   {
    count++;
   }
  }
 }
 //Checking for sparse

 b[0][2]=count;  //inserting total no. of non zero elements
 if(count<=((r*c)/4))
 {
  printf("\nThe above matrix is sparse\n");
    for(i=0,k=1;i<=r-1,k<=count;i++)
 {
 for (j=0;j<=c-1;j++)
  {
   if(a[i][j]>0)
   {
     l=0;
     b[k][l]=i;
     b[k][l+1]=j;
     b[k][l+2]=a[i][j];
     k++;
   }
   else if(a[i][j]<0)
   {
     l=0;
     b[k][l]=i;
     b[k][l+1]=j;
     b[k][l+2]=a[i][j];
     k++;
   }
  }
 }

 printf("\n\nNow the matrix will be represented in conventional sparse format\n");

  for(i=0;i<=count;i++)
  {
   for(j=0;j<=2;j++)
   {
     printf("%d ",b[i][j]);
   }
     printf("\n");
  }
//printing sparse matrix

printf("\nTranspose matrix\n");
t[0][0]=c;
t[0][1]=r;
t[0][2]=count;


 k=1;
 for(i=0;i<c;i++)
 {
  for(j=1;j<=count;j++)
  {
    if(b[j][1]==i)
    {
     t[k][0]=b[j][1];
     t[k][1]=b[j][0];
     t[k][2]=b[j][2];
     k++;
    }
   }
 }

  for(i=0;i<=count;i++)
  {
   for(j=0;j<=2;j++)
   {
    printf("%d ",t[i][j]);
   }
    printf("\n");
   }
 }
  else
 {
   printf("\n The above matrix is not sparse\n");
 }
 printf("\nTotal non zero elements are %d",count);
 //All results displayed

 getch();
 }