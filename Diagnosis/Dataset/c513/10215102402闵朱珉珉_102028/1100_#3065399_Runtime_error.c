#include <stdio.h>
#include <string.h>
void change(char *s,int  *a1,int  *b1)
{
    int len=strlen(s);
    int  x=0,y=0;
    for (int  i=0;i<len;i++)
    {
        switch (s[i])
        {
        case 'U':
            {
                y++;
                break;
            }
        case 'R':
            {
                x++;
                break;
            }
        case 'L':
            {
                x--;
                break;
            }
        case 'D':
            {
                y--;
                break;
            }
        }
        a1[i]=x;b1[i]=y;
    }
}
int main()
{
    char s[101]={0};
    scanf("%s",s);
    int len=strlen(s);
    int a1[101]={0},b1[101]={0};
    change(s,a1,b1);
    int q;
    scanf("%d",&q);
    int a[101]={0},b[101]={0};
    for (int i=0;i<q;i++)
    {
        scanf("%lld %lld",&a[i],&b[i]);
        int  n=0,flag=0;;
        for (int j=0;j<len;j++)
        {
            if (a[i]==0 && b[i]==0)
            {
                flag=1;
                break;
            }
            if (a1[len-1] && ((a[i]-a1[j])%a1[len-1]==0) && ((n=(a[i]-a1[j])/a1[len-1])>=0) && b[i]==n*b1[len-1]+b1[j])
            {
                flag=1;
                break;
            }
            else if (a1[len-1]==0)
            {
                if (b1[len-1] && ((b[i]-b1[j])%b1[len-1]==0) && ((n=(b[i]-b1[j])/b1[len-1])>=0) && a[i]==n*a1[len-1]+a1[j])
                {
                    flag=1;
                    break;
                }
                else if (b1[len-1]==0 && a[i]==a1[j] && b[i]==b1[j])
                {
                    flag=1;
                    break;
                }
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

}
