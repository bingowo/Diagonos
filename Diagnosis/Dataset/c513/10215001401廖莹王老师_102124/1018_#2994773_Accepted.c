#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int cnt;
    int a[150];
}point;
point b[25];
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}
void read(char s[100])
{
    reverse(s);
    int i=0,k=24,m=0;
 for(i=0;s[i];i++)
    {
        if(s[i]!=',' && s[i+1]!=',' && s[i+1])
        {
            m=s[i]-'0'+(s[i+1]-'0')*10;
            i=i+1;b[k].a[0]=m%10;b[k].a[1]=m/10;b[k].cnt=2;k--;
        }
        else if(s[i]!=',')
        {b[k].a[0]=s[i]-'0';b[k].cnt=1;k--;}

    }
}

point add(point a,point b)
{
    int i=0,j=0,m=0,n=0;
    point c;c.cnt=0;memset(c.a,0,sizeof(int)*150);
    if(a.cnt>b.cnt)
    {
        for(i=0;i<b.cnt;i++)
        {
            m=a.a[i]+b.a[i]+n;
            c.a[i]=m%10;n=m/10;
        }
        for(i=b.cnt;i<a.cnt;i++)
        {
            m=a.a[i]+n;
            c.a[i]=m%10;n=m/10;
        }
        if(n>0){c.a[i]=n;i++;}
    }
    else
    {
        for(i=0;i<a.cnt;i++)
        {
            m=a.a[i]+b.a[i]+n;
            c.a[i]=m%10;n=m/10;
        }
        for(i=a.cnt;i<b.cnt;i++)
        {
            m=b.a[i]+n;
            c.a[i]=m%10;n=m/10;
        }
        if(n>0){c.a[i]=n;i++;}
    }
    c.cnt=i;
    return c;
}
point mul(point s,point t)
{
    point r={s.cnt+t.cnt,{0}};
    int i=0; int m=0,k=0,j=0,c=0;
    for(i=0;i<t.cnt;i++)
    {   m=0;
        for(j=0;j<s.cnt;j++)
        {
            m=s.a[j]*t.a[i]+c+r.a[i+j];r.a[i+j]=m%10;c=m/10;
        }
        k=i+j;while(c>0){m=c+r.a[k];r.a[k]=m%10;c=m/10;k++;}
    }
    for(i=s.cnt+t.cnt-1;i>0;i--){if(r.a[i]==0)r.cnt--;else break;}return r;
}
void sum()
{   int i=24,k;
    point sum;sum.cnt=0;memset(sum.a,0,sizeof(int)*150);
    point prime[25]={2,{1,9},2,{9,8},2,{3,8},2,{9,7},2,{3,7},2,{1,7},2,{7,6},2,{1,6},2,{9,5},2,{3,5},2,{7,4},2,{3,4},2,{1,4},2,{7,3},2,{1,3},2,{9,2},2,{3,2},
    2,{9,1},2,{7,1},2,{3,1},2,{1,1},1,{7},1,{5},1,{3},1,{2}};
    for(i=24;i>=0;i--)
    {
       point m;m.cnt=1;memset(m.a,0,sizeof(int)*150);m.a[0]=1;
        if(i<24){for(k=24;k>i;k--)m=mul(m,prime[k]);}
        m=mul(m,b[i]);
        sum=add(sum,m);
    }
    for(i=sum.cnt-1;i>=0;i--)printf("%d",sum.a[i]);
}
int main()
{
    char s[100];
    int i;
    for(i=0;i<25;i++){b[i].cnt=0;memset(b[i].a,0,sizeof(int)*150);}
    scanf("%s",s);
    read(s);
   sum();
    return 0;
}
