#include <stdio.h>
#include <string.h>
int main() {
    int a=1;
    char s[1001];
    scanf("%s",s);
    int len= strlen(s),num=1;
    for(int i=0;i<len;i++){
        if(i-1>=0&&s[i]!=s[i-1]){
            num++;
        }if((i+1<len)&&(s[i]!=s[i+1])&&(s[i-1]!=s[i+1])){
            num++;
        }
        a=(a%1000000007)*(num);
        num=1;
    }
    int ret = a%1000000007;
    printf("%d",ret);
    return 0;
}
