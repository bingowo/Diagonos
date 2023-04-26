#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    char s1[600],s2[600];
    int n;
    int a1[510],a2[510];
    memset(a1,0,sizeof(a1));
    memset(a2,0,sizeof(a2));
    scanf("%s%s%d",s1,s2,&n);
    int leni1=0,leni2=0;
    int point1=strchr(s1,'.')-s1;
    int point2=strchr(s2,'.')-s2;

    if (point1==0)
        a1[leni1++]=0;
    else if (strchr(s1,'.')!=NULL){
        for (int i=point1-1;i>=0;i--)
            a1[leni1++]=s1[i]-'0';}
     else
        for (int i=strlen(s1)-1;i>=0;i--) a1[leni1++]=s1[i]-'0';


    if (point2==0)
        a2[leni2++]=0;
    else if (strchr(s2,'.')!=NULL){
        for (int i=point2-1;i>=0;i--)
            a2[leni2++]=s2[i]-'0';}
    else
        for (int i=strlen(s1)-1;i>=0;i--) a2[leni2++]=s2[i]-'0';

    int lend1=0,lend2=0;




    int a3[501],a4[501];
    memset(a3,0,sizeof(a3));
    memset(a4,0,sizeof(a4));
    if(strchr(s1,'.')==NULL||point1==strlen(s1)-1){
        lend1=1;
        a3[0]=0;
    }
    else{
        for (int i=1;i+point1<=strlen(s1)-1;i++)
            a3[lend1++]=s1[point1+i]-'0';
    }

    if(strchr(s2,'.')==NULL||point2==strlen(s2)-1){
        lend2=1;
        a4[0]=0;
    }
    else{
        for (int i=1;i+point2<=strlen(s2)-1;i++)
            a4[lend2++]=s2[point2+i]-'0';
    }





    int lendmax=0;
    if (lend1>lend2) lendmax=lend1;
    else lendmax=lend2;

    for (int i=lendmax;i>=0;i--)
    a3[i]=a3[i]+a4[i];
    int carry=0;
    for (int i=lendmax;i>=0;i--){
        if (i==n-1&&a3[i+1]>=5) carry+=1;
        a3[i]=a3[i]+carry;
        carry=a3[i]/10;
        a3[i]=a3[i]%10;
    }

    int lenimax=0;
    if (leni1>leni2) lenimax=leni1;
    else lenimax=leni2;

    for (int i=0;i<lenimax||carry>0;i++){
        if (i==lenimax-1){
            a1[i]=a1[i]+a2[i]+carry;
            carry=a1[i]/10;
            a1[i]=a1[i]%10;
            if (carry>0) lenimax++;
        }
        else
        {
            a1[i]=a1[i]+a2[i]+carry;
            carry=a1[i]/10;
            a1[i]=a1[i]%10;
        }
    }
    while (a[lenimax]==0) lenimax--;
    for (int i=lenimax-1;i>=0;i--) printf("%d",a1[i]);
    printf(".");
    for (int i=0;i<n;i++) printf("%d",a3[i]);
    printf("\n");
    return 0;
}