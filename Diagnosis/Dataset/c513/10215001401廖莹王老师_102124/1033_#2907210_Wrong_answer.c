#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char day[5];
    char month[10];
    int year;
}lunar;
int number(char s[10])
{
    int i;
    char month[][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(i=0;i<19;i++){if(strcmp(s,month[i])==0)return i;}
}
int cmp(const void*a,const void*b)
{
    lunar *s1,*s2;
    int k1,k2,d1,d2,i;
    s1=(lunar*)a;
    s2=(lunar*)b;
    k1=number(s1->month);
    k2=number(s2->month);
    if(s1->year!=s2->year)return s1->year-s2->year;
    else
    {
        if(k1!=k2)return k1-k2;
        else
        {
            for(i=0;s1->day[i]!='.';i++)d1=d1*10+(s1->day[i]-'0');
            for(i=0;s2->day[i]!='.';i++)d2=d2*10+(s2->day[i]-'0');
            return d1-d2;
        }
    }

}
void paixu(h)
{
    int n,i;
    lunar p[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",p[i].day);
        scanf("%s",p[i].month);
        scanf("%d",&p[i].year);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    printf("case #%d:\n",h);
    for(i=0;i<n;i++)
    {
        printf("%s ",p[i].day);
        printf("%s ",p[i].month);
        printf("%d\n",p[i].year);
    }

}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
        paixu(h);
}
