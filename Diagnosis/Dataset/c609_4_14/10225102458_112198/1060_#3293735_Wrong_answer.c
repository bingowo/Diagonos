#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[110],ss[240];
    int count=1,cnt=0;
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;s[i+1]!='\0';){
        while(s[i+1]!='\0'&&s[i]==s[i+1]){count++;i++;}
        if(s[i]<s[i+1]){for(int j=0;j<count;j++){ss[cnt++]=s[i];ss[cnt++]=s[i];}i++;count=1;}
        else if(s[i]>s[i+1]){for(int j=0;j<count;j++){ss[cnt++]=s[i];}i++;count=1;}
        else {count--;for(int j=0;j<count;j++){ss[cnt++]=s[i];}i++;count=1;}
    }
    ss[cnt]='\0';
    printf("%s\n",ss);
    return 0;
}
