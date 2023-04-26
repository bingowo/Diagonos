#include<stdio.h>
#include<math.h>
#include<string.h>
void find(char* s)
{
    int i,j,len=strlen(s);
    for(i=0;i<len-1;++i)
    {
        if(s[i]==s[i+1]&&s[i]=='9')//相同的数字是9
        {
            if(!i)
            {
                for(j=len;j>0;--j)
                {
                    s[j]=s[j-1];
                }
                s[0]='1';s[1]='0';s[2]='0';
                s[len+1]='\0';
                find(s);
                return;
            }
            else
            {
                s[i-1]+=1;s[i]=s[i+1]='0';
                find(s);
                return;
            }
        }
        else if(s[i]==s[i+1])//相同的数字不是9
        {
            s[i+1]+=1;
            for(j=i+2;j<len;++j)
            {
                if(!((j-i)%2))s[j]='0';
                else s[j]='1';
            }
            return;
        }
    }
    if(s[len-1]=='9')
    {
        s[len-1]='0';
        s[len-2]+=1;
        if(s[len-2]==s[len-3])find(s);
    }
    else {s[len-1]+=1;if(len>1&&s[len-1]==s[len-2])find(s);}
    return;
}
int main()
{
    int T;char s[200];
    scanf("%d\n",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%s",s);
        find(s);
        printf("case #%d:\n%s\n",cas,s);
    }
    return 0;
}