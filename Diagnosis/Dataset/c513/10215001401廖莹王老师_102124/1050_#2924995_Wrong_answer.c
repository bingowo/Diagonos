#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int read1(char o[100],char p[100],int q[100])
{
    int i=0,j=0,m=-1,k=0;
    for(i=0;p[i];i++)
    {
        if(p[i]==o[0])
        {
            for(j=0;p[i+j] && o[j];j++)
            {
                if(p[i+j]!=o[j]){m=-1;break;}
                if(j==strlen(o)-1)m=i;
            }
        }
        if(m!=-1){q[k]=m;k++;}
        m=-1;
    }
    return k;
}
int cmp(const void*a,const void *b)
{
    return *(int *)a-*(int*)b;
}
void hanshu(int h)
{
    char s1[100]={0},s2[100]={0},s[100]={0};
    int a[100]={0},b[100]={0},c[100]={0};
    scanf("%s",s1);scanf("%s",s2);scanf("%s",s);
    int m=0,n=0,g=0,i=0,k=0;
    m=read1(s1,s,a);
    n=read1(s2,s,b);
    printf("%d %d\n",m,n);
        for(i=0;i<m;i++)printf("%d\n",a[i]);
    printf("\n");
    for(i=0;i<n;i++)printf("%d\n",b[i]);printf("\n");

    printf("case #%d:\n",h);
    if(n==0 || m==0)printf("0");
    else
    {
    qsort(a,m,sizeof(a[0]),cmp);
    qsort(b,n,sizeof(b[0]),cmp);
    g=b[n-1]-a[0]-strlen(s1);
    k=a[m-1]-b[0]-strlen(s2);
    if(g>=k)printf("%d\n",g);
    else printf("%d\n",k);
    }
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
        hanshu(h);
}



