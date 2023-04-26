#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Mystr
{
    char s0[40];
    int digit;
    char sdigit[40];
    char s1[40];
    char s2[40];
}mystr;

int cmp(const void *a, const void *b)
{
    mystr A = *(mystr*)a, B = *(mystr*)b;
    if(strcmp(A.sdigit,B.sdigit)!=0){return strcmp(A.sdigit,B.sdigit);}
    else {return strcmp(A.s1,B.s1);}

}

int main()
{
    mystr s[100];memset(s,0,100*sizeof(mystr));
    int cnt = 0;
    while(scanf("%s",s[cnt].s0)!=EOF)
    {

        sscanf(s[cnt].s0,"%[^0-9]%[0-9]%[^0-9]",s[cnt].s1,s[cnt].sdigit,s[cnt].s2);
        strcat(s[cnt].s1,s[cnt].s2);
        sscanf(s[cnt].sdigit,"%d",&s[cnt].digit);
        cnt++;
    }

    qsort(s,cnt,sizeof(s[0]),cmp);
    //printf("cnt = %d\n",cnt);
    for(int i = 0;i<cnt;i++)
    {
        printf("%s ",s[i].s0);
        //printf("s = %s, digit = %d, sdigit = %s,s1 = %s, s2 = %s\n"
        //       ,s[i].s0,s[i].digit,s[i].sdigit,s[i].s1,s[i].s2);
    }
    return 0;
}
