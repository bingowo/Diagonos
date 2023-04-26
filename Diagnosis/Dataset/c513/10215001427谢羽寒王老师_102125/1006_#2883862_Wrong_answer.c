#include<stdio.h>
#include<string.h>

int main()
{
    int n,N=70;
    int i,j,x,y,result=0,r,z,c;
    char s[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);

        for(j=strlen(s)-1,c=1;j>=0;j--){
            if(s[j]=='-') r=-1;
            if(s[j]=='0') r=0;
            if(s[j]=='1') r=1;
            z=r*c;
            result=result+z;
            c=c*3;



        }
















        printf("case #%d\n",i);
        printf("%d\n",result);
    }






   return 0;
}
