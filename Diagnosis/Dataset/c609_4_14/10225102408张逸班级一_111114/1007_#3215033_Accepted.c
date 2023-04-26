#include<stdio.h>
#include<stdlib.h>
int compare(long long a){
    int num=0;
    while(a){
        a=a&(a-1);
        num++;
    }
    return num;
}
int mycmp(const void*a1,const void*a2){
    if(compare(*(long long*)a1)>compare(*(long long*)a2)){
        return -1;
    }
    else if(compare(*(long long*)a1)<compare(*(long long*)a2)){
        return 1;
    }
    else if(compare(*(long long*)a1)==compare(*(long long*)a2)){
        if(*(long long*)a1>*(long long*)a2){return 1;}
        else return -1;
    }
}
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int n;
        scanf("%d",&n);
        long long s[n];
        for(int i=0;i<n;i++){
        scanf("%lld",&s[i]);
        }
         if(n==1){
            printf("case #%d:\n",i);
             printf("%lld\n",s[0]);
        }

        else{qsort(s,n,sizeof(s[0]),mycmp);
        printf("case #%d:\n",i);
       for(int i=0;i<n-1;i++){
            printf("%lld ",s[i]);
        }
        printf("%lld\n",s[n-1]);}
    }
}