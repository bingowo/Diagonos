#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        int all=0,i;
        printf("case #%d:\n",t);
        char a[101];
        char f1[4]="the",f2[2]="a",f3[3]="an",f4[3]="of",f5[4]="for",f6[4]="and";
        char F1[4]="THE",F2[2]="A",F3[3]="AN",F4[3]="OF",F5[4]="FOR",F6[4]="AND";
        char Ff1[4]="The",Ff3[3]="An",Ff4[3]="Of",Ff5[4]="For",Ff6[4]="And";
        gets(a);
        for(i=0;i<strlen(a);i++)
        {
            int j=0;
            char s[101]={'\0'};
            while(a[i]!=' '&&i<strlen(a))
            {
                s[j]=a[i];
                i++;
                j++;
            }
            if(strcmp(s,f1)!=0&&strcmp(s,f2)!=0&&strcmp(s,f3)!=0&&strcmp(s,f4)!=0&&strcmp(s,f5)!=0&&strcmp(s,f6)!=0
               &&strcmp(s,F1)!=0&&strcmp(s,F2)!=0&&strcmp(s,F3)!=0&&strcmp(s,F4)!=0&&strcmp(s,F5)!=0&&strcmp(s,F6)!=0
               &&strcmp(s,Ff1)!=0&&strcmp(s,Ff3)!=0&&strcmp(s,Ff4)!=0&&strcmp(s,Ff5)!=0&&strcmp(s,Ff6)!=0)
                all++;
        }
        printf("%d\n",all);
    }
    return 0;
}
