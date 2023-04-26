#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[20];
    int a=0,b=0,c=0,d=0;
    while(scanf("%s",s)!=EOF)
    {
        if(strstr(s,"IN")&&strstr(s,"AX")) 
        {
            int k1=0;
            while(s[k1]<'0'||s[k1]>'9') k1++;
            while(s[k1]>='0'&&s[k1]<='9'&&s[k1]!='\0') {a=a*10+s[k1];k1++;}
        }
        if(strstr(s,"IN")&&strstr(s,"BX")) 
        {
            int k2=0;
            while(s[k2]<'0'||s[k2]>'9') k2++;
            while(s[k2]>='0'&&s[k2]<='9'&&s[k2]!='\0') {b=b*10+s[k2];k2++;}
        }
        if(strstr(s,"IN")&&strstr(s,"CX")) 
        {
            int k3=0;
            while(s[k3]<'0'||s[k3]>'9') k3++;
            while(s[k3]>='0'&&s[k3]<='9'&&s[k3]!='\0') {c=c*10+s[k3];k3++;}
        }
        if(strstr(s,"IN")&&strstr(s,"DX")) 
        {
            int k4=0;
            while(s[k4]<'0'||s[k4]>'9') k4++;
            while(s[k4]>='0'&&s[k4]<='9'&&s[k4]!='\0') {d=d*10+s[k4];k4++;}
        }
        if(strstr(s,"MOV"))
        {
            
        }
        
        
        
        
    }
    
    return 0;
}
