#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,n;
    scanf("%d",&T);
    char s[50];
    long long int sum;

    for(int q=0;q<T;q++)
    {
        sum=0;
        scanf("%s",s);
        getchar();
        n=strlen(s);
        int a[n];
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
            a[i]=1;
        if(s[i]=='-')
            a[i]=-1;
        if(s[i]=='0')
            a[i]=0;
        sum=sum*3+a[i];
    }
    printf("case #");
    printf("%d:\n",q);
    printf("%lld\n",sum);
    }
}
