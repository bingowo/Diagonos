#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    char c;
    scanf("%s",s);
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]>='a'&&s[i]<='z'){c=s[i];break;}


    }

    int fz=0,fm=0;
    int i=0;
    int flag=1;
    int sum=0;
    while(s[i]!='=')
    {
        if(s[i]>='0'&&s[i]<='9')sum=sum*10+s[i]-'0';
        if(s[i]=='-')
        {
            if(s[i-1]==c&&i>=1)
            {   if(i==1)fm+=flag;
                else if((i>=2)&&(s[i-2]=='-'||s[i-2]=='+'))fm+=flag;
                else fm+=flag*sum;
            }
            else fz-=flag*sum;
            flag=-1;
            sum=0;
        }
        if(s[i]=='+')
        {
            if(s[i-1]==c&&i>=1)
            {
                if(i==1)fm+=flag;
                else if((i>=2)&&(s[i-2]=='-'||s[i-2]=='+'))fm+=flag;
                else fm+=flag*sum;
            }
            else fz-=flag*sum;
            flag=1;
            sum=0;
        }
        i++;
    }
    if(s[i-1]==c&&i>=1)
    {
        if(i==1)fm+=flag;
        else if((i>=2)&&(s[i-2]=='-'||s[i-2]=='+'))fm+=flag;
        else fm+=flag*sum;
    }
    else fz-=flag*sum;
    flag=1;
    sum=0;
    i++;
while(s[i]!='\0')
    {
        if(s[i]>='0'&&s[i]<='9')sum=sum*10+s[i]-'0';
        if(s[i]=='-')
        {
            if(s[i-1]==c&&i>=1)
            {
                if((i>=2)&&(s[i-2]=='-'||s[i-2]=='+'))fm-=flag;
                else fm-=flag*sum;
            }
            else fz+=flag*sum;
            flag=-1;
            sum=0;
        }
        if(s[i]=='+')
        {
            if(s[i-1]==c&&i>=1)
            {
                if((i>=2)&&(s[i-2]=='-'||s[i-2]=='+'))fm-=flag;
                else fm-=flag*sum;
            }
            else fz+=flag*sum;
            flag=1;
            sum=0;
        }
        i++;
    }
    if(s[i-1]==c&&i>=1)
    {
        if((i>=2)&&(s[i-2]=='-'||s[i-2]=='+'))fm-=flag;
        else fm-=flag*sum;
    }
    else fz+=flag*sum;
 //   printf("%d %d\n",fz,fm);
    printf("%c=%.3f\n",c,(double)fz/(double)fm);


}
