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
        else i++;
    }
    if(s1==NULL)
        return -1;
    else
        return 1;
}
int main()
{
    char s[26];
    while(scanf("%s",s)!=EOF)
    {
        for(int i=0;i<26;i++)
        {
            p[s[i]]=i;
            p[s[i]+'a'-'A']=i;
        }
        char a[100][100],c;
        int cnt=0,k=0;
        c=getchar();
        while(1)
        {
            c=getchar();
            if(c=='\n')
                break;
            else if((c<='z'&&c>='a')||(c<='Z'&&c>='A'))
            {
                a[cnt][k++]=c;
            }
            else if(c==' ')
            {
                cnt++;
                k=0;
            }
        }

        cnt++;
        qsort(a,cnt,sizeof(a[0]),cmp);
        for(int j=0;j<cnt;j++)
            printf("%s ",a[j]);
        printf("\n");
        for(int i=0;i<26;i++)
        {
            p[i]=0;
         //   printf("%d",p[i]);
        }
    }
    return 0;
}
