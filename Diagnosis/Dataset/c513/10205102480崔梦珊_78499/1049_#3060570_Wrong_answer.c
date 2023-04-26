#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    return strcmp((char*) a,(char*) b);
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        char c;
        char s[500][500]={0};
        int k=0;
        int j=0;
        int flagg=0;
        while((c=getchar())!='\n')
        {
            if((c==' '||c==','||c=='.'||c=='!'||c=='?')&&flagg==0)
            {
                j++;
                k=0;
                flagg=1;
            }
            if((c==' '||c==','||c=='.'||c=='!'||c=='?')&&flagg==1)
            {
                continue;
            }
            if(c!=' '&&c!=','&&c!='.'&&c!='!'&&c!='?')
            {
                s[j][k]=c;
                k++;
                flagg=0;
            }
        }

        int num=j;
        for(int m=0;m<j;m++)
        {
            for(int n=m;n<j;n++)
            {
                if(strcmp(s[m],s[n])==0&&m!=n)
                {
                    num--;
                    for(int g=0;g<strlen(s[n]);g++)
                    {
                        s[n][g]=0;
                    }
                }
            }
        }
        char ans[500][500]={0};     //去重
        int a=0,b=0;
        for(int m=0;m<j;m++)
        {
            if(strlen(s[m])!=0)
            {
                for(int n=0;n<strlen(s[m]);n++)
                {
                    ans[a][b]=s[m][n];
                    b++;
                }
                a++;
            }
        }

        /*for(int p=0;p<j;p++)
        {
            printf("%s\n",s[p]);
        }*/

        qsort(s,j,sizeof(s[0]),cmp); //排序
        printf("case #%d:\n",i);

        for(int m=0;m<j;m++)
        {
            if(strlen(s[m])!=0)
            {
                printf("%s",s[m]);
                if(m!=j-1) printf(" ");
                else printf("\n");
            }
        }
    }
}
