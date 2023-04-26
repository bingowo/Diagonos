#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *s=(char *)malloc(100000*sizeof(char));
    int a[100]={0},i,c;
    int j=0;
    char b[100][50];
    scanf("%s",s);
    while(1){
        if(j==0) c=0;
        else c = a[j];
        a[j]=c+strstr(s+c,"0x")-s;
        printf("%d\n",a[j]);
        if(strstr(s+a[j]+2,"0x")==NULL) break;
        j = j+1;
    }

        //for(i=a+2;i<strlen(s);i++){
        //    if(s+i>="0"&&s+i<="9"&&s+i>="a"&&s+i<="f"){
         //       b[j]=
        //    }
       // }


    return 0;
}
