#include <stdio.h>
#include <string.h>


int main()
{
    int T,x,y;
    char s[100];                 /* s用来存储读入的字符串*/
    char t[100];                 /*t可以用来记录s中元素种类*/
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",s);
        x=strlen(s);
        int a=1;
        for(int l=1;l<x;l++){
            for(int m=0;m<l;m++){
                if(s[l]==s[m]){

                    break;
                }
                if(m==(l-1)&&s[l]!=s[m]){
                    a++;
                    break;
                }
            }
        }                            /*该循环一直遍历字符串中所有元素，得到种类个数，用来确定进制*/
        y=1;
        int j;
        int n=2;
        t[0]=s[0];
        int p=0;
        while(s[p]==s[0]){
            p++;
        }
        t[1]=s[p];                   /*第一个和第二个数字特殊，0，1位置交换，所以需要先确定这两个元素，这样使得下次这个元素在字符串中序号为几就可以表示几*/
        for( j=1;j<x;j++){
            if(s[j]==t[0]){
                y=y*a+1;
            }else if(s[j]==t[1]){
                y=y*a+0;}
            else{
                for(int k=0;k<n;k++){
                    if(s[j]==t[k]){
                        y=y*a+k;
                        break;
                    }
                    if(k==(n-1)){
                        t[n]=s[j];
                        y=y*a+n;
                        n++;
                        break;
                    }
                }
            }
        }
        printf("case #%d:\n%d\n",i,y);
    }
    return 0;
}
