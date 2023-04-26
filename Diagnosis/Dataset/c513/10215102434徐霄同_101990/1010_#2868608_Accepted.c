#include <stdio.h>
#include <string.h>
int main()
{
    char n[500];
    int a[10];
    int i,j,l,x,l0,l1,l2;
    scanf("%s",n);
    l=strlen(n);
    l1=l/3;
    l2=l%3;
    l0=l;
    printf("0001");
    for(i=0;i<10;i++)
        a[i]=0;
    i=9;
    while(l0>0){
        a[i]=l0%2;
        l0=l0/2;
        i--;
    }
    for(i=0;i<10;i++)
        printf("%d",a[i]);
    for(i=0;i<l1;i++){
        x=(n[i*3]-'0')*100+(n[i*3+1]-'0')*10+(n[i*3+2]-'0');
        for(j=0;j<10;j++)
            a[j]=0;
        j=9;
        while(x>0){
            a[j]=x%2;
            x=x/2;
            j--;
        }
        for(j=0;j<10;j++)
            printf("%d",a[j]);
    }
    if(l2==1){
        x=n[l-1]-'0';
        for(i=0;i<4;i++)
            a[i]=0;
        i=0;
        while(x>0){
            a[i]=x%2;
            x=x/2;
            i++;
        }
        for(i=3;i>=0;i--)
            printf("%d",a[i]);
    }
    else if(l2==2){
        x=(n[l-2]-'0')*10+(n[l-1]-'0');
        for(i=0;i<7;i++)
            a[i]=0;
        i=0;
        while(x>0){
            a[i]=x%2;
            x=x/2;
            i++;
        }
        for(i=6;i>=0;i--)
            printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
