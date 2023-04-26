#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[30];
    scanf("%s",s);
    long long A=0,B=0,C=1;
    int cnt=0,i=0;
    for(;s[i]!='.'&&s[i];i++)
    {
        if(s[i]=='2')A=A*3-1;
        else A=A*3+s[i]-'0';
    }
    if(s[i])
        for(int j=i+1;s[j];j++)
        {

            if(s[j]=='2')B=B*3-1;
            else B=(s[j]-'0')+B*3;
            C*=3;
            if(A>0)
            {
                A+=B/C;
                B=B%C;
            }
        }
    if(B<0&&A>0){B=C+B;A--;}
    else if(B>0&&A<0){B=C-B;A++;}
    B?A?printf("%lld %lld %lld",A,B,C):printf("%lld %lld",B,C):printf("%lld",A);
    return 0;
}
