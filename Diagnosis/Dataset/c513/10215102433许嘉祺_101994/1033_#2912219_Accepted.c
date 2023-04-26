#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct pi
{
    char s[100];
    int n;

} day[10000];

int cmp(const void*a,const void*b){
    int d1=((struct pi*)a)->n,d2=((struct pi*)b)->n;
    if (d1>d2) {return 1;}
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    char s2[10];
    int n1;
    char s3[18][10]= {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
    for (int i=0; i<t; i++)
    {

        scanf("%d",&n1);
        char c=getchar();
        for (int j=0; j<n1; j++)
        {
            gets(day[j].s);
            int find=0;
            char*s1=day[j].s;
            day[j].n=0;
            while(s1[find]!='.') day[j].n=day[j].n*10+s1[find++]-'0';
            find=find+2;
            int len=0;
            while (s1[find]!=' ') s2[len++]=s1[find++];
            s2[len]=0;
            find++;
            int year=0;
            while (s1[find]!=0) year=year*10+s1[find++]-'0';
            day[j].n+=(year-2000)*365;

            for (int k=0; k<18; k++)
                if (strcmp(s2,s3[k])==0) break;
                else day[j].n+=20;
        }
        qsort(day,n1,sizeof(day[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0; j<n1; j++)
            printf("%s\n",day[j].s);


    }
    return 0;
}
