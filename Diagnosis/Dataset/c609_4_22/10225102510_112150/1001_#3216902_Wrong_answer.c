#include <stdio.h>
#include <stdlib.h>
#define N 100
int main()
{
    int T,i=0,j=0;
    int a,b,n=0;
    char m,s[N];
    scanf("%d",&T);
    while(i<T)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        for(j=0;a!=0;j++)
        {
            if(a%b<10)
            s[j]=a%b;
            else s[j]='A'+a%b-10;
            a=a/b;
        }
        j--;
        for(n=0;n<j;j--)
        {
            m=s[j];s[j]=s[n];s[n]=m;
        }
        printf("%s",s);
        i++;
    }
    return 0;
}
