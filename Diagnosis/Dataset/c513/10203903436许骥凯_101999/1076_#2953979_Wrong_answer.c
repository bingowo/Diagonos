#include<stdio.h>
#include<string.h>

char stack[300] = {0};
int len = 0;
char table[130];

void push(char item){
    stack[len++] = item;
    stack[len] = 0;
}

void pop(){
    stack[--len] = 0;
}

char top(){
    return stack[len - 1]; 
}

int isEmpty(){
    return len <= 0;
}

int main(){
    int n; scanf("%d", &n); getchar();
    for (int i = 0; i != n; i++){
        char c; int flag = 0;
        while((c = getchar()) != '\n'){
            if (!isEmpty()){
                if (top() == '('){
                    if(c == '{') push(c);
                    else if(c == ')'){
                        pop();
                        continue;
                    }
                    else flag = 1;
                } 
                else if (top() == '['){
                    if (c == '(') push(c);
                    else if (c == ']'){
                        pop();
                        continue;
                    }
                    else flag = 1;
                }
                else if (top() == '{'){
                    if (c == '[') push(c);
                    else if (c == '}') {
                        pop();
                        continue;
                    }
                    else flag = 1;
                }
            }
            else if (c == '[' || c == '(' || c == '{') push(c);
        }
        if (flag) printf("No\n");
        else if (!isEmpty()) printf("No\n");
        else printf("Yes\n");
        memset(stack, 0, 300);
        len = 0;
    }
    return 0;
}