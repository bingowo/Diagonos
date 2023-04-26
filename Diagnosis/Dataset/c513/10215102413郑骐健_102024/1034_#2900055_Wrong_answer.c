#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>



struct alph
{
    char s;
    double weight;
};
struct alph s1[26];

int cmp1(const void*p1,const void*p2)
{
    char *p_1= (char*)p1;
    char*p_2 = (char*)p2;
    int n1 = 0,n2= 0;
    for(;n1<26;n1++)
    {
        if(*p_1 == s1[n1].s||*p_1 == s1[n1].s+'A' -'a')break;
    }
     for(;n2<26;n2++)
    {
        if(*p_2 == s1[n2].s||*p_2 == s1[n2].s+'A' -'a')break;
    }
    if(n1 == n2)return -*p_1 +*p_2;
    return (n1>n2)?1:-1;
}
int cmp(const void*p1,const void*p2)
{
    struct alph* p_1 =(struct alph*)p1;
     struct alph*p_2 = (struct alph*)p2;
    return ((*p_1).weight<(*p_2).weight)?1:-1;
}
int main()
{
    int t;
    scanf("%d",&t);
    int i =0;
    for(;i<t;i++)
    {
        char s[102];

        for(int q = 0;q <26;q++)
        {
            s1[q].s = q+'a';
            scanf("%lf",&s1[q].weight);
        }
        scanf("%s",s);
        qsort(s1,26,sizeof(struct alph),cmp);
        qsort(s,strlen(s),sizeof(char),cmp1);

    scanf("case #%d:\n",i);
    for(int i =0;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
    }
    return 0;
}
