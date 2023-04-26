#include <stdio.h>

int main()
{
    int a[9], t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
        int isZero = 1, isInit = 1;
        for(int j = 0 ; j < 9; j ++){
            scanf("%d", &a[j]);
            if(a[j] != 0){
                isZero = 0;
            }
        }
    printf("case #%d:\n", i);
    if(isZero){
        printf("0");
    }
    else{
        for(int j = 0 ; j < 9 ; j ++){
            if(a[j] != 0){
                if(isInit/*是否是首项*/){
                    if(j < 7){
                        if(a[j] == -1){
                            printf("-x^%d", 8 - j);
                        }
                        else if(a[j] == 1){
                            printf("x^%d", 8 - j);
                        }else{
                            printf("%dx^%d", a[j], 8 - j);
                        } 
                    }else if(j == 7){
                        if(a[j] == -1){
                            printf("-x", 8 - j);
                        }
                        else if(a[j] == 1){
                            printf("x", 8 - j);
                        }
                        else{
                            printf("%dx", a[j], 8 - j);
                            } 
                        }else{
                            printf("%d", a[j]);
                        }
                        isInit = 0; }else{
                            if(j < 7){
                                if(a[j] == -1){
                                    printf("-x^%d", 8 - j);
                                    
                                }else if(a[j] == 1){
                                    printf("+x^%d", 8 - j);
                                    
                                }else{
                                    printf("%+dx^%d", a[j], 8 - j);
                                    
                                } 
                                
                            }else if(j == 7){
                                if(a[j] == -1){
                                    printf("-x", 8 - j);
                                    
                                }else if(a[j] == 1){
                                    printf("+x", 8 - j);
                                    
                                }else{
                                    printf("%+dx", a[j], 8 - j);
                                    
                                } 
                                
                            }else{
                                printf("%+d", a[j]);
                                
                            }
                    }
                }
            }
        }
        printf("\n");
        }
    return 0;
}