#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int j=strlen(s)-1,k;
    for(k=0,j;j>k;k++,j--)
    {
        char a;
        a=s[k];s[k]=s[j];s[j]=a;
    }
}

void itob(int n,char s[100],int b)
{
    int a=abs(n),temp,i=0;
    while(a!=0)
    {
        temp=a%b;
        s[i]=(temp>9)?(temp-10)+'A':temp+'0';
        a=a/b;
        i++;
        if(a==0) s[i]='\0';
    }
    reverse(s);
    if(n<0)
    {
        for(int j=strlen(s)+1;j>0;j--)
            s[j]=s[j-1];
        s[0]='-';
    }
}

int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int n,b;
        char s[100];
        scanf("%d%d",&n,&b);
        itob(n,s,b);
        printf("%s\n",s);
    }
    return 0;
}
