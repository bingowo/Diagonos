#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{char s[110];}node;
int aa[30]={0};
int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    for(int i=0;p1.s[i];i++)
    {
        if(p1.s[i]>='a'&&p1.s[i]<='z')p1.s[i]-=32;
    }
    for(int i=0;p2.s[i];i++)
    {
        if(p2.s[i]>='a'&&p2.s[i]<='z')p2.s[i]-=32;
    }
    int k=0;
    while(p1.s[k]&&p2.s[k])
    {
        if(aa[p1.s[k]-'A']==aa[p2.s[k]-'A'])k++;
        else return aa[p1.s[k]-'A']-aa[p2.s[k]-'A'];
    }
if(p1.s[k]==0)return -1;
if(p2.s[k]==0)return 1;
}
int main()
{
    char s1[30];char s2[12000];
    while(gets(s1)!=NULL)
{

    for(int i=0;i<26;i++)
        aa[s1[i]-'A']=i;

    node p[101]={0};
    gets(s2);
    int cnt=0;
    int k=0;
    int j=0;
    while(1)
    {
        if(s2[k]==' '){p[cnt].s[j++]='\0';cnt++;k++;j=0;}
        else if(s2[k]=='\0'){
            p[cnt].s[j++]='\0';break;
        }
        else{p[cnt].s[j++]=s2[k];
            k++;
        }
    }
    qsort(p,cnt+1,sizeof(p[0]),cmp);
    int i;
    for( i=0;i<=cnt;i++)
        printf("%s ",p[i].s);
   printf("%s\n",p[i].s);


}



}
