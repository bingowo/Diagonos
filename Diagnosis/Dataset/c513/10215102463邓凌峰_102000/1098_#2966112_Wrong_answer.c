#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        char lights[101]={0};
        scanf("%s",lights);
        int badLights[4]={0};
        int r=0,b=0,y=0,g=0;
        for(int j=0;j<strlen(lights);j++){
            if(lights[j]=='!') badLights[j%4]++;
            if(lights[j]=='R') r=j;
            else if(lights[j]=='B') b=j;
            else if(lights[j]=='Y') y=j;
            else if(lights[j]=='G') g=j;
        }
        printf("case #%d:\n%d %d %d %d\n",i,badLights[r%4],badLights[b%4],badLights[y%4],badLights[g%4]);


    }

    return 0;
}
