#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
double p[27];
char str[101];
float time[26];
int i;
int cmp(const void *a,const void *b)
{
    char *p1=(char *)a;
    char *p2=(char *)b;

    if(*p1==*p2+32) return -1;
    if(*p1==*p2-32) return 1;

    int t1= *p1<=96 ? *p1-'A':*p1-'a';
    int t2= *p2<=96 ? *p2-'A':*p2-'a';

    if(time[t1]>time[t2]) return -1;
    else return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        printf("case #%d:\n",i);
        for(int j=0;j<26;j++){
            scanf("%f",time+j);
        }
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(char),cmp);
        printf("%s\n",str);
    }
}