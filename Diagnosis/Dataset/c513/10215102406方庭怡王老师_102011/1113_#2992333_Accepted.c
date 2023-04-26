#include<stdio.h>

int main() {
    int k,n;
    scanf("%d%d",&k,&n);
    int terms[k][100];
    for(int i=0; i<k; i++) {
        for(int j=0; j<100; j++) {
            terms[i][j]=0;
        }
    }
    terms[1][99]=1;
    if(n==1) {
        printf("0");
    } else if(n==2) {
        printf("1");
    } else {
        for(int i=2; i<n; i++) {
            int sum=0;
            int carry=0;
            for(int j=99; j>=0; j--) {
                sum=0;
                for(int m=0; m<k; m++) {
                    sum+=terms[m][j];
                }
                sum+=carry;
                terms[i%k][j]=sum%10;
                carry=sum/10;
            }
        }
        int first_non_zero_index=0;
        while(first_non_zero_index<100) {
            if(terms[(n-1)%k][first_non_zero_index]!=0) {
                break;
            } else {
                first_non_zero_index++;
            }
        }
        if(first_non_zero_index==100) {
            printf("0");
        } else {
            for(int i=first_non_zero_index; i<100; i++) {
                printf("%d",terms[(n-1)%k][i]);
            }
        }
    }
    return 0;
}