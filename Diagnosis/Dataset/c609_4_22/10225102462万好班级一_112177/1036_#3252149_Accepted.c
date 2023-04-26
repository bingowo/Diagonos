#include <stdio.h>



int answer(int b){
    if(b == 0)return 1;
    else
    {int a = 1;
        for (int i = 0; i < b; ++i) {a = a*2;}
        return a;
    }
}

int main(){

    char str[101];gets(str);
    int lco = -1;int rco = 0;int ans = 0;int k = -1;
    while(str[++k] != '\0')
    {
        if(str[k] == '('){lco++;}
        else if(str[k] == ')'&& str[k+1] == '('){ans = ans + answer(lco);rco++;lco = lco - rco;rco = 0;}
        else if(str[k] == ')'&& str[k+1] == '\0'){ans = ans + answer(lco);}
        else if(str[k] == ')'&& str[k+1] == ')'){rco++;}
    }printf("%d",ans);
}