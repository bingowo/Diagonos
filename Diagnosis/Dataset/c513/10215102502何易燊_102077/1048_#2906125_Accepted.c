#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void getnum(char s[],int a[])
{
    char buffer[30] = {};
    int index = 0;
    int sign = 1;
    int exponent;
    int coe;
    if (s[0] == '-') sign = -1;
    for (int i=(s[0]=='-')?1:0;s[i];i++)
    {

        if (s[i]!='+'&&s[i]!='-') buffer[index++] = s[i];
        else
        {
            if (!strchr(buffer,'^')) exponent = 1;
            else
            {
                char *res = (char*)malloc(10);
                res = strchr(buffer,'^')+1;
                exponent = atoi(res);
            }
            if (buffer[0]=='x') coe = sign;
            else if (strchr(buffer,'x'))
            {
                char *res = (char*)malloc(10);
                //memset(res,0,sizeof(res));
                res = strchr(buffer,'x');
                *res = '\0';
                coe = atoi(buffer)*sign;
            }
            else /*(!strchr(buffer,'x'))*/ {exponent = 0; coe = atoi(buffer)*sign;}
            a[exponent] = coe;
            index = 0;
            memset(buffer,0,sizeof(buffer));
        }
        if (s[i]=='+') sign = 1;
        if (s[i]=='-') sign = -1;
    }

}

main()
{
    char line[501] = {};
    while (gets(line)!=NULL)
    {
        char s[501] = {},t[501] = {};
        int a[51] = {}, b[51] = {};
        sscanf(line,"%s %s",s,t);
        strcat(s,"+"); strcat(t,"+");
        getnum(s,a); getnum(t,b);
        int result[103] = {};
        for (int i=0;i<51;i++)
            for (int j=0;j<51;j++)
            {
                result[i+j] += a[i]*b[j];
            }
        for (int i=102;i>=0;i--) if (result[i]!=0) printf("%d ",result[i]);
    }
    return 0;
}