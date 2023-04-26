#include<stdio.h>
#include<string.h>
#include<math.h>

char check(char s[101])
{
    int t=sizeof(s);
    int p=0;
    char b[1000];
    memset(b,0,sizeof(b));
    for(int i=0;i<t;i++)
    {
        if(i==0)
        {
            if(s[i]!=s[i+1])
            {
                b[p++]=s[i];
            }
        }
        else if(i==t-1)
        {
            if(s[i]!=s[i-1])
            {
                b[p++]=s[i];
            }
        }
        else
        {
            if(s[i]!=s[i-1]&&s[i]!=s[i+1])
            {
                b[p++]=s[i];
            }
        }
    }

    return b;
}
int main()
{
    int n;
    char a[3]={'A','B','C'};
    scanf("%d",&n);
    char s[101];
    int mm=n;
    while(n--)
    {
        scanf("%s",s);
        int len=sizeof(s);
        int minx=0x3f3f3f;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<=len;j++)
            {
                char ss=s.substr(0,j)+a[i]+s.substr(j,len-j);
                while(ss!=check(ss))
                {
                    ss=check(ss);
                }
                int len2=sizeof(ss);
                minx=min(len2,minx);


            }
        }
        printf("case #%d:\n",mm-n);
        printf("%d\n",len+1-minx);
}
    return 0;
}

