#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100]={0};
    void jinzhi(int a,char s[])
    {
        int t=0,j=0;
        char p;
        while(a){
            t = a%2;
            s[j]=t;
            a=a/2;
            j++;
        }
        for(int i=0;i<j;i++,j--){
            p = s[i];
            s[i]=s[j];
            s[j]=p;
        }
    }
    int a,b,c;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        for(int x=0;x<100;x++) s[x]=0;
        scanf("%d",&b);
        jinzhi(b,s);
        printf("%s",s);
    }
    return 0;
}
