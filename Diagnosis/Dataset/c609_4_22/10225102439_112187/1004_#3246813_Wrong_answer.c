#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,A,t=0,x,y,i=0,z;
    char s[20],ch;
    scanf("%d",&A);
    getchar();
    while ((ch=getchar())!=' ')
        s[i++]=ch;
    s[i]='\0';
    if (s[0]=='0') 
    {
        printf("0");
        return 0;
    }
    scanf("%d",&y);
    for (int j=0;j<i;j++)
    {
        if ((s[j]>='a')&&(s[j]<='g')) z=10+s[j]-'a';
        else if ((s[j]>='A')&&(s[j]<='G')) z=10+s[j]-'A';
        else z=s[j]-'0';
        x=x*A+z;
    }
    char b[100000];
    while (x!=0)
    {
        m=x%y;
        x/=y;
        if (m>=10)
        {
            b[t++]='A'+m-10;
            continue;
        }
        b[t++]='0'+m;
    }
    t--;
    while (t>=0)
        printf("%c",b[t--]);
    return 0;
}
