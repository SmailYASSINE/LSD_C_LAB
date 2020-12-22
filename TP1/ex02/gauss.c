#include <stdio.h>
#include <stdlib.h>
#define N 10

float *remontee(float A[N][N], float B[N], int n)
{
  int s=0;
  float *x;
  x=malloc(n*sizeof(float));

  /******Implement the solution here******/
	 x[n-1]=B[n-1]/A[n-1][n-1];
        for(int i=n-1;i>=0;i--){
                for(int j=i+1;j<n;j++)
                        s+=A[i][j]*x[j];
                x[i]=(B[i]-s)/A[i][i];
        }

  return(x);
}

float *gauss(float A[N][N] ,float B[N], int n)
{
	float factor;
	float *x;
	for(int k=0;k<N-1;k++)
	{
		for(int i=k+1;i<N;i++)
		{
			factor=A[i][k]/A[k][k];
			for(int j=k;j<N;j++)
			{
				A[i][j]=A[i][j]-factor*A[k][j];
			}
		B[i]=B[i]-factor*B[k];
		}
	}

  x = remontee(A, B, n);
  return(x);
}

int main()
{
  float   A[N][N], B[N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = gauss(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

