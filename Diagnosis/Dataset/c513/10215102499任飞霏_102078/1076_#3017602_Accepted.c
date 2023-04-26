#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 110
#define outer 0
#define small 1
#define mid 2
#define big 3
#define filled_mid 4
#define filled_big 5

int judge(char* str)
{
    int len = strlen(str),states[MAX],top=0;
    states[top] = outer;
    for(int i=0;i<len;i++){
        int state = states[top];
        char ch = str[i];
        switch(state)
        {
        case outer:
            {
                if(ch=='(')states[++top] = small;
                else if(ch=='[')states[++top] = mid;
                else if(ch=='{')states[++top] = big;
                else return 0;
                break;
            }
        case small:
            {
                if(ch=='{')states[++top] = big;
                else if(ch==')'){
                    top--;
                    if(states[top]!=outer)
                        states[top]=filled_mid;
                }
                else return 0;
                break;
            }
        case mid:
        case filled_mid:
            {
                if(ch=='(')states[++top] = small;
                else if(ch==']')
                {
                    //中括号内没有内容，不优雅
                    if(state == mid)return 0;
                    top--;
                    if(states[top]!=outer)
                        states[top]=filled_big;
                }
                else return 0;
                break;
            }
        case big:
        case filled_big:
            {
                if(ch=='[')states[++top] = mid;
                else if(ch=='}')
                {
                    if(state==big)return 0;
                    top--;
                }
                else return 0;
                break;
            }
        }
    }
    return states[top] == outer;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char str[101] = {0};
        scanf("%s",str);
        printf(judge(str)?"Yes\n":"No\n");
    }
    return 0;
}
