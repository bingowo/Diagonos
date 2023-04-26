#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[55];
    scanf("%s",s);
    int a=0;        //max
    int b=1;         //每一次的长度
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]!=s[i+1]){
            b++;
        }else{
            if(b>a){
                a=b;
            }
            b=1;
        }
    }
    printf("%d",a);
    return 0;
}
