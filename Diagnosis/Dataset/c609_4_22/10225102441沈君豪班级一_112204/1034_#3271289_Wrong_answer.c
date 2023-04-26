#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[10010];
    scanf("%s",s);
    int key=0;                        //判断是否无输出
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='0'){
            int x=0;                        //x存储十进制的值
            int j;
            for(j=i+1;s[j]=='0';j++);      //排掉前面的0
            if(s[j]=='x'){                 //找到你啦
                for(int k=j+1;k<strlen(s);k++){
                    if(s[k]>=48&&s[k]<58){
                        x=x*16+s[k]-'0';
                    }else if(s[k]>96&&s[k]<103){
                        x=x*16+s[k]-87;
                    }else{
                        break;
                    }
                }
            }
            if(x!=0){
                printf("%d ",x);
                key++;
            }
        }
    }
    if(key==0){
        printf("-1");
    }
    return 0;
}
