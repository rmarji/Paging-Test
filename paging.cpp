/**************************************************************/
/*                                                            */
/*                      paging.cpp                     */
/*                                                            */
/*               By Raed Marji @ JUST               	      */
/*                                                            */
/* This program is used to paging storage mechanism  		  */
/*                                                            */
/**************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>
#include<malloc.h>
#include <sys/stat.h>
#include <sys/time.h>

int **A, **B, **C;   // Shared Matrices: C = A x B
int N;               // Matrix Dimension Size

main(int argc, char *argv[])
{
   int i, j;
   struct stat dirstat;
   struct timeval st_time, end_time;
	
   // Get the dimension size from the command line arguments
   N = (int)atoi(argv[1]);
   
   // Allocate memory for and initialize the matrices
   A = new int*[N];
   B = new int*[N];
   C = new int*[N];
   for(i=0; i<N; i++)
   {
      A[i] = new int[N];
      B[i] = new int[N];
      C[i] = new int[N];
      for(j=0; j<N; j++)
      {
         A[i][j] = rand();
         B[i][j] = rand();
         C[i][j] = 0;
      }
   }

   

      printf("summing two %dx%d matrices row by row\n", N, N);
      
      gettimeofday(&st_time, NULL); //store current time
      
      for(i=0; i<N; i++)
         for(j=0; j<N; j++)
               C[i][j] += (A[i][j]*B[i][j]); 
      
      gettimeofday(&end_time, NULL); // get current time to calclulate used time
      
      printf("done in %0.3f secs\n",(float)((int)(end_time.tv_sec - st_time.tv_sec)) + (float)(int)(end_time.tv_usec - st_time.tv_usec) / 1000000);
      
      /***********************************************************************/
      
      printf("summing two %dx%d matrices column by column\n", N, N);
      gettimeofday(&st_time, NULL); //store current time
      
      for(j=0; j<N; j++)
      	for(i=0; i<N; i++)
        	C[i][j] += (A[i][j]*B[i][j]); 
      
      gettimeofday(&end_time, NULL); // get current time to calclulate used time
      printf("done in %0.3f secs\n",(float)((int)(end_time.tv_sec - st_time.tv_sec)) + (float)(int)(end_time.tv_usec - st_time.tv_usec) / 1000000);
      

      printf("Done!\n");
         
}

      
   


