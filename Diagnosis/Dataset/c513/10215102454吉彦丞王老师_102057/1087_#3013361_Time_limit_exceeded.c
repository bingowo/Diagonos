#include<stdio.h>
#include<string.h>
void change(int a[],int l){
    a[l]=a[l]+1;
    for(int i=l;i>0;i--){
        if(a[i]>=10){
            a[i-1]=a[i-1]+a[i]/10;
            a[i]=a[i]%10;
        }
    }
}
int test(int a[],int l){
    int t=0;
    for(int i=l;i>0;i--){
        if(a[i]==a[i-1]){
            t++;
        }
    }
    return t;
}
int main(){
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        char s[100];
        scanf("%s",s);
        int l=strlen(s);
        int a[l+1];
        a[0]=0;
        for(int j=0;j<l;j++){
            a[j+1]=s[j]-'0';
        }
        change(a,l);
        while(test(a,l)!=0){
            change(a,l);
        }
        printf("case #%d:\n",i);
        if(a[0]==0){
           for(int j=1;j<l+1;j++){
               printf("%d",a[j]);
           }
        }
        else{
            for(int j=0;j<l+1;j++){
                printf("%d",a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}