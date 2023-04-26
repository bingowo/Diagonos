#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[55];
    scanf("%s",s);
    int a=1;        //max
    int b=1;         //每一次的长度
    int len=strlen(s);
    for(int i=0;i<len-1;i++){
        if(s[i]!=s[i+1]){
            b++;
        }else{
            if(b>a){
                a=b;
            }
            b=1;
        }
    }
    if(b>a){
        a=b;            //排掉最后的不等不经过else
    }
    printf("%d",a);
    return 0;
}
