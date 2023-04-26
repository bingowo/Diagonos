#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef long long ll;

int pros;
int len,r;
char s[50];
int b=3;

int main(){
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%s",s);
        len=strlen(s);
        r=0;
        for(int i=len-1,w=1,t;i>=0;i--,w*=b){
            t=0;
            if(s[i]=='1') t=1;
            else if(s[i]=='-') t=-1;
            r+=t*w;
        }
        printf("case #%d:\n",cnt);
        printf("%d\n",r);
    }
    return 0;
}


