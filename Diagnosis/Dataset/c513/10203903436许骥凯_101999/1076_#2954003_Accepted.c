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
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        char s[300]; scanf("%s", s); int slen = strlen(s);
        for (int i = 0; i != slen; i++){
            if (isEmpty()) push(s[i]);
            else if (top() == '('){
                if (s[i] == '{') push(s[i]);
                else if (s[i] == ')') pop();
                else break;
            }
            else if (top() == '['){
                if (s[i] == '(') push(s[i]);
                else if (s[i] == ']') pop();
                else break;
            }
            else if (top() == '{'){
                if (s[i] == '[') push(s[i]);
                else if (s[i] == '}') pop();
                else break;
            }
            else break;
        }
        if (!isEmpty()) printf("No\n");
        else printf("Yes\n");
        memset(stack, 0, 300);
        len = 0;
    }
    return 0;
}