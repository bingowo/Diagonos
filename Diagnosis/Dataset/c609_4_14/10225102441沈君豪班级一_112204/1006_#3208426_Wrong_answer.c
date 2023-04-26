#include <stdio.h>
#include <string.h>


int main()
{
    int T,x,y;
    char s[100];
    char t[100];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",s);
        x=strlen(s);
        int a=1;
        for(int l=1;l<x;l++){
            for(int m=0;m<l;m++){
                if(s[l]==s[m]){

                    break;
                }
                if(m==(l-1)&&s[l]!=s[m]){
                    a++;
                    break;
                }
            }
        }
        y=1;
        int j;
        int n=2;
        t[0]=s[0];
        t[1]=s[1];
        for( j=1;j<x;j++){
            if(s[j]==s[0]){
                y=y*a+1;
            }else if(s[j]==s[1]){
                y=y*a+0;}
            else{
                for(int k=0;k<n;k++){
                    if(s[j]==t[k]){
                        y=y*a+k;
                        break;
                    }
                    if(k==(n-1)){
                        t[n]=s[j];
                        y=y*a+n;
                        n++;
                        break;
                    }
                }
            }
        }
        printf("case #%d:\n%d\n",i,y);
    }
    return 0;
}
