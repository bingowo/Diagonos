#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define ll long long

ll mypow(int d, int h){
    ll res = d;
    if (h == 0) res = 1;
    else{
        while (h-1){
            res *= d;
            h--;
        }
    }
    return res;
}

ll getValue(char s[], int begin){
    ll res = 0;
    int fuhao = 1;
    if (s[begin] == '-'){
        fuhao = -1;
        begin++;
    } 
    for (int i = begin; i < strlen(s); i++){
        if(isdigit(s[i])){
            res += (s[i] - '0');
            res *= 10;
        }
        else break;
    }
    res /= 10;
    return res*fuhao;
}

int main(){
ll a, b, c, d;
    int res[100] = {0};
    char s[40];
    gets(s);
    char * bp = strchr(s, 'i');

    if (bp != NULL){
        int bend = bp - s;
        if (strlen(s) == 1){
            a = 0;
            b = 1;
        }
        else if (s[bend-1] == '-'){
            a = getValue(s, 0);
            b = -1;
        } 
        else if (s[bend-1] == '+'){
            a = getValue(s, 0);
            b = 1;
        } 
        else{
            int i, bfuhao = 1;
            for (i = bend - 1; i >= 0; i--){
                if (isdigit(s[i])){
                    b += (s[i] - '0') * mypow(10, bend-i);
                }
                else{
                    if (s[i] == '-'){
                        bfuhao = -1;
                        if (i == 0) i = -1;
                    } 
                    else if (s[i] == '+'){
                        i=0;
                    }
                    break;
                }
            }
            b /= 10;//最后一下多乘了一个10，除回来。
            b *= bfuhao;
            if (i != -1) a = getValue(s, 0);
            else a = 0;
            
        }
    }
    else{
        b = 0;
        a = getValue(s, 0);
            }
    //printf("a:%d b:%d\n", a, b);
    

    int r = (a+b)%2 == 0 ? 0 : 1;
    res[0] = r;
    int i;
    for (i = 0; a != 0 || b != 0 ;i++){
        c = (r-a+b)/2;
        d = (r-a-b)/2;
        a = c;
        b = d;
        r = (a+b)%2 == 0 ? 0 : 1;
        res[i+1] = r;
    }
    int j = i + 1;
    while (res[j] == 0) j--;
    for (j; j >= 0; j--) printf("%d", res[j]);
    return 0;
}