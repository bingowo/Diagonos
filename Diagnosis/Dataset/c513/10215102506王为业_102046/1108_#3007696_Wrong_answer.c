//simu\1104.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/


#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

struct rest
{
    int quo;
    int rem;
};
typedef struct rest st;
st buf[110];
int buflen;
int get_circle(int q,int r)//-1 not found
{
    for(int i=0;i<buflen;++i){
        if(buf[i].quo==q&&buf[i].rem==r){
            return i;
        }
    }
    return -1;//not found
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    getchar();
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int n,m;
        scanf("%d%d",&n,&m);
        buflen=0;
        int begin_circle=-1;
        while(n!=0){
            n*=10;
            if(n>=m){
                buf[buflen].quo=n/m;
                n%=m;
                buf[buflen].rem=n;
                if((begin_circle=get_circle(buf[buflen].quo,n))!=-1){
                    break;
                }
                ++buflen;//circle not included
            }else{
                buf[buflen].quo=0;
                buf[buflen].rem=0;
                ++buflen;
            }
            
        }
        printf("0.");
        for(int i=0;i<buflen-1;++i){
            printf("%d",buf[i].quo);
        }
        if(n!=0)
            printf("%d",buf[buflen-1].quo);
        putchar('\n');
        if(begin_circle!=-1){
            printf("%d-%d\n",begin_circle+1,buflen);
        }
        
    }
}

