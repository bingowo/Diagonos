#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
     char s[100];
     int t[100];
     int len;
}Date;

int cmp(const void*a,const void*b)
{
    int* ta=(*(Date*)a).t;
    int* tb=(*(Date*)b).t;
    int x,y;
    x=(*(Date*)a).len;
    y=(*(Date*)b).len;
    int i;
    for(i=0;i<x&&i<y;i++){
        if(ta[i]!=tb[i]){
            return ta[i]-tb[i];
            break;
        }
    }
    if(x>y&&i==y){
        return 1;
    }
    if(x<y&&i==x){
        return -1;
    }
}

int main()
{
    char s1[30];
    while(scanf("%s",s1)!=EOF){
        int b=strlen(s1);
        Date* k=(Date*)malloc(sizeof(Date)*100);
        int i=0;
        int a;
        char c;                               /*用于读取换行符*/
        while(scanf("%s",k[i].s)){
            a=strlen(k[i].s);
            k[i].len=a;
            char* s2=k[i].s;
            int* t2=k[i].t;
            for(int j=0;j<a;j++){
                for(int m=0;m<b;m++){
                    if(s1[m]==s2[j]||s1[m]==(s2[j]-32)){
                        t2[j]=m;
                        break;
                    }
                }
            }
            if((c=getchar())=='\n'){
                break;
            }
            i++;


        }
        qsort(k,i+1,sizeof(Date),cmp);
        for(int j=0;j<i+1;j++){
            printf("%s ",k[j].s);
        }
        printf("\n");
        free(k);
    }
    return 0;
}
