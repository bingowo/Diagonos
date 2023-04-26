#include <stdio.h>
#include <stdlib.h>
int p[128]={0};

int cmp(const void *a,const void *b)
{
    char *s1=(char *)a;
    char *s2=(char *)b;
    int i=0;
    while(s1!=NULL&&s2!=NULL)
    {
        if(p[s1[i]]!=p[s2[i]])
            return p[s1[i]]-p[s2[i]];
        else
        {
            s1++;
            s2++;
        }
    }
    if(s1==NULL)
        return -1;
    else
        return 1;
}
int main()
{
    char s[27];
    for(int i=0;i<128;i++)
    p[i]=-1;
    while(scanf("%s",s)!=EOF)
    {
        for(int i=0;i<26;i++)
        {
            p[s[i]]=i;
            p[s[i]-'A'+'a']=i;
        }
        char a[105][100],c;
        int cnt=0,k=0,state=0;
        c=getchar();
        while(1)
        {
            c=getchar();
            if(c=='\n')
                break;
            if(c!=' '&&c!='\n')
            {
                a[cnt][k++]=c;
                state=1;
            }
            else if(state==1)
            {
                a[cnt][k]='\0';
                cnt++;
                state=0;
                k=0;
            }
        }
        a[cnt][k]='\0';
        cnt++;
        qsort(a,cnt,sizeof(a[0]),cmp);
        for(int j=0;j<cnt;j++)
            printf("%s ",a[j]);
        printf("\n");
        for(int i=0;i<26;i++)
        {
            p[i]=-1;
        }
    }
    return 0;
}
