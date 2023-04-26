#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{

    //IVXLCDM
    char s[60];
    scanf("%s",s);
    int l=strlen(s);
    long long int ans=0;
    int a[60]={0};
    int p[128]={0};
    p['I']=1;p['V']=5;p['X']=10;
    p['L']=50;p['C']=100;p['D']=500;
    p['M']=1000;
    int cnt=0;
    int f=1;
for(int i=0;i<l;i++)
{
    switch(s[i])
    {
        case '(':f*=1000;break;
        case ')':f/=1000;break;
        default:a[cnt++]=f*p[s[i]];break;

    }
}
for(int i=0;i<cnt-1;i++)
{
    if(a[i]<a[i+1])ans-=a[i];
    else ans+=a[i];
}
ans+=a[cnt-1];

printf("%lld\n",ans);


}
