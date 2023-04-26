#include <stdio.h>
#include <stdlib.h>

#define MXL 120

int gcd(int x, int y)
{	if (y)
        return gcd(y, x%y);
    else
        return x;
}

int cnt1char(char x)
{
    int a=0,n=1;
    for (int i=0;i<32;i++)
    {
        if((x&n)!=0)a++;
        n<<=1;
    }
    return a;
}

int main()
{
    int n,Len=0,M=0;scanf("%d",&n);
    getchar();
    char s[MXL],c;
    char* p;
    for (int i=0;i<n;i++,Len=0,M=0)
    {
        for (int j=0;j<MXL;j++)s[j]='\0';
        p=s;
        while(1)
        {
            c=getchar();
            if(c!='\n')
            {
                *(p++)=c;
            }
            else
                break;
        }
        for (int j=0;j<MXL && s[j]!='\0';j++)
        {
            Len++;
            M+=cnt1char(s[j]);
        }
        printf("%d/%d\n",M/gcd(M,8*Len),Len*8/gcd(M,8*Len));
    }
    return 0;
}
