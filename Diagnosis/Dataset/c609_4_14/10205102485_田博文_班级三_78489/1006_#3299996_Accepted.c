#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmt(){
    char s[61];
    scanf("%s",s);
    int a[128];
    for (int i=0;i<128;i++)
        {a[i]=-1;}
    int digit=0,N=1,i;
    char *p=s;
    a[*p]=1;
    while (*++p)
    {
        if (a[*p]==-1)
    { a[*p]=digit; digit=digit?digit+1:2; N++;}}
    if (N<2) N=2;
    long long ans=0;
    p=s;
    while (*p) ans=ans*N+a[*p++];
    printf("%lld\n",ans);
}

int main(){
    int n=0;
    scanf("%d",&n);
    for(int m=0;m<n;m++)
    {
        printf("case #%d:\n",m);
        cmt();
    }
}
