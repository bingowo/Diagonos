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
        int i=0,j=0,flag=1,sum=0;
        string s[501]={};
        while ((c=getchar())!='\n')
        {
            if (c==' ')
            {
                j++;
                i=0;
            }
            else
            {
                s[j].temp[i++]=c;
            }
        }
        j++;
        for (int k=0;k<j;k++)
        {
            if (strcmp(s[k].temp,"the")!=0&&strcmp(s[k].temp,"a")!=0&&strcmp(s[k].temp,"an")!=0&&strcmp(s[k].temp,"of")!=0&&strcmp(s[k].temp,"for")!=0&&strcmp(s[k].temp,"and")!=0&&strcmp(s[k].temp,"THE")!=0&&strcmp(s[k].temp,"A")!=0&&strcmp(s[k].temp,"AN")!=0&&strcmp(s[k].temp,"AND")!=0&&strcmp(s[k].temp,"OF")!=0&&strcmp(s[k].temp,"For")!=0&&strcmp(s[k].temp,"The")!=0&&strcmp(s[k].temp,"An")!=0&&strcmp(s[k].temp,"anD")!=0&&strcmp(s[k].temp,"OF")!=0&&strcmp(s[k].temp,"FOR")!=0)
                sum++;
        }
        printf("case #%d:\n",q);
        printf("%d\n",sum);
    }
    return 0;
}
