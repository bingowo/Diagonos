#include<stdio.h>
#include<math.h>
#include<string.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void reverse(A,n,B)
{
    int num=0,i=0,j=0,sum=0,a=0;
    int len=strlen(n);
    int s[100];
    while(n[i]!='\0')
    {
        if(n[i]>='0'&&n[i]<='9')
        {
            num=n[i]-'0';
        }
        else if(n[i]>='a'&&n[i]<='z')
        {
            num=n[i]-'a'+10;
        }
        else if(n[i]>='A'&&n[i]<='Z')
        {
            num=n[i]-'A'+10;
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
    if(sum==0)
        printf("%d",sum);
    while(sum>0)
    {
        s[a]=table[sum%B];
        sum=sum/B;
    }
    for(int b=0;b<strlen[s];b++)
    {
        printf("%c",s[b]);
    }
}
int main()
{
    int A,B,n[32];
    scanf("%d,%c,%d",&A,&n,&B);
    reverse(A,n,B);
    return 0;
}