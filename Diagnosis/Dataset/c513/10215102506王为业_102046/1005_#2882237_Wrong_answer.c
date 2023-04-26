//digsys\1005.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
char input[52];
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
        long double tem=(input[len-1]-'0')/8.0;
        for(int i=len-2;i>=0;--i){
            tem=(tem+(input[i]-'0'))/8.0;
        }
        printf("%.*llf\n",3*len,tem);
    }
}
