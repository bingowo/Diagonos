#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    char s[5001];
    char *c[15][4000];
    int num[15];
    memset(num,0,sizeof(num));
    for(int i=0; i<t; i++)
    {
        scanf("%s",s);

        c[strlen(s)][num[strlen(s)]]=(char*)malloc(sizeof(char)*strlen(s));
        strcpy(c[strlen(s)][num[strlen(s)]],s);
        num[strlen(s)]++;
    }

    scanf("%s",s);
    for (int i=0; i<strlen(s); i++)
    {
        int find=0;
        for (int j=14; j>=1; j--)
            if (num[j]!=0)
            {
                char s1[16];
                for (int k=0; k<j; k++) s1[k]=s[i+k];
                s1[j]=0;

                for (int k=0; k<num[j]; k++)
                    if(strcmp(s1,c[j][k])==0)
                    {
                        find=1;
                        break;
                    }
                if (find==1)
                {
                    printf("%s ",s1);
                    i=i+j-1;
                    break;
                }
            }
        if (find==0)
            printf("%c ",s[i]);

    }
    for (int i=1; i<15; i++)
        for (int j=0; j<num[i]; j++)
            free(c[i][j]);
    return 0;
}