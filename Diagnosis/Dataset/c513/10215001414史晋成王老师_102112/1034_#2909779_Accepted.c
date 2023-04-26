#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double a[28];
int cmp(const void*c,const void*b)
{ char ch1,ch2; int p1,p2;
    ch1=*((char*) c);
    ch2=*((char*) b);
    if (ch1>='a'&&ch1<='z') p1=ch1-'a'; else p1=ch1-'A';
    if (ch2>='a'&&ch2<='z') p2=ch2-'a'; else p2=ch2-'A';
    if(a[p2]>a[p1]) return 1;
    else if(fabs(a[p2]-a[p1])<1e-8)
    if(p1==p2) return ch2-ch1;
    else return p1-p2;
    else return -1;
}
int main()
{ int T,i,j; char s[101];
scanf("%d",&T);
for(i=0;i<T;i++)
{ for(j=0;j<26;j++)
    scanf("%lf",&a[j]);
    scanf("%s\n",s);
    qsort(s,strlen(s),sizeof(s[0]),cmp);
    printf("case #%d:\n",i);
    printf("%s\n",s);
}
    
}