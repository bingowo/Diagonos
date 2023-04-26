#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student{char a[11];int total；};
int cmp(const struct student*c,const struct student*b)
{int m;
if((*c).total!=(*b).total) return (*b).total-(*c).total;
for(m=0;m<11;m++)
{if((*c).a[m]!=(*b).a[m]) return (*c).a[m]-(*b).a[m];
}

}

int main()
{int i,T,N,M,G,j,k,l,d,sum,o,u,y,v;
char s[11];
    scanf("%d",&T);
for(i=0;i<T;i++)
{
    scanf("%d%d%d",&N,&M,&G);
    struct student*q=(struct student*)malloc(N*sizeof(struct student));
    int*p=(int*)malloc(M*sizeof(int));
    for(j=0;j<M;j++)
    {scanf("%d",&p[j]);}
    for(l=0,y=0,k=0;k<N;k++)
    {scanf("%s",s);
    scanf("%d",&d);
    for(o=0,sum=0;o<d;o++)
    {scanf("%d",&u);
    sum+=p[u-1];}
    if(sum>=G) {q[y].total=sum;strcpy(q[y].a,s);y++;}
    }
    if(y==0){printf("case #%d:\n",i);printf("0\n");return 0;}
        else{qsort(q,y,sizeof(q[0]),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",y);
        for(v=0;v<y;v++)
        {printf("%s ",q[v].a);
        printf("%d\n",q[v].total);
        }

}}
}
