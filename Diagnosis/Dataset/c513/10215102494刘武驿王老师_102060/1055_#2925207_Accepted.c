#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000001];
    scanf("%s",s);
    int hash[1000];
    for(int x=0;x<1000;x++) hash[x]=-1;
    int start,end,ts=0,te=0,max=-2;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(hash[s[i]]<ts)
        {
            hash[s[i]]=i;
            te=i;
        }
        else
        {
            te=i-1;
            if(te-ts>max)
            {
                if(te-ts==max+1)
                {
                    ts=hash[s[i]]+1;
                    hash[s[i]]=i;
                    continue;
                }
                max=te-ts-1;
                start=ts;
                end=te;
            }
            ts=hash[s[i]]+1;
            hash[s[i]]=i;
            continue;
        }
        if(i==len-1)
        {
            if(te-ts>max+1)
            {
                max=te-ts;
                start=ts;
                end=te;
                ts=hash[s[i]]+1;
                hash[s[i]]=i;
            }
        }
    }
   for(int i=start;i<=end;i++) printf("%c",s[i]);
}
