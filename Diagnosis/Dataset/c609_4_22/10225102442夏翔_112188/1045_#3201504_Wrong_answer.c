#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
int cmp2(const void *a, const void *b){
    return *(int*)b-*(int*)a;
}
int main(){
    char c, temp;
    int ret1=-1, ret2=-1, ret3=-1;//是否处于引号、行注释、块注释中
    while(scanf("%c", &c)!=EOF){
        if(c=='\'' || c=='\"') ret1 = -1*ret1;
        if(ret1==-1 && c=='/'){
            scanf("%c", &temp);
            if(temp=='/') ret2 = -1*ret2;
            else if(temp=='*') ret3 = -1*ret3;
            else printf("%c%c", c, temp);
            continue;
        }
        if(ret1==-1 && c=='*'){
            scanf("%c", &temp);
            if(temp=='/') ret3 = -1*ret3;
            else printf("%c%c", c, temp);
            continue;
        }
        if(ret1==-1 && ret2==1 &&c=='\n'){
            ret2 = -1*ret2;
        }
        if(ret2!=1 &&ret3!=1) printf("%c", c);
    }
    return 0;
}