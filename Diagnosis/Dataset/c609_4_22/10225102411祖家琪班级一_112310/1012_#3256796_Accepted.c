#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char mode[52];
        scanf("%s",mode);
        char *p;
        p = mode+2;
        char oct[50];
        strcpy(oct,p);
        //printf("%s",oct);
        char dec[152];
        int l = strlen(oct);
        int remain = 0,nums = 0,tmp,cnt = 0;//remain是余数,nums代表已经计算了几位小数
        for(int j=l - 1;j>-1;j--){//霍纳规则，小数部分是从后往前遍历
            cnt = 0;//cnt表示当前一次循环已经计算了多少位
            remain = oct[j] - '0';
            do{
               if(cnt < nums){//表示还没有和上次除法的商相加完毕
                    //与前一位相加再进行除8的操作
                    tmp = remain*10 + dec[cnt] - '0';//此步即为借用操作
                    dec[cnt++] = tmp/8 + '0';
                    remain = tmp%8;
               }
               else{
                    tmp = remain*10;
                    remain = tmp%8;
                    dec[cnt++] = tmp/8 + '0';
               }
               }while(remain != 0 || cnt<nums);
            //八进制小数的某一位算完了
            nums = cnt;
        }
        dec[cnt] = '\0';
        printf("case #%d:\n0.%s\n",i,dec);
    }
    return 0;
}
