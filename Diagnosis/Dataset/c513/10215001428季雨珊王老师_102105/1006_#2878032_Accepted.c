#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[100];
        scanf("%s",s);
        int n=strlen(s);
        int result=0;
        for(int i=0;i<n;i++){
            if(s[i]=='-')
                result+=(-1)*pow(3,n-1-i);
            if(s[i]=='0')
                result=result;
            if(s[i]=='1')
               result+=pow(3,n-1-i);
        }
        printf("case #%d:\n%d\n",t,result);
    }
    return 0;
}
