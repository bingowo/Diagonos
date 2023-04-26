#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void plus(char*p1,char*p2,char*p3)
{
   int k,d;
   for(k=0;k<strlen(p2)&&k<strlen(p3);k++)
   {
       d=p2[k]-'0'+p3[k]-'0'+p1[k];
       p1[k]=d%10+'0';
       p1[k+1]=d/10;
    }
    if(strlen(p2)==strlen(p3)){if(p1[k]) p1[k]+='0';}
    if(strlen(p2)>strlen(p3))
    {
        for(;k<strlen(p2);k++)
        {
            d=p1[k]+p2[k]-'0';
            p1[k]=d%10+'0';
            p1[k+1]=d/10;
        }
        if(p1[k]) p1[k]+='0';
    }
     if(strlen(p2)<strlen(p3))
    {
        for(;k<strlen(p3);k++)
        {
            d=p1[k]+p3[k]-'0';
            p1[k]=d%10+'0';
            p1[k+1]=d/10;
        }
        if(p1[k]) p1[k]+='0';
    }

}
void reverse(char*a)
{
    int j=strlen(a),i;
    char b;
    for(i=0;i<j/2;i++)
    {
        b=a[i];
        a[i]=a[j-i-1];
        a[j-i-1]=b;
    }
}
int main()
{
 int n,i;
 char a[501][200]={0};
 scanf("%d",&n);
 a[1][0]='1';
 a[2][0]='2';
 a[3][0]='3';
 a[4][0]='6';
 for(i=5;i<=n;i++)
 {
     char b[200]={0};
     plus(b,a[i-1],a[i-2]);
     plus(a[i],b,a[i-4]);

 }
 reverse(a[n]);
 printf("%s",a[n]);
}
