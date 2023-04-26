#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct
{
    char s[100];
    long long n;
}string;
int cmp(const void*a,const void*b)
{
    string*s1,*s2;
    s1=(string*)a;
    s2=(string*)b;
    if(s1->n>s2->n)return 1;
    else if(s1->n<s2->n)return -1;
    else return strcmp(s1->s,s2->s);
}
long long hp(char s[61])
{
    int digit=0,i,n=1,k=0;
    long long sum=0;
    int a[128];
    for(i=0;i<128;i++)a[i]=-1;
    char *p=s;
    a[*p]=1;
    while(*++p)
    if(a[*p]==-1){a[*p]=digit;digit=digit?digit+1:2;n++;}
    if(n<=2)n=2;
    p=s;
    while(*p)
    {
        sum=sum*n+a[*p];
        p++;
    }
   return sum;
}
int main()
{
    int a,i;
    string p[12000];
    scanf("%d",&a);
   for(i=0;i<a;i++)
   {
    scanf("%s",p[i].s);
    p[i].n=hp(p[i].s);
   }
   qsort(p,a,sizeof(p[0]),cmp);
  for(i=0;i<a;i++)
   printf("%s\n",p[i].s);
    return 0;

}
