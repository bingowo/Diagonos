#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void*a,const void*b){
    int x=*(int*)a;
    int y=*(int*)b;
    return x>y;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char s[30];
        scanf("%s",s);
        int p[30];
        p[0]=0;
        for(int i=0;i<strlen(s);i++){
            p[i+1]=s[i]-48;
        }
        int len=strlen(s)+1;
        printf("%d\n",len);
        int flag=0;
        int index1,index2;
        for(int i=len-2;i>=0;i--){
            for(int j=len-1;j>i;j--){
                if(p[j]>p[i]){
                    index1=i;
                    index2=j;
                    flag=1;
                    break;
                }
                else continue;
            }
            if(flag==1)break;
        }
        int x=p[index2];
        for(int i=index2;i>index1;i--){
            p[i]=p[i-1];
        }
        p[index1]=x;
        int pp[20];
        int lens=0;
        for(int i=index1+1;i<len;i++){
            pp[lens]=p[i];
            lens++;
        }
        qsort(pp,lens,sizeof(pp[0]),cmp);
        if(p[0]!=0)printf("%d",p[0]);
        for(int i=1;i<=index1;i++){
            printf("%d",p[i]);
        }
        for(int i=0;i<lens;i++){
            printf("%d",pp[i]);
        }
        printf("\n");
    }
}
