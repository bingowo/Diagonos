#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,x,count,i,len;
    long long res;
    char s[61],hash[256];
    scanf("%d",&T);
    for(x=0;x<T;x++)
    {
        scanf("%s",s);
        count=res=0;
        len=strlen(s);
        memset(hash,0,sizeof(hash));
        for(i=0;i<len;i++)
        {

            if(hash[s[i]]==0)
            {
                count++;
                if(count==1)
                    hash[s[i]]='1';
                else if(count==2)
                    hash[s[i]]='0';
                else
                    hash[s[i]]='0'+count-1;
            }
            else;
            //printf("%d %d-----\n",count,hash[s[i]]-'0');
        }
        if(count==1)
            count=2;

        //printf("%d\n",count);
        for(i=0;i<len;i++)
        {
            res=res*count+hash[s[i]]-'0';
            //printf("%lld---\n",res);
        }
        printf("case #%d:\n",x);
        printf("%lld\n",res);
    }
    return 0;
}
