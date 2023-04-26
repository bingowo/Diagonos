#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

void fz(int*a,int k)
{
    for(int i=0;i<k/2;i++)
    {
        int c;
        c=a[i];
        a[i]=a[k-i-1];
        a[k-i-1]=c;
    }
}
int main()
{
    int a1[600]={0},a2[600]={0},b1[600]={0},b2[600]={0},z1=0,z2=0,f1=0,f2=0,wei;
    int c1[600]={0},c2[600]={0};
    char a[600],b[600];
    scanf("%s",a);
    scanf("%s",b);
    scanf("%d",&wei);
    
    char *p1=a,*p2=b;
    while(*p1!='.'&&*p1)
       {
           a1[z1]=*p1-'0';
           z1++;
           p1++;
       }
    if(*p1=='.'){p1++;
    while(*p1)
    {
        a2[f1]=*p1-'0';
        f1++;
        p1++;
    }}
    while(*p2!='.'&&*p2)
       {
           b1[z2]=*p2-'0';
           z2++;
           p2++;
       }
    if(*p2=='.'){p2++;
    while(*p2)
    {
        b2[f2]=*p2-'0';
        f2++;
        p2++;
    }}
    //z1,z2是a,b整数的位数，f1,f1是a,b小数的位数
     
    
    int maxf=(f1>f2)?f1:f2;
    fz(a2,maxf);
    fz(b2,maxf);
    int jie1=0,jie2=0;
    for(int i=0;i<maxf;i++)
    
    
    
    
    
    
    
    
    
    
