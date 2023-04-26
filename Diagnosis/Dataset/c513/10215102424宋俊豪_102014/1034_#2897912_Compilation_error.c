#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,len;
    float a[128];
    char s[100],c;
    scanf("%d",&n);
    for (int i=0; i<128; i++)
        a[i]=-1;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<26; j++)
        {
            scanf("%f",&a['A'+j]);
            a['A'+j+32]=a['A'+j];
        }
        scanf("%s",s);
        len=strlen(s);
        for(int x=0; x<len; x++)
            for(int j=x+1; j<len; j++)
            {
                if(a[s[j]]>a[s[x]])
                {
                    c=s[j];
                    s[j]=s[x];
                    s[x]=c;
                }
                else if (a[s[j]]==a[s[x]])
                {
                    if(s[j]==s[x]+32||s[j]==s[x]-32)
                    {
                        if(s[j]>s[x])
                        {
                            c=s[j];
                            s[j]=s[x];
                            s[x]=c;
                        }
                    }
                    else
                    {
                        if(s[j]<s[x])
                        {
                            c=s[j];
                            s[j]=s[x];
                            s[x]=c;
                        }
                    }
                }
            }
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}

        return 0;
    }
