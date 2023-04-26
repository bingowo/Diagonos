#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *s, *temp;
    int count=0, ret;
    long long sum;
    s = (char*)malloc(sizeof(char)*100001);
    scanf("%s", s);
    temp = strstr(s,"0x");
    sum = -1; //防止s中一个0x都没有，而sum又刚刚好不等于-1直接输出
    while(temp){
        sum = -1; //标记未开始出现合法
        if(!(temp[2]>='0'&&temp[2]<='9') && !(temp[2]>='a'&&temp[2]<='f')){//非法16进制
            temp = strstr(temp+2,"0x");
            continue;
        }
        sum = 0;
        ret = 2;
        while(1){
            if(temp[ret]>='0'&&temp[ret]<='9') sum = sum*16+(int)temp[ret]-48;
            else if(temp[ret]>='a'&&temp[ret]<='f') sum = sum*16+(int)temp[ret]-87;
            else{
                printf("%lld ", sum);
                count++;
                sum = -1; //标记未开始出现合法
                break;
            }
            ret++;
        }
        temp = strstr(temp+2,"0x"); //注意这个+2，要跳过当前的0x
    }
    if(sum!=-1){
        printf("%lld", sum);
        count++;
    }
    if(count==0) printf("%d", -1);
    free(s);
    return 0;
}