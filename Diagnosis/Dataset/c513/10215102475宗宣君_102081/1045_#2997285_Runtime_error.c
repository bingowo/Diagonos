#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    return (*(int*)a)-(*(int *)b);
}
void differ(char *a,char *b,int c[])
{
    int k = 1,i,m = 0;
    b[0] = a[0];
    for(i = 1;i<strlen(a);i++)
    {
        c[m]++;
        if(a[i]!=a[i-1]) {b[k++] = a[i];m++;}
    }
    c[m]++;
    b[k] = '\0';
}
int main()
{
    int n,m,sum = 0,res = 0,i,j,k,p;
    scanf("%d",&n);
    char s[n][1001];
    for(i = 0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    char b[100][10001];
    int c[100][100] = {0},d[100];
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
    return 0;
}
