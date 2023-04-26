#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    char A[501],B[501];
    while(scanf("%s",A)!=EOF&&scanf("%s",B)!=EOF){
        int len1=strlen(A),len2=strlen(B);
        //第一种情况A>B
        if(len1>len2||(len1==len2&&strcmp(A,B)>=0)){
            char c[501],d[501];
            for(int i=0;i<len1;i++)c[len1-i-1]=A[i];
            strcpy(A,c);
            for(int i=0;i<len2;i++)d[len2-i-1]=B[i];
            strcpy(B,d);
            for(int i=0;i<len2;i++){
                int m=i;
                while(A[m]<48){
                    A[m]=10-(48-A[m])+48;
                    A[m+1]--;
                    m++;
                }
                A[i]=A[i]-B[i]+48;
                m=i;
                while(A[m]<48){
                    A[m]=10-(48-A[m])+48;
                    A[m+1]--;
                    m++;
                }
            }
            for(int i=0;i<len1;i++)c[i]=A[len1-i-1];
            strcpy(A,c);
            int startp=0;
            for(int i=0;i<len1;i++){
                if(A[i]!='0'){
                    startp=i;
                    break;
                }
            }
            for(int i=startp;i<len1;i++)printf("%c",A[i]);
            printf("\n");
        }
        //A<B
        else{
            char c[501],d[501];
            printf("-");
        for(int i=0;i<len1;i++)c[len1-i-1]=A[i];
            strcpy(A,c);
            for(int i=0;i<len2;i++)d[len2-i-1]=B[i];
            strcpy(B,d);
            for(int i=0;i<len1;i++){
                int m=i;
                while(B[m]<48){
                    B[m]=10-(48-B[m])+48;
                    B[m+1]--;
                    m++;
                }
                B[i]=B[i]-A[i]+48;
                m=i;
                while(B[m]<48){
                    B[m]=10-(48-B[m])+48;
                    B[m+1]--;
                    m++;
                }
            }
            for(int i=0;i<len2;i++)d[len2-i-1]=B[i];
            strcpy(B,d);
            int startp=0;
            for(int i=0;i<len2;i++){
                if(B[i]!='0'){
                    startp=i;
                    break;
                }
            }
            for(int i=startp;i<len2;i++)printf("%c",B[i]);
            printf("\n");
        }
    }
}
