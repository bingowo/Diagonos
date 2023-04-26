//digsys\1005.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
#define MAXLEN 170
char input[52];
int res[MAXLEN];// 使用分数时，index 0 should be the first object
int a[MAXLEN];
void ha_division(int res[],int b,int accuracy)//calc accuracy
{
    for(int i=0;i<MAXLEN;++i){
        a[i]=res[i];
    }
    memset(res,0,MAXLEN*sizeof(res[0]));
    int tem=0;
    for(int i=0;i<accuracy;++i){
        res[i]=(a[i]+tem)/b;
        tem=10*((a[i]+tem)%b);
    }
}

void prarr(int x[],int accuracy)
{
    while(res[accuracy]==0)--accuracy;
    printf("0.");
    for(int i=1;i<accuracy;++i){//不输出个位
        printf("%d",x[i]);
    }printf("%d\n",x[accuracy]);
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    getchar();//key
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        getchar();
        getchar();
        scanf("%s",input);
        getchar();//remove \n
        int len=strlen(input);
        int accuracy=3*len+4;
        memset(res,0,MAXLEN*sizeof(res[0]));
        for(int i=len-1;i>=0;--i){
            res[0]+=input[i]-'0';//个位进位
            ha_division(res,8,accuracy);
        }
        prarr(res,3*len);
    }
}
