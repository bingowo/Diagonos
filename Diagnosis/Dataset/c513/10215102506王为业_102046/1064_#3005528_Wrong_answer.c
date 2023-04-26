//string\1064.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/


#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;


double digstack[50];
int digstack_top=0;
void push(double m)
{
    digstack[digstack_top++]=m;
}
double pop()
{
    return digstack[--digstack_top];
}
char temstore[60][12];
int p_top=0;

int getword()
{
    char c;
    int wsize=0;
    while((c=getchar())!='\n'&&c!=' '&&c!=EOF){
        temstore[p_top][wsize++]=c;
    }
    temstore[p_top][wsize]='\0';
    ++p_top;
    if(c=='\n'||c==EOF){
        return FALSE;
    }else{
        return TRUE;
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
    getchar();
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        p_top=0;
        while(getword());//get all words in one line
        while(p_top!=0){
            --p_top;//point to avaliable pos
            if(isdigit(temstore[p_top][0])){
                push(atof(temstore[p_top]));
            }else{
                double before=pop();
                double after=pop();
                if(temstore[p_top][0]=='+'){
                    push(before+after);
                }else if(temstore[p_top][0]=='-'){
                    push(before-after);
                }else if(temstore[p_top][0]=='*'){
                    push(before*after);
                }else if(temstore[p_top][0]=='/'){
                    push(before/after);
                }else{
                    printf("Warning\n");
                }
            }
        }
        printf("%llf\n",pop());
    }
}

