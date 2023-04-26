#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct{
    int sum;
    char from;
}Block;

Block in[210][210];

void reverse(char s[])
{
    int len = strlen(s);
    char temp;
    for (int i=0; i<len/2; i++) {
        temp=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=temp;
    }
}

int main(void)
{
    int m,n;
    int temp;
    char path[11000];
    scanf("%d %d",&m,&n);
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%d",&temp);
            if (i==1&&j==1) {
                in[i][j].sum=temp;
                in[i][j].from='N';
            }
            else if(i==1){
                in[i][j].sum=in[i][j-1].sum+temp;
                in[i][j].from='R';
            }
            else if(j==1){
                in[i][j].sum = in[i-1][j].sum+temp;
                in[i][j].from='D';
            }
            else{
                if(in[i-1][j].sum<in[i][j-1].sum){
                    in[i][j].sum=in[i-1][j].sum+temp;
                    in[i][j].from='D';
                }
                else{
                    in[i][j].sum=in[i][j-1].sum+temp;
                    in[i][j].from='R';
                }
            }
        }
    }
    int i=m,j=n,index=0;
    
    while (i!=1||j!=1) {
        path[index++]=in[i][j].from;
        if(in[i][j].from=='R'){
            j-=1;
        }
        else if(in[i][j].from=='D'){
            i-=1;
        }
    }
    path[index]='\0';
    reverse(path);
    printf("%d\n",in[m][n].sum);
    printf("%s",path);
}
