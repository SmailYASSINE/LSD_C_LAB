#include <stdio.h>      


float f(float x){
	return x;
}


float  rectangle_droit(float(*f)(float),float a, float b, int n){
    float h=(b-a)/n;
    float sum=0;
    for (int i=1;i<=n;i++) 
    {
        sum+= (*f)(a+i*h)*h; 
    }
    return sum;
}
 //Remarque

 /*
  lorsque j'utilise sum+=(*f)(a+i*h)*h ça fonctionne c'est comme on utilise celui là :
  sum+=f(a+i*h)*h malgré que on a déja déclaré un pointeur veers une fonction dans les paramètres
  de rectangle_droit
 */

float rectangle_gauche(float (*f)(float),float a, float b, int n)
{
	float s=0;
	float h=(b-a)/n;
	float x=a+h;
	for( int i=0; i<n;i++) //La méthode est trés claire mais ce qui la caractérise c'est qu'on commence i par 0 
	{
		s+=f(x);
		x+=h;
	}
	return h*s;
}

float trapeze( float (*f)(float),float a,float b,int n)
{
	float s=(1/2)*(f(a)+f(b)); // l'intégral entre a et b est approché par cette relation
	float h=(b-a)/n; // la longueur de chaque sous interval
	float x=a+h;
	for (int i=0 ; i<n-1 ; i++)
	{
		s+=f(x); 
		x+=h;
	}
	return h*s;
}

float simpson(float (*f)(float),float a,float b,int n)
{
	float h=(b-a)/n; // la longueur de chaque sous interval
	float x=a+h;	// on initialise x par a+h et à chaque fois on incrémente h dans la boucle ci-dessous
	float z=a+h/2;
	float p=0;
	float q=f(z);
	for( int i=0; i<n-1; i++)
	{
		z+=h;
		p+=f(z);
		q+=f(z);
		x+=h;
	}

	return (h/6)*(f(a)+f(b)+2*p+4*q); // c'est la relation qui définit la méthode de simpson
}





// si on déclare une autre fonction g et la fonction integral prend pointer vers cette fonction alors 
// si on utilise g dans main ça va marcher





//                                    Q2__1

//int nbr_necessairre(float f,float a,float b,float err,float(*methode)(float),i){
//	int n=1;
//	while 





int main()
{

 
    float res = rectangle_droit(f,0, 1, 10);
    printf("the result is : %f ", res);
    printf("/n");
    float s=simpson(f,0,1,100);
    printf("The result using simpson is :%f",s);


    return 0;


}


