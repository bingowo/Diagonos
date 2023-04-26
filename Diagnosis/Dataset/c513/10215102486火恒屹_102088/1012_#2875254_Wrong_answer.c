#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100]={'0'};
    scanf("%s",&a);
    int real;
    int com;
    int flag=-1;
    char store[100]={'0'};
    char store1[100]={'0'};
    for(int i=0;i<100;i++)
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
                {store[99-c]=a[i];
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
                    store[99-c]=a[i];
                    c=c+1;
                    real=0;
                    com=atoi(store);
                }
            }
        }
    }
    char res[101]={'\0'};
    for(int i=0;i<100;i++)
        res[i]='0';
    int u=0;
    while((real!=0)||(com!=0))
    {
        if(abs(real)%2==abs(com)%2)
        {
            res[99-u]='0';
            u++;
            int tmpt=real;
            real=(-real+com)/2;
            com=-(tmpt+com)/2;
        }
        else
        {
            res[99-u]='1';
            u++;
            real=real-1;
            int tmpt=real;
            real=(-real+com)/2;
            com=-(tmpt+com)/2;
        }
    }

    printf("%d\n",atoi(res));
    return 0;
}
