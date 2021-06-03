#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float wallis_pi(int i){
float a=1;
float b;
float c;
for (int n=1;n<=i;n++){
b=4*n*n;
c=b-1;
a=a*(b/c);}
return 2*a;}

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}


