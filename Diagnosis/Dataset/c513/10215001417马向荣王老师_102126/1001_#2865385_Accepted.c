#include<stdio.h>
int main()
{
    int T=0;
    scanf("%d\n", &T);
    int N,R;
    int i=0,j=0,c=0,b=0;
    char a[100000];
    while(scanf("%d %d\n",&N,&R)!=EOF)
    {
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        while(N!=0)
        {
            ++i;
            c=N/R;
            a[i]=N%R;
            N=c;
        }
        for(j=i;j>0;j--)
        {
            if(a[j]>=10)
            {
                if(j!=1)
                {
                    printf("%c", a[j]+55);
                }
                else
                {
                    printf("%c\n", a[j]+55);
                    i=0;
                }
            }
            else
            {
                if(j!=1)
                {
                    printf("%d", a[j]);
                }
                else
                {
                    printf("%d\n", a[j]);
                    i=0;
                }
            }
        }
    }
    return 0;
}