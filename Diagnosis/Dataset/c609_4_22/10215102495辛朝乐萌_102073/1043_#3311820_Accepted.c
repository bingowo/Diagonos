#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[110];
int sp=0;

void push(int c){
    stack[sp++]=c;
}

int pop(void){
    return stack[--sp];
}

int isempty(void){
    return sp==0;
}

int top(void){
    return stack[sp-1];
}

void clear(void){
    memset(stack,0,sizeof(stack));
    sp=0;
}

int main()
{
    int t;
    scanf("%d",&t);
    char c= getchar();
    for (int i = 0; i < t; ++i) {
        int isperfect=1;
        while ((c=getchar())!='\n'){
            if (c=='('||c=='['||c=='{'){
                if (c=='(' && !isempty()){
                    if (top()!='['){
                        isperfect=0;
                    }
                }
                else if(c=='[' && !isempty()){
                    if (top()!='{'){
                        isperfect=0;
                    }
                }
                else if(c=='{' && !isempty()){
                    if (top()!='('){
                        isperfect=0;
                    }
                }
                push(c);
            }
            else{
                if (c==')'&&top()=='('){
                    pop();
                }
                else if (c==']' && top()=='['){
                    pop();
                }
                else if(c=='}' && top()=='{'){
                    pop();
                }
                else{
                    push(c);
                }
            }
        }
        if (!isempty()){
            isperfect=0;
            clear();
        }
        if (isperfect){
            printf("Yes\n");
        } else{
            printf("No\n");
        }
    }
    return 0;

}