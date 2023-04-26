#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,j,len,m,k,n;
    char s[16],res[16];
    scanf("%d ",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        for(j=0,m=0;j<len;j++)
        {
            for(k=j+1;k<len;k++)
            {
                if(s[j]==s[k])
                {
                    for(m=k;m<len;m++)
                        s[m]=s[m+1];
                    len--;
                    k--;
                }
            }
            //printf("%s 5\n",s);
        }
        //printf("%s 44\n",s);
        printf("case #%d:\n",i);
        for(j=0;j<len;j++)
        {
            printf("%c\n",s[j]);
            if(j==len-1)
                break;
            for(n=1;n<len-j;n++)
            {
                memset(res,'\0',sizeof(res));
                m=0;
                res[m++]=s[j];
                for(k=j+n;k<len;k++)
                {
                    res[m++]=s[k];
                    printf("%s\n",res);
                }
            }
        }
    }
    return 0;
}
