#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int flag;
    char text;
}special;

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
        char s[3000];
        char res[2000];
        int j,co,m,k,p=0;
        special te[2000];
        char sum[3000];
        memset(sum,0,3000*sizeof(char));
        memset(res,0,2000*sizeof(char));
        memset(s,0,3000*sizeof(char));
        memset(te,0,2000*sizeof(special));
        gets(s);
        int len=strlen(s);
        for(j=0,k=0;j<len;j++)
        {
            if((s[j]>='A')&&(s[j]<='Z')) sum[k++]=s[j];
            else
            {
                te[p].flag=j;
                te[p].text=s[j];
                p++;
            }
        }
        co=k;
        int nofp=p;
        qsort(sum,co,sizeof(char),cmp);

        for(j=0,m=0;j<len;j++)
        {
            for(k=0;k<nofp;k++)
            {
                if(j==te[k].flag)
                    {
                        res[j]=te[k].text;
                        break;
                    }
            }
            if(k>=nofp)
            {
                res[j]=sum[m++];
            }
        }
        printf("case #%d:\n",i);
        printf("%s\n",res);


    }

    return 0;
}
