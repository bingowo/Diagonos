#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[1000]={'\0'};
    scanf("%s",&a);
    long long real;
    long long com;
    int flag=-1;
    char store[1000]={'\0'};
    char store1[1000]={'\0'};
    for(int i=0;i<999;i++)
        store[i]='0';
    if(a[strlen(a)-1]=='i')
        flag=1;
    if(flag!=1)
    {
        real=atoi(a);
        com=0;
    }
    else
    {
        if(strlen(a)==1)
        {
            real=0;
            com=1;
        }
        else if((strlen(a)==2)&&(a[0]=='-'))
        {
            real=0;
            com=-1;
        }
        else if((strlen(a)==2)&&(a[0]!='-'))
        {
            real=0;
            com=a[0]-'0';
        }
        else if(a[strlen(a)-2]=='+')
        {
            com=1;
            for(int j=0;j<strlen(a)-2;j++)
                store1[j]=a[j];
            real=atoi(store1);
        }
        else if(a[strlen(a)-2]=='-')
        {
            com=-1;
            for(int j=0;j<strlen(a)-2;j++)
                store1[j]=a[j];
            real=atoi(store1);
        }
        else
        {
            int c=0;
            for(int i=strlen(a)-2;i>=0;i=i-1)
            {
                if((a[i]>='0')&&(a[i]<='9')&&(i!=0))
                {store[999-c]=a[i];
                c=c+1;}
                else if(a[i]=='+')
                {
                    com=atoi(store);
                    for(int j=0;j<i;j++)
                        store1[j]=a[j];
                    real=atoi(store1);
                    break;
                }
                else if((a[i]=='-')&&(i!=0))
                {
                    com=-atoi(store);
                    for(int j=0;j<i;j++)
                        store1[j]=a[j];
                    real=atoi(store1);
                    break;
                }
                else if((a[i]=='-')&&(i==0))
                {
                    com=-atoi(store);
                    real=0;
                }
                else if((a[i]>='0')&&(a[i]<='9')&&(i==0))
                {
                    store[999-c]=a[i];
                    c=c+1;
                    real=0;
                    com=atoi(store);
                }
            }
        }
    }
    char res[1001]={'\0'};
    int u=0;
    while((real!=0)||(com!=0))
    {
        if(abs(real)%2==abs(com)%2)
        {
            res[u]='0';
            u++;
            long long tmpt=real;
            real=(-real+com)/2;
            com=-(tmpt+com)/2;
        }
        else
        {
            res[u]='1';
            u++;
            real=real-1;
            long long tmpt=real;
            real=(-real+com)/2;
            com=-(tmpt+com)/2;
        }
    }
    for(int i=strlen(res)-1;i>=0;i=i-1)
    printf("%c",res[i]);
    return 0;
}
