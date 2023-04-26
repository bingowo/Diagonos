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
        double num1=0,num2=0,num3=0;
        gets(s);
        int len=(int)strlen(s);
        int c=0,d=0,k=0,dian=0,readnum=0;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]<='9'&&s[i]>='0' && dian==0) 
            {num2=num2/10+(s[i]-'0');num3+=(s[i]-'0')*pow(10,c++);readnum=1;}
            if(s[i]<='9'&&s[i]>='0' && dian==1){num1+=(s[i]-'0')*pow(10,d++);readnum=1;}
            else if(s[i]=='.') dian=1;
            else if(s[i]==' ' && dian==1) 
            {L[k++]=num1+num2/10;dian=0;num1=0;num2=0;num3=0;readnum=0;c=0;d=0;}
            else if(s[i]==' ' && dian==0 && readnum==1)
            {L[k++]=num3;dian=0;num1=0;num2=0;num3=0;readnum=0;c=0;d=0;}
            else if(s[i]=='+') {L[k-2]=L[k-1]+L[k-2];k--;}
            else if(s[i]=='-') {L[k-2]=L[k-1]-L[k-2];k--;}
            else if(s[i]=='*') {L[k-2]=L[k-2]*L[k-1];k--;}
            else if(s[i]=='/') {L[k-2]=L[k-1]/L[k-2];k--;}
        }
        printf("case #%d:\n",m);
        printf("%.6lf\n",L[0]);
    }
    return 0;
}