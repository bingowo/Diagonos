#include <stdio.h>
#include <string.h>
int main()
{
    int ss[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,93};
    int a[25],b[25],c[25];
    int i,j,t,x,l1,l2,la,lb,l;
    char s1[500],s2[500];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s%s",s1,s2);
        l1=strlen(s1);
        l2=strlen(s2);
        la=0;
        a[0]=0;
        for(j=0;j<l1;j++){
            if(s1[j]!=',')
                a[la]=a[la]*10+s1[j]-'0';
            else{
                la++;
                a[la]=0;
            }
        }
        lb=0;
        b[0]=0;
        for(j=0;j<l2;j++){
            if(s2[j]!=',')
                b[lb]=b[lb]*10+s2[j]-'0';
            else{
                lb++;
                b[lb]=0;
            }
        }
        if(la<lb){
            l=lb;
            for(j=lb;j>=lb-la;j--)
                a[j]=a[j+la-lb];
            for(j=lb-la-1;j>=0;j--)
                a[j]=0;
        }
        else{
            l=la;
            for(j=la;j>=la-lb;j--)
                b[j]=b[j+lb-la];
            for(j=la-lb-1;j>=0;j--)
                b[j]=0;
        }
        x=0;
        for(j=l;j>=0;j--){
            c[j]=a[j]+b[j]+x;
            x=0;
            if(c[j]>=ss[l-j]){
                c[j]=c[j]-ss[l-j];
                x=1;
            }
        }
        printf("case #%d:\n",i);
        if(x==1)
            printf("1,");
        for(j=0;j<=l;j++){
            printf("%d",c[j]);
            if(j==l)
                printf("\n");
            else
                printf(",");
        }
    }
    return 0;
}
