#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char m[520],n[520];
    memset(m,'\0',520);
    memset(n,'\0',520);
    while(scanf("%s %s",m,n)==2)// 我们要求的是m-n
    {
        int flag;
        int lm=strlen(m);
        int ln=strlen(n);

        if(lm>ln) flag=1;
        else if(lm<ln) flag=-1;
        else if(lm==ln)
        {
            int k=lm-1;
            for(;k>=0;k--)
            {
                if(m[k]>n[k]) {flag=1;break;}
                else if(m[k]<n[k]) {flag=-1;break;}
                else continue;
            }
        }

        int l=(lm>=ln)?lm:ln;
        int l0=l;
        int ans[520]={0};

        if(flag==-1)
        {
              char temp[520];
              memset(temp,'\0',520);
              strcpy(temp,m);
              memset(m,'\0',520);
              strcpy(m,n);
              memset(n,'\0',520);
              strcpy(n,temp);
        }

            for(int i=lm-1,j=ln-1;l>=0;i--,j--)//要注意字符数组的-'0'处理
        {
            if(j<0) {
                    ans[l--]=m[i]-'0';
            }
            else if(m[i]>=n[j])//之后要处理ans中位上大于十的情况嘛？不需要，借位不可能出现大于10的情况
            {
                 ans[l]=m[i]-n[j];
                 l--;
            }
            else {
                    int move=1;
                    while(m[i-move]-'0'==0)
                    {
                        move++;
                    }
                    m[i]+=10;
                    m[i-move]--;
                    for(int j=i-1;j>=i-move+1;j--)
                        m[j]+=9;
                    ans[l]=m[i]-n[j];
                    l--;
            }
        }

        if(flag==1)
        {
            int i=0;
            while(ans[i]==0||ans[i]<0) i++;
            for(;i<=l0;i++)
            printf("%d",ans[i]);
        }

        if(flag==-1)
        {
            printf("-");
            int i=0;
            while(ans[i]==0||ans[i]<0) i++;
            for(;i<=l0;i++)
            printf("%d",ans[i]);
        }
        printf("\n");
        memset(m,'\0',520);
        memset(n,'\0',520);
    }

    return 0;
}
