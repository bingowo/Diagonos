#include<stdio.h>
#include<string.h>
#include<ctype.h>

int c[110] = {0};

void work(char s[], int a[]){
    //先处理第一项为x//实际上没什么必要。
    int i = 0;
    if (s[i]=='x'){
        int up = 1;
        if (s[i+1]=='^'){
            up = s[i+2]-'0';
            if (i+3<strlen(s) && isdigit(s[i+3])){
                up = s[i+2]*10+s[i+3];
            }
        }
        a[up] = 1;
        i++;
    }
    for (i; i < strlen(s); i++){
        if (s[i]=='x'){
            int val = 0, up = 1;
            if (isdigit(s[i-1])){
                val = s[i-1]-'0';
                if (i >= 2){
                    if (isdigit(s[i-2])) {
                        val += 10*(s[i-2]-'0');
                        if (i>=3 && s[i-3]=='-') val = -val;
                    } 
                    else if (s[i-2]=='-') val = -val;
                }
            }
            else {
                if (s[i-1]=='-') val = -1;//-x
                else if (s[i-1]=='+') val = 1;//...+x
            }
            if (s[i+1]=='^'){
                up = s[i+2]-'0';
                if (i+3<strlen(s) && isdigit(s[i+3])){
                    up *=10;
                    up += s[i+3]-'0';
                }
            }
            a[up] = val;
        }
    }
    int val = 0;
    //处理可能存在的最后一个常数项
    for (i = strlen(s)-1; i >= 0; i--){
        if (s[i]=='x'){
            for (int j = 1; i+j < strlen(s); j++){
                if (s[i+j]=='+' || s[i+j]=='-'){
                    val = s[i+j+1]-'0';
                    if (i+j+2 < strlen(s)) {
                        val *= 10;
                        val += s[i+j+2] - '0';
                    }
                    if (s[i+j]=='-') val = -val;
                }
            }
            break;
        }
    }
    a[0] = val;

    if (i==-1) {
        int fuhao = 1, val = 0;
        if (s[0]=='-') {
            fuhao = -1;
            val = s[1]-'0';
            if (2<strlen(s) && isdigit(s[2])) {
                val *= 10;
                val += s[2]-'0';
            }
        }
        else if (isdigit(s[0])) {
            val = s[0]-'0';
            if (1<strlen(s) && isdigit(s[1])) {
                val*=10;
                val+=s[1]-'0';
            }
        }
        a[0] = val*fuhao;
    }
    return;
}

void multi(int a[], int b[]){
    for (int i = 0; i < 51; i++){
        for (int j = 0; j < 51; j++){
            c[i+j] += a[i]*b[j];
        }
    }
    return;
}

int main(){
    char s[101] = {0};
    int a[110] = {0}, b[110] = {0};
    scanf("%s ", s);
    work(s, a);
    memset(s, 0, 100);
    scanf("%s", s);
    work(s, b);
    multi(a, b);
    for (int i = 109; i >= 0; i--) if(c[i]!=0) printf("%d ", c[i]); 
    printf("\n");
    return 0;
}