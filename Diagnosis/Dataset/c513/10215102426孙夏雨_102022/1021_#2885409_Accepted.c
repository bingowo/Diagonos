#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char alpha[21];
    int n[21];
} ALPHY;

int cmp(const void* p3,const void* p4)
{
    ALPHY* p1=(ALPHY* )p3;
    ALPHY* p2=(ALPHY* )p4;
    int len1=strlen(p1->alpha);
    int len2=strlen(p2->alpha);
    for(int i=0;i<(len1<len2 ? len1:len2);i++){
        if((p1->n[i])>(p2->n[i])) return 1;
        else if((p1->n[i])<(p2->n[i])) return -1;
    }
    if(len1<len2) return -1;
    else return 1;
}

int main()
{
    char s0[27];
    while(scanf("%s",s0)!=EOF){
    ALPHY* p=(ALPHY* )malloc(100*sizeof(ALPHY));
    getchar();
    char c;
    int num=0,len=0;
    while((c=getchar())!='\n'){
        if(isalpha(c)){
            int ii=0;
            for(;ii<26;ii++){
                if((c==s0[ii])||(c==s0[ii]+'a'-'A')) break;
            }
            (p+num)->n[len]=ii;
            (p+num)->alpha[len]=c;
            len++;
        }
        else if(c==' '){
            (p+num)->alpha[len]=0;
            len=0;
            num++;
        }
    }
    (p+num)->alpha[len]=0;
    num++;
    qsort(p,num,sizeof(ALPHY),cmp);
    for(int tt=0;tt<num;tt++) printf("%s ",(p+tt)->alpha);
    printf("\n");
    free(p);
    }
    return 0;
}
