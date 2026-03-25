#include <stdio.h>
#include <random.h>
double printrandom(int n) {
    int i;
    //double k=9.99;
    double rands[n];
    //double m=0.0;
    //m=1.0+0.5*n*random_normal();
    for (i = 0; i < n; i++) {
        rands[i] = 1.0+0.5*random_normal();
        printf("%d : In library: %f \r\n", i, rands[i]);
    }
   printf("\n");
   return random_normal();
   //k=9.99;
    //return k*n;
}