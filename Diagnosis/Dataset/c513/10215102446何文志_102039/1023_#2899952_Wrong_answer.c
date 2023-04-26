#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Mystr
{
    char s0[40];
    int digit;
    char s1[40];
}mystr;

int cmp(const void *a, const void *b)
{
    mystr A = *(mystr*)a, B = *(mystr*)b;
    if(A.digit!=B.digit){return A.digit-B.digit;}
    else {return strcmp(A.s1,B.s1);}

}

int main()
{
    mystr s[100];memset(s,0,100*sizeof(mystr));
    int cnt = 0;
    while(scanf("%s",s[cnt].s0)!=EOF)
    {

        sscanf(s[cnt].s0,"%[^0-9]%d",s[cnt].s1,&s[cnt].digit);
        cnt++;
    }
    qsort(s,cnt,sizeof(s[0]),cmp);
    //printf("cnt = %d\n",cnt);
    for(int i = 0;i<cnt;i++)
    {
        printf("%s ",s[i].s0);
        //printf("s = %s, digit = %d, s1 = %s\n",s[i].s0,s[i].digit,s[i].s1);
    }
    return 0;
}
