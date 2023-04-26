#include<stdio.h>
#include<string.h>
int main(){
    int T,j=0;
    scanf("%d",&T);
    while(T-->0){
        char c[1000];
        int c1[1000];
        int temp=0;
        scanf("%s",c);
        int len=strlen(c);
        //printf("%s %d\n",c,len);
        for(int i=0;i<len;i++){
            if(c[i]=='1') c1[i]=1;
            else if(c[i]=='-') c1[i]=-1;
            else c1[i]=0;
        }
        for(int i=0;i<len;i++)
            temp=temp*3+c1[i];
        printf("case #%d:\n%d\n",j++,temp);
    }
    return 0;
}