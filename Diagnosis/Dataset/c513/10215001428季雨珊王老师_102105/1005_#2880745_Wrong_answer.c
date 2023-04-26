#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[52];
        scanf("%s",s);
        int N=strlen(s)-2;
        int *num;
        num=(int *)malloc(sizeof(int)*N);
        long double result=0;
        for(int i=0;i<N;i++){
            num[i]=s[i+2]-'0';
            result+=num[i]*pow(8,-1-i);
        }
        printf("case #%d:\n%f\n",t,result);
    }
    return 0;
}
