#include <stdio.h>
int main() {
    int N;
    int x;
    int l=0;
    int r=0;
    int check=0;
    scanf("%d",&N);
    for (int i=0;i<N;i++) {
        scanf("%d",&x);
        if (x==1 && check==0) {
            l=i;
            check=1;
        }
        else if (x==1 && check==1) {
            r=i;
        }
    }
    if (r==0 && l!=0) {
        printf("%d",0);
    }
    else {
        printf("%d",r-l);
    }
}