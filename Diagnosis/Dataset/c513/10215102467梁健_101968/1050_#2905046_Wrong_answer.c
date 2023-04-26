#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int dis1(const void *a,const void *b,const void *c)
{
    char s[100],s1[100],s2[100];
    strcpy(s,(char*)c);strcpy(s1,(char*)a);strcpy(s2,(char*)b);
    int ep=0,Ep=-1,Sp=-1,R=0;
    int l=strlen(s);
    int l1=strlen(s1);
    int l2=strlen(s2);
    for(int m=0;m<l;m++){
        char jud1[100];
        for(int n=m;n<l1+m;n++)jud1[n-m]=s[n];
        if(strcmp(jud1,s1)==0){
            Sp=m+l1;
            break;
        }
        if(Sp!=-1)break;
    }
    for(int m=0;m<l;m++){
        char jud2[100];
        for(int n=m;n<l2+m;n++)jud2[n-m]=s[n];
        if(strcmp(jud2,s2)==0)ep=m;
        if(ep>Ep)Ep=ep;
    }
    if(Ep==-1||Sp==-1)return 0;
    else return (Ep-Sp);
}
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s1[90];char s2[90];char s[100];
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        int R1,R2,Res;
        R1=dis1(s1,s2,s);
        R2=dis1(s2,s1,s);
        Res=(R1>R2?R1:R2);
        printf("%d\n",Res);
    }
    return 0;
}
