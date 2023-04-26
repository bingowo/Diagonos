#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int l,num,i=0;
    char k[500]={0};
    scanf("%s",k);
    printf("0001");
    l=strlen(k);
    k[l]='0';
    ord(l);
    if(l%3==0) num=l/3;
    else num=l/3+1;
    int temp=0;
    while((i/3)<num)
    {
        temp=(k[i]-48)*100+(k[i+1]-48)*10+k[i+2]-48;
        ord(temp);
        i=i+3;
    }
    return 0;
}
void ord(int a)
{
    int b[10]={0};
    int i=0;
    while(a!=0)
    {
        b[i]=a%2;
        i++;
        a=a/2;
    }
    for(int s=9;s>=0;s--)
        printf("%d",b[s]);
}
