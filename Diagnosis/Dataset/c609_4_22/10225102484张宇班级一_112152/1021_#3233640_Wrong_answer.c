#include <stdio.h>
#include<stdlib.h>
#include <string.h>
char p[27];
int cmp(const void *a,const void *b){
    char *s1,*s2;char ch1,ch2;
    s1=*(char (*)[21])a;s2=*(char (*)[21])b;
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;
        ch2=(*s2)>='a'?*s2-32:*s2;
        if(p[ch1-'A']!=p[ch2-'A'])
                return p[ch1-'A']-p[ch2-'A'];
        else {s1++;s2++;}
    }
    if(*s1==0) return -1;
    else return 1;
}
int main(){
scanf("%s",p);
char a[100][21];
int n;
while (scanf("%s",a[n])!=EOF)
n++;
qsort(a,n,sizeof(a[0]),cmp);
for(int i=0;i<n;i++)
    printf("%s",a[i]);
return 0;


}