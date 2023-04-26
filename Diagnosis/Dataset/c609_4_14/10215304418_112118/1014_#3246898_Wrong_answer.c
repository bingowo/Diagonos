#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    int a[123456];
    int pos0=0;
    int i=0;
    while (A%3==0 && B!=1){
        A/=3;
        B/=3;
    }
    while (A!=0){
        if ((A+1)%3==0){
            a[i]=2;
            i++;
            A=(A+1)/3;
        }
        else if (A%3==0){
            a[i]=0;
            i++;
            A=(A)/3;
        }
        else if ((A-1)%3==0){
            a[i]=1;
            i++;
            A=(A-1)/3;
        }
        if (B!=1){
            B/=3;
            if (B==1){
                pos0=i;
            }
        }
    }
    if (B!=1) {
        while (B!=1) {
            B/=3;
            i++;
        }
        pos0=i;
    }
    if (pos0==i) printf("0.");
    for (int j=i-1;j>=0;j--){
        printf("%d",a[j]);
        if (pos0==j && pos0!=0) printf(".");
    }
    printf("\n");
    return 0;
}
