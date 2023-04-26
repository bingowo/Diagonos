#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()

{
    char s[500],ss[4];
    int s1[20];
    int a,b;
    scanf("%s",s);
    printf("0001");
    a=strlen(s);
    b=0;
    while (a>0)
    {
        s1[b++]=a%2;
        a=a/2;
    }
    for (int i=0; i<10; i++)
        if (i<10-b) printf("0");
        else printf("%d",s1[9-i]);
    b=0;
    a=0;

    while (strlen(s)/3>b)
    {
        a=100*(s[3*b]-'0')+10*(s[3*b+1]-'0')+s[3*b+2]-'0';
        int w=0;
        while (a>0)
        {
            s1[w++]=a%2;
            a=a/2;
        }
        for (int i=0; i<10; i++)
            if (i<10-w) printf("0");
            else printf("%d",s1[9-i]);
        b=b+1;
    }
    if (strlen(s)%3==1){
        a=s[3*b]-'0';
        int w=0;
        while (a>0)
        {
            s1[w++]=a%2;
            a=a/2;
        }
        for (int i=0; i<4; i++)
            if (i<4-w) printf("0");
            else printf("%d",s1[3-i]);
    }
    else if (strlen(s)%3==2){
        a=s[3*b+1]-'0'+10*(s[3*b]-'0');
        int w=0;
        while (a>0)
        {
            s1[w++]=a%2;
            a=a/2;
        }
        for (int i=0; i<7; i++)
            if (i<7-w) printf("0");
            else printf("%d",s1[6-i]);
    }

    return 0;
}
