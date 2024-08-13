#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include "naivgauss.h"



int main()
{
 struct systeme Mat;

    printf("***Bonjour et bienvenu(e) dans le programme de resolution des systemes d'equations linéaires***\n");
    printf("*** Ces equations peuvent se mettre sous la forme A*X=B, avec A :la matice des coefficients; X: la matrice des inconnues; B: matrices colonnes comportant les resultas des equations lineaires par ligne\n");
    printf("***Entrez le nombre d'equations***\n");
    scanf("%d",&Mat.N);
    printf(" La valeur de n est bien %d \n", Mat.N);
    allocation(&Mat);

    if (test(Mat.N) ==0)
    {
        printf("L'odre du syteme ne peut pas etre nul, essayez de nouveau avec un ordre non nul\n");
        return 0;
    }
    else{
    printf("nous allons proceder au remplissage de la matrice A\n");
    printf ("entrez la valeurs des coefficients lignes par lignes\n");
    // Remplissage de la matrice A
    for(int i=0;i<Mat.N;i++)
    {
        Mat.c[i]=0;
    }

    for(int i = 0 ;i < Mat.N ; i++)
    {

         for(int j = 0 ;j < Mat.N ; j++)
        {
           printf("entrez la valeur de a%d%d\n",i,j);
           scanf("%f",&Mat.a[i][j]);
        }
        //Fin du remplissage de la matrice A
        //remplissage de la matrice B
         printf("entrez la valeur de b%d\n",i);
         scanf("%f",&Mat.b[i]);
         //Fin du remplissage de la matrice B
    }

if (elimination(&Mat)==0)
{
    printf("***Ce Systeme n'admet pas de solution***\n");
    return 0;

}
else
{

reverseascent(&Mat);
for (int i=0;i<Mat.N;i++){
    printf("%f",Mat.c[i]);
}
  printf("la solution est:(");
    for(int i=0 ;i<Mat.N ;i++)
    {
        printf ("%f ;",Mat.c[i]);
    }
    printf(")\n");
    printf("***Merci pour Votre Participation***\n");

    }
    }
     return 0;
}

