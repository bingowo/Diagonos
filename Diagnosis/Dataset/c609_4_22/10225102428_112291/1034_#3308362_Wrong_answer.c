#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[100001];
    scanf("%s",s);
    int len=strlen(s);
    unsigned int aa[50000];
    int num=0;
    int count=0;
    int flag=0;
    int i=0;
    for(i=0;i<len;i++){
        if(s[i]=='0'){
                if(s[i+1]=='x'&&!(s[i+2]>='0'&&s[i+2]<='9'||s[i+2]>='a'&&s[i+2]<='f')){
//                              if(s[i]>='0'&&s[i]<='9'){
//                                  if(flag)aa[count++]=num,num=0,flag=0;
//
//                              }
//                              else if(s[i]>='a'&&s[i]<='f'){
//                                  if(flag)aa[count++]=num,num=0,flag=0;
//                              }
                        flag=1;
                }else if(s[i+1]=='x'&&((s[i+2]>='0'&&s[i+2]<='9')||(s[i+2]>='a'&&s[i+2]<='f'))){
                        flag=1;
                        i+=2;
                }

          }

        if(flag){
                if(s[i]>='0'&&s[i]<='9')num=num*16+s[i]-'0';
                else if(s[i]>='a'&&s[i]<='f')num=num*16+s[i]-'a'+10;
                else {
                        if(num!=0)aa[count++]=num,flag=0,num=0;
                        else flag=0;
                }
          }
    }
    if(flag) aa[count++]=num;
    if(count>0){
        for(int i=0;i<count;i++)printf("%u ",aa[i]);
    }
    else printf("-1");
    return 0;
}