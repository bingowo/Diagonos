#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{char s[35];int num;}node;
int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.num!=p2.num)return p1.num-p2.num;
    else return strcmp(p1.s,p2.s);



}
int main()
{
    node p[101]={0};
    int cnt=0;
    while(scanf("%s",p[cnt].s)!=EOF)
    {
int l=strlen(p[cnt].s);
int k;
for(k=0;k<l;k++)
{
    if(p[cnt].s[k]>='0'&&p[cnt].s[k]<='9')break;

}
if(k==l)p[cnt].num=-1;
else{int sum=0;
        for(int i=k;p[cnt].s[i]>='0'&&p[cnt].s[k]<='9';i++)
sum=sum*10+p[cnt].s[i]-'0';
p[cnt].num=sum;

}
        cnt++;;

    }
   
    qsort(p,cnt,sizeof(p[0]),cmp);
for(int i=0;i<cnt;i++) printf("%s ",p[i].s);
return 0;

}
