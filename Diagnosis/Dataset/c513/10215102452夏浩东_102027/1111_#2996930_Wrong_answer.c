#include <stdio.h>
#include <string.h>
int main()
{
    char s[50];
    char L[41][41];
    int count = 0;
    while(scanf("%s",s)!=EOF){
        if(count==1) printf("\n");
        count=1;
        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++){
                if(i!=20 && j!=20) L[i][j]='.';
                else if(i==20){
                    if(j==40) L[i][j]='>';
                    else L[i][j]='-';
                }else if(j==20){
                    if(i==0) L[i][j]='^';
                    else L[i][j]='|';
                }
            }
        }
        int NL[4],flag=1,num=0;
        for(int i=0;i<4;i++) NL[i]=0;
        for(int i=5;i<(int)strlen(s);i++){
            if(s[i]=='-') flag=-1;
            else if(s[i]<='9'&&s[i]>='0') num=num*10+s[i]-'0';
            else if(s[i]=='x'){
                if(s[i+1]=='^'){
                    num= num==0?1:num;
                    NL[s[i+2]-'0']=flag*num;
                    num=0;
                    flag=1;
                    i+=2;
                }else if(s[i+1]!='^'){
                    num= num==0?1:num;
                    NL[1]=flag*num;
                    num=0;
                    flag=1;
                }
            }
        }
        NL[0]=num*flag;
        for(int i=-20;i<=20;i++){
            int num = NL[0]+NL[1]*i+NL[2]*i*i+NL[3]*i*i*i;
            if(num<=20 && num>=-20) L[20-num][i+20]='*';
        }
        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++){
                printf("%c",L[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}