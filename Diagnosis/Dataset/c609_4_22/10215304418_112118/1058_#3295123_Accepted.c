#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

char st[2234];
char temp[2540];
int ans[12345];

int main(){
    scanf("%s",st);
    if (st[0]=='0') {
        printf("0\n");
        return 0;
    }
    int num=0;
    if (st[0]!='+' && st[0]!='-') {
        for (int i=strlen(st)+1;i>=1;i--)
            st[i]=st[i-1];
        st[0]='+';
    }
    while (1){
        if (st[0]=='+' && st[1]=='1' && strlen(st)==2){
            ans[num++]=1;
            break;
        }
        int f=1;
        if (st[0]=='-') f=-1;
        if (st[0]=='+') st[0]='-';
        else st[0]='+';
        int ii=1;
        int left=0;
        for (int i=1;i<strlen(st);i++){
            int x=left*10+(st[i]-'0');
            if (x<=1 && i==1) {
                left=x;
                continue;
            }
            left=x%2;
            st[ii]='0'+x/2;
            ii++;
        }
        st[ii]='\0';
        if (left==1 && f==-1 && strlen(st)!=1) st[ii-1]+=1;
        else if (left==1 && f==-1){
            st[ii]='1';
            st[ii+1]='\0';
        }
        ans[num++]=left;
    }
    for (int i=num-1;i>=0;i--){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
