#include <stdio.h>
#include <stdlib.h>

int main()
{int p[26];
char s[27];
char a[100][21];
char string[2200];
int i,count,j,k,l;
while(scanf("%s\n",s)!=EOF)
{

for(i=0;i<26;i++)
{p[s[i]-'A']=i;}
int cmp(const void*a,const void*b)
{char*s1,*s2;
char ch1,ch2;
s1=(char*)a;s2=(char*)b;
while(*s1&&*s2)
{ch1=*s1>='a'?*s1-32:*s1;
 ch2=*s2>='a'?*s2-32:*s2;
 if(p[ch1-'A']!=p[ch2-'A']) return p[ch1-'A']-p[ch2-'A'];

else{s1++;s2++;}}
if(*s1==0) return -1;
else return 1;

}
gets(string);
count=0;j=0;
while(1){k=0;
        while(string[j]!=' '&&string[j])a[count][k++]=string[j++];
a[count][k]=0;
count++;
if(!string[j]) break;
else j++;}
qsort(a,count,sizeof(a[0]),cmp);
for(l=0;l<count-1;l++)
{printf("%s ",a[l]);}
printf("%s",a[l]);
}}

