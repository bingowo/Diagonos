//string\1076.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*

*/
#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;


#define NONE ','
char cstk[110];
int cTOPpos=0;
void cpush(char c)
{
    cstk[cTOPpos++]=c;
}
int stkempty()
{
    return cTOPpos==0;
}
char pop()
{
    return cstk[--cTOPpos];
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        int NO=FALSE;
        char c;
        char situ=NONE;
        while((c=getchar())!='\n'&&c!=EOF){
            if(NO){
                while((c=getchar())!='\n'&&c!=EOF);//clear io
                cTOPpos=0;//clear the stack
                break;
            }
            switch(situ){
        case NONE:
            if(c=='{'||c=='['||c=='(')
                situ=c;
            else
                NO=TRUE;
            break;
        case '{':
            if(c=='}'){
                if(stkempty())
                    situ=NONE;
                else
                    situ=pop();
            }else if(c=='['){
                cpush('{');
                situ='[';
            }else{
                NO=TRUE;
            }
            break;
        case '[':
            if(c==']'){
                if(stkempty())
                    situ=NONE;
                else
                    situ=pop();
            }else if(c=='('){
                cpush('[');
                situ='(';
            }else{
                NO=TRUE;
            }
            break;
        case'(':
            if(c==')'){
                if(stkempty())
                    situ=NONE;
                else
                    situ=pop();
            }else if(c=='{'){
                cpush('(');
                situ='{';
            }else{
                NO=TRUE;
            }
            break;

            }
        }
        if(NO){
            printf("No\n");
        }else{
            if(!stkempty()){
                printf("No\n");
                cTOPpos=0
            }else
                printf("Yes\n");
        }
    }
}
