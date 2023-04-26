#include<stdio.h>
#include<string.h>
int give(int x,int t)
{
    if(t==0)  return 1;
    if(t==1)  return 0;
    return t;
}
int main()
{
    int n,i,j,k,len,b;
    char s[1000];
    int table[200];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        memset(table,-1,sizeof(table));
        b=0;
        scanf("%s",s);
        printf("case #%d:\n",i);
        len=strlen(s);
        if(len==1)
        {
            printf("1\n");
            continue;
        }
        for(j=0;j<len;j++)
        {
            if(table[s[j]]==-1)
            {
                table[s[j]]=give(j,b);
                b++;
            }
        }
        long long weight=1,sum=0;
        for(j=len-1;j>=0;j--)
        {
            sum=sum+table[s[j]]*weight;
            weight*=b;
        }
        printf("%d\n",sum);
    }
    
    return 0;
}