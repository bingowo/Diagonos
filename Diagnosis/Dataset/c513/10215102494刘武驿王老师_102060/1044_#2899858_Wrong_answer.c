#include<stdio.h>
#include<string.h>
int main()
{
    char s[20000];
    char oc[20000];
    int res[20000];
    scanf("%s",s);
    int sum=0,test=0,count=0,j=0;
    if(s[0]=='0'&&s[1]=='x') test=1;
    for(int i=2;i<=strlen(s);i++)
    {
        if(((s[i]=='0'&&s[i+1]=='x')||i==strlen(s))&&test==2)
        {
            oc[j]='\0';
            test=1;
            for(int x=j-1;x>=0;x--)
            {
                if(oc[x]<='f'&&oc[x]>='a') sum+=(oc[x]-'a'+10)*pow(16,j-1-x);
                else sum+=(oc[x]-'0')*pow(16,j-1-x);
            }
            res[count]=sum;
            sum=0;
            test=1;
            count++;
            j=0;
            continue;
        }
        if(((s[i]<='f'&&s[i]>='a')||(s[i]<='9'&&s[i]>='0'))&&test>=1)
        {
            test=2;
            oc[j]=s[i];
            j++;
        }
    }
    if(test<=1) 
    {
        printf("-1");
        return 0;
    }
    for(int x=0;x<count;x++) printf("%d ",res[x]);
}