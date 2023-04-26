#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char jud[128];
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int ep=0,Ep=0,Sp=-1,R=0;
        char s1[81];char s2[81];char s[81];
        scanf("%s",s1);scanf("%s",s2);scanf("%s",s);
        int l1=strlen(s1),l2=strlen(s2);
        for(int m=0;m<strlen(s);m++){
            char jud1[l1+1];
            for(int n=m;n<l1+m;n++){
                jud1[n-m]=s[n];
                if(strcmp(jud1,s1)==0){Sp=m+l1;
                break;}
            }
            if (Sp!=-1)break;
        }
        for(int m=0;m<strlen(s);m++){
            char jud2[l2+1];
            for(int n=m;n<l2+m;n++){jud2[n-m]=s[n];
            if(strcmp(jud2,s2)==0)ep=m;
            if(ep>Ep)Ep=ep;}
        }
        R=Ep-Sp;
        if(Sp==-1)printf("0\n");
        else printf("%d\n",R);

    }
    return 0;
}
