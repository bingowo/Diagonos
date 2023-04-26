#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
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
            C*=3;
            if(s[j]=='2')B=B*(C/3)-1;
            else B=(s[j]-'0')+B*(C/3);
            A+=B/C;
            B=B%C;
        }
    if(B<0){B=C+B;A--;}
    B?printf("%d %d %d",A,B,C):printf("%d",A);
    return 0;
}
