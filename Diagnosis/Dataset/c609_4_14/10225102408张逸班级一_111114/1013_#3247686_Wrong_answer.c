#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct pair{
    int r;
    int i;
}Pair;
Pair refer[16]={{0,0},{1,0},{-1,1},{0,1},{0,-2},{1,-2},{-1,-1}\
  ,{0,-1},{2,2},{3,2},{1,3},{2,3},{2,0},{3,0},{1,1},{2,1}};

int main(){
    char s[50];
    Pair ans={0,0};
    scanf("%s",s);
    int len=strlen(s);
    for(int j=2;j<len;j++){
        int a=(s[j]>='A')?s[j]-'A'+10:s[j]-'0';
       ans.i=ans.i*(-4)+refer[a].i;
       ans.r=ans.r*(-4)+refer[a].r;
    }
    if(ans.i>0&&ans.r!=0){
        if(ans.i!=1)
        printf("%d+%di\n",ans.r,ans.i);
        else printf("%d+i\n",ans.r);
    }
    else if(ans.i<0&&ans.r!=0){
        if(ans.i!=-1)
        printf("%d-%di\n",ans.r,-ans.i);
        else printf("%d-i\n",ans.r);    
    }
    else if(ans.r==0&&ans.i!=0){
        printf("%di\n",ans.i);
    }
    else if(ans.i==0){
        printf("%d\n",ans.r);
    }
 return 0;   
}
