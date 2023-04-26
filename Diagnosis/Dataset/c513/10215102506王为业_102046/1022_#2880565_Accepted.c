//sort\1022.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
char memory[2000009];
int mepos;
struct sortchar{
    char*user;
    char*server;
};
typedef struct sortchar mail;
int mailstrcmp(char*x,char*y)
{
    while(*x==*y&&*x!='@'){
        ++x;++y;
    }
    if(*x=='@'&&*y=='@')
        return 0;
    if(*x=='@')
        return -1;
    if(*y=='@')
        return 1;
    return *x>*y?1:-1;
}
int cmp(mail*x,mail*y)
{
    int k;
    if(k=mailstrcmp(x->server,y->server))
        return k;
    else //servers are the same
        return -mailstrcmp(x->user,y->user);
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n;
    scanf("%d",&n);
    getchar();
    mail *mails=malloc(n*sizeof(mail));
    char c;
    for(int in=0;in<n;++in){
        mails[in].user=memory+mepos;//locate
        while((c=getchar())!='@'){
            memory[mepos++]=c;
        }
        memory[mepos++]='@';
        mails[in].server=memory+mepos;
        while((c=getchar())!='\n'&&c!=EOF){
            memory[mepos++]=c;
        }
        memory[mepos++]='@';//ÓÃ×÷·Ö¸ô·û
    }
    qsort(mails,n,sizeof(mails[0]),cmp);
    for(int in=0;in<n;++in){
        char* temc=mails[in].user;
        while(*temc!='@')
            putchar(*temc++);
        putchar('@');
        temc=mails[in].server;
        while(*temc!='@')
            putchar(*temc++);
        putchar('\n');
    }
}
