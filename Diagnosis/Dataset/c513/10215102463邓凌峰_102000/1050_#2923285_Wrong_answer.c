#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int left(char *s,char *s1)
{
    char *L;
    L=strstr(s,s1);
    return L==0?-1:L-s;
//    char* p=strstr(s,s1);
//    return p==0?-1:p-s;
}

int right(char*s,char*s1)
{

    char *p=s,*p1=0;
    while ((p1=strstr(p,s1))!=0) p=p1+1;
    return p-s-1;
}

int max(int a,int b) { return a>b?a:b; }



int main()
{
    int T;scanf("%d",&T);
    char xx=getchar();
    for(int i=0;i<T;i++){
        char s1[81],s2[81],s[81];
        gets(s1);gets(s2);gets(s);
        int L=left(s,s1),R=right(s,s2);
        printf("%d %d\n",L,R);
        if(L!=-1 &&R!=-1)printf("case #%d:\n%d\n",i,max(R-L-strlen(s1),0));
        else printf("0");
    }

    return 0;
}
