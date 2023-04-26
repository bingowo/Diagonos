#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char s[31];
    int x;
} WORD;

int cmp(const void* p3,const void* p4)
{
    WORD* p1=(WORD* )p3;
    WORD* p2=(WORD* )p4;
    if(p1->x==-1){
        int w=strcmp(p1->s,p2->s);
        if(w>0) return 1;
        else return -1;
    }
    else {
        if((p1->x)>(p2->x)) return 1;
        else return -1;
    }
}

int main()
{
    char c;
    char s1[31];
    int num1=0,num2=0;
    WORD* p1=(WORD* )malloc(100*sizeof(WORD));
    WORD* p2=(WORD* )malloc(100*sizeof(WORD));
    do{
        scanf("%s",s1);
        int dec=0,all=0;
        for(int i=0;i<strlen(s1);i++){
            if(isdigit(s1[i])){
                dec=1;
                all=all*10+s1[i]-'0';
            }
        }
        if(dec==1) {
            strcpy((p2+num2)->s,s1);
            (p2+num2)->x=all;
            num2++;
            all=0;
        }
        else{
            strcpy((p1+num1)->s,s1);
            (p1+num1)->x=-1;
            num1++;
            all=0;
        }
    }while((c=getchar())!='\n');
    qsort(p1,num1,sizeof(WORD),cmp);
    qsort(p2,num2,sizeof(WORD),cmp);
    for (int j=0;j<num1;j++) printf("%s ",(p1+j)->s);
    for (int jj=0;jj<num2;jj++) printf("%s ",(p2+jj)->s);
    return 0;
}
