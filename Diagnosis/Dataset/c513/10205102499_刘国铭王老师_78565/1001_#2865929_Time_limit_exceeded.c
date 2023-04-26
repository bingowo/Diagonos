#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,R,r;
        int flag=1;
        char a[10000];
        scanf("%d %d",&N,&R);
        if(N<0)
        {
            flag=-1;
            N=-N;
        }
        do
        {
            r=N%R;
            N=N/R;
            if(r>=0&&r<=9)
                a[i++]=r+'0';
            if(r>9)
                a[i++]=r-10+'A';
        }
        while(N);
        if(flag==-1)
            printf("-");
        i=i-1;
        while(i>=0) printf("%c",a[i--]);
        printf("\n");
    }
    return 0;
}
