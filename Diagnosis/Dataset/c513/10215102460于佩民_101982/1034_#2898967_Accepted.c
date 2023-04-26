#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a,const void *b);

double p[27];
int main(){
    int i,num,now=0;
    scanf("%d",&num);
    while(now<num){
        for(i=0;i<26;i++) scanf("%lf",&p[i]);
        char str[101]; scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #");
        printf("%d:\n",now);
        printf("%s\n",str);
        now++;}
return 0;}

int cmp(const void *a,const void *b)
{
    char ch1,ch2;
    int p1,p2;
    ch1=*((char *)a);
    ch2=*((char *)b);
    if(ch1>='a'&&ch1<='z') p1=ch1-'a'; else p1=ch1-'A';
    if(ch2>='a'&&ch2<='z') p2=ch2-'a'; else p2=ch2-'A';
    if(p[p2]>p[p1]) return 1;
    else if(fabs(p[p2]-p[p1])<1e-8)
        if(p1==p2) return ch2-ch1;
        else return p1-p2;
    else return -1;
}