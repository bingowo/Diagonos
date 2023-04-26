#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[110];
    int q;
    scanf("%s%d",s,&q);
    int step[110][2];
    for(int i=0;i<110;i++){
        step[i][0]=0;
        step[i][1]=0;
    }
    int len=0;
        if(s[0]=='L')step[len][0]=-1;
        if(s[0]=='R')step[len][0]=1;
        if(s[0]=='D')step[len][1]=-1;
        if(s[0]=='U')step[len][1]=1;
    len++;
    for(int i=1;i<strlen(s);i++){
        if(s[i]=='L'){step[len][0]=step[len-1][0]-1;step[len][1]=step[len-1][1];len++;}
        if(s[i]=='R'){step[len][0]=step[len-1][0]+1;step[len][1]=step[len-1][1];len++;}
        if(s[i]=='D'){step[len][0]=step[len-1][0];step[len][1]=step[len-1][1]-1;len++;}
        if(s[i]=='U'){step[len][0]=step[len-1][0];step[len][1]=step[len-1][1]+1;len++;}
    }
    for(int i=0;i<len;i++){
        printf("%d %d\n",step[i][0],step[i][1]);
    }

    for(int i=0;i<q;i++){
        int flag=0;
        int a,b;
        scanf("%d%d",&a,&b);
        int rem1=a,rem2=b;
        if(a*step[len-1][0]>0&&b*step[len-1][1>0]){
        while((rem1-step[len-1][0])>=0&&(rem2-step[len-1][1])>=0){
            rem1=rem1-step[len-1][0];
            rem2=rem2-step[len-1][1];
        }
        }
        if(rem1==0&rem2==0)flag=1;
        for(int j=0;j<len;j++){
            if(rem2==step[j][1]&&rem1==step[j][0]){flag=1;break;}
        }
        if(flag){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
