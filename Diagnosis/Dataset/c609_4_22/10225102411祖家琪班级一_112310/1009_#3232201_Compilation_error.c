#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define byte 8
int main()
{
    int n;
    char s[121];
    scanf("%d",&n);
    getchar();//scanf读取n后，输入缓冲区残留\n,用getchar吃掉，防止gets读不到单词（gets遇\n停止）
    for(int i = 0;i < n;i++){
        gets(s);//gets能够读取空格
        int cnt1 = 0;
        for(int j = 0;j < strlen(s);j++){
            int temp = (int)s[j];
            for(int k = 0;k < byte;k++){
                if((temp>>k)&1) cnt1++;//还可以用lowbit(x)操作，找x的二进制数的最后一个1
            }
            }
        }
        int dmnt = byte*strlen(s);
        int val = cnt1;
        for(int j = 2;j <= val;j++){
            if(j*j > val && j > 3) break;
            while(cnt1%j == 0 && dmnt%j == 0){
                cnt1 /= j;
                dmnt /= j;
            }
        }
        printf("%d/%d\n",cnt1,dmnt);
    }
    return 0;
}
