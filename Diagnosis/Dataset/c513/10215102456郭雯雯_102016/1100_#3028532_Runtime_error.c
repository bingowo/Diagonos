#include<stdio.h>
#include<string.h>

int main(){
    char s[101];
    scanf("%s",s);
    int u=0,d=0,l=0,r=0,q,up=0,lf=0;
    int len=strlen(s);
    scanf("%d",&q);
    int di[len+1][2];
    di[0][0]=0;di[0][1]=0;
    for(int i=0;i<len;i++){
        if(s[i]=='U'){
            u++;
            di[i+1][0]=di[i][0];
            di[i+1][1]=di[i][1]+1;
        }
        else if(s[i]=='D'){
            d++;
            di[i+1][0]=di[i][0];
            di[i+1][1]=di[i][1]-1;
        }
        else if(s[i]=='L'){
            l++;
            di[i+1][0]=di[i][0]-1;
            di[i+1][1]=di[i][1];
        }
        else if(s[i]=='R'){
            r++;
            di[i+1][0]=di[i][0]+1;
            di[i+1][1]=di[i][1];
        }
    }
    up=abs(u-d);lf=abs(l-r);
    while(q--){
        int a,b,i=0;
        scanf("%d%d",&a,&b);
        for(;i<=len;i++){
            if(a==di[i][0]&&b==di[i][1]){
                printf("Yes\n");
                break;
            }
            else if((a-di[i][0])%up==0&&(b-di[i][1])%lf==0){
                printf("Yes\n");
                break;
            }
        }
        if(i>len)printf("No\n");
    }
}