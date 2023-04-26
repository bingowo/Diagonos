#include <stdio.h>
#include <string.h>
int main()
{
    int A,B,res = 1,j = 0;
    char n[32],ans[64];
    scanf("%d%s%d",&A,n,&B);
    for(int i = 0;i < strlen(n) - 1;i++){
        if (n[i] >= 'a'){
            res *= A * (n[i] - 'A' + 10) + (n[i + 1] >= 'A'?((n[i + 1] >= 'a')?(n[i + 1] - 'a'+ 10):(n[i + 1] - 'A' + 10)):n[i + 1] - '0');
        }
        else if (n[i] >= 'A'&&n[i] <= 'a'){
            res *= A * (n[i] - 'a' + 10) + (n[i + 1] >= 'A'?((n[i + 1] >= 'a')?(n[i + 1] - 'a'+ 10):(n[i + 1] - 'A' + 10)):n[i + 1] - '0');
        }
        else res *= A * (n[i] - '0') + (n[i + 1] >= 'A'?((n[i + 1] >= 'a')?(n[i + 1] - 'a'+ 10):(n[i + 1] - 'A' + 10)):n[i + 1] - '0');
    }
    do{
        if (ans[j] >= 'a'){
            ans[j++] = res % B + 10 - 'a';
            res /= B;
        }
        else if (ans[j] >= 'A'&&ans[j] <= 'a'){
            ans[j++] = res % B + 10 - 'A';
            res /= B;
        }
        else{
            ans[j++] = res % B - '0';
            res /= B;
        }
    }while(res);
    for(j;j > -1;j--){
        printf("%c",ans[j]);
    }
    return 0;
}