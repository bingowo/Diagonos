#include <stdio.h>
#include <string.h>
char table[]="012";
char ans[100];//默认字符0
void reverse(char s[])
{
    for(int i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        int t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
}
void add(char s[])
{
    int carry=0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='.')
        {
            ans[i+1]='.';
        }
        else
        {
            int temp=(s[i]-'0')+1+carry;
            if(temp==3)
            {
                carry=1;temp=0;
            }
            else if(temp==4)
            {
                carry=1;temp=1;
            }
            else
            {
                carry=0;
            }
            ans[i+1]=temp + 48;
        }

    }
    ans[0]+=(carry+48);
}
void jian(char s[])
{
    int i;
    for(i=1;i<strlen(ans);i++)
    {
        if(ans[i]=='.') continue;
        else if(ans[i]=='2') ans[i]='1';
        else if(ans[i]=='1') ans[i]='0';
        else if(ans[i]=='0') ans[i]='2';
    }
    ans[i]='\0';
}
int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    int a,b;
    a=A/B;b=A%B;
    char s[100];char t[50];int i=0;
     do
    {
        int r=a%3;
        s[i]=table[r];i++;
        a=a/3;
    } while(a!=0);
    s[i]='\0';
    reverse(s);
    if(b!=0)
    {
        s[i]='.';
        s[++i]='\0';
        int k=0;
        while(b!=0)
        {
            t[k]=table[b%3];
            k++;
            b/=3;
        }
        t[k]='\0';
        reverse(t);
        strcat(s,t);
    }
    add(s);
    jian(ans);
    if(ans[0]!='0') printf("%c",ans[0]);
    for(int m=1;m<strlen(ans);m++)
    {
        printf("%c",ans[m]);
    }
    return 0;
}
