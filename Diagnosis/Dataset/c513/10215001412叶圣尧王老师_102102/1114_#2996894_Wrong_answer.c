#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[50];scanf("%s",s);
    int i,j,a[3]={0},t;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='-')
        {
            if(s[i+1]=='x')
            {
                if(s[i+2]=='^'){a[2]=-1;i+=3;}
                else {a[1]=-1;i+=1;}
            }
            else
            {
                t=0;
                for(j=i+1;isdigit(s[j])&&j<strlen(s);j++)
                    t=t*10+s[j]-'0';
                if(j==strlen(s)){a[0]=t*-1;i=j;}
                else
                {
                    if(s[j+1]=='^'){a[2]=-1*t;i=j+2;}
                    else {a[1]=t*-1;i=j;}
                }
            }
        }
        else if(s[i]=='+')
        {
            if(s[i+1]=='x')
            {
                if(s[i+2]=='^'){a[2]=1;i+=3;}
                else {a[1]=1;i+=1;}
            }
            else
            {
                t=0;
                for(j=i+1;isdigit(s[j])&&j<strlen(s);j++)
                    t=t*10+s[j]-'0';
                if(j==strlen(s)){a[0]=t;i=j;}
                else
                {
                    if(s[j+1]=='^'){a[2]=t;i=j+2;}
                    else {a[1]=t;i=j;}
                }
            }
        }
        else if(isdigit(s[i]))
        {
            t=s[i]-'0';
            if(s[i+1]=='x')
            {
                if(s[i+2]=='^'){a[2]=t;i+=3;}
                else {a[1]=t;i+=1;}
            }
            else
            {
                t=0;
                for(j=i;isdigit(s[j])&&j<strlen(s);j++)
                    t=t*10+s[j]-'0';
                if(j==strlen(s)){a[0]=t;i=j;}
                else
                {
                    if(s[j+1]=='^'){a[2]=t;i=j+2;}
                    else {a[1]=t;i=j;}
                }
            }
        }
    }
    int a1,c1,a2,c2;
    printf("%d %d %d",a[2],a[1],a[0]);
}
