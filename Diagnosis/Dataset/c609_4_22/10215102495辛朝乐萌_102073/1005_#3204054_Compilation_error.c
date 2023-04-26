#include <stdio.h>
#include <string.h>

int cal(char c)
{
    int res;
    if(c=='-') res=-1;
    if(c=='0') res=0;
    if(c=='1') res=1;
}

int main() {
    int t;
    int num=0;
    int ch=1;
    char s[10000];
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%s",s);
        printf("case #%d:\n",i);
        if(strlen(s)==0&&s[0]='0') printf("0");
        else{
            for(int i= strlen(s)-1;i>=0;i--){
                num+= cal(s[i])*ch;
                ch=ch*3;
            }
        }
        printf("%d\n",num);
    }

    return 0;
}

