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
        if(a<0)
        a=-a,sy=1;
        else if(a>0)
        sy=0;
        if(a==0)
        {
            printf("0\n");
            continue;
        }
        for(;a!=0;j++)
        {
            if(a%b<10)
            s[j]='0'+a%b;
            else if(a%b>=10)
            s[j]='A'+(a%b-10);
            a=a/b;
        }
        j--;
        int t=j;
        for(;n<j;j--)
        {
            m=s[j];s[j]=s[n];s[n]=m;n++;
        }
        if(sy=1)
        {
            m=s[t];
            s[t+1]=m;
            while(u<t)
            {
                s[u+1]=s[u];
                u++;
            }
            s[0]='-';
        }
        printf("%s\n",s);
        i++;
    }
    return 0;
}

