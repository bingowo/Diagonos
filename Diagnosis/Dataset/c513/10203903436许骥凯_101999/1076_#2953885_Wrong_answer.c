#include<stdio.h>
#include<string.h>

char stack[101] = {0};
int len = 0;
int table[130];

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
    return len == 0;
}

int judge(char *s){
    int len = strlen(s);
    for (int i = 0; i != len; i++){
        if (s[i] == '(') if (s[i+1] != ')' || s[i+1] != '{') return 0;
        else if (s[i] == '[') if (s[i+1] != '(') return 0;
        else if (s[i] == '{') if (s[i+1] != '[') return 0;
        else if (s[i] == ')') if (s[i-1] != '}' || s[i-1] != '(') return 0;
        else if (s[i] == ']') if (s[i-1] != ')') return 0;
        else if (s[i] == '}') if (s[i-1] != ']') return 0; 
    }
    return 1;
}

int main(){
    table['('] = ')'; table['['] = table[']']; table['{'] = '}';
    int n; scanf("%d", &n); getchar();
    for (int i = 0; i != n; i++){
        char c;
        char temp[101]; memset(temp, 0, 101); int tlen = 0;
        while((c = getchar()) != '\n'){
            temp[tlen++] = c;
            if (!isEmpty()){
                if (top() == c) pop();
                else push(c);
                continue;
            }
            push(c);
        }
        temp[tlen] = 0;
        if (!isEmpty()) printf("No\n");
        else{
            if (judge(temp)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}