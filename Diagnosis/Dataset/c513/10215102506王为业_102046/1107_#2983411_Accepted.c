//simu\1107.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

char ans[5][5];

void reverse(int x,int y)
{
    if(ans[x][y]=='1')
        ans[x][y]='0';
    else
        ans[x][y]='1';
}
void action(int x,int y)
{
    reverse(x,y);
    reverse(x+1,y);
    reverse(x-1,y);
    reverse(x,y-1);
    reverse(x,y+1);
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
        int input;
        memset(ans,'1',5*sizeof(ans[0]));
        printf("case #%d:\n",iT);
        for(int ix=1;ix<=3;++ix){
            for(int iy=1;iy<=3;++iy){
                scanf("%d",&input);
                if(input&1){
                    action(ix,iy);
                }
            }
        }
        for(int ix=1;ix<=3;++ix){
            for(int iy=1;iy<3;++iy){
                printf("%c ",ans[ix][iy]);
            }
            printf("%c\n",ans[ix][3]);
        }
    }
}

