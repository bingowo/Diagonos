#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[501]="",r[501]="";
        scanf("%s",s);
        int count=1,j=0;
        for(int i=1;i<strlen(s);i++)
        {
            char t[4]="";
            if(s[i]==s[i-1])
            {
                if(count==255)
                {
                    itoa(255,t,10);
                    strcat(r,t);
                    r[j+3]=s[i];
                    j+=4;
                    count=1;
                }
                else count++;
            }
            else if(s[i]!=s[i-1])
            {
                itoa(count,t,10);
                strcat(r,t);
                r[j+strlen(t)]=s[i-1];
                j+=strlen(t)+1;
                count=1;
            }
            if(i==strlen(s)-1) r[j]=count+'0',r[j+1]=s[i],j+=2;
        }
        r[j]=0;
        if(strlen(s)==1) r[0]=1+'0',r[1]=s[0],r[2]=0;
        printf("case #%d:\n%s\n",i,r);
    }
    return 0;
}
