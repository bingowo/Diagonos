#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    getchar();getchar();
    char s[40],consulta[21],consultb[21];char str[161];
    scanf("%s",s);
    void two(char *s,char *str);
    two(s,str);
    long long int qr=0,qi=0;
    long long int a,b;
    for(int i=0;i<strlen(str);i++)
    {
        int r=str[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }
    if(a==0)printf("%lldi",b);
    else if(b==0)printf("%lld",a);
    else printf("%lld%lldi",a,b);
    
}

void two(char *s,char *str)
{
    int i,j,k;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')k=s[i]-'0';
        else k=s[i]-55;
        for(j=i*4;j<i*4+4;j++)
        {
            str[i*4+3-j+i*4]=k%2+'0';
            k/=2;
        }str[j]='\0';
    }
}
