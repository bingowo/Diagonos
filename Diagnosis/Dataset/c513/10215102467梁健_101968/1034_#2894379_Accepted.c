#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
double fre[27];
int comp1(const void *a,const void *b)
{
    char a1=*(char *)a,b1=*(char *)b;
    if(a1-b1==32||a1==b1)return -1;
    else if(b1-a1==32)return 1;
    if(65<=a1&&a1<=90)a1=a1-65;
    else a1=a1-97;
    if(65<=b1&&b1<=90)b1=b1-65;
    else b1=b1-97;
    if(fre[a1]!=fre[b1])return fre[b1]>fre[a1]?1:-1;
    else return a1-b1;

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        for(int fr=0;fr<26;fr++)scanf("%lf",&fre[fr]);
        char s[101];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(char),comp1);
        printf("%s\n",s);
    }
    return 0;
}
