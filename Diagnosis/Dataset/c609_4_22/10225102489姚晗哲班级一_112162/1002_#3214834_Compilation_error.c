#include <stdio.h>
#include <string.h>
void trans(int a,char s[])
    {
        int t=0,n=0;
        char m;
        while(a){
            t = a%2;
            s[j]=t+'0';
            a/=2;
            n++;
        }
        n--;
        for(int i=0;i<n;i++,n--){
            p = s[i];
            s[i]=s[n];
            s[n]=m;
        }
    }
int main()
{
    char s[100]={0};
    int a,b,c,sum=0,num;int i=0;
    scanf("%d",&a);
    for(;i<a;i++){
        sum = 1;
        for(int x=0;x<100;x++) s[x]=0;
        scanf("%d",&b);
        trans(b,s);
        c = strlen(s);
        for(int j=0;j<c-1;j++){
            num=1;
            while(s[j+1]!=s[j]&&j<c-1){
                sum1++;
                j++;
            }
            if(num>sum) sum=num;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}