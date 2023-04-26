#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[11000]={0};
    int i;
    scanf("%s",s);
    for(i=0;s[i];i=i)
    {
        char t[11000]={0};
        int k=0,j=0,z=0;
        for(j=i;s[j];j++){if(s[j]>='a' && s[j]<='z')t[j-i]=s[j];else break;} t[j]=0;
        z=j;
        for(j=j;s[j];j++){if(s[j]<='9' && s[j]>='0')k=k*10+(s[j]-'0');else break;}
        i=j;
        if(z==strlen(s) && k==0)k=1;
        for(j=0;j<k;j++)printf("%s",t);
    }
    return 0;
}
