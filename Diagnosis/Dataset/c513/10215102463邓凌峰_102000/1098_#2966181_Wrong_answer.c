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
        if(strlen(lights)==4){
            int bad=6;
            for(int j=0;j<4;j++){
                if(lights[j]=='R') bad-=0;
                else if(lights[j]=='B') bad-=1;
                else if(lights[j]=='Y') bad-=2;
                else if(lights[j]=='G') bad-=3;
            }
            badLights[bad]++;
            printf("%d %d %d %d\n",badLights[0],badLights[1],badLights[2],badLights[3]);
        }
        else{
            for(int j=0;j<strlen(lights);j++){
                if(lights[j]=='!') badLights[j%4]++;
                else{
                    if(lights[j]=='R') r=j;
                    else if(lights[j]=='B') b=j;
                    else if(lights[j]=='Y') y=j;
                    else g=j;
                }
            }
            printf("case #%d:\n%d %d %d %d\n",i,badLights[r%4],badLights[b%4],badLights[y%4],badLights[g%4]);
        }

    }

    return 0;
}
