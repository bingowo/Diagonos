#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[2000],x[2000],y[2000];
    int k=0;
    scanf("%s",s);
    char t[1000];
    long long int r,qr=1,qi=1;
    long long int a,b,num;
    int i;
    num=0;
    if (strchr(s,'i')==0)
    {
        a=atol(s);
        b=0;
    }
    else
    {
        if (strchr(s,'+')==0||strchr(s,'-')==0)
        {
            a=0;
            b=atol(s);
        }
        else if (strchr(s,'-')==1)
        {
            a=0;
            b=atol(s);
        }
        else
        {
            for(i=1; i<strlen(s); i++)
            {
                if (s[i]=='+')
                {
                    for (int j=0; j<i; j++)
                        x[j]=s[j];
                    x[i]='\0';
                    for (int j=i+1; j<strlen(s)-1; j++)
                        y[j-i-1]=s[j];
                    y[strlen(s)-2-i]='\0';
                    a=atol(x);
                    b=atol(y);
                }
                else if (s[i]=='-')
                {
                    for (int j=0; j<i; j++)
                        x[j]=s[j];
                    x[i]='\0';
                    for (int j=i+1; j<strlen(s)-1; j++)
                        y[j-i-1]=s[j];
                    y[strlen(s)-2-i]='\0';
                    a=atol(x);
                    b=-atol(y);
                }
            }
        }
    }

    while((qr!=0)||(qi!=0))
    {
        if (labs(a%2)==labs(b%2))
            r=0;
        else
            r=1;
        qi=(r-a-b)/2;
        qr=(r+b-a)/2;
        a=qr;
        b=qi;
        t[num++]=r+'0';
    }
    t[num]='\0';
    for(int i=num-1; i>=0; i--)
        printf("%c",t[i]);
    return 0;
}


