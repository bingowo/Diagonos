#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int n;scanf("%d",&n);
    int s[n][2];
    for(int i=0;i<n;i++){
        scanf("%d/%d",&s[i][0],&s[i][1]);
    }
    int fenzi=s[0][0],fenmu=s[0][1];
    for(int i=1;i<n;i++){
        if(fenmu%s[i][1]!=0){
            s[i][0]*=fenmu;
            fenmu*=s[i][1];
            fenzi*=s[i][1];
            fenzi+=s[i][0];
        }
        else{
            s[i][0]*=(fenmu/s[i][1]);
            fenzi+=s[i][0];
        }
    }
    int r,max=fenmu,min=fenzi;
    do{
        r=max%min;
        max=min;
        min=r;
    }while(r!=0);
    printf("%d/%d",fenzi/max,fenmu/max);
}
