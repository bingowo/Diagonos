#include<stdio.h>
#include<string.h>

int gcd(int x,int y)
{
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else b-=a;
    }
    return a;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i!=n;i++){
        char s[121]={'0'};
        int i=0;
        while((s[i++]=getchar())!='\n');
        int slen=strlen(s);
        int sum=0;
        for(int j=0;j!=slen-1;j++){
            int tmp=s[j];
            for(int k=0;k!=8;k++){
                if(tmp & 1)
                    sum++;
                tmp >>= 1 ;
            }
        }
        int result=gcd(sum,(slen-1)*8);
        printf("%d/%d\n",result,(slen-1)*8/(sum/result));
    }
}
