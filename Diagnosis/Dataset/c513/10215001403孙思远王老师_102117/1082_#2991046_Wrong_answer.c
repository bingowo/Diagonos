#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int a1[500]={0},a2[500]={0},a3[500]={0},b1[500]={0},b2[500]={0},b3[500]={0},n;
    char s1[502],s2[502];
    scanf("%s%s%d",s1,s2,&n);
    int i,j,j1,j2,a;
    for(i=0;isdigit(s1[i]);i++)
        a1[i]=s1[i]-'0';
    for(j=0;j<i/2;j++)
        {
            a=a1[j];
            a1[j]=a1[i-1-j];
            a1[i-1-j]=a;
        }
    for(j1=0;s1[i+j1+1]&&isdigit(s1[i+j1+1]);j1++)
        a2[j1]=s1[i+j1+1]-'0';
    for(i=0;isdigit(s2[i]);i++)
        b1[i]=s2[i]-'0';
    for(j=0;j<i/2;j++)
        {
            a=b1[j];
            b1[j]=b1[i-1-j];
            b1[i-1-j]=a;
        }
    for(j2=0;s2[i+j2+1]&&isdigit(s2[i+j2+1]);j2++)
        b2[j2]=s2[i+j2+1]-'0';
    int w=j1;
    if(j1<j2)
        w=j2;
    for(i=w;i>0;i--)
    {
        b3[i]+=a2[i]+b2[i];
        if(b3[i]>=10)
        {
            b3[i-1]+=b3[i]/10;
            b3[i]=b3[i]%10;
        }
    }
    b3[0]+=a2[0]+b2[0];
    if(b3[n]>=5)
        b3[n-1]++;
    for(i=n-1;i>0;i--)
    {
        if(b3[i]>=10)
        {
            b3[i-1]+=b3[i]/10;
            b3[i]=b3[i]%10;
        }
    }
    if(b3[0]>=10)
        {
            a1[0]++;
            b3[i]%=10;
        }
    for(i=0;i<499;i++)
    {
        a3[i]+=a1[i]+b1[i];
        if(a3[i]>=10)
        {
            a3[i+1]++;
            a3[i]=a3[i]%10;
        }
    }
    for(i=499;i>=0;i--)
        {
            if(a3[i]!=0)
                break;
        }
    if(i==-1)
        printf("0");
    for(;i>=0;i--)
        printf("%d",a3[i]);
    printf(".");
    for(i=0;i<n;i++)
        printf("%d",b3[i]);
    return 0;
}
