//simu\1110.c

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

char ch_unknown;

struct side_equ{
    int val;
    int un_size;
};

typedef struct side_equ side;
side get_val(char* beg,char* end)
{
    int unknown=0,val=0;
    while(beg!=end){
        int tem_neg;
        if(*beg=='+'){
            tem_neg=FALSE;
            ++beg;
        }else if(*beg=='-'){
            tem_neg=TRUE;
            ++beg;
        }else{
            tem_neg=FALSE;
        }
        //---digit process---------------
        int temcoe=1;
        if(isdigit(*beg)){
            temcoe=0;
            do{
                temcoe=temcoe*10+(*beg-'0');
                ++beg;    
            }while(isdigit(*beg));
        }
        //---alpha process--------
        if('a'<=*beg&&*beg<='z'){
            ch_unknown=*beg;
            unknown+=tem_neg?-temcoe:temcoe;
            ++beg;
        }else{
            val+=tem_neg?-temcoe:temcoe;
        }
    }
    side ret={val,unknown};
    return ret;
}

int main()
{

#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    char input[90];
    scanf("%s",input);
    int inlen=strlen(input);
    int pos_equ=0;
    while(*(input+pos_equ)!='='){
        ++pos_equ;
    }
    side left,right;
    left=get_val(input,input+pos_equ);
    right=get_val(input+pos_equ+1,input+inlen);
    double un_coe=left.un_size-right.un_size;
    double res=(right.val-left.val)/un_coe;
    printf("%c=%.3lf",ch_unknown,res);
}