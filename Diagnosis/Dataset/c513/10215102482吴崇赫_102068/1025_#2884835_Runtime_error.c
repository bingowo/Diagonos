#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 105

int lowerC(char c)
{
    int ret=c-'A';
    return ret;
}

int d_Words(char* s)
{
    int* a=(int*)malloc(30*sizeof(int));
    int cnt=0,n=strlen(s);
    for(int i=0;i<30;++i)a[i]=0;
    for(int i=0;i<n;++i){
        a[lowerC(s[i])]++;
    }
    for(int i=0;i<27;++i){
        if(a[i])cnt++;
    }
    return cnt;
}

int cmp(const void* a,const void* b)
{
    if(d_Words(*(char**)a)!=d_Words(*(char**)b))return d_Words(*(char**)a)<d_Words(*(char**)b)?1:-1;
    else return strcmp(*(char**)a,*(char**)b);
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char in[N][25];
        for(int i=0;i<N;++i){
            for(int j=0;j<25;++j)in[i][j]='\0';
        }
        int n;scanf("%d\n",&n);
        for(int i=0;i<n;++i)scanf("%s",in[i]);
        qsort(in,n,sizeof(in[0]),cmp);
        printf("case #%d:\n",x++);
        for(int i=0;i<n;++i)printf("%s\n",in[i]);
    }
    return 0;
}

