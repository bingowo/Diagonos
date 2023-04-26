#include<string.h>
#include<stdio.h>
int main()
{
    char a[51];
    scanf("%s",a);
    int len=strlen(a);
    int num=0,sum=0,b[25]={0},h=0;
    for(int i=0;i<len;i++){
        if(a[i]='('){
            if(num==0){
                b[h]=1;
                num++;
            }
            else b[h]=b[h]*2;
        }
        if(a[i]=')'){
            num=num-1;
            if(num==0)h=h+1;
        }
    }
    for(int c=0;c<=h;c++){
        sum=sum+b[c];
    }
    printf("%d",sum);
}