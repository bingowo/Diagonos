#include <stdio.h>
#include <stdlib.h>
#define N 100
int main()
{
    int T,i=0,j=0,n=0,sy=0,u=0;
    int a,b;
    char m,s[N];
    scanf("%d",&T);
    while(i<T)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        if(a>0)
        sy=0;
        if(a<0)
        {
            a=-a;
            sy=1;
        }
        if(a==0)
        {
            printf("0\n");
            continue;
        }
        for(j=0;a!=0;j++)
        {
            if(a%b<10)
            s[j]='0'+a%b;
            else if(a%b>=10)
            s[j]='A'+(a%b-10);
            a=a/b;
        }
        j--;
        int t=j;
        if(sy=0)
            while(t!=0)
            {
                printf("%c",s[t]);
                t--;
            }
        if(sy=1)
        {
            printf("-");
            while(t>=0)
            {
                printf("%c",s[t]);
                t--;
            }
        }
        printf("\n");
        i++;
    }
    return 0;
}

