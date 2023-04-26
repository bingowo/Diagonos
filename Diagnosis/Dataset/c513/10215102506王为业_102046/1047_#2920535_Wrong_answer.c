//string\1046.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

unsigned char press_data[600];
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
        int pdlen=0;
        printf("case #%d:\n",iT);
        char tc;
        unsigned char bef_num=0;
        char before='\b';
        while((tc=getchar())!='\n'){
            if(tc==before){
                if(bef_num==255){
                    press_data[pdlen++]=bef_num;
                    press_data[pdlen++]=before;
                    bef_num=1;
                }else{
                    ++bef_num;
                }
            }else{
                press_data[pdlen++]=bef_num;
                press_data[pdlen++]=before;
                before=tc;
                bef_num=1;
            }
        }
        press_data[pdlen++]=bef_num;
        press_data[pdlen++]=before;

        for(int i=0;i<pdlen;++i){
            if(i&1)
                putchar(press_data[i]);
            else
                printf("%u",press_data[i]);
        }
        putchar('\n');
    }
}
