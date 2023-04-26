#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {char temp[27];} string;
int cmp(const void *a,const void *b)
{
    string *a1=(string*)a,*b1=(string*)b;
    return strcmp(a1->temp,b1->temp);
}
int main()
{
    int T;
    scanf ("%d",&T);
    getchar();
    for (int q=0;q<T;q++)
    {
        char c,t[27];
        int i=0,j=0,flag=1;
        string s[501];
        while ((c=getchar())!='\n')
        {
            if (c==' '||c==','||c=='.'||c=='!'||c=='?')
            {
                i=0;flag=1;
                for (int k=0;k<j;k++)
                {
                    if (strcmp(s[k].temp,s[j].temp)==0)
                    {
                        flag=0;
                        break;
                    }
                }
                if (flag) j++;
                else memset(s[j].temp,0,sizeof(s[j].temp));
            }
            else
            {
                s[j].temp[i++]=c;
            }
        }//去重
         j++;
         qsort(s,j,sizeof(s[0]),cmp);//排序
         printf("case #%d:\n",q);
         for (int i=0;i<j-1;i++)
         {
             printf("%s%c",s[i].temp,(i==j-1)?'\n':' ');
         }
    }
    return 0;
}
