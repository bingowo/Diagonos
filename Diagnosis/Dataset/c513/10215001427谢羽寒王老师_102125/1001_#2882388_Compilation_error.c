#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,N=1000;
    int a,r;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&r);
        int s[N];
        if(a<0){a=-a;
            printf("-");
        }
        for(j=0;a!=0;j++){
        d=a%r;
        
        if(d<10) s[j] = d+'0';
        else s[j] = d-10+'A'
        a=a/r;
        }
        for(;j>=0;j--){
            printf("%c",s[j]);
            for(i=0,j=strlen(s)-1;i<j;i++,j--) //反转
            {c=s[i],s[i]=s[j],s[j]=c;
                }

        }
        printf("\n");

    }