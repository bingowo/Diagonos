
#include <stdio.h>

int main()
{
    int N,R;
    int T;
    scanf("%d",&T);
    int count=1;
    for(;count<=T;count++)
    {
        int i=0;
        scanf("%d%d",&N,&R);
        char a[100];
        if(N<0)
        {
            N=-N;
            printf("-");
        }
        if(N==0)printf("0\n");
        int m;
        while(N>0)
        {
        m=N%R;
        if(m>=10)a[i]=m-10+'A';
        else a[i]=m+'0';
        N/=R;
        i++;
        }
        while(i>0)printf("%c",a[--i]);
        printf("\n");
    }
    return 0;
}

