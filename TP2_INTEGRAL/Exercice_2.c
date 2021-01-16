#include<stdio.h>

//Remarque
//instead of inserting and copy the functions that we will use on the NombreNecessaire function 
// I am using the command gcc Exe1.c Exercice_2.c -o combined so that I can use the functions of the ex1 
// Then I use 'combined' to see the resullts.



int valeur_absolu(int x)
{

	if (x>=0)
		return x;
	else if ( x<0)
		return -x;

}




int NombreNecessaire(double (*f)(double),double a,double b, double err,double (*methode)(double(*)( double)),double valeur)
{
	int n=1;
	while (valeur_absolu(methode(f,a,b,n)-valeur)>err)
	{
		n+=1;
	}
	return n;
}

int main()
{
	printf("%d",NombreNecessaire(f,0,1,0.0001,trapeze,0.5);
}







