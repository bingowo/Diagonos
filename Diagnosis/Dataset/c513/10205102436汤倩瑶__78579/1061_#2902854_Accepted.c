#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
 char s[20];
 long long int t;
}node;
int cmp(const void *a,const void *b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
if(p1.t>p2.t)return 1;
else if(p1.t<p2.t) return -1;
else return strcmp(p1.s,p2.s);


}
long long int solve(char s[])
{
    int l=strlen(s);
    int N=0;
    long long int ans=0;
    int a[128]={0};
    for(int i=0;i<128;i++)
        a[i]=-1;
    for(int i=0;i<l;i++)
    {
        if(a[s[i]]==-1)
        {
            N++;
            if(N==2)a[s[i]]=0;
            else if(N==1)a[s[i]]=1;
            else a[s[i]]=N-1;
        }
    }
    if(N<2)N=2;
    for(int i=0;i<l;i++)
        ans=N*ans+a[s[i]];
return ans;
}
int main()
{
 int T;
 scanf("%d",&T);
 node *p=(node *)malloc(sizeof(node)*T);
 for(int i=0;i<T;i++)
 {
     scanf("%s",p[i].s);
p[i].t=solve(p[i].s);
 }
qsort(p,T,sizeof(p[0]),cmp);
for(int i=0;i<T;i++)
    printf("%s\n",p[i].s,p[i].t);
}
