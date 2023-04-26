#include<stdio.h>
#include<string.h>
int one(int a)
{
    int b=0;
    while(a%2==1)
    {
        b++;
        a=a/2;
    }
    return b;
}
int main()
{
    int number;
    scanf("%d",&number);
    int n[number];
    char s[number][120];
    for(int i=0;i<number;i++)
    {
        scanf("%s",s[i]);
        int l=strlen(s[i]);
        for(int j=0;j<l;j++)
        {
            s[i][j]=getchar();
            n[i]=n[i]+one(s[i][j]);
        }
    }
}