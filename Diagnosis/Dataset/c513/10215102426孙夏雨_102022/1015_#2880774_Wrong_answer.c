#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T;
    scanf("%d",&T);
    int arr0[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(int i=0;i<T;i++){
        char s1[60],s2[60];
        scanf("%s %s",s1,s2);
        int len1=strlen(s1),len2=strlen(s2);
        int arr1[25],arr2[25];
        int len3=0,len4=0;
        int x=1,sum=0;
        for(int j=len1-1;j>=0;j--){
            if(isdigit(s1[j])){
                sum+=x*(s1[j]-'0');
                x*=10;
            }
            else {
                arr1[len3]=sum;
                len3++;
                sum=0;
                x=1;
            }
        }
        arr1[len3]=sum;
        len3++;
        sum=0;
        x=1;
        for(int j=len2-1;j>=0;j--){
            if(isdigit(s2[j])){
                sum+=x*(s2[j]-'0');
                x*=10;
            }
            else {
                arr2[len4]=sum;
                len4++;
                sum=0;
                x=1;
            }
        }
        arr2[len4]=sum;
        len4++;
        int ans[26];
        int a=len3>len4 ? len4:len3;
        int b=len3>len4 ? len3:len4;
        int next=0,Sum=0;
        int j=0;
        for(;j<a;j++){
            Sum=arr1[j]+arr2[j]+next;
            if(Sum>=arr0[j]){
                next=1;
                Sum=Sum-arr0[j];
            }
            else next=0;
            ans[j]=Sum;
        }
        for (;j<b;j++){
            if (len3>len4) Sum=arr1[j]+next;
            else Sum=arr2[j]+next;
            if(Sum>=arr0[j]){
                next=1;
                Sum=Sum-arr0[j];
            }
            else next=0;
            ans[j]=Sum;
        }
        if(next==1) {ans[j]=1;j++;}
        printf("case #%d:\n",i);
        for(int k=j-1;k>0;k--) printf("%d,",ans[k]);
        printf("%d\n",ans[0]);
    }
    return 0;
}
