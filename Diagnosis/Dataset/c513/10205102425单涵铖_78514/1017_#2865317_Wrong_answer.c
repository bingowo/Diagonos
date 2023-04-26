#include <stdio.h>
#include <stdlib.h>


unsigned long long solve(char s[])
{
    int num[128],i;
    memset(num,128,0);

    num['I'] = 1;
    num['V'] = 5;
    num['X'] = 10;
    num['L'] = 50;
    num['C'] = 100;
    num['D'] = 500;
    num['M'] = 1000;
    int l,sign=1;
    unsigned long long n=0;
    l = strlen(s);

    for(i=0;i<l;i=i+2)
    {
        if(s[i]=='(')   {i--;sign=sign*1000;}
        else if(num[s[i]]<=num[s[i+1]]) n = n+num[s[i]]+num[s[i+1]];
        else if(num[s[i]]>num[s[i+1]]) n = n+num[s[i]]-num[s[i+1]];
    }

    if(i!=l-1)  n = n+num[s[l]];
    return n*sign;
}

int main()
{
    char s[51],t[51];
    int len,p=0,i;
    unsigned long long n=0;
    int num[128];
    memset(num,128,0);
    num['I'] = 1;
    num['V'] = 5;
    num['X'] = 10;
    num['L'] = 50;
    num['C'] = 100;
    num['D'] = 500;
    num['M'] = 1000;


    scanf("%s",s);
    len = strlen(s);

    if(len==1)  printf("%d\n",num[*s]);
    else{
        for(i=0;i<len;i=i+2)
        {
            if(s[i]=='(')   {t[p]=s[i];p++;i++;}
            else if(s[i]==')')  {solve(t);i++;}

            if(num[s[i]]<=num[s[i+1]]) n = n+num[s[i]]+num[s[i+1]];
            else n = n+num[s[i]]-num[s[i+1]];
        }
        if(i!=len-1)  n = n+num[s[len]];
    }

    printf("%lld\n",n);
    return 0;
}
