#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define byte 8
int main()
{
    ///*
    int n;
    char s[121];
    scanf("%d",&n);
    getchar();
    for(int i = 0;i < n;i++){
        gets(s);
        int cnt1 = 0;
        for(int j = 0;j < strlen(s);j++){
            int temp = (int)s[j];
            for(int k = 0;k < byte;k++){
                if((temp>>k)&1) cnt1++;
            }
        }
        int dmnt = byte*strlen(s);
        /*
        while(dmnt%cnt1 == 0 && cnt1 != 1){//分子是分母的因数
            dmnt /= cnt1;
            cnt1 /= cnt1;
        }
        while(dmnt%2 == 0 && cnt1%2 == 0){
            dmnt /= 2;
            cnt1 /= 2;
        }
        while(dmnt%3 == 0 && cnt1%3 == 0){
            dmnt /= 3;
            cnt1 /= 3;
        }
        while
        while(dmnt%11 == 0 && cnt1%11 == 0){
            dmnt /= 11;
            cnt1 /= 11;
        }
        */
        int val = cnt1;
        for(int j = 2;j < val;j++){
            if(j*j > val) break;
            while(cnt1%j == 0 && dmnt%j == 0){
                cnt1 /= j;
                dmnt /= j;
            }
        }
        printf("%d/%d\n",cnt1,dmnt);
    }
    //*/
    /*char s;
    scanf("%s",&s);
    printf("%lld",s);*/
    return 0;
}
