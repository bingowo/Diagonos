#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    scanf("%s",a);
    int tool,inte=0,position;
    for(int i=0;a[i]!='\0'&&a[i]!=".";i++){
        tool=(int)a[i];
        if(tool==2)tool=-1;
        inte=inte*3+tool;
        position=i;
    }//整数部分
    if(a[++position]!='\0'){
        int u=0,d=1;
        for(int i=position;a[i]!='\0';i++){
            tool=a[i];
            if(tool==2)tool=-1;
            u=u*3+u;
            d*=3;
        }//小数部分
    printf("%d %d %d",inte,u,d);
    }
    else printf("%d",inte);
    return 0;
}
