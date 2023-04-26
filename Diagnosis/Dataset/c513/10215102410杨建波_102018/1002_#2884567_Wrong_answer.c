#include<stdio.h>
#include<string.h>
int main(){
    int T,i = 1,num = 1,flag,n = 1,m = 0;
    long long int result = 0;
    char s[61], a[60] = {'\0'}, p;
    scanf("%d",&T);
    for(T;T>0;T--){

        scanf("%s",s);
        while(i <= strlen(s)-1){
           for(int j = 0;j<i;j++){
               if(s[i]==s[j]){
                   flag = 1;
                   break;
               }
           }
           if(flag == 1);
           else{
               a[n++] = s[i];num++;
           }
           i++;
           flag = 0;
        }
        i = 0;
        a[0] = s[0];
       p = a[1];
       a[1] = a[0];
       a[0] = p;
        for(int t = 0;t<strlen(s);t++){
           while(s[t]!= a[i]){
           i++;
           }
           result = i+result*num;
           i = 0;
        }
    printf("case #%d\n%lld\n",m++,result);
    }
}
