#include <stdio.h>
#include <stdlib.h>

char table[16][4] = {
    {'0',0,0,0},{'1',0,0,0},{'-','1','+','i'},{'i',0,0,0},
    {'-','2','i',0},{'1','-','2','i'},{'-','1','-','i'},{'-','i',0,0},
    {'2','+','2','i'},{'3','+','2','i'},{'1','+','3','i'},{'2','+','3','i'},
    {'2',0,0,0},{'3',0,0,0},{'1','+','i',0},{'2','+','i',0}
    };

int main()
{
    int i,j,k;
    char str[4] = {0,0,0,0};
    scanf("%s",str);
    for(i = 0;i < 16;i++){
        int number = 0;
        for(j = 0;j < 4;j++){
            if(str[j] != table[i][j])break;
            else
                number++;
        }
        if(number == 4)break;
    }

    return 0;
}
