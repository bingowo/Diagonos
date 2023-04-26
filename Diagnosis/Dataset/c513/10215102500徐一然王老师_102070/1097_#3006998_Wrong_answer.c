#include <stdio.h>
#include <string.h>

int main()
{
    char s[200];
    char dic[300][100];
    while(scanf("%s",s)!=EOF)
    {
        //printf("%s\n",s);
        char *p=s;
        for(int i=0;i<300;i++)
        {
            for(int j=0;j<99;j++)
            {
                dic[i][j]=' ';
                //printf("%c",dic)
            }
            dic[i][99]='\0';
        }
        int A[300];
        for(int i=0;i<300;i++)A[i]=0;
        char temp;int cnth=100;int cntl=0;
        while(*p)
        {
            if(p==s){dic[cnth][cntl]=*p;A[cnth]=cntl+1;cnth++;cntl++;}
            else
            {
                if(*p>temp)
                {
                    dic[cnth][cntl]=*p;A[cnth]=cntl+1;cnth++;cntl++;
                }
                else
                {
                    cnth=cnth-2;dic[cnth][cntl]=*p;A[cnth]=cntl+1;cnth++;cntl++;
                }
            }
            temp=*p;
            p++;
        }
        for(int i=199;i>=0;i--)
        {
            if(A[i]==0)continue;
            for(int j=0;j<A[i];j++)
            {
                printf("%c",dic[i][j]);
            }
            printf("\n");

        }

    }
}
