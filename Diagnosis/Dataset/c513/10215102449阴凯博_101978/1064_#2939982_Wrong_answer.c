#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char s1[15];
} NUM;

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[120]={0}; char pn[60]={0};
        int j=0,k=0,h=0,l=0;
        gets(s);
        for (j=0;j<strlen(s);j++)
        {
            if (ispunct(s[j]))
                pn[h++]=s[j];
        }
        NUM* arr=(NUM*)calloc(h+1,sizeof(NUM));
        for (j=0;j<strlen(s);j++)
            if (isdigit(s[j]))
            {
                while (s[j]!=' ' && j<strlen(s))
                {
                    arr[l].s1[k++]=s[j++];
                }
                k=0;
                l++;
            }
        double result=strtod(arr[0].s1,&arr[0].s1[strlen(arr[0].s1)]);

        for (k=0,l=1;k<h;k++)
        {
            if (pn[k]=='+')
                result=result+strtod(arr[l].s1,&arr[l].s1[strlen(arr[l].s1)]);
            if (pn[k]=='-')
                result=result-strtod(arr[l].s1,&arr[l].s1[strlen(arr[l].s1)]);
            if (pn[k]=='*')
                result=result*strtod(arr[l].s1,&arr[l].s1[strlen(arr[l].s1)]);
            if (pn[k]=='/')
                result=result/strtod(arr[l].s1,&arr[l].s1[strlen(arr[l].s1)]);
        }
        printf("%lf\n",result);


    }
    return 0;
}
