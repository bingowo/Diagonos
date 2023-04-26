#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,r;
    char n[20],a[20];
    scanf("%d %s %d",&A,n,&B);
    int l=sizeof(n[20]);
    for(int i=0;i<l;i++){
        if(n[i]>96){n[i]=n[i]-32;}
    }
    for(int i=1;i<l;i++)r=n[i]+n[i-1]*A;
    int j=0;
    while(r>0){
        if(r/B<10) a[j]=r/B+48;
        else a[j]=r/B+55;
        r=r%B;
        j++;
    }
    printf("%s",a);
    return 0;
}
