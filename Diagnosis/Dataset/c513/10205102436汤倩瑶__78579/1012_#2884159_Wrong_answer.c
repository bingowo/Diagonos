#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char s[100];
scanf("%s",s);
int l=strlen(s);
long long int a=0,b=0;
if(s[l-1]!='i')
{
    b=0;
    if(s[0]=='-'){
        for(int i=1;i<l;i++)
            a=a*10+s[i]-'0';
        a=-a;
    }
    else {for(int i=0;i<l;i++)
            a=a*10+s[i]-'0';
        }
}
else {
        if(s[0]=='-'){
            int i;
        for(i=1;s[i]!='-'&&s[i]!='+';i++)
            a=a*10+s[i]-'0';
        a=-a;
if(s[i]=='-'){
         for(int j=i+1;i<l-1;i++)
            b=b*10+s[j]-'0';
        b=-b;
}
else {
         for(int j=i+1;i<l-1;i++)
            b=b*10+s[j]-'0';
}



    }
    else {int i;
        for(i=0;s[i]!='-'&&s[i]!='+';i++)
            a=a*10+s[i]-'0';
    if(s[i]=='-'){
         for(int j=i+1;i<l-1;i++)
            b=b*10+s[j]-'0';
        b=-b;
}
else {
         for(int j=i+1;i<l-1;i++)
            b=b*10+s[j]-'0';
}

        }

}
printf("%lld %lld",a,b);
}
