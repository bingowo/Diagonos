#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 80
int main()
{
    int n,digit;char s[N];char de[3*N];
    scanf("%d\n",&n);int temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%s\n",s);
        int numbers=0;
        int len=strlen(s)-1;
        for(;len!=1;len--)
        {
            digit=s[len]-'0';
            j=0;
            do{
                if(j<numbers)
                temp=digit*10+de[j]-'0';
                else 
                temp=digit*10;
                de[j++]=temp/8+'0';
                digit=temp%8;
            }
            while(digit||j<numbers);
            numbers=j;
        }
        de[numbers]='\0';
        printf("case #%d:\n",i);
        printf("%s\n");
    }
    return 0;
}