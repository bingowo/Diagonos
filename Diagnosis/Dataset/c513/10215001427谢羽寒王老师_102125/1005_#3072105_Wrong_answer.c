#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    getchar();      //回车
    for (int i = 0; i < T; i++) {
        char s[100];
        gets(s);
        int k = 0,j,cnt=0,c=8;
        int sd[155];
        memset(sd, 0, sizeof(sd));
        for (j = strlen(s) - 1; j >1; j--) {
            int n = (s[j] - '0');  //读取八进制的一位数字
            int tmp;
            tmp=n*c+k;
            k=tmp/10;
            sd[cnt++]=tmp%10;
            c*=8;
        }
        printf("case #%d:\n0.", i);
        for(int i = 0; i < cnt; ++i) {
            printf("%d", sd[i]);
        }
        printf("\n");
    }
    return 0;
}