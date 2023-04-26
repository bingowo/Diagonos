#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a,b;
    char str[100];
    scanf("%d%s%d",&amp;a,str,&amp;b);
    int len=strlen(str);
    int d=1;
    int sum=0;
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]>='0'&amp;&amp;str[i]<='9')
        {
            sum=sum+d*(str[i]-'0');
            d=d*a;
        }
        else if(str[i]>='a'&amp;&amp;str[i]<='z')
        {
            sum=sum+d*(str[i]-'a'+10);
            d=d*a;
        }
        else
        {
            sum=sum+d*(str[i]-'A'+10);
            d=d*a;

        }
    }
    char t[100];
    int temp;
    
    int i=0;
    while(sum!=0)
    {
        temp=sum%b;
        if(temp<10)
            t[i]=temp+'0';
        else
            t[i]=temp-10+'A';
        sum=sum/b;
        i++;
    }
    i--;
    for(int j=i;j>=0;j--)
    {
        printf("%c",t[j]);
    }

    return 0;
}