#include <stdio.h>
#include <string.h>
#include <ctype.h>


void solve(char *s,int *a)
{
    int flag = 0;
    for(int i = 0;i < strlen(s);i++)
    {
        if(flag) break;
        int time=1,sig=0,num=1,start = 0;      //分别是次数，正负标志，系数
        for(int j = i;j < strlen(s);j++){
            if(s[i] == '-' && start == 0){
                sig = 1;
                start = 1;
                continue;
            }
            if(s[i] == '+' && start == 0){
                start = 1;
                continue;
            }
            if(s[j] == '-' || s[j] == '+'){
                i = j-1;
                break;
            }
            else if(isdigit(s[j])){    //如果读到了数字
                num = 0;
                for(int k = j;k < strlen(s);k++){
                    if(s[k] == 'x'){
                        j = k-1;
                        break;
                    }
                    num = num*10 + s[k]-'0';
                    if(k == strlen(s)-1){
                        time = 0;
                        j = strlen(s)-1;
                        flag = 1;
                    }
                }
            }
            else if(s[j] == 'x') continue;
            else if(s[j] == '^'){
                time = 0;
                for(int k = j+1;k < strlen(s);k++){
                    if(s[k] == '+' || s[k] == '-'){
                        j = k-1;
                        break;
                    }
                    time = time*10 + s[k]-'0';
                    if(k == strlen(s)-1){
                        j = strlen(s)-1;
                        flag = 1;
                    }
                }
            }
        }
        if(sig) a[time] = -num;
        else a[time] = num;
    }
}

int main(void)
{
    char s1[1000] = {0};
    char s2[1000] = {0};
    while((scanf("%s %s",s1,s2)) != EOF)
    {
        int A[51] = {0};
        int B[51] = {0};
        int ans[50] = {0};
        solve(s1,A);
        solve(s2,B);
        for(int i = 0;i < 50;i++){
            for(int j = 0;j < 50;j++){
                ans[i+j] += A[i]*B[j];
            }
        }
        for(int i = 49;i >= 0;i--){
            if(ans[i] != 0) printf("%d ",ans[i]);
        }
        printf("\n");
        memset(s1,'\0',sizeof(s1));
        memset(s2,'\0',sizeof(s2));
    }

    return 0;
}