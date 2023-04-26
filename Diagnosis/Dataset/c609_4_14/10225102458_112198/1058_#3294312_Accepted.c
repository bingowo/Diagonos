#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    char s[120];
    int num[120],binary[500];
    int flag=1,cnt=0,y,c,begin=0,count=0;
    scanf("%s",s);
    if(s[0]=='-')flag=-1;
    for(int i=0;s[i]!='\0';i++){if(s[i]!='-'&&s[i]!='+')num[cnt++]=s[i]-'0';}
    while(begin!=cnt){
        y=0;
        for(int i=begin;i<cnt;i++){
        c=y*10+num[i];
        num[i]=c/2;
        y=c%2;
        }
        if(y==1){
            if(flag==-1)num[cnt-1]++;
            binary[count++]=1;
        }
        else binary[count++]=0;
        while(num[begin]==0&&begin<cnt){begin++;}
        flag*=-1;
    }
    for(int i=count-1;i>=0;i--)printf("%d",binary[i]);

    return 0;
}
