#include<stdio.h>
#include<string.h>
int main()
{
    int T,n;
    char c;
    scanf("%d",&T);
    scanf("%c",&c);
    for(n=0;n<T;n++)
    {
        int sy[26],i;
        for(i=0;i<26;i++)
        {
            sy[i]=0;
        }
        char s[201];
        i=0;
        scanf("%c",&c);
        while(c!='\n')
        {
            s[i]=c;
            if(c>='A'&&c<='Z')
            {
                sy[c-'A']++;
            }
            i++;
            scanf("%c",&c);
        }
        s[i]='\0';
        int j,len=strlen(s),k;
        for(k=0;k<26;k++)
        {
            if(sy[k]!=0)
            {
                j=sy[k];
                break;
            }
        }
        for(i=0;i<len;i++)
        {
            c=s[i];
            if(c>='A'&&c<='Z')
            {
                s[i]='A'+k;
                j--;
                if(j==0)
                {
                    k++;
                    for(;k<26;k++)
                    {
                        if(sy[k]!=0)
                        {
                            j=sy[k];
                            break;
                        }
                    }
                }
            }
        }
        printf("case #%d:\n%s\n",n,s);
    }
    return 0;
}
