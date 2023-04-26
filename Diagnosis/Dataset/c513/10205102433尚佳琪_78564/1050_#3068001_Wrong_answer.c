#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
typedef struct
{
    char word[100];
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    return strcmp(s1.word,s2.word);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s1[100],s2[100],s3[100];
        scanf("%s %s %s",s1,s2,s3);
        int len3=strlen(s3),len2=strlen(s2),len1=strlen(s1);
        int k=0,t=len2-1;
        int j;
        for(j=0;j<len3;j++)
        {
            while(s3[j]==s1[k]&&k<=len1-1)
            {
                j++;
                k++;
            }
            if(k==len1)
                break;
            else k=0;
        }
       // printf("%d\n",j);
       int j1=j-len1;
        int p;
        for(p=len3-1;p>=0;p--)
        {
            while(s3[p]==s2[t]&&t>=0)
            {
            //     printf("%c ",s2[t]);
                p--;
                t--;
            }
            if(t==-1)
                break;
            else
                t=len2-1;
        }
        int p1=p+len2;
        if(j<p)
        //printf("%d\n",p);
        printf("case #%d:\n%d\n",i,p-j+1);
        else if(p1<j1)
        {
            int k=len2-1,t=0;
            int p;
            for(p=len3-1;p>=0;p--)
            {
                while(s3[p]==s1[k]&&k>=0)
                {
            //     printf("%c ",s2[t]);
                    p--;
                    k--;
                }
                if(k==-1)
                    break;
                else
                    k=len2-1;
            }
            int j;
            for(j=0;j<len3;j++)
            {
                while(s3[j]==s2[t]&&k<=len2-1)
                {
                    j++;
                    t++;
                }
                if(t==len2)
                    break;
                else t=0;
            }
            printf("case #%d:\n%d\n",i,p-j+1);
        }
        else
                printf("case #%d:\n0\n",i);
    }
}
