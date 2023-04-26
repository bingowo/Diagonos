#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int invert(char s)
{
    if(s>='a'&&s<='f')return s-'a'+10;
    else if(s>='0'&&s<='9')return s-'0';
    else return -1;
}

int main()
{
    char s[100001];
    scanf("%s",s);
    unsigned int aa[50000];
    int num=0;
    int count=0;
    int flag=0;
    int i=0,m;
    for(i=0;s[i]!='\0';i++){
          if(s[i]=='0'){
                    if(s[i+1]=='x'){
                              if(invert(s[i+2])!=-1){
                                  if(flag)aa[count++]=num,num=0,flag=0;
                              }
                              flag=1;
                              i+=2;
                    }
          }
          if(flag){
                    m=invert(s[i]);
                    if(m!=-1)num=num*16+m;
                    else {aa[count++]=num;flag=0;num=0;}
          }

          if(flag) aa[count++]=num;
          if(count>0){
              for(int i=0;i<count;i++)printf("%u ",aa[i]);
          }
          else printf("-1");
          return 0;
    }
}
