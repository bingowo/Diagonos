#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
const char Char[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
int result[30];
int szResult; 
int main()
{
    int N,R;
    int r;
    int dir;
    scanf("%d%d",&N,&R);
    szResult=0;
    if(N>0)dir=-1;//待转换数是正数，一开始都是负的，也就是要在原值上减 
    else
        dir=1;//待转换数是负数，一开始都是正的，也就是要在原值上加 
    if(R<0) R=-R;//我们做取模的时候都要用正数 
    while(N!=0)
    {
        if(N>0)
        {
            //正数如此处理 
            r=N%R;    
            if(r!=0 && dir>0)//负数（正常）用取模值，正数（负基数特有）要用基数-取模值
                r=R-r;            
        }
        else
        {
            r=N%R;
            if(r!=0 && dir>0)//负数（正常）用取模值，正数（负基数特有）要用基数-取模值
                r=-R-r;            
        }
        N+=dir*r;
        if (r<0)
            result[szResult]=-r;//计数的时候都要当正数来记录
        else
            result[szResult]=r;//计数的时候都要当正数来记录 
        szResult++;
        N/=R;
        dir=-dir;        
    }
    for (int i=szResult-1;i>=0;i--)
        printf("%c",Char[result[i]]);
    R=-R;
    return 0;
}