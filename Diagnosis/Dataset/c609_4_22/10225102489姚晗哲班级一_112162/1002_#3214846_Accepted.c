#include <stdio.h>
#include <string.h>
void trans(int a,char s[])
    {
        int t=0,n=0;
        char p;
        while(a){
            t = a%2;
            s[n]=t+'0';
            a/=2;
            n++;
        }
        n--;
        for(int i=0;i<n;i++,n--){
            p = s[i];
            s[i]=s[n];
            s[n]=p;
        }
    }
int main()
{
    char s[100]={0};

    int a,b,c,sum=0,num;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        sum = 1;
        for(int x=0;x<100;x++) s[x]=0;
        scanf("%d",&b);
        trans(b,s);
        c = strlen(s);
        for(int n=0;n<c-1;n++){
            num=1;
            while(s[n+1]!=s[n]&&n<c-1){
                num++;
                n++;
            }
            if(num>sum) sum=num;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}