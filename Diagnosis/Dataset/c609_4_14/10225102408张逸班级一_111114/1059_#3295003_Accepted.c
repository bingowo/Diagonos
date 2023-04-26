#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char str[100];
}String;
int cmp(const void*a1,const void*a2){
    String* p1=(String*)a1;
    String* p2=(String*)a2;
    double d1=atof(p1->str);double d2=atof(p2->str);
    if(d1>d2)return 1;
    else return -1;
}
int main(){
    int num;
    scanf("%d",&num);
    String n[num];
    for(int i=0;i<num;i++){
        scanf("%s",&n[i].str);
    }
    qsort(n,num,sizeof(String),cmp);
    for(int i=0;i<num;i++){
        printf("%s\n",n[i].str);
    }
    return 0;
}