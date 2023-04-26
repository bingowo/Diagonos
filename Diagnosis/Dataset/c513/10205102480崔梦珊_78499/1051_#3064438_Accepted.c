#include<stdio.h>
#include<string.h>


int main()
{
    char alpha[64]={0};
    for(int i=0;i<=25;i++)
    {
        alpha[i]='A'+i;
    }
    for(int i=26;i<=51;i++)
    {
        alpha[i]='a'+i-26;
    }
    for(int i=52;i<=61;i++)
    {
        alpha[i]='0'+i-52;
    }
    alpha[62]='+';
    alpha[63]='/';
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        char s[100]={0};
        scanf("%s",s);
        int len=strlen(s);
        int rem[1000]={0};//记录输入字符串的二进制
        for(int j=0;j<len;j++)//转二进制
        {
            int temp=s[j];
            int pos=j*8+7;
            while(temp/2!=0)
            {
                rem[pos]=temp%2;
                temp=temp/2;
                pos--;
            }
            rem[pos]=temp%2;
        }
        int end=len*8;
        if(len*8%6!=0) end=end+6-(len*8)%6;
        int n=0;
        for(int j=0;j<end;j=j+6)
        {
            int temp=rem[j];
            for(int k=1;k<=5;k++)
            {
                temp=temp*2+rem[j+k];
            }
            printf("%c",alpha[temp]);
            n++;
        }
        if(n%4==0) printf("\n");
        if(n%4==1) printf("===\n");
        if(n%4==2) printf("==\n");
        if(n%4==3) printf("=\n");

    }
}
