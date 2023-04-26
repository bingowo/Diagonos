#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int read()
{
    int t;
    char s[4];
    scanf("%s",s);
    if (strcmp(s,"A")==0) return 1;
    if (strcmp(s,"B")==0) return 2;
    if (strcmp(s,"AB")==0) return 3;
    if (strcmp(s,"O")==0) return 4;
    return 0;
}
int main()
{
    const int ABO[4][4][4]= {1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1, 0,0,0,1};
   char *s[4]= {"A","AB","B","O"};
    int mother,father,son;
    int testABO[4];
    mother=read();
    father=read();
    son=read();
    printf("%d%d%d\n",mother,father,son);
    if (son==0)
    {
        printf("%s %s {",s[mother-1],s[father-1]);
        int i;
        for ( i=0; i<4; i++) if (ABO[father-1][mother-1][i]==1)
            {
                printf("%s",s[i]);
                break;
            }
        for (i+=1; i<4; i++) if (ABO[father-1][mother-1][i]==1) printf(",%s",s[i]);
        printf("}\n");
    }
    else if (father==0)
    {
        int count=0;
        for (int i=0; i<4; i++ )if (ABO[i][mother-1][son-1]==1)count++;
        if (count==0) printf("%s impossible %s\n",s[mother-1],s[son-1]);
        else
        {
            printf("%s {",s[mother-1]);
            for (int i=0; i<4; i++)
                if(ABO[i][mother-1][son-1]==1)
                {
                    if(count==1) printf("%s",s[i]);
                    else
                    {
                        count--;
                        printf("%s,",s[i]);
                    }
                }
            printf("} %s\n",s[son-1]);
        }

    }
    else
    {
        int count=0;
        for (int i=0; i<4; i++ )if (ABO[i][father-1][son-1]==1)count++;
        if (count==0) printf("%s impossible %s\n",s[mother-1],s[son-1]);
        else
        {
            printf("{");
            for (int i=0; i<4; i++)
                if(ABO[father-1][i][son-1]==1)
                {
                    if(count==1) printf("%s",s[i]);
                    else
                    {
                        count--;
                        printf("%s,",s[i]);
                    }
                }
            printf("} %s %s\n",s[father-1],s[son-1]);
        }

    }
    return 0;
}
