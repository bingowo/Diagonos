#include<stdio.h>
void main()
{
    int a;
    scanf("%d",&a);
    int i=0;
    while(i<a){
        int m,n=0;
        scanf("%d %d",&m,&n);
        char M[1000];
        int t=1;
        int c=0;
        while (m!=0){
            c=m%n;
            if(c>=10)
              M[-t]="A"+c-10;
            else
              M[-t]="0"+c;
            m=m/n;
        }
        printf("%c",M[1000]);
        printf("\n");
        i=i+1;
    }
}