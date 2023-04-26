#include <stdio.h>
#include <string.h>

int main()
{
    char s[200];
    char dic[200][100];
    while(scanf("%s",s)!=EOF)
    {
        //printf("%s\n",s);
        char *p=s;
        for(int i=0;i<110;i++)
        {
            for(int j=0;j<98;j++)
            {
                dic[i][j]=' ';
                //printf("%c",dic)
            }
            dic[i][98]='\0';
        }
        int A[200];
        char temp;int cnth=0;int cntl=0;
        while(*p)
        {
            if(p==s){dic[0][0]=*p;A[cnth]=cntl+1;cnth++;cntl++;}
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
