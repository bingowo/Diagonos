#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct{
    char a[20];
}str;
int cmp(const void*a,const void *b){
    str* pa= (str*)a;
    str* pb= (str*)b;
    return strcmp(pa->a,pb->a);
}
int main(){
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        str data[501];
        char s[501];
        int index=0;
        gets(s);
        char *p=s;
        int j=0,i=0;
        while(*p){
            if(isalpha(*p)){
                data[j].a[i++]=*p;
                p++;
            }
            else{
                data[j].a[i]='\0';
                i=0;
                j++;
                while(isalpha(*p)==0 && *p){
                    p++;
                }
            }
        }
//        for(int w=0;w<j;w++){
//            printf("%s\n",data[w].a);
//        }
//经检测输入功能正常
        qsort(data,j,sizeof(data[0]),cmp);

//        for(int w=0;w<j;w++){
//            printf("%s\n",data[w].a);
//        }
//经检测排序功能正常
        str * q1=data;
        str * q2=data+1;
        printf("case #%d:\n",t);
        while(*q2->a) {
            if (strcmp(q1->a, q2->a)==0) {
                printf("%s ",q1->a);
                q1+=2;
                q2+=2;
            }
            else{
                printf("%s ",q1->a);
                q1++;
                q2++;
            }
        }
        if(*q1->a) printf("%s ",q1->a);
    }
    return 0;
}