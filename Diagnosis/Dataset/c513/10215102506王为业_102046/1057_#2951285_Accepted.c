//string\1057.c
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

char area[2030];
char *begin=area+1010;
char *end=area+1010;


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    char c=getchar();
    if('a'<=c&&c<='z')
        c=c-'a'+'A';
    *begin=c;
    while((c=getchar())!=EOF){
        if('a'<=c&&c<='z')
            c=c-'a'+'A';
        if(c>=*begin)
            *(--begin)=c;
        else
            *(++end)=c;
    }
    while(begin<=end){
        putchar(*begin++);
    }
}
