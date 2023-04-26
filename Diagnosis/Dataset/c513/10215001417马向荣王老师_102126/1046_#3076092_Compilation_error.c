#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
char ban[6][5]={"the","a","an","of","for","and"};
int makeit(char *a){
int sum=0;
int length=strlen(a);
char temp[100][100];
int cnt=0,ct=0;
bool flag=false;
for(int i=0; i<=length; i++){
if(isspace(a[i])||a[i]=='\0'){
temp[ct][cnt]='\0';
for(int i=0; i<6; i++){
if(strcmp(temp[ct],ban[i])==0)
flag=true;
}
ct++;
cnt=0;
if(!flag)
sum++;
flag=false;
}
else if(!isspace(a[i])){
temp[ct][cnt++]=a[i];
}
}
return sum;
}
int main()
{
    int cs,ans;
    scanf("%d\n",&cs);
    char vis[200];
    for(int i=0;i<cs;i++)
    {
        gets(vis);
        int length=strlen(vis);
        for(int k=0;vis[k]>='A'&&vis[k]<='Z';k++)
        {
            vis[k]+=32;
        }
        ans=make(vis);
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}