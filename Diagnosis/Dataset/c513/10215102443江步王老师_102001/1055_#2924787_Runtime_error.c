#include<stdio.h>
#include<string.h>

int main()
{
    int t,i;
    int len,max;
    int start,end;
    char s[1000000];
    int m[128];
    for (i=0;i<128;i++){
        m[i]=-1;
    }
    scanf("%s",s);
    len=strlen(s);
    t=0;i=t+1;max=0;
    m[s[t]]=t;
    while (i<len)
    {
        while (m[s[i]] < t)
        {
            m[s[i]]=i;
            i++;
            if (i>=len){
                if (i-t > max){
                    max=i-t;
                    start=t;
                    end=i-1;
                }
                break;
            }
        }
        if (i-t > max){
            max=i-t;
            start=t;
            end=i-1;
        }
        t=m[s[i]]+1;
    }
    for (i=start;i<=end;i++){
        printf("%c",s[i]);
    }
    return 0;
}