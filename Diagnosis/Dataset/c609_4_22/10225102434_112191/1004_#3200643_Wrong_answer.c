#include<stdio.h>
#include<string.h>
int Turn(char s[1000],int a)
{
    int i,j,n;
    int y = 1,x = 0;
    for(i = strlen(s)-1;i>=0;i--)
    {
        if(s[i]>='a') n = s[i]-'a'+10;
        else if(s[i]>='A') n = s[i]-'A'+10;
        else n = s[i]-'0';

        x = x+n*y;
        y = y*a;
    }
    return x;
}
void Tur(int x,int b)
{
    int i,j,m;
    char a[1000];
    for(i = 0;x>0;i++)
    {
        m = x%b;
        x = x/b;
        if(m<10)m = m+'0';
        else m = m+'A'-10;
        a[i] = m;
    }
    for(j = i-1;j>=0;j--)
    {
        printf("%c",a[j]);
    }
}
int main()
{
    int a,b;
    char s[1000];
    scanf("%d",&a);
    scanf("%s",s);
    scanf("%d",&b);
    int x;

    x = Turn(s,a);
    Tur(x,b);
    return 0;
}
