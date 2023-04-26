#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 32
int main()
{
    int A,B;
    char str[N]={0};
    int exchange[N];
    scanf("%d",&A);
    scanf("%s",str);
    scanf("%d",&B);
    int len=strlen(str);
    int i;int num=0;
    for(i=len-1;i>=0;i--)
    {
        if(str[i]>='0'&&str[i]<='9')
        num=num+(str[i]-'0')*((int)pow(A,len-1-i));
        else if(str[i]>='a'&&str[i]<='z')
        num=num+(str[i]-'a'+10)*((int)pow(A,len-1-i));
        else if(str[i]>='A'&&str[i]<='Z')
        num=num+(str[i]-'A'+10)*((int)pow(A,len-1-i));
    }
    i=0;
    if(num==0)
    printf("%d",0);
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