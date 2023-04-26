#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sixteen2ten(char* s)
{
    int res=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0' && s[i]<='9'){
            res=res*16+(s[i]-'0');
        }
        else{
            res=res*16+(10+s[i]-'a');
        }
    }
    return res;
}

int main()
{
    char s[1000];
    scanf("%s",s);
    int i=0,res=0;
    int len=strlen(s);
    while(i<len){
        while(!(s[i]=='0'&&s[i+1]=='x'))i++;
        if(s[i]=='0'&&s[i+1]=='x')i+=2;
        char tmp[100]={0};
        int j=0;
        while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f'))
        {
            tmp[j++]=s[i++];
        }
        res=sixteen2ten(tmp);
        printf("%d ",res);

    }
    return 0;
}


