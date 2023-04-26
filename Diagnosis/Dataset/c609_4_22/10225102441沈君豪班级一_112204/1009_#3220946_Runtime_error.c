#include <stdio.h>
#include <string.h>

int measure(int x,int y){
    int z=y;
    while(x%y!=0){
        z=x%y;
        x=y;
        y=z;
    }
    return z;
}

int main()
{
    int n;
    scanf("%d",&n);    /* 此时输入流中还留有一个换行符，要把它吃掉*/
    char t=getchar();
    char c[100];
    for(int i=0;i<n;i++){
        gets(c);
        int b=strlen(c);
        int x=0,y,z;
        for(int j=0;j<b;j++){
            int a=1;
            for(int k=0;k<8;k++){
                if(c[j]&a){
                    x++;
                }
                a=a<<1;
            }
        }
        y=b*8;
        z=measure(x,y);
        printf("%d/%d\n",x/z,y/z);
    }
    return 0;
}
