#include<stdio.h>
#include<string.h>
int main()
{
    char s[51];
    int chang;
    scanf("%s",&s);
    chang=strlen(s);
    s[chang]=-1;
    int max=1,length=1;
    for(int p1=0,p2=1;s[p1]!=-1&&s[p2]!=-1;p1++,p2++){
        if(s[p1]!=s[p2])//不重复的时候
        length++;
        else{//重复情况
            if(length>max)
            max=length;//更新最大长度
            length=1;
        }
    }
    if(max<length)
    max=length;
    printf("%d",max);
    return 0;
}