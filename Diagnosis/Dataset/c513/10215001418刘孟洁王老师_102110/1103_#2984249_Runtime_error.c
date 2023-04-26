#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char s[3];int num;}val;

char s1[3] = {"IN"},s2[4] = {"MOV"},s3[4] = {"ADD"},s4[4] = {"SUB"},s5[4] = {"MUL"},s6[4] = {"DIV"},s7[4] = {"OUT"};

int main()
{
    int i,j = 0,k,h,h1,h2,sum;
    char imp[20],s[4],ele1[20],ele2[20];
    val cp[10];
    while(scanf("%s",s)!=EOF)
    {
        scanf("%s",imp);
        int len = strlen(imp);
        for(i = 0; imp[i] != ','; i++)ele1[i] = imp[i];
        ele1[i] = '\0';
        for(i += 1,k = 0; i < len; i++,k++)ele2[k] = imp[i];
        ele2[k] = '\0';
        if(strcmp(s,s1) == 0)
        {
            strcpy(cp[j].s,ele1);
            for(h = 0,sum = 0; h < k; h++)
                sum += ele2[h]-'0';
            cp[j++].num = sum;
        }
        else if(strcmp(s,s2) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;continue;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;continue;}
            }
            cp[h1].num = cp[h2].num;
        }
        else if(strcmp(s,s3) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;continue;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;continue;}
            }
            cp[h1].num += cp[h2].num;
        }
        else if(strcmp(s,s4) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;continue;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;continue;}
            }
            cp[h1].num -= cp[h2].num;
        }
        else if(strcmp(s,s5) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;continue;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;continue;}
            }
            cp[h1].num *= cp[h2].num;
        }
        else if(strcmp(s,s6) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;continue;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;continue;}
            }
            cp[h1].num /= cp[h2].num;
        }
        else if(strcmp(s,s7) == 0)
        {
            for(h = 0; h < j; h++)if(strcmp(ele1,cp[h].s) == 0){h1 = h;continue;}
            printf("%d\n",cp[h1].num);
        }
    }
    return 0;
}
