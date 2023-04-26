#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        printf("case #%d:\n",i);
        int b;
        int num=0;
        scanf("%d",&b);
        int cb=b;
        while(b/2){
            num++;
            b/=2;
        }
        int s[num+1];
        int j=0;
        while(cb){
            s[j]=cb%2;
            cb/=2;
            j++;
        }
        int max=0;int jmax=0;int k=0;
       while(k<j){
           if(s[k]!=s[k+1]){
               max++;
               if(jmax<max){jmax=max;}
           }
           else max=0;
       }
       printf("%d\n",jmax);
    }
    return 0;
}