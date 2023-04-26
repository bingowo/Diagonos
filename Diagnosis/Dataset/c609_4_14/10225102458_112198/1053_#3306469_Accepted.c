#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void change(int* a,int num)
{
    for(int i=num-1;i>=0;i--){
        a[i]=0;
    }
}
int convert(int* a,int num)
{
    for(int i=0;i<num;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[num]!=0)num++;
    return num;
}
int main()
{
    char m[110];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    scanf("%s",m);
    int len=strlen(m);
    int a[len+5],circle=1;
    memset(a,0,sizeof(a));
    for(int i=0;i<len;i++){
        a[i]=m[len-1-i]-'0';
    }
    a[0]++;
    len=convert(a,len);
    while(circle){
        circle=0;
        for(int i=len-1;i>0;i--){
            if(a[i]==a[i-1]){
                a[i-1]++;
                if(a[i-1]>=10){len=convert(a,len);change(a,i-1);circle=1;break;}
                else {change(a,i-1);}
            }
        }
    }
    printf("case #%d:\n",i);
    for(int i=len-1;i>=0;i--)printf("%d",a[i]);
    printf("\n");}
    return 0;
}
