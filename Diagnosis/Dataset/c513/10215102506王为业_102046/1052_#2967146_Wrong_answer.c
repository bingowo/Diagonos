//string\1052.c


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
char number[12][8]={"ZERO","ONE","TWO","THREE",
"FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

char ans[35];
int anslen;
char str[25];
int chafre[30];
int cmp(char*x,char*y)
{
    return *x>*y?1:-1;
}
void num_remove(int num,int times)
{
    char *cp=number[num];
    while(*cp){
        chafre[*cp-'A']-=times;
        ++cp;
    }
    while(times--)
        ans[anslen++]=num+'0';
}
void calctotal()//read how many charactres are there
{
    memset(chafre,0,30*sizeof(chafre[0]));
    char *cp=str;
    while(*cp){
        ++chafre[*cp-'A'];
        ++cp;
    }
}
void specific_remove()
{
    if(chafre['Z'-'A']!=0){
        num_remove(0,chafre['Z'-'A']);
    }
    if(chafre['G'-'A']!=0){
        num_remove(8,chafre['G'-'A']);
    }
    if(chafre['W'-'A']!=0){
        num_remove(2,chafre['W'-'A']);
    }
    if(chafre['U'-'A']!=0){
        num_remove(4,chafre['U'-'A']);
    }
    if(chafre['T'-'A']!=0){//DEPEND ON 2 TWO
        num_remove(3,chafre['T'-'A']);
    }
    if(chafre['X'-'A']!=0){
        num_remove(6,chafre['X'-'A']);
    }
    if(chafre['S'-'A']!=0){//depend on 6 X
        num_remove(7,chafre['S'-'A']);
    }
    if(chafre['V'-'A']!=0){//depend on 7 V
        num_remove(5,chafre['V'-'A']);
    }
    if(chafre['I'-'A']!=0){//depend on 7 V
        num_remove(9,chafre['I'-'A']);
    }
    if(chafre['O'-'A']!=0){//depend on 7 V
        num_remove(1,chafre['O'-'A']);
    }
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
        scanf("%s",str);
        anslen=0;
        calctotal();
        specific_remove();
        qsort(ans,anslen,sizeof(ans[0]),cmp);
        for(int i=0;i<anslen;++i){
            putchar(ans[i]);
        }
        putchar('\n');
    }
}

