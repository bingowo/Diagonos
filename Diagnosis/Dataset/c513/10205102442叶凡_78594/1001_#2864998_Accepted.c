#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 33

int main()
{
    int T;
    int cas;
    scanf ("%d",&T);
    for (cas=0;cas<T;cas++){
        int R,N=0;
        int r,i=0;
        int flag=1;
        char a[MAX];
        scanf("%d%d",&N,&R);
        if (N<0){
            flag=-1;
            N=abs(N);
        }
        do{
            r=N%R;
            N=N/R;
            if (r>=0&&r<=9)
                a[i++]=r+'0';
            if (r>9)
                a[i++]=r-10+'A';
        }while (N);
        if (flag==-1)
            printf("-");
        i=i-1;
        while (i>=0)
            printf("%c",a[i--]);
        printf("\n");
    }
    
    return 0;
}
