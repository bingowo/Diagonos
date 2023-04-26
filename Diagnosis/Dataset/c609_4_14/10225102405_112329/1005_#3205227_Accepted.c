#include<stdio.h>
int main()
{
    int T,i,j,output;
    char a[100][100];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%s",&a[i]);
    }
    for(i=0;i<T;i++){
        output=0;
        for(j=0;a[i][j]!='\0';j++){
            output*=3;
            if (a[i][j]=='1'){output+=1;}
            else if(a[i][j]=='-'){output+=-1;}
        }
        printf("case #%d:\n%d\n",i,output);
    }
    return 0;
}
