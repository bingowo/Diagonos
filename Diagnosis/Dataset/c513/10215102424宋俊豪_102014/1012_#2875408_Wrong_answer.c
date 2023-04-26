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
    for(i=1; i<strlen(s); i++)
        if (s[i]=='+'||s[i]=='-')
            k=i;
    if (strchr(s,'i')==NULL)
    {
        a=atol(s);
        b=0;
    }
    else
    {
        if (k==0)
        {
            if (s[0]=='i')
            {
                a=0;
                b=1;
            }
            else if (s[0]='-'&&s[1]=='i')
            {
                a=0;
                b=-1;
            }
            else
            {
                a=0;
                b=atol(s);
            }
        }
        else
        {
            for(i=1; i<strlen(s); i++)
            {
                if (s[i]=='+')
                {

                    a=atol(s);
                    if (s[i+1]=='i')
                        b=1;
                    else{
                    for (int j=i+1; j<strlen(s)-1; j++)
                        y[j-i-1]=s[j];
                    y[strlen(s)-2-i]='\0';
                    b=atol(y);
                    }
                }
                else if (s[i]=='-')
                {
                    a=atol(s);
                    if (s[i+1]=='i')
                        b=-1;
                    else{
                    for (int j=i+1; j<strlen(s)-1; j++)
                        y[j-i-1]=s[j];
                    y[strlen(s)-2-i]='\0';
                    b=-atol(y);
                    }
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

