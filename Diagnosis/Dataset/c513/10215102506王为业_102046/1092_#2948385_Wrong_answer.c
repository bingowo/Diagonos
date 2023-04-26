//math\1093.c
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

int res[300]={1};
int reslen=1;

void highac_mult(int mul)
{
    for(int i=0;i<reslen-1;++i){
        res[i]*=mul;
        res[i+1]+=res[i]/10;
        res[i]%=10;
    }
    res[reslen-1]*=mul;
    if(res[reslen-1]>=10){
        res[reslen]=res[reslen-1]/10;
        res[reslen-1]%=10;
        ++reslen;//avoid unnecessary problems
    }
}

char instr[1050];
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    scanf("%s",instr);
    int slen=strlen(instr);
    if(slen==1){
        printf("1");
    }else if(slen==2){
        if(instr[0]==instr[1])
            printf("1");
        else
            printf("4");
    }else{
        if(instr[0]!=instr[1]){
            highac_mult(2);
        }
        //key
        char *bef=instr;
        char *aft=instr+2;
        for(int i=1;i<=slen-2;++i){
            int tem=3;
            if(*bef==*aft||instr[i]==*bef||instr[i]==*aft){
                --tem;
                if(*bef==*aft&&*bef==instr[i])
                    continue;
            }
            highac_mult(tem);
            ++bef;++aft;
        }
        //key
        if(instr[slen-1]!=instr[slen-2]){
            highac_mult(2);
        }
        for(int i=reslen-1;i>=0;--i){
            printf("%d",res[i]);
        }
    }
}
