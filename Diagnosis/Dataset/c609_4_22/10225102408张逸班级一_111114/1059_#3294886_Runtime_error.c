#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a1,const void*a2){
    char*p1=(char*)a1;char*p2=(char*)a2;
    double d1=atof(p1),d2=atof(p2);
    if(d1==d2){
        return 0;
    }
    else if(d1>d2)return 1;
    else return -1;
}
int main(){
    int num;
    scanf("%d",&num);
    char*s[num];
    for(int i=0;i<num;i++){
        scanf("%s",s[i]);
    }
    qsort(s,num,sizeof(char*),cmp);
    for(int i=0;i<num;i++){
        printf("%s\n",s+i);
    }
    return 0;
}