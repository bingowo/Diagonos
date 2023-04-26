//string\1050.c
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
char s1[82];
char s2[82];
char s[82];
int slen;

int issubstr(char substr[],int sublen,int pos)
{
    for(int i=0;i<sublen;++i){
        if(substr[i]!=s[pos+i])
            return FALSE;
    }
    return TRUE;
}

int dis(char sleft[],char sright[])
{
    int l_len=strlen(sleft);
    int r_len=strlen(sright);
    int lbeg_pos=0;
    int rbeg_pos=slen-r_len;
    while(lbeg_pos<=slen-l_len){
        if(issubstr(sleft,l_len,lbeg_pos))
            break;
        ++lbeg_pos;
    }
    while(rbeg_pos>=0){
        if(issubstr(sright,r_len,rbeg_pos))
            break;
        --rbeg_pos;
    }
    if(lbeg_pos<=slen-l_len&&rbeg_pos>=0){
        int res=(rbeg_pos)-(lbeg_pos+l_len);
        if(res>0)
            return res;
        else
            return 0;
    }
    return 0;
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
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        slen=strlen(s);
        int maxdis=0;
        int tem=dis(s1,s2);
        if(tem>maxdis)maxdis=tem;
        tem=dis(s2,s1);
        if(tem>maxdis)maxdis=tem;
        printf("%d\n",maxdis);
    }
}
