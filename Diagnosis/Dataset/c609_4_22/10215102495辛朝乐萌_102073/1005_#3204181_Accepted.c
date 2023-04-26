#include <stdio.h>
#include <string.h>

int cal(char c)
{
    int res;
    if(c=='-') res=-1;
    else if(c=='0') res=0;
    else  res=1;
    return res;
}

int suan(char s[])
{
    int num=0;
    int ch=1;
    if(strlen(s)==1 && s[0]=='0')  printf("0");
    else{
        for(int i= strlen(s)-1;i>=0;i--){
            num += cal(s[i])*ch;
            ch=ch*3;
        }
    }
    return num;
}

int main() {
    int t;
    int num=0;
    int ch=1;
    char s[10000];
    scanf("%d",&t);
    for (int i = 0; i < t; i++) {
        scanf("%s",s);
        num= suan(s);
        printf("case #%d:\n%d\n",i,num);
    }

    return 0;
}