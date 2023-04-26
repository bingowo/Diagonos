#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char s[200] = {};
    scanf("%s",s);
    int t[1000] = {};
    t[0]=0,t[1]=0,t[2]=0,t[3]=1;
    int index = 4;
    int num = strlen(s);
    for (int i=9;i>=0;i--) t[index++] = (num>>i)&1;
    int p;
    for (p=0;s[3*p+2];p++)
    {
        num = (s[3*p]-'0')*100+(s[3*p+1]-'0')*10+(s[3*p+2]-'0');
        for (int i=9;i>=0;i--) t[index++] = (num>>i)&1;
    }
    if (strlen(s)%3==0) ;
    else
    {
        if (s[3*p+1])
        {
            num = (s[3*p+1]-'0') + (s[3*p]-'0')*10;
            for (int i=6;i>=0;i--) t[index++] = (num>>i)&1;
        }
        else 
        {
            num = s[3*p]-'0';
            for (int i=3;i>=0;i--) t[index++] = (num>>i)&1;
        }
    }
    for (int i=0;i<index;i++)
    {
        printf("%d",t[i]);
    }
    system("pause");
    return 0;
}