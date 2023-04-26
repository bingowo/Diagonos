#include <stdio.h>
#include <stdlib.h>

int GCD(const int a,const int b){
    int gcd=a;
    for (gcd=a;gcd>=1;gcd--){
        if((a%gcd==0)&&(b%gcd==0)){
            break;
        }
    }
    return gcd;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int i;
    for(i=0;i<n;i++){
        char s[1201]={0};
        fgets(s,1202,stdin);
        //printf("%s",s);
        int count=0;
        int j;
        for(j=0;s[j+1]!='\0';j++){
            char A=s[j];
            while(A!=0){
                A=A&(A-1);
                count++;
            }
        }
        //printf("%d\n",count);
        int sum=0;
        sum=j*8;
        //printf("%d\n",sum);
        int gcd=GCD(count,sum);
        printf("%d/%d\n",(count/gcd),(sum/gcd));
    }
    return 0;
}
