//greedy\1115.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

void cswap(char *x,char *y)
{
    char tem=*x;
    *x=*y;
    *y=tem;
}
void reverse(char *low,char*end)
{
    --end;//high is the end
    char tem;
    while(low<end){
        tem=*low;
        *low=*end;
        *end=tem;
        --end,++low;
    }
}
char number[25];

int next_permutation(char * num,int slen)
{//return new num len
    if(slen==1){
        num[1]=num[0];
        num[0]=0;
        return slen+1;
    }
    int high=1;
    while(high<slen&&num[high]>=num[high-1]){
        ++high;
    }//check whether there is a descending subset
    if(high==slen){//total descending 5 4 3 2 1
        num[slen]=0;
        int first_nozero=0;
        while(first_nozero<slen&&num[first_nozero]==0){
            ++first_nozero;
        }
        cswap(num+first_nozero,num+slen);
        reverse(num,num+slen);
        ++slen;
    }else{ 
        int replace=0;
        while(replace<high&&num[replace]<=num[high]){
            ++replace;
        }
        if(replace==high){
            printf("ERROR");
        }
    cswap(num+replace,num+high);
    reverse(num,num+high);
    }
    return slen;
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
        char c;
        int numlen=0;
        while((c=getchar())!='\n'&&c!=EOF)
            number[numlen++]=c-'0';
        reverse(number,number+numlen);

        numlen=next_permutation(number,numlen);

        for(int i=numlen-1;i>=0;--i){
            printf("%d",number[i]);
        }
        putchar('\n');
    }
}

