#include<stdio.h>
int gcd(int m,int n)
{
    int r;
    while(n)
    {
        r = m%n;
        m = n;
        n = r;
    }
    return m;
}
int FindOne(char c)
{
    int s = 0;
    int a = (int)c;
    while(a != 0)
    {
        if(a%2==1)
        {
            s++;
            a = a/2;
        }
        else
        {
            a = a/2;
        }
    }
    return s;
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i = 0;i<n;i++)
    {
        char str[120]={'\0'};
        int count=0;
        while((str[count]=getchar())!='\n')
        {
            count++;
        }
        count = count-1;
        int j = 0;
        int sum = 0;
        while(str[j]!='\n')
        {
            sum = sum + FindOne(str[j]);
            j++;
        }
        printf("%d/%d\n",sum/gcd(sum,j*8),j*8/gcd(sum,j*8));

    }
    return 0;
}