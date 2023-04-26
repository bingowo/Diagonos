#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char f[3][15];int p=-1;
    for(int i=0;i<3;i++){
        scanf("%s",f[i]);
        if(!isalpha(f[i][0]))p=i;
    }
    //推测孩子
    if(p==2){
        
    }
    //推测父母
    else{
        int fab=0,fo=0;
        for(int i=0;i<2;i++)
            if(strlen(f[i])==2)fab=1;
        if(f[2][0]=='O')fo=1;
        if(fo&&fab){//不可能的情况
            for(int i=0;i<3;i++){
                if(i!=p)printf("%s ",f[i]);
                else printf("impossible ");
            }
        }
        else{
            
        }
    }

    return 0;
}
