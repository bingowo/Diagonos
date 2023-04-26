#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int solution(int t,int r)
{
    if (t==0&&r!=0) return -2;
    if (t==0&&r==0) return -1;
    if (r%t!=0||r/t<0) return -2;
    return r/t;
}


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
         for(int j=0;j<len;j++){
            int m1,m2;
            m1=solution(-step[len-1][0],step[j][0]-a);
            m2=solution(-step[len-1][1],step[j][1]-b);
            if (m1 == -2||m2 == -2) continue;
            if (m1 == -1||m2 == -1||m1 == m2){   flag=1;  break;  }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
