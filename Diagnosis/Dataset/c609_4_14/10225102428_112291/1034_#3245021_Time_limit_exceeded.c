#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001];
    scanf("%s",&s);
    int len=strlen(s);
    unsigned int num=0;
    int flag=-1;
    int i=0;
    for(i=0;i<len;i++){
          if(s[i]=='0'){
                    if(s[i+1]=='x'){
                              i=i+2;
                              flag=1;
                    }
          }
          while(flag=1){
                    if(s[i]>='0'&&s[i]<='9')num=num*16+s[i]-'0',i++;
                    else if(s[i]>='a'&&s[i]<='f')num=num*16+s[i]-'a'+10,i++;
                    else if(s[i]=='0'&&s[i+1]=='x')flag=-1;
                    else if(i<len-1)flag=-1;
          }
          printf("%u ",num);

    }
    if(num==0)printf("-1");
    return 0;
}