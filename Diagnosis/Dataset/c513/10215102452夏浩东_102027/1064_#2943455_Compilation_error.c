#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int cnt=0;
    char ch;
    scanf("%d%c",&cnt,&ch);
    for(int m=0;m<cnt;m++)
    {
        char s[101];
        double L[100]={-1};
        double num1=0,num2=0;
        gets(s);
        int len=(int)strlen(s);
        int c=0,k=0,dian=0;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]<='9'&&s[i]>='0' && dian=0) {num2=num2+(s[i]-'0')*10;c++;}
            else if(s[i]<='9'&&s[i]>='0' && dian==1){num1=num1*10+(s[i]-'0');}
            else if(s[i]=='.') {num2=num2/pow(10,c);dian=1;}
            else if(s[i]==' ') {L[k++]=num1+num2;dian=0;num1=0;num2=0;}
            else if(s[i]=='+') {L[k-2]=L[k-1]+L[k-2];k--;}
            else if(s[i]=='-') {L[k-2]=L[k-2]-L[k-1];k--;}
            else if(s[i]=='*') {L[k-2]=L[k-2]*L[k-1];k--;}
            else if(s[i]=='/') {L[k-2]=L[k-2]/L[k-1];k--;}
        }
        printf("case #%d:\n",m);
        printf("%.6lf\n",L[0]);
    }
    return 0;
}