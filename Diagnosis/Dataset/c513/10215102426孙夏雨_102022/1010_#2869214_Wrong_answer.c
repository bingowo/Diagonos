#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[501];
    scanf("%s",s);
    int length=strlen(s);
    int x=512;
    printf("0001");
    for(int i=0;i<10;i++){
        printf("%d",(length&x)>0 ? 1 : 0);
        x=x>>1;
    }
    if (length<3){
        if(length==1){
            int ans1=atoi(s);
            int y=8;
            for (int i=0;i<4;i++){
                printf("%d",(ans1&y)>0 ? 1 : 0);
                y=y>>1;
            }
        }
        else{
            int ans2=atoi(s);
            int z=64;
            for (int i=0;i<7;i++){
                printf("%d",(ans2&z)>0 ? 1 : 0);
                z=z>>1;
            }
        }
    }
    else{
        int j=0;
        for(;length-j>=3;j+=3){
            char s1[4];
            for(int k=0;k<3;k++) s1[k]=s[j+k];
            s1[4]=0;
            int ans3=atoi(s1);
            int w=512;
            for (int i=0;i<10;i++){
                printf("%d",(ans3&w)>0 ? 1 : 0);
                w=w>>1;
            }
        }
        char s2[3];
        for(int l=0;l<length-j;l++) s2[l]=s[j+l];
        s2[j]=0;
        if(length-j==1){
            int ans1=atoi(s2);
            int y=8;
            for (int i=0;i<4;i++){
                printf("%d",(ans1&y)>0 ? 1 : 0);
                y=y>>1;
            }
        }
        else if (length-j==2){
            int ans2=atoi(s2);
            int z=64;
            for (int i=0;i<7;i++){
                printf("%d",(ans2&z)>0 ? 1 : 0);
                z=z>>1;
            }
        }
    }
    return 0;
}
