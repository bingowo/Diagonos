#include<stdio.h>
#include<string.h>
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
        if(c%2!=0) num++;
        c/=2;
    }
    return num;
}
int GCD(int a,int b)
{
    while(b!=0)
    {
        int m=b;
        b=a%b;
        a=m;
    }
    return a;
}
int main(void)  
{
    int n=0;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char str[125]={'\0'};
        char c;
        int j=0;
        while((c=getchar())!='\n') str[j++]=c;
        int len=strlen(str);
        int number=0;
        for(int p=0;p<len;p++) number+=count(c);
        int nums=8*len;
        int gcd=GCD(number,nums);
        number/=gcd;
        nums/=gcd;
        printf("%d/%d\n",number,nums);
    }
    return 0;
}