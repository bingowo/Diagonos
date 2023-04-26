#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int n;scanf("%d",&n);
        char jud[334]={0},res[101];
        int k=333;
        while(n>0){
            jud[k--]=n%2;
            n/=2;
        }
        for(int i=k+1;i<334;i++)jud[i]~=jud[i];
        int p=333-1-k;
        int w[101];w[0]=1;
        for(int i=0;i<p;i++){
            
        }
        
    }
    return 0;
}
