//sort\1032.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define ARRLEN 1010
#define TRUE 1
#define FALSE 0

int data[ARRLEN][21];
int *datap[ARRLEN];

int cmp(int **x,int**y)
{
    int *xp=*x;
    int *yp=*y;
    while(*xp==*yp){
        ++xp;++yp;
    }
    return *yp-*xp;
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
        //memset(data,0,21*ARRLEN*sizeof(data[0]));
        int line;
        scanf("%d",&line);
        for(int iline=0;iline<line;++iline){
            datap[iline]=(int *)data[iline];
            int t_n=0,t_input;
            while(scanf("%d",&t_input)==1&&t_input!=-1){
                data[iline][t_n++]=t_input;
            }
            data[iline][t_n]=-1;//end note
        }
        qsort(datap,line,sizeof(datap[0]),cmp);
        for(int iline=0;iline<line;++iline){
            printf("%d",*datap[iline]++);
            while(*datap[iline]!=-1){
                printf(" %d",*datap[iline]++);
            }
            putchar('\n');
        }
    }
}
