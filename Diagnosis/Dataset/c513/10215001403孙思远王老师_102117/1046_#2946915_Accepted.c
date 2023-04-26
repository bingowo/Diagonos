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
        char F21[4]="THe",F23[3]="An",F24[3]="Of",F25[4]="FOr",F26[4]="ANd";
        char F31[4]="ThE",F33[3]="aN",F34[3]="oF",F35[4]="FoR",F36[4]="AnD";
        char F41[4]="tHE",F45[4]="fOR",F46[4]="aND";
        char F51[4]="The",F55[4]="foR",F56[4]="anD";
        char F61[4]="thE",F65[4]="For",F66[4]="And";
        char F71[4]="tHe",F75[4]="fOr",F76[4]="aNd";
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
               &&strcmp(s,F21)!=0&&strcmp(s,F31)!=0&&strcmp(s,F41)!=0&&strcmp(s,F51)!=0&&strcmp(s,F61)!=0&&strcmp(s,F71)!=0
               &&strcmp(s,F23)!=0&&strcmp(s,F24)!=0&&strcmp(s,F25)!=0&&strcmp(s,F26)!=0&&strcmp(s,F33)!=0&&strcmp(s,F34)!=0
               &&strcmp(s,F35)!=0&&strcmp(s,F36)!=0&&strcmp(s,F45)!=0&&strcmp(s,F55)!=0&&strcmp(s,F65)!=0&&strcmp(s,F75)!=0
               &&strcmp(s,F46)!=0&&strcmp(s,F56)!=0&&strcmp(s,F66)!=0&&strcmp(s,F76)!=0)
                all++;
        }
        printf("%d\n",all);
    }
    return 0;
}
