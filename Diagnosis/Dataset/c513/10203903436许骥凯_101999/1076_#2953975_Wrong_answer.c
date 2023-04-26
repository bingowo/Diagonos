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
        char c;
        char temp[300]; memset(temp, 0, 300); int tlen = 0;
        while((c = getchar()) != '\n'){
            temp[tlen++] = c;
            if (!isEmpty()){
                if (top() == '('){
                    if(c == '{') push(c);
                    else if(c == ')'){
                        pop();
                        continue;
                    }
                    else break;
                } 
                else if (top() == '['){
                    if (c == '(') push(c);
                    else if (c == ']'){
                        pop();
                        continue;
                    }
                    else break;
                }
                else if (top() == '{'){
                    if (c == '[') push(c);
                    else if (c == '}') {
                        pop();
                        continue;
                    }
                    else break;
                }
            }
            else push(c);
        }
        if (!isEmpty()) printf("No\n");
        else printf("Yes\n");
        memset(stack, 0, 300);
        len = 0;
    }
    return 0;
}