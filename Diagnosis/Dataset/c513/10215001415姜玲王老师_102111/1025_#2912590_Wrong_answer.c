#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct string{char a[20];int sum;};
int main()
{int n,k;
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
    int d;
    scanf("%d",&d);
    struct string p[100];
    for(int j=0;j<d;j++)
    {scanf("%s",p[j].a);
    p[j].sum=0;
    for(k=0;k<strlen(p[j].a)-1;k++)
    {
        if(p[j].a[k]!=p[j].a[k+1]) p[j].sum++;}}
int cmp(const void*a,const void*b)
{struct string*p1=(struct string*)a;
struct string*p2=(struct string*)b;
if((*p1).sum!=(*p2).sum) return (*p2).sum-(*p1).sum;
return strcmp((*p1).a,(*p2).a);}
qsort(p,d,sizeof(p[0]),cmp);
for(int y=0;y<d;y++)
{printf("%s\n",p[y].a);
}

}
}

