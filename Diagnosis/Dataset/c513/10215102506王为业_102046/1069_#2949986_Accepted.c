//math\1069.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*

*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

unsigned char nownum[20];
int nowlen=0;
int isnow_huiwen()
{
    for(int i=0,j=nowlen-1;i<j;++i,--j){
        if(nownum[i]!=nownum[j])
            return FALSE;
    }
    return TRUE;
}
unsigned char temnum[20];
int temlen=0;
void clear_temnum()
{
    temlen=0;
    memset(temnum,0,20*sizeof(temnum[0]));
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    scanf("%s",nownum);
    int addtime=0;
    nowlen=strlen(nownum);
    for(int i=0;i<nowlen;++i){
        nownum[i]-='0';
    }
    for(int i=0,j=nowlen-1;i<j;++i,--j){
        unsigned char tem=nownum[i];
        nownum[i]=nownum[j];
        nownum[j]=tem;
    }
    do{
        unsigned char*low=nownum,*high=nownum+nowlen-1;
        temlen=nowlen;
        for(int i=0;i<nowlen;++i){
            temnum[i]=*low++ + *high--;
        }
        for(int i=0;i<temlen-1;++i){
            temnum[i+1]+=temnum[i]/10;
            temnum[i]%=10;
        }
        if(temnum[temlen-1]>=10){
            temnum[temlen]=temnum[temlen-1]/10;
            temnum[temlen-1]%=10;
            ++temlen;
        }
        for(int i=0;i<temlen;++i){
            nownum[i]=temnum[i];
        }nowlen=temlen;
        ++addtime;
        clear_temnum();
    }while(!isnow_huiwen());
    printf("%d ",addtime);
    for(int i=nowlen-1;i>=0;--i){
        printf("%d",nownum[i]);
    }
}
