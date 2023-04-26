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
    int l=0;
    for(i=0;i<len;i++){
          if(s[i]=='0'){
                    if(s[i+1]=='x'){
                              i=i+2;
                              if(flag==1)printf("%u ",num);
                              flag=1;
                              l++;
                    }
          }
          if(flag=1){
                    if(s[i]>='0'&&s[i]<='9')num=num*16+s[i]-'0';
                    else if(s[i]>='a'&&s[i]<='f')num=num*16+s[i]-'a'+10;
                    else printf("%u ",num),l++,flag=-1;
          }

    }
    if(flag==1) printf("%u ",num),l++;
    if(num==0&&l==0)printf("-1");
    return 0;
}

