#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//+ 43 / 47 0 48 A 65 a 97
char A[65];
int main()
{
    for(int i=0;i<26;i++){
        A[i]=65+i;
    }
    for(int i=26;i<52;i++){
        A[i]=97+i-26;
    }
    for(int i=52;i<62;i++){
        A[i]=i-4;
    }
    A[62]='+';A[63]='/';
    int T;scanf("%d",&T);
    for(int p=0;p<T;p++){
        printf("case #%d:\n",p);
        char s[150];scanf("%s",s);
        int len=strlen(s);
        len*=8;
        int lens=len+1;
        if(len%6)
            lens=6-(len%6)+len+1;
        char st[lens+1];
        for(int i=0;i<strlen(s);i++){
            int t=s[i];
            for(int c=7;c>=0;c--){
                st[c+8*i]=t%2;
                t/=2;
            }
        }
        for(int i=strlen(s)*8;i<lens-1;i++){
            st[i]=0;
        }
        st[lens-1]=0;
        char res[100];
        for(int i=0;i<=lens/6;i++){
            int R=0;
            R=st[i*6]*32+st[1+i*6]*16+st[2+i*6]*8+st[3+i*6]*4+st[4+i*6]*2+st[5+i*6];
            res[i]=A[R];
        }
        if(lens/6%4){
            for(int i=lens/6;i<4-lens/6%4+lens/6;i++){
                res[i]='=';
            }
            res[4-lens/6%4+lens/6]=0;
        }
        else res[lens/6+1]=0;
        printf("%s\n",res);
    }
    return 0;
}
