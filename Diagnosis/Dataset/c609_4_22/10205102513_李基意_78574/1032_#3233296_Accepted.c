#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    int a[100]={0};
    while(scanf("%s",str)==1){
        int cnt=0;
        for(int i=1; i<strlen(str); i++){
            if(str[i]!=str[i-1]) a[cnt]++;
            else cnt++;
        }
        int max=a[0];
        for(int i=1; i<=cnt; i++)
            if(a[i]>max) max=a[i];
        printf("%d\n",max+1);
    }
}