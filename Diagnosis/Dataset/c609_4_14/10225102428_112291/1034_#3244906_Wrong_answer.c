#include<stdio.h>
#include<string.h>
int main()
{
    char s[100000];
    scanf("%s",&s);
    int len=strlen(s);
    int num=0;
    for(int i=0;i<len;i++){
          if(s[i]=='0'){
                    if(s[i+1]=='x'){
                              for(int j=i+2;s[j]!='0'||s[j+1]!='x';j++){
                                        if(s[j]>='1'&&s[j]<='9')num=num*16+s[j]-'0';
                                        else if(s[j]>='a'&&s[j]<='f')num=num*16+s[j]-'a'+10;
                                        else break;
                              }
                              printf("%d ",num);
                    }
          }
    }
    if(num==0)printf("-1");

    return 0;
}

