#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


typedef struct data{
    int num;
    int exsit;
}data;

data a[501];
data b[1001];
int t,n;

int cmp(const void *a,const void *b)
{
    data *m,*n;
    m=(data *)a;
    n=(data *)b;
    if (m->exsit&&n->exsit) return m->exsit-n->exsit;
    else if (m->exsit) return 1;
    else if (n->exsit) return -1;
    else return m->num-n->num;
}


int main()
{
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%d",&a[i].num);
    }
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&b[i].num);
        b[i].exsit=0;
    }
    int c[10000];
    for (int i = 0; i < 10000; ++i) {
        c[i]=-1;
    }
    for (int i = 0; i < t; ++i) {
        c[a[i].num]=0;
    }
    for (int i = 0; i < n; ++i) {
        if (c[b[i].num]==0) b[i].exsit=1;
    }
    qsort(b,n, sizeof(b[0]),cmp);
    for (int i = 0; i < n; ++i) {
        printf("%d ",b[i]);
    }
    return 0;
}