#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,y,N=1000;
    int a,r,c,d;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&r);
        char s[N];
        if(a<0){a=-a;
            printf("-");
        }
        for(j=0;a!=0;j++){
            d=a%r;
        
         if(d<10) s[j] = d+'0';
         else s[j] = d-10+'A' ;
         a=a/r;
        }
    
            for(y=0,j=strlen(s)-1;y<j;y++,j--) //反转
            {c=s[y],s[y]=s[j],s[j]=c;
                }
     printf("%s",s);
             printf("\n");
        }


    }