#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[20];
    int a=0,b=0,c=0,d=0,flag1=1,flag2=1,flag3=1,flag4=1;
    while((scanf("%s",s))!=EOF)
    {
        if(strstr(s,"IN")&&strstr(s,"AX"))
        {
            int k1=0;
            while(s[k1]<'0'||s[k1]>'9'&&s[k1]!='-') k1++;
            if(s[k1]=='-') {flag1=-1;k1++;}
            while(s[k1]>='0'&&s[k1]<='9'&&s[k1]!='\0') {a=a*10+s[k1];k1++;}
            a=a*flag1;
        }
        if(strstr(s,"IN")&&strstr(s,"BX"))
        {
            int k2=0;
            while(s[k2]<'0'||s[k2]>'9'&&s[k2]!='-') k2++;
            if(s[k2]=='-') {flag2=-1;k2++;}
            while(s[k2]>='0'&&s[k2]<='9'&&s[k2]!='\0') {b=b*10+s[k2];k2++;}
            b*=flag2;
        }
        if(strstr(s,"IN")&&strstr(s,"CX"))
        {
            int k3=0;
            while(s[k3]<'0'||s[k3]>'9'&&s[k3]!='-') k3++;
            if(s[k3]=='-') {flag3=-1;k3++;}
            while(s[k3]>='0'&&s[k3]<='9'&&s[k3]!='\0') {c=c*10+s[k3];k3++;}
            c*=flag3;
        }
        if(strstr(s,"IN")&&strstr(s,"DX"))
        {
            int k4=0;
            while(s[k4]<'0'||s[k4]>'9'&&s[k4]!='-') k4++;
            if(s[k4]=='-') {flag4=-1;k4++;}
            while(s[k4]>='0'&&s[k4]<='9'&&s[k4]!='\0') {d=d*10+s[k4];k4++;}
            d*=flag4;
        }
        if(strstr(s,"MOV"))
        {
            if(strstr(s,"AX")&&strstr(s,"BX"))
               {if(strstr(s,"AX")<strstr(s,"BX")) a=b;
                    else b=a;}
            if(strstr(s,"AX")&&strstr(s,"CX"))
               {if(strstr(s,"AX")<strstr(s,"CX")) a=c;
                    else c=a;}
            if(strstr(s,"AX")&&strstr(s,"DX"))
               {if(strstr(s,"AX")<strstr(s,"DX")) a=d;
                    else d=a;}
            if(strstr(s,"BX")&&strstr(s,"CX"))
               {if(strstr(s,"BX")<strstr(s,"CX")) b=c;
                    else c=b;}
            if(strstr(s,"BX")&&strstr(s,"DX"))
               {if(strstr(s,"BX")<strstr(s,"DX")) b=d;
                    else d=b;}
            if(strstr(s,"DX")&&strstr(s,"CX"))
               {if(strstr(s,"CX")<strstr(s,"DX")) c=d;
                    else d=c;}

        }
        if(strstr(s,"ADD"))
        {
            if(strstr(s,"AX")&&strstr(s,"BX"))
               {if(strstr(s,"AX")<strstr(s,"BX")) a+=b;
                    else b+=a;}
            if(strstr(s,"AX")&&strstr(s,"CX"))
               {if(strstr(s,"AX")<strstr(s,"CX")) a+=c;
                    else c+=a;}
            if(strstr(s,"AX")&&strstr(s,"DX"))
               {if(strstr(s,"AX")<strstr(s,"DX")) a+=d;
                    else d+=a;}
            if(strstr(s,"BX")&&strstr(s,"CX"))
               {if(strstr(s,"BX")<strstr(s,"CX")) b+=c;
                    else c+=b;}
            if(strstr(s,"BX")&&strstr(s,"DX"))
               {if(strstr(s,"BX")<strstr(s,"DX")) b+=d;
                    else d+=b;}
            if(strstr(s,"DX")&&strstr(s,"CX"))
               {if(strstr(s,"CX")<strstr(s,"DX")) c+=d;
                    else d+=c;}

        }
        if(strstr(s,"SUB"))
        {
            if(strstr(s,"AX")&&strstr(s,"BX"))
               {if(strstr(s,"AX")<strstr(s,"BX")) a-=b;
                    else b-=a;}
            if(strstr(s,"AX")&&strstr(s,"CX"))
               {if(strstr(s,"AX")<strstr(s,"CX")) a-=c;
                    else c-=a;}
            if(strstr(s,"AX")&&strstr(s,"DX"))
               {if(strstr(s,"AX")<strstr(s,"DX")) a-=d;
                    else d-=a;}
            if(strstr(s,"BX")&&strstr(s,"CX"))
               {if(strstr(s,"BX")<strstr(s,"CX")) b-=c;
                    else c-=b;}
            if(strstr(s,"BX")&&strstr(s,"DX"))
               {if(strstr(s,"BX")<strstr(s,"DX")) b-=d;
                    else d-=b;}
            if(strstr(s,"DX")&&strstr(s,"CX"))
               {if(strstr(s,"CX")<strstr(s,"DX")) c-=d;
                    else d-=c;}
        }
        if(strstr(s,"MUL"))
        {
            if(strstr(s,"AX")&&strstr(s,"BX"))
               {if(strstr(s,"AX")<strstr(s,"BX")) a*=b;
                    else b*=a;}
            if(strstr(s,"AX")&&strstr(s,"CX"))
               {if(strstr(s,"AX")<strstr(s,"CX")) a*=c;
                    else c*=a;}
            if(strstr(s,"AX")&&strstr(s,"DX"))
               {if(strstr(s,"AX")<strstr(s,"DX")) a*=d;
                    else d*=a;}
            if(strstr(s,"BX")&&strstr(s,"CX"))
               {if(strstr(s,"BX")<strstr(s,"CX")) b*=c;
                    else c*=b;}
            if(strstr(s,"BX")&&strstr(s,"DX"))
               {if(strstr(s,"BX")<strstr(s,"DX")) b*=d;
                    else d*=b;}
            if(strstr(s,"DX")&&strstr(s,"CX"))
               {if(strstr(s,"CX")<strstr(s,"DX")) c*=d;
                    else d*=c;}
        }
        if(strstr(s,"DIV"))
        {
            if(strstr(s,"AX")&&strstr(s,"BX"))
               {if(strstr(s,"AX")<strstr(s,"BX")) a/=b;
                    else b/=a;}
            if(strstr(s,"AX")&&strstr(s,"CX"))
               {if(strstr(s,"AX")<strstr(s,"CX")) a/=c;
                    else c/=a;}
            if(strstr(s,"AX")&&strstr(s,"DX"))
               {if(strstr(s,"AX")<strstr(s,"DX")) a/=d;
                    else d/=a;}
            if(strstr(s,"BX")&&strstr(s,"CX"))
               {if(strstr(s,"BX")<strstr(s,"CX")) b/=c;
                    else c/=b;}
            if(strstr(s,"BX")&&strstr(s,"DX"))
               {if(strstr(s,"BX")<strstr(s,"DX")) b/=d;
                    else d/=b;}
            if(strstr(s,"DX")&&strstr(s,"CX"))
               {if(strstr(s,"CX")<strstr(s,"DX")) c/=d;
                    else d/=c;}
        }
        if(strstr(s,"OUT"))
        {
            if(strstr(s,"AX")) printf("%d",a);
            if(strstr(s,"BX")) printf("%d",b);
            if(strstr(s,"CX")) printf("%d",c);
            if(strstr(s,"DX")) printf("%d",d);
        }




    }

    return 0;
}
