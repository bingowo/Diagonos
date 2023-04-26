#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[20];
    scanf("%s",s);
    int x=0;
    char s1[20]={'\0'};
    if(s[x]=='-'||s[x]=='+'){
        int y=0;
        while(x<strlen(s)){
            s1[y]=s[x];
            y++;
            x++;
        }
    }
    else{
        s1[0]='+';
        int y=1;
        while(x<strlen(s)){
            s1[y]=s[x];
            y++;
            x++;
        }
    }
    int a,b,c;
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]=='+'||s1[i]=='-'){
            int flag=1;
            if(s1[i]=='+'){flag=1;}
            else if(s1[i]=='-'){flag=-1;}
            int sum=0;
            int j=i+1;
            while(isdigit(s1[j])){
                sum=sum*10+s1[j]-48;
                j++;
            }
            sum=sum*flag;
            if(sum==0&&s1[j-1]!='0')sum=flag;
            if(s1[j]=='x'){
                if(s1[j+2]=='2'){
                    a=sum;
                }
                else{
                    b=sum;
                }
            }
            else{
                c=sum;
            }
        }
    }
    //printf("%d %d %d %d\n",p[3],p[2],p[1],p[0]);

}
