#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[121];
}big;
int cmp(const void*a,const void*b)
{
    big* x=(big*)a;
    big* y=(big*)b;
    if(x->s[0]=='-'&&y->s[0]!='-')return -1;
    else if(x->s[0]!='-'&&y->s[0]=='-')return 1;
    else if(x->s[0]!='-'&&y->s[0]!='-')
    {
        if(strlen(x->s)>strlen(y->s))return 1;
        else if(strlen(x->s)<strlen(y->s))return -1;
        else return strcmp(x->s,y->s)<0?-1:1;
    }
    else
    {
        if(strlen(x->s)>strlen(y->s))return -1;
        else if(strlen(x->s)<strlen(y->s))return 1;
        else return strcmp(x->s,y->s)<0?1:-1;
    }

}
void ctoi(char s[],int a[])
{
    int index=0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='-')
        {
            break;
        }
        a[index++]=s[i]-'0';
    }
}
void minu(int a[],int b[])
{
    for(int i=0;i<121;i++)
    {
        if(a[i]<b[i])
        {
            a[i]=a[i]+10-b[i];
            a[i+1]=a[i+1]-1;
        }
        else
        {
            a[i]=a[i]-b[i];
        }

    }
}
void add(int a[],int b[])
{
    int sum;
    for(int i=0;i<121;i++)
    {
       sum=a[i]+b[i];
       a[i]=sum%10;
       a[i+1]+= sum/10;
    }
}
void print(int a[])
{
    int i;
    for(i=120;a[i]==0&&i>=0;i--);
    if(i==-1)printf("0\n");
    else
    {
        for(;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
}
int main()
{
  int n,flaga,flagb;
  int a[121]={0},b[121]={0};
  scanf("%d",&n);
  big ans[n];
  for(int i=0;i<n;i++)
  {
      scanf("%s",ans[i].s);

  }
  qsort(ans,n,sizeof(ans[0]),cmp);
  if(ans[0].s[0]=='-')flaga=-1;
  else flaga=1;
  if(ans[n-1].s[0]=='-')flagb=-1;
  else flagb=1;
  ctoi(ans[0].s,a);
  ctoi(ans[n-1].s,b);
  if(flaga>0&&flagb>0)
  {
      minu(b,a);
      print(b);
  }
  else if(flaga<0&&flagb>0)
  {
      add(a,b);
      print(a);
  }
  else
  {
      minu(a,b);
      print(a);
  }
  return 0;

}
