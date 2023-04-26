#include <stdio.h>
#include <stdlib.h>
struct student{char a[11];long long int total;};
int cmp(const struct student*c,const struct student*b)
{int m;
if((*c).total!=(*b).total){if((*c).total>(*b).total)return -1;
else return 1;}
for(m=0;m<11;m++)
{if((*c).a[m]!=(*b).a[m]) return (*c).a[m]-(*b).a[m];
}}

int main()
{int n,N,M,u,j,m,b,i;
long long G,d;
scanf("%d",&n);
for( i=0;i<n;i++)
{scanf("%d%d%d",&N,&M,&G);
long long int*p=(long long int*)malloc(M*sizeof(long long int));
for(int k=0;k<M;k++){scanf("%lld",&p[k]);}
struct student*q=(struct student*)malloc(N*sizeof(struct student));
for(j=0;j<n;j++)
    {scanf("%s",q[j].a);
q[j].total=0;
scanf("%d",&d);
for(int o=0;o<d;o++)
    {scanf("%d",&u);
    q[j].total+=p[u-1];}}
qsort(q,j,sizeof(q[0]),cmp);
for( m=0,b=0;m<N;m++){if(q[m].total>=G)b++;}
if(b==0){printf("case #%d:\n",i);printf("0\n");}
else {printf("case #%d:\n",i);printf("%d\n",b);
for(int h=0;q[h].total>=G;h++)printf("%s %lld\n",q[h].a,q[h].total);}
}}
