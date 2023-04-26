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

char proword[6][5]={"the","a","an","of","for","and"};
int isword(char s[])
{
    for(int i=0;i<6;++i){
        if(strcmp(proword[i],s)==0)
            return FALSE;
    }
    return TRUE;
}
char nowword[110];
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

        int total=0;
        int nowlen=0;
        char c='4';
        while(c!='\n'){
            nowlen=0;
            memset(nowword,0,110*sizeof(char));
            while((c=getchar())!=' '&&c!='\n'){
                nowword[nowlen++]='A'<=c&&c<='Z'?c-'A'+'a':c;
            }nowword[nowlen]='\0';
            if(isword(nowword))
                ++total;
        }
        printf("%d\n",total);
    }
}
