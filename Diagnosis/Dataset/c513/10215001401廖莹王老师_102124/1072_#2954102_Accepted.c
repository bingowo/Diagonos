#include <stdio.h>
#include <stdlib.h>
long long abss(long long x)
{
    long long j=0;
    if(x>=0)j=x;
    else j=-x;
    return j;
}
long long d[64];
void jisuan()
{
    int i=0;long long a=1;
    for(i=0;i<65;i++){d[i]=a;a=a*2;}
    return;
}
long long  zou(long long x,long long y)
{
   long long k1=abss(x)+abss(y);
   long long l1=1,l2=1,i=1;
   if(k1%2==0)return -1;
   else if(k1==0)return 0;
   else
   {
       while(l2<k1)
       {
           l1=l1*2;l2=l2+l1;
           i++;
       }
       return i;
   }
}
char s[10000]={0};
long long r,j;
long long max(long long x,long long y)
{
    x=abss(x);y=abss(y);
    if(x>=y)return x;
    else return y;
}
void fangxiang(long long x,long long y)
{
    if(x==0 & y==0)return;
    else
    {
        if(max(x,y)==x){x=x-d[r-1];r--;s[j]='E';j++;return fangxiang(x,y); }
        else if(max(x,y)==(-x)){x=x+d[r-1];r--;s[j]='W';j++;return fangxiang(x,y); }
        else if(max(x,y)==y){y=y-d[r-1];r--;s[j]='N';j++;return fangxiang(x,y); }
        else if(max(x,y)==(-y)){y=y+d[r-1];r--;s[j]='S';j++;return fangxiang(x,y); }
    }
}
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}
int main()
{
    long long x,y,step=0;

    scanf("%lld %lld",&x,&y);
    if(x==0 && y==0)printf("0");
    else
    {
        step=zou(x,y);r=step;j=0;
    jisuan();
    if(r==-1)printf("-1");
    else
    {
    fangxiang(x,y);
    reverse(s);
    printf("%lld\n",step);
    printf("%s",s);
    }
    }
    

    return 0;
}
