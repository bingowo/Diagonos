#include <stdio.h>
#include <string.h>
int main()
{
    int A,B,res = 1,j = 0;
    char n[32],ans[64];
    scanf("%d%s%d",&A,n,&B);
    for(int i = 0;i < strlen(n) - 1;i++){
        if(0 == i){
            if (n[0] >= 'a') res = n[0] + 10 - 'a';
            else if (n[i] >= 'A'&&n[i] < 'a') res = n[0] + 10 - 'A';
            else res = n[0] - '0';
        }
        res = res*A + (n[i + 1] >= 'A'?((n[i + 1] >= 'a')?(n[i + 1] - 'a'+ 10):(n[i + 1] - 'A' + 10)):n[i + 1] - '0');
    }
    do{
        ans[j++] = (res % B >= 10)?res % B + 'A':res % B + '0';
        res /= B;
        }while(res);
    for(j = j - 1;j > -1;j--){
        printf("%c",ans[j]);
    }
    return 0;
}
