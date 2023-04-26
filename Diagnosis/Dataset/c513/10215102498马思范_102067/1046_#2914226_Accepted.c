#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const char* ban[]={"the","a","an","of","for","and"};
int makeit(char *a){
    int sum=0;
    int length=strlen(a);
    char temp[100][100];
    int cnt=0,ct=0;
    int flag=0;
    for(int i=0; i<=length; i++){
        if(isspace(a[i])||a[i]=='\0'){
            temp[ct][cnt]='\0';
            for(int m=0; m<6; m++){
                if(strcmp(temp[ct],ban[m])==0)
                    flag=1;
            }
            ct++;
            cnt=0;
            if(flag==0)
                sum++;
            flag=0;
        }
        else if(!isspace(a[i])){
            temp[ct][cnt++]=a[i];
        }
    }
    return sum;
}
int main(){
    int t,ans;
    char vis[200];
    scanf("%d",&t);
    getchar();
    for(int k=0;k<t;k++)
    {
        gets(vis);
        int length=strlen(vis);
        for(int i=0;i<length;i++)
        {
            if(vis[i]>='A'&&vis[i]<='Z')
                vis[i]+=32;
        }
        ans=makeit(vis);
        printf("case #%d:\n%d\n",k,ans);
    }
}