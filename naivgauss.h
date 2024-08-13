#ifndef NAIVGAUSS_H_INCLUDED
#define NAIVGAUSS_H_INCLUDED


struct systeme {
float **a;
float *b;
float *c;
int N;

};
int test (int N);

int elimination(struct systeme *mat);
void reverseascent(struct systeme *mat);
void allocation(struct systeme *mat);
void pivoting(int i, int j,struct systeme *mat);
int checkpivoting(int i,struct systeme *mat);
void resourdre(struct systeme *mat);
float det(struct systeme *mat);
void remplir(struct systeme *mat);

#endif // NAIVGAUSS_H_INCLUDED
