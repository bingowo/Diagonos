#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int cmp1(const void*a,const void*b)
{
    char c=*(char*)a;
    char d=*(char*)b;
    if(c<d) return -1;
    else return 1;
}

int cmp2(const void*a,const void*b)
{
    char *c=*(char**)a;
    char *d=*(char**)b;
    if(strcmp(c,d)<0) return -1;
    else return 1;
}

int main()
{
    int i,j,T,k;
    char s1[17],s2[17];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s1);
        int l=strlen(s1);
        int p[128];
        for(j=0;j<128;j++)
            p[j]=-1;
        for(j=0,k=0;j<l;j++)
        {
            if(p[s1[j]]==-1)
            {
                s2[k++]=s1[j];
                p[s1[j]]=0;
            }
        }
        int len=k;
        qsort(s2,len,sizeof(s2[0]),cmp1);
        char **t;
        t=(char**)malloc(pow(2,len)*sizeof(char*));
        for(j=0;j<pow(2,len);j++)
            t[j]=(char*)malloc(17*sizeof(char));
        for(j=1;j<pow(2,len);j++)
        {
            for(l=0,k=0;l<len;l++)
            {
                if((j>>l)&1)
                {
                    t[j-1][k++]=s2[l];
                }
            }
            t[j-1][k]='\0';
        }
        qsort(t,j-1,sizeof(t[0]),cmp2);
        printf("case #%d:\n",i);
        for(k=0;k<j-1;k++)
            printf("%s\n",t[k]);
        memset(s2,0,sizeof(s2[0]));
    }
    return 0;
}
