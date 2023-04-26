#include <stdio.h>
int main(){
    int n,i,j=0,a;
    scanf("%d",&n);
    char s[100];
    for(j=0;j<n;j++){
        scanf("%d",&a);
        i=0;
        while(a/2!=0){
            s[i]=a%2;
            a=a/2;
            i=i+1;
        }
        s[i]=a%2;
        int m=1,max=1,k=1;
        while(k<=i){

            if(s[k]!=s[k-1]){
                m++;
                k++;
            }
            else{
                m=1;
                k++;
            }
            if(m>max){
                max=m;
            }

        }
        printf("case #%d:\n%d\n",j,max);

    }
    return 0;
}
