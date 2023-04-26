#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //字符数组
    char s1[100001];

    scanf("%s",s1);

    //分割字符数组
    int len = strlen(s1);

    //计算合法十六进制个数
    int count = 0;
    for(int i = 0;i < len;i++){
        //所转换的十进制数
             unsigned int num = 0;
        if(s1[i] == '0' && s1[i + 1] == 'x'){
            //计算"ox"到下一个“ox”有多少位
            int k = 0;
            do{
                k++;
            }while((s1[i + k] != '0' || s1[i + k + 1] != 'x') && k + i  < len);

            //判断合法的十六进制数在哪里截止
            int end;
            for(end = i + 2; end < i + k; end++){
                if((s1[end] >= '0' && s1[end] <= '9') || (s1[end] >= 'a' && s1[end] <= 'f')){
                    continue;
                }
                break;
            }


            //将十六进制数转换为十进制
            int j;
            for(j = i + 2;j < end;j++){
                if(s1[j] >= '0' && s1[j] <= '9')
                    {
                        num = num*16 + (s1[j] - '0');
                    }
                if(s1[j] >= 'a' && s1[j] <= 'f')
                    {
                        num = num * 16 + 10 + (s1[j] - 'a');
                    }
            }

            //跳转到下一个
            i = i + k - 1;
        }
        if(num != 0)
        {
            count++;
        }
        if(count != 0)
        {
            printf("%u ",num);
        }


    }

    if(count == 0)
    {
        printf("-1");
    }


}
