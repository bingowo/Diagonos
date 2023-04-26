#include<stdio.h>
#include<string.h>
#include<stdlib.h>


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
    for(m = 0;m<strlen(a);m++){
        if(a[m]<='9'&&a[m]>='0'){
            NUM = NUM*10+a[m]-'0';
        }
    }
    return NUM;
}
int cmp(const void *a,const void *b){
    int num_a,num_b;
    int i;
    num_a = num((char *)a);
    num_b = num((char *)b);
    if(num_a==num_b&&num_a == 0){
        return strcmp((char *)a,(char *)b);
    }else if(num_a!=num_b){
        return num_a-num_b;
    }else if(num_a==num_b&&num_a != 0){
        return strcmp((char *)a,(char *)b);
    } 
}

