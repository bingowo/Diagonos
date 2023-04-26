#include <stdio.h>
#include <string.h>

void result(int all, int num){
    int a=all; int b=num; int temp;
    temp=a%b;
    while (temp!=0){
        a=b;  b=temp;  temp=a%b;
    }
    all/=b;  num/=b;
    printf("%d/%d\n",num,all);



}

void Density(char *a){
    int len=strlen(a);
    int flag=1; int num_1=0;
    for(int k=0;k<len;k++){
        for(int m=0;m<8;m++){
            if(a[k]&flag == 1) num_1++;
            flag<<1;
        }
    }
    int all;
    all=8*len;
    result(all,num_1);

}

int main() {
    int total;
    scanf("%d",&total);
    for(int i=0;i<total;i++){
        char a[1000]={'\0'};
        char c; int j=0;
        while (c=getchar()!='\n'){
            a[j++]=c;
        }
        Density(a);
    }
    return 0;
}
