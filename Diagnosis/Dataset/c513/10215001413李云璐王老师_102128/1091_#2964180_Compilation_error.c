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
    int ss[10000]={0},ff[10000]={0},ss1[10000]={0},ff1[10000]={0};
    ss[0]=1;ff[0]=1;
    int wei1=1,wei2=1,wei3=1,wei4=1;
    int yu1=0,yu2=0;
    for(int k=0;k<n;k++)
    {
        yu=0;
        for(int l=0;l<wei1;l++)
        {
            int c=ss1[1];
            ss1[l]=(ss1[l]*a+yu)%10;
            yu=(c*a+yu)/10;
        }
        while(yu>0){ss1[wei1]=yu;wei1++;yu/=10;}
        for(int l=0;l<wei2;l++)
        {
            int c=ff1[l];
            ff1[l]=(ff1[l]*b+yu)%10;
            yu=(c*b+yu)/10;
        }
        while(yu>0) {ff1[wei2]=yu;wei2++;yu/=10;}
        
    }
    
    
    
    
}