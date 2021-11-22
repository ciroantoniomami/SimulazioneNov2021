#include <stdio.h>
#include <stdlib.h>

//calcolare il fattoriale in maniera ricorsiva
int fattoriale(int k)
{
    if(k==1 || k==0)
        return 1;
    else
        return k*fattoriale(k-1);
}

//calcolare la potenza in maniera ricorsiva
float potenza(float x, int k)
{
    if(k==0)
        return 1.0;
    else
        return x*potenza(x, k-1);

}

//calcolare il valore n-esimo della serie: versione iterativa
float serie_it(int x, int n)
{
    float somma = 0;
    for(int i=0; i<n; i++)
        somma += (potenza(x, i) / fattoriale(i));
    return somma;
}

//calcolare il valore n-esimo della serie: versione ricorsiva
float serie(int x, int n)
{
  if(n==0)
      return 1.0;
  return potenza(x,n)/fattoriale(n) + serie(x, n-1);
}

//vettore contenente i primi n elementi della serie
float* serie_array(int x, int n)
{
  float* a = malloc((n+1)*sizeof(float));
  a[0] = 1;
  for(int k=1; k<=n; k++)
      a[k] = potenza(x,k)/fattoriale(k) + a[k-1];
  return a;
}

int main(int argc, char **argv) {
    float e = 2.71828;
    int x;
    printf("x = ");
    scanf("%d", &x);
    //verificare convergenza serie
    printf("n: (somma successione, esponenziale)\n");
    for(int n=2; n<15; n+=2)
    {
        float succ = serie(x, n);
        float conv = potenza(e, x);
        printf("%d: (%.3f, %.3f)\n", n, succ, conv);
    }
    //vettore allocato dinamicamente
    int n;
    printf("n = ");
    scanf("%d", &n);
    float* a = serie_array(x, n);
    printf("[ ");
    for(int i=0; i<n+1; i++)
      printf("%.3f ", a[i]);
    printf("]\n");
    free(a);
}