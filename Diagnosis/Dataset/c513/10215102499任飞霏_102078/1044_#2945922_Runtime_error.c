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
    int i=0,flag=-1;
    int len=strlen(s);
    while(i<len){
        int res=-1;
        while(!(s[i]=='0'&&s[i+1]=='x')&&i<len){
            i++;
        }

        if(s[i]=='0'&&s[i+1]=='x')i+=2;
        if((s[i]>'9'&&s[i]<'a')||s[i]>'f'){
                i++;
        }
        else{
            if(i>=len)break;
            flag=1;
            char tmp[100]={0};
            int j=0;
            while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f'))
            {
                tmp[j++]=s[i++];
            }
            res=sixteen2ten(tmp);
            }
            if(res!=-1)printf("%d ",res);

    }
    if(flag==-1)printf("%d",flag);
    return 0;
}


