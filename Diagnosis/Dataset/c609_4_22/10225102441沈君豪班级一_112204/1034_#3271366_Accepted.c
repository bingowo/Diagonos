#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100100];
    scanf("%s",s);
    int key=0;                        //判断是否输出
    int cao=0;                          //判断有无输出
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='0'){
            long long int x=0;                        //x存储十进制的值
            int j;
            for(j=i+1;s[j]=='0';j++){
                i++;
            }      //排掉前面的0
            i++;
            if(s[j]=='x'){                //找到你啦
                for(int k=j+1;k<strlen(s);k++){
                    if(s[k]>=48&&s[k]<58){
                        x=x*16+s[k]-'0';
                        i++;
                        key++;
                    }else if(s[k]>96&&s[k]<103){
                        x=x*16+s[k]-87;
                        i++;
                        key++;
                    }else{
                        i++;
                        break;
                    }
                }
                if(key>0){
                    printf("%lld ",x);
                    key=0;
                    cao=1;
                }
            }
        }
    }
    if(cao==0){
        printf("-1");
    }
    return 0;
}
