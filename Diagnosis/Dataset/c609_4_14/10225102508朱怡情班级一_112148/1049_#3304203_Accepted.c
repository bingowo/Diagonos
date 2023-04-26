#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int cmp(char a[],char b[])
{
    int l1,l2;
    l1=strlen(a);
    l2=strlen(b);
    if(l1!=l2)return l1-l2;
    else{
        for(int i=0;i<l1;i++)if(a[i]!=b[i])return a[i]-b[i];
        return 0;
    }
}

int main()
{
    char a[509],b[509];
    while(scanf("%s%s",a,b)!=EOF){
        int s1[509]={0},s2[509]={0};
        int l1,l2,k=0,flag=0;
        l1=strlen(a)-1;
        l2=strlen(b)-1;
        if(cmp(a,b)==0){
            printf("0\n");
            continue;
        }
        else if(cmp(a,b)>0){
            for(int i=l1;i>=0;i--)s1[k++]=a[i]-'0';
            k=0;
            for(int i=l2;i>=0;i--)s2[k++]=b[i]-'0';
        }
        else{
            for(int i=l2;i>=0;i--)s1[k++]=b[i]-'0';
            k=0;
            for(int i=l1;i>=0;i--)s2[k++]=a[i]-'0';
            flag=1;
        }
        int carry=0;
        for(int i=0;i<500;i++){
            int t=10-carry+s1[i]-s2[i];
            if(s2[i]>s1[i]-carry)carry=1;
            else carry=0;
            s2[i]=t%10;
        }
        if(flag)printf("-");
        int i;
        for(i=500;i>=0;i--)if(s2[i])break;
        for(i=i;i>=0;i--)printf("%d",s2[i]);
        printf("\n");
    }
    return 0;
}
