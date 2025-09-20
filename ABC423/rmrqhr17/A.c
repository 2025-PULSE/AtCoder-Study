#include <stdio.h>
#define Y 1000
int main(void) {
    int X,C;
    scanf("%d %d",&X,&C);
    int res=0;
    while (X>0) {
        X-=Y+C;
        if (X<0) {
            break;
        }
        res++;
    }
    printf("%d\n",res*Y);
}