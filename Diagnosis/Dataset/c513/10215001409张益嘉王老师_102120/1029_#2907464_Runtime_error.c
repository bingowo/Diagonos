#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int flag;
    char text[100];
}special;

int splitstring(char* zong,char sign,char* fen[],int maxn)
{
    int len,i,co=0;
    len=strlen(zong);
    fen[co++]=zong;
    for(i=0;i<len;i++)
    {
        if(zong[i]==sign)
        {
            zong[i]=0;
            fen[co++]=&zong[i+1];
            if(co>=maxn) break;
        }

    }
    return co;

}

int cmp(const void*a,const void*b)
{
    char aa=*((char*)a);
    char bb=*((char*)b);

    return aa-bb;

}

int main()
{
    int t,i;
    char ss[5];
    gets(ss);
    t=atoi(ss);
    for(i=0;i<t;i++)
    {
        char s[300];
        char *word[200];
        char *res[200];
        int j,co,m,k,p;
        special te[200],fei[200];
        char sum[300];
        memset(sum,0,300*sizeof(char));
        //memset(res,0,200*sizeof(char*));
        for(j=0;j<200;j++)
        {
            res[j]=(char*)malloc(200*sizeof(char));
        }
        memset(te,0,200*sizeof(special));
        gets(s);
        co=splitstring(s,' ',word,200);
        //printf("co=%d\n",co);
        for(j=0,k=0,p=0;j<co;j++)
        {
            if((strcmp(word[j],"A")<0)||(strcmp(word[j],"Z")>0)) {te[k].flag=j;strcpy(te[k].text,word[j]);k++;}

            else strcat(sum,word[j]);
            fei[p].flag=strlen(word[j]);
            p++;
        }
        int nofsp=k;
        //printf("sum=%s\n",sum);

        qsort(sum,strlen(sum),sizeof(char),cmp);
        //printf("sum=%s\n",sum);

        p=0;
        for(j=0,m=0;j<co;j++,m++)
        {
            for(k=0;k<nofsp;k++)
            {
                if(j==te[k].flag)
                    {
                        res[j]=te[k].text;
                        break;
                    }
            }
            if(k>=nofsp)
            {
                char mid[200];
                memset(mid,0,200*sizeof(char));
                for(int mi=0;mi<fei[m].flag;mi++)
                {
                    mid[mi]=sum[p++];
                }
                strcpy(res[j],mid);
            }
        }
        printf("case #%d:\n",i);
        for(j=0;j<co-1;j++)
        {
            printf("%s ",res[j]);
        }
        printf("%s\n",res[j]);
    }
    return 0;
}
