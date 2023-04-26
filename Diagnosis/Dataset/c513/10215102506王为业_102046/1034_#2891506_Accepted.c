//sort\1034.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define ARRLEN 10100
#define TRUE 1
#define FALSE 0

double frequency[27];
char str[110];

int cmp(char*x,char*y)
{
    int tx='a'<=*x&&*x<='z'?2*(*x-'a'):2*(*x-'A')+1;//num smaller->higher pos
    int ty='a'<=*y&&*y<='z'?2*(*y-'a'):2*(*y-'A')+1;
    if(frequency[tx>>1]==frequency[ty>>1])
        return tx<ty?-1:1;
    else
        return frequency[tx>>1]>frequency[ty>>1]?-1:1;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        for(int i=0;i<26;++i){
            scanf("%lf",&frequency[i]);
        }
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        for(char *sp=str;*sp;++sp){
            putchar(*sp);
        }putchar('\n');
    }
}
