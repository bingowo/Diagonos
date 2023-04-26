#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    char s[110];
    char t[110];
    char a[7][5]={"the","a","an","of","for","and"};
    gets(s);
    for(int cas=0;cas<T;cas++)
    {
        gets(s);
        int flag=1,sign=1;int ans=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==' ') flag=1;
            else if(flag==1)
            {
                flag=0;int k=0;int j=0;
                for(j=i,k=0;;j++,k++)
                {
                    if(s[j]==' ' || s[j]=='\0')break;
                    t[k]=s[j];
                }
                i=j-1;
                t[k]='\0';
                for(k=0;k<6;k++)
                {
                    if(strcmp(t,a[k])==0)
                    {
                        sign=0;break;
                    }
                }
                if(sign) ans++;
                sign=1;
            }
        }
        printf("case #%d:\n",cas);
        printf("%d\n",ans);
    }
    return 0;
}

