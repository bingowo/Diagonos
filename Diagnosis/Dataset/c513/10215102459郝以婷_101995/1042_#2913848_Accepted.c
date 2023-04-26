#include <stdio.h>
#include <string.h>

void comb(char* s,char* t)
{
    if(*s)
    {
        char left[17]={0};
        sprintf(left,"%s%c",t,s[0]);
        printf("%s\n",left);
        comb(s+1,left);
        comb(s+1,t);
    }
}

int main()
{
    int T,i,j,len,m,k,n,min;
    char s[16],res[16],temp;
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
        }
        for(j=0;j<len;j++)
        {
            for(k=0;k<len-1-j;k++)
            {
                if(s[k]>s[k+1])
                {
                    temp=s[k];
                    s[k]=s[k+1];
                    s[k+1]=temp;
                }
            }
        }
        printf("case #%d:\n",i);
//        for(j=0;j<len;j++)
//        {
//            printf("%c\n",s[j]);
//            if(j==len-1)
//                break;
//            for(n=1;n<len-j;n++)
//            {
                memset(res,'\0',sizeof(res));
//                m=0;
//                res[m++]=s[j];
//                for(k=j+n;k<len;k++)
//                {
//                    res[m++]=s[k];
//                    printf("%s\n",res);
//                }
//            }
//        }
        comb(s,res);
    }
    return 0;
}
