#include <stdio.h>
#include <stdlib.h>
int f(int a){
    int ret=0;
    if(a<0){
        ret++;
        a = a*-1;
    }
    while(a!=0){
        ret++;
        a = a/10;
    }
    return ret;
}
int cmp1(const void *a, const void *b){
    int x1=*(int*)a, x2=*(int*)b;
    int n1=f(x1), n2=f(x2);
    if(n1!=n2) return n2-n1;
    else return x1-x2;
}
int main(){
    int *num, count=0, flag=1;
    char temp;
    num = (int*)calloc(1e+6,sizeof(int));
    while(scanf("%c", &temp)!=EOF){
        if(temp=='-') flag=-1;
        else if(temp>='0'&&temp<='9') num[count] = num[count]*10+(int)temp-48;
        else{
            num[count++] *= flag;
            flag = 1; 
        }
    }
    qsort(num,count,sizeof(num[0]),cmp1);
    for(int i=0; i<count-1; i++) printf("%d ", num[i]);
    printf("%d", num[count-1]);
    free(num);
    return 0;
}
