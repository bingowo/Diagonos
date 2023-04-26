#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,j,len,m,len1,k,n;
    char s[16],res[16],s1[16];
    scanf("%d ",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        memset(s1,'\0',sizeof(s1));
        for(j=0,m=0;j<len;j++)
        {
            if(len==1)
                {s1[0]=s[0];break;}
            for(k=j+1;k<len&&s[j]-s[k];k++);
            if(!(k-len))
                s1[m++]=s[j];
            //printf("%s 5\n",s1);
        }
        //printf("%s 44\n",s1);
        len1=strlen(s1);
        printf("case #%d:\n",i);
        for(j=0;j<len1;j++)
        {
            printf("%c\n",s1[j]);
            if(j==len-1)
                break;
            for(n=1;n<len1-j;n++)
            {
                memset(res,'\0',sizeof(res));
                m=0;
                res[m++]=s1[j];
                for(k=j+n;k<len1;k++)
                {
                    res[m++]=s1[k];
                    printf("%s\n",res);
                }
            }
        }
    }
    return 0;
}
