#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s[121];
    mygets(s);
    for(int i=0;i<n;i++)
    {
        mygets(s);
        int length = strlen(s);
        int num=0;
        for(int j=0;j<length;j++)
        {
            while(s[j])
            {
                s[j] = s[j] & (s[j]-1);
                num++;
            }
        }
        int r = gcd(num,8*length);
        printf("%d/%d\n",num/r,8*length/r);
    }
    return 0;
}
int gcd(int m,int n)
{
    int r;
    while(n)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
void mygets(char *s)
{
    int i=0;
    char a;
    while((a= getchar())!=EOF && i<121)
    {
        s[i++]=a;
        if(a=='\n')
            break;
    }
    s[--i]='\0';
}