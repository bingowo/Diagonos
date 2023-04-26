#include<stdio.h>
#include<string.h>

int num(char a[]);
int cmp(const void *a,const void *b);
int main()
{
    char a[100][31];
    int i=0,m;
    while(scanf("%s",a[i])!=EOF)  i++;
    if(i==1){
        printf("%s",a[0]);
        return 0;
    }
    else{
        qsort(a,i,sizeof(a[0]),cmp);
        for(m = 0;m<i;m++){
            printf("%s ",a[m]);
        }
    }
    return 0;
}
int num(char a[]){
    int m,NUM=0;
    int n[8],c=0;
    for(m = 0;m<strlen(a);m++){
        if(a[m]<='9'&&a[m]>='0'){
            NUM++;
            n[c++]=m;
        }
    }
    return NUM,n[0];
}
int cmp(const void *a,const void *b){
    int num_a,num_b,A,B;
    int i;
    num_a,A = num((char *)a);
    num_b,B = num((char *)b);
    if(num_a==num_b&&num_a == 0){
        return strcmp((char *)a,(char *)b);
    }else if(num_a!=num_b){
        return num_a-num_b;
    }else if(num_a==num_b&&num_a != 0){
        while(A<=A+num_a){
            if(*(char*)(a+A)!=*(char*)(b+B))
                return *(char*)(a+A)-*(char*)(b+B);
            A++;
        }
        return strcmp((char *)a,(char *)b);
    }
}
