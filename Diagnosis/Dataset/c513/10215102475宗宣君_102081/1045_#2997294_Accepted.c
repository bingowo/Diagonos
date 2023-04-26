#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
int cmp(const void* a,const void* b)
{
    return (*(int*)a)-(*(int *)b);
}
void differ(char *a,char *b,int c[])
{
    int k = 1,i,m = 0;
    b[0] = a[0];
    c[0] = 0;
    for(i = 1;i<strlen(a);i++)
    {
        c[m]++;
        if(a[i]!=a[i-1]) {b[k++] = a[i];m++;c[m] = 0;}
    }
    c[m]++;
    b[k] = '\0';
}
int main()
{
    int n,m,sum = 0,res = 0,i,j,k,p;
    scanf("%d",&n);
    char(*s)[101] = (char(*)[101])malloc(100000*101);
    for(i = 0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    char(*b)[101] = (char(*)[101])malloc(100000*101);
    int(*c)[100] = (int(*)[100])malloc(100000*100*4);
    int*d = (int *)malloc(100000*4);
    differ(s[0],b[0],c[0]);
    for(i = 1;i<n;i++)
    {
        differ(s[i],b[i],c[i]);
        if(strcmp(b[i-1],b[i])) {printf("-1");return 0;}
    }
    j = strlen(b[0]);
    for(k = 0;k<j;k++)
    {sum = 0;
    for(i = 0;i<n;i++)
    {
        d[i] = c[i][k];
        sum+=d[i];
    }
    //printf("%d ",sum);
    qsort(d,n,4,cmp);
    m = d[n/2];
    for(p = 0;p<n;p++)
    res = res + abs(d[p]-m);
    }
    printf("%d",res);
    free(s);
    free(b);
    free(c);
    free(d);
    return 0;
}
