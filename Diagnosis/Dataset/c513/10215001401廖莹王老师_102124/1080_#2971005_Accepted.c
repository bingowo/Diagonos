#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int d;
    int a[200];
}cc;
cc p;
void chuyier(int a[200])
{
    int i=0,k=0,m=0;
    if(a[p.d-1]<2){p.d--;k=1;}
    for(i=p.d-1;i>=0;i--)
    {
        m=a[i]+10*k;
        a[i]=m/2;
        k=m%2;
    }
}
void erjinzhi(int a[200],int d)
{
    int i=0,k=0,m=0;
    for(i=0;i<=p.d;i++)
    {
        k=a[i]*2+m;
        a[i]=k%10;m=k/10;
    }
    if(m>0){p.d++;a[p.d]=m;}
    a[0]=a[0]+d;
}
void jisuan(int h)
{
    char s[200]={0};
    int re[400]={0};
    memset(p.a,0,sizeof(p.a[0]));
    scanf("%s",s);
    int i=0,j=0,m=0,k=0;
    p.d=strlen(s);
    for(i=0;i<p.d;i++)p.a[i]=s[p.d-i-1]-'0';
      while(p.d>0)
    {
        re[j]=p.a[0]%2;j++;
        chuyier(p.a);
    }
    p.a[0]=0;
   for(i=0;i<j;i++){erjinzhi(p.a,re[i]);}
   printf("case #%d:\n",h);
   for(i=p.d;i>=0;i--)printf("%d",p.a[i]);printf("\n");

}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
