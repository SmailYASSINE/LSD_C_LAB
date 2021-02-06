#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10


 

   float cholesky(float A[N][N],float B[N])
   {
	float c[N][N];
	int s=0;
	c[0][0]=sqrt(A[1][1]);
	for(int i=1;i<n;i++ )
		c[i][0]=A[i][0]/c[0][0];

	for (int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			c[i][j]=0;
	for(int i=1;i<n;i++)
		for (int k=0;k<i-1;k++)
			s=s+c[i][j];
		c[i][i]=sqrt(A[i][i]-s);
	
	for(i=0;i<n;i++){
		for (int j=0;j<n;j++){
			float sum=0;
			for (int k=0;k<j;k++){
				sum+=c[i][k]^c[j][k];
			}
			c[i][j]=(A[i][j]-sum)/c[j][j];
			
	return c[N][N];

   }

int main(){
	int n;
	float a[N][N];
	float b[N];
	float x[N];
	float y[N];
	float c[N][N];
	printf("Enter the dimension of your matrix ");
	scanf("%d", &n);


	for(int i=0;i<n; i++)
		for(int j=0; j<n;j++){
			printf("enter the value of a[%d][%d]=", i, j);
			scanf("%f", &a[i][j]);
			             }


	for(int i=0;i<n;i++){
		printf("enter the value of b[%d]=", i);
		scanf("%f", &b[i]);
		}


	//implémentation de C :
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			c[i][j]=0;
		}
	}
	
	
	
	
	c[N][N]=cholesky(c, a, 4);
	//printing  c
	printf("the c matric \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("c[%d][%d] = %f\t",i, j, c[i][j]);
		}
		printf("\n");
	}
	
	//La resolution de  c(Transpose)*y=b
	
	y[0]=b[0]/c[0][0];
	for(int i=1;i<n;i++){
		float sum1=0;
		for(int j=0;j<=i-1;j++){
			sum1+=c[i][j]*y[j];
		}
		y[i]=(b[i]-sum1)/c[i][i];
	}
	//printing the vector y
	for(int i=0;i<n;i++){
		printf("y[%d]=%f\t",i, y[i]);
	}
	
	//sovling the following equation : c*x=y
	
	x[n-1]=y[n-1]/c[n-1][n-1];

	for(int i=n-2;i>=0;i--){
		float sum2=0;
		for(int j=i;j<n;j++){
			sum2+=c[j][i]*x[j];
		}
		x[i]=(y[i]-sum2)/c[i][i];
	}
	//printing x
	printf("\n the final solution is :\n");
	for(int i=0; i<n;i++)
		printf("x[%d]=%f\t",i, x[i]);
}

























  return (0);
}
