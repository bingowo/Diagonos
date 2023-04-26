//string\1018.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    char str[55];
    scanf("%s",str);
    int highlen=1;
    int slen=strlen(str);
    int i=0,j=0;
    int p_is_across;
    while(i<slen){
        j=i+1;
        p_is_across=str[i]=='-'?TRUE:FALSE;
        while(j<slen){
            if(p_is_across){
                if(str[j]=='|')
                    p_is_across=FALSE;
                else
                    break;
            }else{
                if(str[j]=='-')
                    p_is_across=TRUE;
                else
                    break;
            }
            ++j;
        }//break,then calc;
        if(j-i>highlen)highlen=j-i;
        i=j;
    }
    printf("%d",highlen);
}
