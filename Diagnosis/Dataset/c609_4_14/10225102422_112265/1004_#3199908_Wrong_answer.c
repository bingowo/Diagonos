#include<stdio.h>
#include<string.h>
#define N 32
int main()
{
    int A,B;
    char str[N]={0};
    int exchange[N];
    scanf("%d",&A);
    fgets(str,N,stdin);
    scanf("%d",&B);
    int len=strlen(str);
    int i;int num=0;
    for(i=len-1;i>=0;i--)
    {
        if(str[i]>='0'&&str[i]<='9')
        num=num*A+str[i]-'0';
        else if(str[i]>='a'&&str[i]<='z')
        num=num*A+str[i]-'a';
        else if(str[i]>='A'&&str[i]<='Z')
        num=num*A+str[i]-'A';
    }
    i=0;
    while(num!=0)
    {
        exchange[i]=num%B;
        num=num/B;
        i++;
    }
    int index;
    for(index=i-1;index>=0;index--)
    {
        if(exchange[index]>9)
        printf("%c",exchange[index]-10+'A');
        else
        printf("%d",exchange[index]);
    }
    return 0;
}