//sort\1029.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
char line[205];
int getline()
{
    int len=0;
    char c;
    while((c=getchar())!='\n'&&c!=EOF){
        line[len++]=c;
    }
    line[len]=0;
    return len;
}
int times[27];
int alphaPOS=0;
char getalpha()
{
    if(times[alphaPOS]){// !=0
        --times[alphaPOS];
        return alphaPOS+'A';
    }else{
        ++alphaPOS;
        return getalpha();
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
    getchar();//key
    for(int iT=0;iT<T;++iT){
        memset(times,0,27*sizeof(times[0]));
        alphaPOS=0;//extern variables need to be reset
        printf("case #%d:\n",iT);
        int len=getline();
        for(char*sp=line;*sp!='\0';++sp){
            if('A'<=*sp&&*sp<='Z'){
                ++times[*sp-'A'];
                *sp='\a';
            }
        }
        for(char*sp=line;*sp;++sp){
            if(*sp=='\a'){
                *sp=getalpha();
            }
        }
        for(int i=0;i<len;++i){
            putchar(line[i]);
        }
        putchar('\n');
    }
}
