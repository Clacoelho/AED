#include<stdio.h>
#include<math.h>

int main(void){
    double r,n,area;
    n = 3.14159;
    scanf("%lf ",&r);
    area = n * pow(r,2);
    printf("A=%0.4lf\n", area);
    return (0);
    }
