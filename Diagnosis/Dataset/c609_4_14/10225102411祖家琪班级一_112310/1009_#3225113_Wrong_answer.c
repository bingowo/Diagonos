#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define byte 8
int main()
{
    int n;
    char s[121];
    scanf("%d",&n);
    getchar();
    for(int i = 0;i < n;i++){
        gets(s);//使用gets()函数可以读空格
        int cnt1 = 0;
        for(int j = 0;j < strlen(s);j++){
            long long temp = (long long)s[j];
            for(int k = 0;k < 32;k++){
                if((temp>>k)&1) cnt1++;
            }
        }
        int dmnt = byte*strlen(s);
        if((cnt1%2)&&(cnt1 != 2)){//奇数
            while(!(dmnt % cnt1)){
                dmnt /= cnt1;
                cnt1 /= cnt1;
            }
        }
        else{
            while(!(cnt1%2)){
                cnt1 /= 2;
                dmnt /= 2;
            }
        }
        printf("%d/%d\n",cnt1,dmnt);
    }
    return 0;
}
