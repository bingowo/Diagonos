#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001];
    scanf("%s",&s);
    int len=strlen(s);
    int num=0;
    int count=0;
    int flag=-1;
    int i=0;
    int l=0;
    for(i=0;i<len;i++){
          if(s[i]=='0'){
                    if(s[i+1]=='x'){
                              if(s[i]>='0'&&s[i]<='9'){
                                  if(flag=1)aa[count++]=num;
                                  num=0;
                                  flag=-1;
                              }
                              else if(s[i]>='a'&&s[i]<='f'){
                                  if(flag=1)aa[count++]=num;
                                  num=0;
                                  flag=-1;
                              }
                              flag=1;
                              i+=2;
                    }
          }
          if(flag=1){
                    if(s[i]>='0'&&s[i]<='9')num=num*16+s[i]-'0';
                    else if(s[i]>='a'&&s[i]<='f')num=num*16+s[i]-'a'+10;
                    else aa[count++]=num,flag=-1,num=0;
          }

    }
    if(flag==1) aa[count++]=num;
    if(count>0){
        for(int i=0;i<count;i++)printf("%u",aa[i]);
    }
    else printf("-1");
    return 0;
}

