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

unsigned char number[109];
int numlen=0;
int TdivNINE()
{
    LL sum=0;
    for(int i=0;i<numlen;++i){
        sum+=number[i];
    }
    if(sum%9==0){
        ++number[0];
        return TRUE;
    }else{
        return FALSE;
    }
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    char c;

    while((c=getchar())!=EOF&&c!='\n'){
        number[numlen++]=c-'0';
    }
    for(int i=0,j=numlen-1;i<j;++i,--j){
        int tem=number[i];
        number[i]=number[j];
        number[j]=tem;
    }
    ++number[0];
    int t=0;
    while(number[t]>9){
        if(t!=numlen)
        number[t+1]+=number[t]/10;
        number[t]%=10;
        ++t;
    }
    do{
        if(number[numlen-1]==9){
            number[numlen-1]=0;
            number[numlen++]=1;
        }
        for(int i=0;i<numlen;++i){
            if(number[i]==9){
                ++number[i+1];
                number[i]=0;
            }
        }
    }while(TdivNINE());
    for(int i=numlen-1;i>=0;--i){
        printf("%d",number[i]);
    }
}
