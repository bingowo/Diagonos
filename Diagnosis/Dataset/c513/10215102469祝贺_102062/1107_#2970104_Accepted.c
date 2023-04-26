#include<stdio.h>
#include<string.h>
#include<ctype.h>
void turn (int cube[5][5],int i,int j){
    cube[i][j]^=1;
    cube[i-1][j]^=1;
    cube[i][j-1]^=1;
    cube[i+1][j]^=1;
    cube[i][j+1]^=1;
    return ;
}
int main(){
    int cube[5][5],pro;
    scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cube[i][j]=1;
            }
        }
        for(int i=0;i<9;i++){
            int n;scanf("%d",&n);
            if(n%2!=0){
                switch(i){
                    case(0):{turn(cube,1,1);break;}
                    case(1):{turn(cube,1,2);break;}
                    case(2):{turn(cube,1,3);break;}
                    case(3):{turn(cube,2,1);break;}
                    case(4):{turn(cube,2,2);break;}
                    case(5):{turn(cube,2,3);break;}
                    case(6):{turn(cube,3,1);break;}
                    case(7):{turn(cube,3,2);break;}
                    case(8):{turn(cube,3,3);break;}
                }
            }
        }
        printf("case #%d:\n",index);
        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
                if(j!=3)printf("%d ",cube[i][j]);
                else printf("%d\n",cube[i][j]);
            }
        }
    }
    return 0;
}
