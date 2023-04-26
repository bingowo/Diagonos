#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 501



int cmp(const void*p1,const void*p2)
{
    char *p_1 = *(char(*)[num])p1;
    char *p_2 = *(char(*)[num])p2;
    return strcmp(p_1,p_2);
}
    int main()
    {
        char s[6] = {',','.','!','?',' '};
        int t;
        scanf("%d",&t);
        getchar();
        for (int i=0;i<t;i++)
        {
            printf("case #%d:\n",i);
            char(*p)[num]=(char(*)[num])malloc(sizeof(char)*num*num);
            int n=0;
            int len =0;
            char c;
            while((c=getchar())!='\n')
            {
                 int i;
                 for(i =0;i<5;i++)
                {
                    if(s[i] == c)break;
                }
                if(i==5)p[n][len++] = c;
                else if(len !=0)
                {
                    p[n][len] = 0;
                    n++;
                    len = 0;
                }
            }
            p[n][len] =0;
            qsort(p,n,sizeof(char)*num,cmp);
            int po = 1;
            printf("%s ",p[0]);
            while(po<n)
            {
                if(strcmp(p[po],p[po-1]))
                {
                    printf("%s ",p[po]);
                    po++;
                }
                else po++;
            }
            if(i!=t-1)printf("\n");

            free(p);
        }

    return 0;
    }
