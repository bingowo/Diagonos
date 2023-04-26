#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int llu;


void countChioce(int *c,char *w,int len){
    if(len==1){
        c[0]=1;
        return;
    }
    for(int i=0;i<len;i++){
        if(i==0){
            if(w[0]==w[1]) c[i]=1;
            else c[i]=2;
        }
        else if(i==strlen(w)-1){
            if(w[i]==w[i-1]) c[i]=1;
            else c[i]=2;
        }
        else{
            if(w[i]==w[i-1] && w[i]==w[i+1]) c[i]=1;
            else if(w[i]==w[i-1] && w[i]!=w[i+1])
                c[i]=2;
            else if(w[i]!=w[i-1] && w[i]==w[i+1])
                c[i]=2;
            else if(w[i]!=w[i-1] && w[i]!=w[i+1] && w[i-1]==w[i+1])
                c[i]=2;
            else if(w[i]!=w[i-1] && w[i]!=w[i+1] && w[i-1]!=w[i+1])
                c[i]=3;
        }
    }
}

void add(int *a,int *tmp){
    for(int i=499;i;i--){
        a[i]+=tmp[i];
        for(int k=i;a[k]>=10;k--){
            a[k]%=10;
            a[k-1]+=1;
        }
    }
}

void multi(int *a,int c){
    int tmp[500];
    for(int i=0;i<500;i++) tmp[i]=a[i];
    for(int i=1;i<c;i++){
        add(a,tmp);
    }
}


int main()
{
    char w[1001];scanf("%s",w);
    int choice[strlen(w)];
    countChioce(choice,w,strlen(w));

    int a[500]={[499]=1};
    for(int i=0;i<strlen(w);i++){
        multi(a,choice[i]);
    }

    int idx=0;
    for(;a[idx]==0;idx++);
    for(;idx<500;idx++){
        printf("%d",a[idx]);
    }

    return 0;

}



