#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    char *a_ = (char*)a, *b_ = (char*)b;
    if (strlen(a_)!=strlen(b_)) return strlen(b_)-strlen(a_);
    return strcmp(b_,a_);
}

int main()
{
    int n; scanf("%d",&n);
    char distance[51][121] = {};
    for (int i=0;i<n;i++) scanf("%s",distance[i]);
    qsort(distance,n,sizeof(distance[0]),cmp);
    int a[121] = {}, b[121] = {};
    char *p = distance[0], *q = distance[n-1];
    int lena = 0,lenb = 0;
    for (int i=strlen(p)-1;i>=0;i--) a[lena++] = p[i]-'0';
    for (int i=strlen(q)-1;i>=0;i--) b[lenb++] = q[i]-'0';
    for (int i=0;i<lena;i++)
    {
        a[i] -= b[i];
        while (a[i]<0) {a[i] += 10; a[i+1]--;}
    }
    while (a[lena]==0) lena--;
    for (int i=lena;i>=0;i--) printf("%d",a[i]);
    printf("\n");
    return 0;
}