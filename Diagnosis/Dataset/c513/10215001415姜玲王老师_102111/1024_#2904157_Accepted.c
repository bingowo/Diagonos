#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student{char a[12];long long int sum;};
long long number(char*a)
{long long num=0;
    for(int i=0;i<strlen(a);i++)
{num=num*10+a[i]-'0';}
return num;
}
int cmp(const void*a,const void*b)
{struct student*p1,*p2;
p1=(struct student*)a;
p2=(struct student*)b;
if((*p1).sum>(*p2).sum) return -1;
if((*p1).sum<(*p2).sum) return 1;
if(number((*p1).a)>number((*p2).a)) return 1;
else return -1;

}

int main()
{int n,i,k;
struct student p[501];
scanf("%d",&n);
for(i=0;i<n;i++)
{int M,N,v;
long long G;
scanf("%d%d%lld",&N,&M,&G);
long long int  a[10];
int j;
for(j=0;j<M;j++)
{scanf("%lld",&a[j]);}
int t,d,k,temp;
for(t=0;t<N;t++)
{scanf("%s",p[t].a);
p[t].sum=0;
scanf("%d",&d);
for(k=0;k<d;k++)
{scanf("%d",&temp);
p[t].sum+=a[temp-1];}
}
qsort(p,N,sizeof(p[0]),cmp);
for(k=0;k<N&&p[k].sum>=G;k++);
printf("case #%d:\n",i);
printf("%d\n",k);
for(v=0;v<k;v++)
{printf("%s %lld\n",p[v].a,p[v].sum);
}
}
}
