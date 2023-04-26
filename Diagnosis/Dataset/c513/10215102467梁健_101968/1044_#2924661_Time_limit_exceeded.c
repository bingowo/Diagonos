#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[100001];
    scanf("%s",s);
    int count=0;char res[17];unsigned int RES=0;int judge=-1;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='0'&s[i+1]=='x'){
            for(int m=i+2;m<strlen(s);m++){
                if(s[m]>'f'&&s[m]!='x')break;
                if(s[m]=='0'&&s[m+1]=='x'&&(('0'<=s[m+2]&&s[m+2]<='9')||('a'<=s[m+2]&&s[m+2]<='f')))break;
                res[m-i-2]=s[m];
            }
            for(int p=0;p<strlen(res);p++){
                if(isdigit(res[p])){RES=16*RES+res[p]-48;judge=1;}
                else if('a'<=res[p]&&res[p]<='f'){RES=16*RES+res[p]-87;judge=1;}
                else break;
            }
            if(judge>0){count++;printf("%u ",RES);}
            for(int step=0;step<17;step++)res[step]=0;RES=0;judge=-1;
        }
    }
    if(count==0)printf("-1");
    return 0;
}
