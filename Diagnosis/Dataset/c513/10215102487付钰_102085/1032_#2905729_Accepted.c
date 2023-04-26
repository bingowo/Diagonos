#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
int *s1,*s2;
s1=(int *)a;
s2=(int *)b;
while(*s1!=-1&&*s2!=-1&&*s1==*s2) s1++,s2++;
return *s2-*s1;
}

int main()
{
    int t,n,k,j ;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        int a[1000][51];
        for(k=0;k<n;k++)
  	    {
             j=0;
            while(scanf("%d",&a[k][j])&&a[k][j]!=-1) j++;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(k=0; k<n; k++)
        {
            for( j=0; a[k][j+1]!=-1; j++)
                printf("%d ",a[k][j]);
            printf("%d\n",a[k][j]);
        }
    }
}