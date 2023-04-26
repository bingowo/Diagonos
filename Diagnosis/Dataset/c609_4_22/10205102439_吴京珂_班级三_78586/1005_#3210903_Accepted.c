#include <stdio.h>
#include <stdlib.h>

int _3to10(char a[])
{
    int len,i,num;
    int sum=0;
    len=strlen(a);
    for(i=0; i<len; i++)
    {
        if(a[i]=='-') num=-1;
        else if(a[i]=='0') num=0;
        else if(a[i]=='1') num=1;
        sum=sum*3+num;
    }
    printf("%d\n",sum);

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[100];
        scanf("%s",s);
        printf("case #%d:\n",i);
        _3to10(s);
    }
    return 0;
}
