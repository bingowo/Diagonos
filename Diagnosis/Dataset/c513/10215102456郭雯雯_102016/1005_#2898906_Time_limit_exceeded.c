#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    int n=0;
    char q[51];
    while(n<t){
        scanf("%s",q);
        int l=strlen(q);
        double a=q[l-1]-'0';
        for(int i=l-1;i>1;i++){
            a=a/8+(q[i-1]-'0');
        }
        printf("case #%d:\n%lf\n",n,a);
        n++;
    }
}