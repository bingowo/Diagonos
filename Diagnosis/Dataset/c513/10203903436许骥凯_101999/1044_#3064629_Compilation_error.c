#include<stdio.h>
#include<ctype.h> 

int main(){
    char s[100001]; scanf("%s", s);
    int arr[5000]; int arrlen = 0;
    for (int i = 0, flag = 0; s[i]; ++i){
        if (flag && (s[i] == 'x')){
            int res = 0;
            for (++i; s[i] && ishexnumber(s[i]); ++i)
                if (isdigit(s[i])) res = res * 16 + s[i] - '0';
                else res = res * 16 + s[i] - 'a' + 10;
            arr[arrlen++] = res;
            flag = 0;
        } 
        else if (s[i] == '0') flag = 1;
        else flag = 0;
    }
    if (arrlen == 0) printf("-1\n");
    for (int i = 0; i != arrlen; ++i)
        printf("%d%c", arr[i], i == arrlen - 1? '\n': ' ');
    return 0;
}