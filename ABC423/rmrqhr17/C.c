#include <stdio.h>
int main(void) {
    int N,R;
    int x=0;
    int lc=1;
    int lr=0;
    int cont=0;
    scanf("%d %d",&N,&R);
    for (int i=0;i<R;i++) {
        scanf("%d",&x);
        if (x==0) {
            lc=0;
            cont++;
        }
        if (x==1 && lc==0) {
            cont+=2;
        }
    }
    for (int i=R;i<N;i++) {
        scanf("%d",&x);
        if (x==0) {

            cont=cont+(lr*2)+1;
            lr=0;
        }
        if (x==1) {
            lr++;
        }
    }
    printf("%d\n",cont);
}