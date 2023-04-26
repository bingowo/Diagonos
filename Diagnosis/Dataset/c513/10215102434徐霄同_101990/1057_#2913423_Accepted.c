#include <stdio.h>
#include <string.h>
char s[1001];
int i;
void right(char c)
{
    s[i]=c;
}
void left(char c)
{
    int j;
    for(j=i;j>0;j--)
        s[j]=s[j-1];
    s[0]=c;
}
int main()
{
    char w[1001];
    int l;
    scanf("%s",w);
    l=strlen(w);
    for(i=0;i<l;i++)
        if(w[i]>='a'&&w[i]<='z')
            w[i]=w[i]-'a'+'A';
    s[0]=w[0];
    for(i=1;i<l;i++)
        if(w[i]>=s[0])
            left(w[i]);
        else
            right(w[i]);
    s[l]='\0';
    printf("%s\n",s);
    return 0;
}
