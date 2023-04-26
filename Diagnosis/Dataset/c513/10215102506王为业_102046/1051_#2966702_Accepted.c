//string\1051.c
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

char get_base64(unsigned char c)
{
    if(c<=25){
        return c+'A';
    }else if(c<=51){
        return c-26+'a';
    }else if(c<=61){
        return c-52+'0';
    }else if(c==62){
        return '+';
    }else if(c==63){
        return '/';
    }else{
        printf("Error:input b64");
    }
}
void pr_b64(unsigned char c){
    putchar(get_base64(c));
}

unsigned char str[110];
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
        memset(str,0,110*sizeof(str[0]));
        //make sure beyond the area no problem
        scanf("%s",str);
        int slen=strlen(str);
        int eq_num=0;
        if(slen%3!=0){
            eq_num=3-slen%3;
        }
        int past=0;
        char tem;
        for(int i=0;i<slen;++i){
            if(past==0){
                pr_b64(str[i]>>2);
                tem=(str[i]&((1<<2)-1))<<4;
                past=2;
            }else if(past==2){
                pr_b64(tem|(str[i]>>4));
                tem=(str[i]&((1<<4) -1))<<2;
                past=4;
            }else if(past==4){
                pr_b64(tem|(str[i]>>6));
                pr_b64((str[i]&((1<<6) -1)));
                past=0;
            }
        }
        if(past!=0){
            pr_b64(tem);
            while(eq_num--){
                putchar('=');
            }
        }
        putchar('\n');
    }
}
