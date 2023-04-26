#include <stdio.h>
int main()
{
    char s[80];
    int xishu=0,shuzi=0,den=0,flag=1,num=0;
    scanf("%s",s);
    char c='0';
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='='){
            den=1;
            if(num!=0){
            shuzi-=flag*num;
            num=0;flag=1;
            }
        } 
        else if(s[i]=='-'){
            if(num!=0){
                if(den==0) shuzi-=flag*num;
                else shuzi+=flag*num;
                num=0;  
            }
            flag=-1;
        }
        else if(s[i]=='+' && num!=0){
            if(den==0) shuzi-=flag*num;
            else shuzi+=flag*num;
            num=0;flag=1;
        }
        else if(s[i]<='9'&&s[i]>='0') num=num*10+s[i]-'0';
        else if(s[i]<='z'&&s[i]>='a'){
            c=s[i];
            if(den==0){
                if(num==0) xishu+=flag;
                else xishu+=flag*num;
            }else{
                if(num==0) xishu-=flag;
                else xishu-=flag*num;
            }
            num=0;flag=1;
        }
    }
    shuzi+=flag*num;
    double res= 1.0*shuzi/xishu;
    printf("%c=%.3f",c,res);
    return 0;
}