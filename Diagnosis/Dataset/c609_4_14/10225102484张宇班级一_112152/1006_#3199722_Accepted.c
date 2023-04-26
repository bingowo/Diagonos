#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {char a[100];
    scanf("%s",a);
    printf("case #%d:\n",i);
    int b[128];
    for(int j=0;j<128;j++)
        b[j]=-1;
    int R=0;
    char*p=a;
    b[*p]=1;
    while(*++p)
        if(b[*p]==-1)
    {
        b[*p]=R;
        R=R?R+1:2;
    }
    if(R<2) R=2;
    long long N=0;
    p=a;
    while(*p)
       N=N*R+b[*p++] ;
    printf("%lld\n",N);    }
    return 0;
}
