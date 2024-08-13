#include<stdio.h>
#include <math.h>
#include <stdlib.h>


struct systeme {
float **a;
float *b;
float *c;
int N;

};

int test (int N)
{
if (N=0)
{
    return 0;
}
else{
    return 1;
}
}

//Fonction d'élimination
//ici on utilises plutot le paramettrage par adresse paceque  si on ne le fait pas hors de la fonction
//la matrice va reprendre sa valeur de base



int elimination(struct systeme *mat)
{
    printf("entrer dans la fonction elimination\n");
float P, det, qt;
    for(int i=0;i<(mat->N)-1;i++)
    {
        checkpivoting(i,mat);
        pivoting(i,checkpivoting(i,mat),mat);

        for(int j=i+1;j<mat->N;j++)
        {
        P = mat->a[j][i]/mat->a[i][i];
        for(int k=i+1;k<mat->N;k++)
        {
          mat->a[j][k]=mat->a[j][k]-mat->a[i][k]*P;
        }
        mat->b[j]=mat->b[j]-P*mat->b[i];
    }
    det=1;
    for (int i=0; i<(mat->N)-1; i++)
    {
        det= det*mat->a[i][i];
    }
    if (det=0)
    {
        return 0;
    }
    else
    {
            for(int i = 0 ;i < mat->N ; i++)
    {
printf("\n");
printf("\n");
         for(int j = 0 ;j < mat->N ; j++)
        {
           printf("%f ",mat->a[i][j]);
        }
       printf("%f",mat->b[i]);
        }
printf("\n");
printf("sortir dans la fonction elimination\n");
    return 1;
    }
    }
         return 1;
}
//procedure pour la remontée
void reverseascent(struct systeme *mat)
{
   float ct;
     mat->c[mat->N-1]= mat->b[mat->N-1]/mat->a[mat->N-1][mat->N-1];
    for(int i=mat->N-2;i>=0;i--)
    {
     ct= mat->b[i];
        for(int k=i+1;k<mat->N;k++)
            {
              ct=ct-mat->a[i][k]*mat->c[k];
            }
            mat->c[i]=ct/mat->a[i][i];
    for(int i = 0 ;i < mat->N ; i++)
    {
printf("\n");
         for(int j = 0 ;j < mat->N ; j++)
        {
           printf("%f",mat->a[i][j]);
        }

}
}
}



void allocation(struct systeme *mat)
{
    mat->c=(float*)malloc(mat->N*sizeof(float));
    mat->b=(float*)malloc(mat->N*sizeof(float));
    mat->a=(float**)malloc(mat->N*sizeof(float));

    for (int i=0;i<(mat->N);i++)
    {
        mat->a[i]=(float*)malloc(mat->N*sizeof(float));
    }
    if (mat->a== NULL)
{
    printf("Memory allocation for grades failed\n");
    free(mat->a);
    return 1;
}
  if (mat->b== NULL)
{
    printf("Memory allocation for grades failed\n");
    free(mat->b);
    return 1;
}
  if (mat->c== NULL)
{
    printf("Memory allocation for grades failed\n");
    free(mat->c);
    return 1;
}
}


int checkpivoting(int i,struct systeme *mat)
{   int d;
    float max= mat->a[i][i];
    for (int j=0; j<mat->N;j++)
        {
        if(fabs(max)<fabs(mat->a[j][i]))
        {
            printf("oui\n");
         max=  mat->a[j][i];
         d=j;
        }
        }
        return d;
}

void pivoting(int i, int j,struct systeme *mat)
{

    for(int t=0;t<mat->N;t++)
    {
            float temp=mat->a[i][t];
            mat->a[i][t]=  mat->a[j][t];
            mat->a[j][t]=temp;
    }
            float egal=mat->b[i];
        mat->b[i]=mat->b[j];
        mat->b[j]=egal;


           for(int i = 0 ;i < mat->N ; i++)
{
printf("\n");
         for(int j = 0 ;j < mat->N ; j++)
        {
           printf("%f  ",mat->a[i][j]);
        }
        printf("%f",mat->b[i]);


}
}
void resourdre(struct systeme *mat)
{
     printf("entrer dans la fonction elimination\n");
float P, det, qt;
    for(int i=0;i<(mat->N)-1;i++)
    {
        checkpivoting(i,mat);
        pivoting(i,checkpivoting(i,mat),mat);

        for(int j=i+1;j<mat->N;j++)
        {
        P = mat->a[j][i]/mat->a[i][i];
        for(int k=i+1;k<mat->N;k++)
        {
          mat->a[j][k]=mat->a[j][k]-mat->a[i][k]*P;
        }
        mat->b[j]=mat->b[j]-P*mat->b[i];
    }
    }
    det=1;
    for (int i=0; i<(mat->N)-1; i++)
    {
        det= det*mat->a[i][i];
    }
    if (det=0)
    {
        return 0;
    }
    else
    {
            for(int i = 0 ;i < mat->N ; i++)
    {
printf("\n");
printf("\n");
         for(int j = 0 ;j < mat->N ; j++)
        {
           printf("%f ",mat->a[i][j]);
        }
       printf("%f",mat->b[i]);
        }
printf("\n");
printf("sortir dans la fonction elimination\n");
       float ct;
     mat->c[mat->N-1]= mat->b[mat->N-1]/mat->a[mat->N-1][mat->N-1];
    for(int i=mat->N-2;i>=0;i--)
    {
     ct= mat->b[i];
        for(int k=i+1;k<mat->N;k++)
            {
              ct=ct-mat->a[i][k]*mat->c[k];
            }
            mat->c[i]=ct/mat->a[i][i];
    }
    for(int i = 0 ;i < mat->N ; i++)
    {
printf("\n");
         for(int j = 0 ;j < mat->N ; j++)
        {
           printf("%f",mat->a[i][j]);
        }

}
}

      for (int i=0;i<mat->N;i++){
    printf("%f",mat->c[i]);
}
  printf("la solution est:(");
    for(int i=0 ;i<mat->N ;i++)
    {
        printf ("%f ;",mat->c[i]);
    }
    printf(")\n");
    printf("***Merci pour Votre Participation***\n");

    }

float det(struct systeme *mat)
{
    float dete=1;
    for(int i=0; i<mat->N;i++)
    {
        dete=dete*mat->a[i][i];
    }
    return dete;
}
void remplir(struct systeme *mat)
{
    for(int i = 0 ;i < mat->N ; i++)
    {

         for(int j = 0 ;j < mat->N ; j++)
        {
           printf("entrez la valeur de a%d%d\n",i,j);
           scanf("%f",&mat->a[i][j]);
        }
        //Fin du remplissage de la matrice A
        //remplissage de la matrice B
         printf("entrez la valeur de b%d\n",i);
         scanf("%f",&mat->b[i]);
         //Fin du remplissage de la matrice B
    }
}
