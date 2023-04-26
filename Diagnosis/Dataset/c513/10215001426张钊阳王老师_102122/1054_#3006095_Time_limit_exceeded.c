#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int M;
        scanf("%d\n",&M);
        char s[2005];
        memset(s,'\0',2005);
        gets(s);

        int l=strlen(s);
        int cnt[2000]={0};//cnt统计的是每个单词的长度

        int t=0;
        int cnt0=0;
        int cnt00=0;
        for(int i=0;i<l;i++)
        {
            while(s[i]==' '&&s[i+1]==' ')
            {
                s[i]='\0';
                i++;
            }
        }
        char s0[2005];
        memset(s0,'\0',2005);
        for(int j=0,i=0;j<l;j++)
        {
            if(s[j]!='\0')
            {
                s0[i]=s[j];
                i++;
            }
        }
        memset(s,'\0',2005);
        strcpy(s,s0);

        for(int i=0;i<l;i++)
        {
            while(s[i]!=' ')
            {
                if(i==l-1) break;
                cnt[t]++;
                i++;
            }
           t++;
        }

        int num=t;//num表示单词总数 全部组加起来的单词总数
        int zushu=0;
        int zu[2000]={0};//表示的是第k组的单词数
        for(int i=0,k=0;i<num;)
        {
            int len=0;
            while((len+1+cnt[i])<=M+1)
            {
                len+=1+cnt[i];
                i++;
                zu[k]++;
            }
            k++;
            zushu++;
        }

        printf("case #%d:\n",z);

        int flag=0;
        int flag0=0;

        for(int k=0;k<zushu;k++)
        {
            int sumk=0;
            int bu0,jian,base,i0=0;
            for(;i0<zu[k];i0++)
            {
                 sumk+=cnt[flag0+i0];
            }
            flag0+=i0;

            bu0=M-sumk;
            jian=zu[k]-1;
            int kong[2000];
            int u;
            base=bu0/jian;
            u=bu0%jian;
            int u0=u;



            for(int g=0;g<jian;)
            {
                if(u==0)
                {
                    kong[jian-1-g]=base;
                    g++;
                }
                else if(u>0)
                {
                    kong[jian-1-g]=base+1;
                    u--;
                    g++;
                }
            }

            int j,i;
            if(flag!=0) flag++;
            for(j=0,i=0;i<zu[k];j++,i++)
            {
                while(s[flag+j]!=' '&&s[flag+j]!='\0')
                {
                    printf("%c",s[flag+j]);
                    j++;
                }
                if(i<jian)
                {
                    for(int f=0;f<kong[i];f++)
                        printf(" ");
                }
            }

            flag+=j-1;
            printf("\n");
        }
    }
    return 0;
}
