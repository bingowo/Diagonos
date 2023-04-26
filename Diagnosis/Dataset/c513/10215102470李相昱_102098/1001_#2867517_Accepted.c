#include <stdio.h>
int main()
{
    int T;
    char b[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char c[32];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int r=0;
        int n = 0;
        scanf("%d%d",&n,&r);
        int m = 0;
        if(n<0){
            m = 1;
            n = -n;
        }
        int j=0;
        do{
            c[j++] = b[n%r];
            n = n/r;
        }while(n);
        if(m)
            printf("-");
        int q;
        for(q=j-1;q>=0;q--)
            printf("%c",c[q]);
        printf("\n");
    }

    return 0;
}
