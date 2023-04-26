#include <stdio.h>
#include <string.h>
int div9(char s[])
{
    int i,l,n;
    l=strlen(s);
    n=0;
    for(i=0;i<l;i++)
        n=n+(s[i]-'0');
    if(n%9==0)
        return 1;
    else
        return 0;
}
int num9(char s[])
{
    int i,l;
    l=strlen(s);
    for(i=0;i<l;i++)
        if(s[i]=='9')
            return i;
    return -1;
}
void add(char s[],int x)
{
    int i,l;
    i=x;
    s[i]++;
    while(i>0&&s[i]>'9'){
        s[i]=s[i]-10;
        s[i-1]++;
        i--;
    }
    if(s[0]>'9'){
        l=strlen(s);
        for(i=l+1;i>0;i--)
            s[i]=s[i-1];
        s[1]=s[1]-10;
        s[0]='1';
    }
}
int main()
{
    char s[102];
    int l,i,x;
    scanf("%s",s);
    l=strlen(s);
    add(s,l-1);
    while(div9(s)==1||num9(s)!=-1){
        if(num9(s)!=-1){
            x=num9(s);
            for(i=x+1;i<l;i++)
                s[i]='0';
            add(s,x);
        }
        if(div9(s)==1)
            add(s,strlen(s)-1);
    }
    printf("%s\n",s);
    return 0;
}