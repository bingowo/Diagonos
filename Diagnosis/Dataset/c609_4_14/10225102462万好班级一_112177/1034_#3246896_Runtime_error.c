#include <stdio.h>


int main(){
    char s[10001];int arr[300];int count = 0;
    gets(s);
    for (int i = 0;s[i + 1] != '\0'; ++i) {
        if((s[i] == '0')&&(s[i+1] == 'x')){
            arr[count++] = i + 2;
        }
    }int flag = 0;
    for (int i = 0;arr[i] != '\0'; ++i) {
        int tmp;tmp = arr[i];long long ans = 0;int point = 0;
        while(((s[tmp]<='f')&&(s[tmp]>='a'))||((s[tmp] >= '0')&&(s[tmp] <= '9')))
        {   if((s[tmp]<='f')&&(s[tmp]>='a'))ans = ans*16 + s[tmp] - 'a' + 10;
            else ans = ans*16 + s[tmp] - '0';tmp++;point++;flag++;}if(point)printf("%lld ",ans);
    }
    if(flag == 0){
        printf("-1");
    }
}