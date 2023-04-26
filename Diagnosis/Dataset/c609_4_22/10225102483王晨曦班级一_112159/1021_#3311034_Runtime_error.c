#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int order[26];

int cmp(void const *p1,void const *p2)
{
    char *q1,*q2;
    q1=*(char(*)[21])p1;
    q2=*(char(*)[21])p2;

    char letter1,letter2;

    while(*q1&&*q2)
    {
        letter1=(*q1)>='a'? *q1-32:*q1;
        letter2=(*q2)>='a'? *q2-32:*q2;
        if(order[letter1-'A']!=order[letter2-'A'])
            return order[letter1-'A']-order[letter2-'A'];
        else
        {
            q1++;
            q2++;
        }
    }
    if(*q1==0) return -1;
    else return 1;
}

int main()
{
    char letter[26];
    while(scanf("%s",letter)!=EOF)
    {
        for(int i=0; i<26; i++)
            order[letter[i]-'A']=i;
        getchar();
    }

    char a[3001];
    fgets(a,3000,stdin);

    char str[100][21]={0};
    int cnt=0;
    char *p=a;
    while(~sscanf(p,"%s",str[cnt]))
        {p=p+strlen(str[cnt])+1;cnt++;}

    qsort(str,cnt,sizeof(str[0]),cmp);

    for(int k=0;k<cnt-1;k++)
        printf("%s",str[k]);

    return 0;
}
