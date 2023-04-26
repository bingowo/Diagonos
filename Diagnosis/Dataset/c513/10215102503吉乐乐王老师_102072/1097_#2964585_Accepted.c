#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int col;
    int row;
    char ch;
}node;
int main(){
    char s[81];
    while(scanf("%s",s)==1){
        node *data=(node*)malloc(sizeof(node)*strlen(s));//储存每一个字符所在的行和列
        data[0].ch=s[0];data[0].row=0;data[0].col=0;
        int pre=0;
        int min=0,max=0;
        for(int i=1;i<strlen(s);i++){
            data[i].ch=s[i];
            data[i].col=i;
            if(s[i]>s[pre])data[i].row=data[pre].row+1;
            else if(s[i]<s[pre])data[i].row=data[pre].row-1;
            else data[i].row=data[pre].row;
            min=data[i].row<min?data[i].row:min;
            max=data[i].row>max?data[i].row:max;
            pre=i;
        }
        for(int i=0;i<strlen(s);i++){
            data[i].row+=0-min;
        }
        max+=0-min;
        int **pic=(int**)malloc(sizeof(int*)*(max+1));
        for(int i=0;i<=max;i++){
            pic[i]=(int*)malloc(sizeof(int)*strlen(s));
            for(int j=0;j<strlen(s);j++)pic[i][j]=0;
        }
        for(int i=0;i<strlen(s);i++){
            pic[data[i].row][data[i].col]=data[i].ch;
        }
        int flag;
        for(int i=max;i>=0;i--){
            for(int j=0;j<strlen(s);j++){
                if(pic[i][j]){
                    printf("%c",pic[i][j]);
                    flag=0;//假设这一行没有了
                    for(int k=j+1;k<strlen(s);k++){
                        if(pic[i][k]){flag=1;break;}
                    }
                    if(flag)continue;
                    else break;
                }
                else printf(" ");
            }
            printf("\n");
        }
    }
}