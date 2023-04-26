#include <stdio.h>
#include <string.h>
int gcd(int a, int b)
{
    for (int i=a;i>=1;i--)
        if (a%i==0 && b%i==0)
            return i;
}

int count(char c)
{
    int num=0;
    if(c<0)
    {
        num++;
        c^=128;
    }
    while(c!=0)
    {
        if(c%2) num++;
        c/=2;
    }
    return num;
}

int main()
{
    int n;
    scanf("%d\n", &n);
    for(int i=0;i<n;i++)
    {
        char str[125]={'\0'};
        char c;
        int j=0;
        while((c=getchar())!='\n')
            str[j++] =c;
        int len=strlen(str);
        int number1=0;
        for(int p=0;p<len;p++)
            number1+=count(str[p]);
        int nums=len*8;
        int g=gcd(number1,nums);
        number1 /= g;
        nums /= g;  
        
        printf("%d/%d\n",number1,nums);
    }
    return 0;
}