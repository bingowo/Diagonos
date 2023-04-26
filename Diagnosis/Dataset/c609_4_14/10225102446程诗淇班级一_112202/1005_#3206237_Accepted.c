#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int n,i,j,b,m,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        int a;
        a=strlen(s);
        int b=1;
        int sum=0;
        for(j=a-1;j>=0;j=j-1){


            if(s[j]=='-'){
                m=-b;
            }
            if(s[j]=='0'){
                m=0;
            }
            if(s[j]=='1'){
                m=b;
            }
            sum=sum+m;
            b=b*3;
        }
        printf("case #%d:\n",i);
        printf("%d\n",sum);




    }


    return 0;
}
