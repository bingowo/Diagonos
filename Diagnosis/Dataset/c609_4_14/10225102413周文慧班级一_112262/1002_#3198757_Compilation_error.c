#include<stdio.h>
#include<string.h>
void trans(int n)
{
    int m,n=1;
    for(m==0;m<31,m++)
    {
        n=2*n;
    }
    char s[n],l[n];
    int x=0,y=0;
    while(n>1)
    {
        l[x]=n%2;
        n=n/2;
        x++;
    }
    for(x;x>0;x--)
    {
        s[y]=l[x];
        y++;
    }
    return s;
}
int main()
{
    scanf("%d",&T);
    int i,a,b=1;
    for(i==0,i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&n);
        trans(n);
        for(a=1;a<strlen(s);a++)
        {
            if(s[a]!=s[a-1])
            {
                b++;
            }
            else
            {
                break;
            }
            printf("%d",b);
        }
    }
    return 0;
}