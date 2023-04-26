#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[10000];
    scanf("%s",s);
    char*p=strchr(s,'.');
    int a=0;
    int b=0;

    if (p==NULL)
    {
        int i=0;
        while (i<strlen(s))
        {
            int t;
            if(s[i]=='2') t=-1;
            else t=s[i]-'0';
            a=a*3+t;
              i++;
        }
        printf("%d\n",a);

    }
    else
    {   int i;
        for(i=0; s[i]!='.'; i++)
        {
            int t;
            if(s[i]=='2') t=-1;
            else t=s[i]-'0';
            a=a*3+t;
        }
        i++;
        int c=1;
        for (;i<strlen(s);i++){
            int t;
            if(s[i]=='2') t=-1;
            else t=s[i]-'0';
            b=b*3+t;
            c=c*3;
        }
        if (b<0&&a>0) {b=c+b;a=a-1;}
        else if (b<0&&a<0){b=-b;}

        printf("%d %d %d\n",a,b,c);


    }
    return 0;
}
