#include<stdio.h>
#include<math.h>
#include<string.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void reverse(int A,char l[],int B)
{
    int num=0,i=0,j=0,sum=0,a=0;
    int len;
    len=strlen(l);
    int s[100];
    if(len==1&&l[0]=='0')
        printf("%c",l[0]);
    while(l[i]!='\0')
    {
        if(l[i]>='0'&&l[i]<='9')
        {
            num=l[i]-'0';
        }
        else if(l[i]>='a'&&l[i]<='z')
        {
            num=l[i]-'a'+10;
        }
        else if(l[i]>='A'&&l[i]<='Z')
        {
            num=l[i]-'A'+10;
        }
        else
            break;
        for(j=0;j<len-1;j++)
        {
            num=num*A;
        }
        sum+=num;
        i++;
        len--;
    }
    while(sum>0)
    {
        s[a]=table[sum%B];
        sum=sum/B;
        a++;
    }
    for(int b=strlen(s)-1;b>=0;b--)
    {
        printf("%c",s[b]);
    }
}
int main()
{
    int A,B;
    char l[1000000000];
    scanf("%d%s%d",&A,&l,&B);
    reverse(A,l,B);
    return 0;
}
