#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int d;
    int a[500];
}shuzu;
shuzu p;
shuzu k;
void chuer(int a[500])
{
    int i,k=0,l=0;
    if(a[p.d-1]<2){p.d--;l=1;}
    for(i=p.d-1;i>=0;i--)
    {

        k=a[i]+l*10;
        l=k%2;
        a[i]=k/2;
    }
}
void turnintoshi(int a[500],int d)
{
      int i,m,k=0;
      m=d;
      for(i=0;i<=p.d;i++)
      {
          k=a[i]*2+m;
          a[i]=k%10;m=k/10;
      }
      if(m>0){p.d++;a[p.d]=m;}
}
void jisuan(int h)
{
    char s[500]={0};
    memset(p.a,0,sizeof(p.a));
    memset(k.a,0,sizeof(p.a));
    int i;
    k.d=0;
    scanf("%s",s);
    p.d=strlen(s);
    for(i=p.d-1;i>=0;i--)p.a[p.d-1-i]=s[i]-'0';

    while(p.d>0)
    {
        k.a[k.d]=p.a[0]%2; k.d++;
        chuer(p.a);
    }
    p.a[0]=0;p.d=0;
    for(i=0;i<334 && i<k.d;i++)turnintoshi(p.a,k.a[i]);
    printf("case #%d:\n",h);
    for(i=p.d;i>=0;i--)printf("%d",p.a[i]);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
    return 0;
}
