#include <stdio.h>
int gcd(int m1,int m2)
{
    if(m2==0) return m1;
    else return gcd(m2,m1%m2);
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++){
        int L[100],index=0,flag=0;
        int n,m;
        scanf("%d %d",&n,&m);
        printf("case #%d:\n",mm);
        int g = gcd(n,m);
        n = n/g;
        m = m/g;
        printf("0.");
        while(flag==0 && n!=0){
            int num=0;
            n=n*10;
            for(int i=0;i<index;i++){
                if(n==L[i]) {flag=i+1;break;}
            }
            L[index++]=n;
            num = n/m;
            n = n%m;
            if(flag==0) printf("%d",num);
            else {printf("\n");printf("%d-%d",flag,index-1);}
        }
        printf("\n");
    }
    return 0; 
}