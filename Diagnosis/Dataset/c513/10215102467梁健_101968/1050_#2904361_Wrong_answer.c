#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int ep=-1,Ep=-1,Sp=-1,R;
        char s1[100];char s2[100];char s[100];
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        int l=strlen(s);
        int l1=strlen(s1);
        int l2=strlen(s2);
        for(int m=0;m<l+1;m++){
            char jud1[l1+10];
            for(int n=m;n<l1+m;n++){
                jud1[n-m]=s[n];
                if(strcmp(jud1,s1)==0){
                    Sp=m+l1;
                    break;
                }
            }
            if (Sp!=-1)break;
        }
        for(int m=0;m<l+1;m++){
            char jud2[l2+10];
            for(int n=m;n<l2+m;n++){
                jud2[n-m]=s[n];
                if(strcmp(jud2,s2)==0)ep=m;
                if(ep>Ep)Ep=ep;
            }
        }
        printf("%d %d\n",l1,l2);
        printf("%d %d\n",Sp,Ep);
        if(Sp==-1||Ep==-1)printf("0\n");
        else printf("%d\n",R);
    }
    return 0;
}
