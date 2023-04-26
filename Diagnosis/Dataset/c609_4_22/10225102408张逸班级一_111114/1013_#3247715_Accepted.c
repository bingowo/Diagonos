#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct pair{
    long long r;
    long long i;
}Pair;
Pair refer[16]={{0,0},{1,0},{-1,1},{0,1},{0,-2},{1,-2},{-1,-1}\
  ,{0,-1},{2,2},{3,2},{1,3},{2,3},{2,0},{3,0},{1,1},{2,1}};

int main(){
    char s[50];
    Pair ans={0,0};
    scanf("%s",s);
    int len=strlen(s);
    for(int j=2;j<len;j++){
        long long a=(s[j]>='A')?s[j]-'A'+10:s[j]-'0';
       ans.i=ans.i*(-4)+refer[a].i;
       ans.r=ans.r*(-4)+refer[a].r;
    }
    if(ans.i>0&&ans.r!=0){
        if(ans.i!=1)
        printf("%lld+%lldi\n",ans.r,ans.i);
        else printf("%lld+i\n",ans.r);
    }
    else if(ans.i<0&&ans.r!=0){
        if(ans.i!=-1)
        printf("%lld-%lldi\n",ans.r,-ans.i);
        else printf("%lld-i\n",ans.r);    
    }
    else if(ans.r==0&&ans.i!=0){
        if(ans.i!=1&&ans.i!=-1)
        printf("%lldi\n",ans.i);
        else if(ans.i==1)
        printf("i\n");
        else if(ans.i==-1)
        printf("-i\n");
    }
    else if(ans.i==0){
        printf("%lld\n",ans.r);
    }
 return 0;   
}