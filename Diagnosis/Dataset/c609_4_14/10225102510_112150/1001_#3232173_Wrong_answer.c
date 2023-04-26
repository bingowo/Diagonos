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
        if(a==0)
        printf("0");
        for(j=0;a!=0;j++)
        {
            if(a%b<10)
            s[j]=a%b;
            else s[j]='A'+a%b-10;
            a=a/b;
        }
        j--;
        int t=j;
        for(n=0;n<j;j--)
        {
            m=s[j];s[j]=s[n];s[n]=m;
        }
        if(sy=-1)
        {
            m=s[t];
            s[t+1]=m;
            while(u<t)
            {
                s[u+1]=s[u];
                u++;
            }
            s[0]="-";
        }
        printf("%s",s);
        i++;
    }
    return 0;
}
