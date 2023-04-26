//sort\1021.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0


char alpha[29];
char words[102][102];
int wpos;

int getpos(char c)
{
    if('a'<=c&&c<='z'){
        c+='A'-'a';
    }
    int i=0;
    while(alpha[i]!=c)++i;
    return i;
}
int cmp(char *x,char*y)//array is sustainable
{
    while(*x==*y){//*x==0,*y==0 are impossible
        ++x;++y;
    }
    if(x=='\0')
        return -1;//y is larger
    else if(y=='\0')
        return 1;

    return getpos(*x)>getpos(*y)?1:-1;
}

int getword()
{
    scanf("%s",words[wpos++]);
    if(getchar()!='\n')
        return TRUE;
    else
        return FALSE;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    while(scanf("%s",alpha)!=EOF){
        wpos=0;
        getchar();//eat \n
        while(getword());//input
        //wpos==num now
        qsort(words,wpos,sizeof(words[0]),cmp);
        for(int i=0;i<wpos-1;++i){
            printf("%s ",words[i]);
        }printf("%s\n",words[wpos-1]);
    }

}
