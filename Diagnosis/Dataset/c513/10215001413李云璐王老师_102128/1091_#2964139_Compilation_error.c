#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[20];
    int n;
    scanf("%s",s);
    scanf("%d",&n);
    int len=strlen(s),a,b,z=0,f1=1,f2=1,i=0;
    while(i<len)
    {
        if(s[i]=='-') {f1=-1;i++;}
        while(s[i]!='-'&&s[i]!='+'&&s[i]!='\0'&&s[i]!='i')
            {z=z*10+s[i]-48;i++;}
        if(s[i]=='i') 
        {
            if(z==0) b=1*f1;
            else b=z*f1;
        }
        else 
            {
                a=z*f1;
                if(s[i]=='-') f2=-1;
                i++;
                z=0;
                while(s[i]!='\0'&&s[i]!='i')
                    z=z*10+s[i]-48;
                if(s[i]='i')
                {
                    if(z==0) b=1*f2;
                    else b=z*f2;
                }
            }
    }
    int ss[10000]={0},ff[10000]={0};
    ss[0]=1;ff[0]=1;wei1=1;wei2=1;
    int yu1=0,yu2=0;
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<wei1;l++)
        {
            ss[l]=ss[l]*a
        }
    }
    
    
    
    
}