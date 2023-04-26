#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char c;
    int hang;
    int lie;
}AAA;

int cmp(const void* p3,const void* p4)
{
    AAA* p1=(AAA* )p3;
    AAA* p2=(AAA* )p4;
    if((p1->hang)<(p2->hang)) return -1;
    else if((p1->hang)>(p2->hang)) return 1;
    else {
        if((p1->lie)<(p2->lie)) return -1;
        else return 1;
    }
}

int main()
{
    char s[81];
    while((scanf("%s",s))!=EOF){
        int len=strlen(s);
        AAA* p=(AAA *)malloc(len*sizeof(AAA));
        int hangshu=0,lieshu=0;
        p->c=s[0];
        p->hang=hangshu;
        p->lie=lieshu;
        lieshu++;
        for(int i=1;i<len;i++){
            if(s[i]-s[i-1]>0) hangshu--;
            else if(s[i]-s[i-1]<0) hangshu++;
            (p+i)->c=s[i];
            (p+i)->hang=hangshu;
            (p+i)->lie=lieshu;
            lieshu++;
        }
        qsort(p,len,sizeof(AAA),cmp);
        int dangqh=p->hang,kong=0,dangql=p->lie;
        int h=0;
        for(int j=0;j<len;j++){
            h=(p+j)->hang;
            if(j==0){
                kong=(p+j)->lie;
                for(int k=0;k<kong;k++) printf(" ");
                printf("%c",(p+j)->c);
            }
            else if(h==dangqh) {
                kong=(p+j)->lie-dangql;
                dangql=(p+j)->lie;
                for(int i=0;i<kong-1;i++)printf(" ");
                printf("%c",(p+j)->c);
            }
            else if(h>dangqh){
                printf("\n");
                dangqh=h;
                kong=(p+j)->lie;
                dangql=(p+j)->lie;
                for(int k=0;k<kong;k++) printf(" ");
                printf("%c",(p+j)->c);
            }
        }
        printf("\n");
        free(p);
    }
    return 0;
}
