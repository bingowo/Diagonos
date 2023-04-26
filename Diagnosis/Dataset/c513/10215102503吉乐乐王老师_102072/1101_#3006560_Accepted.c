#include <stdio.h>
#include <string.h>
//这个表可以跳过，之间看后面的代码
void PrintPhenotype(char f[], char m[])
{
if(strcmp(f, "A+") == 0 && strcmp(m, "A+") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(m, "A-") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "A-") == 0 && strcmp(m, "A+") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "A-") == 0 && strcmp(m, "A-") == 0){
printf("{A-,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(m, "B+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(m, "B-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "A-") == 0 && strcmp(m, "B+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "A-") == 0 && strcmp(m, "B-") == 0){
printf("{A-,AB-,B-,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(m, "A+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(m, "A-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "B-") == 0 && strcmp(m, "A+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "B-") == 0 && strcmp(m, "A-") == 0){
printf("{A-,AB-,B-,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(m, "B+") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(m, "B-") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "B-") == 0 && strcmp(m, "B+") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "B-") == 0 && strcmp(m, "B-") == 0){
printf("{B-,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(m, "O+") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(m, "O-") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "A-") == 0 && strcmp(m, "O+") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "A-") == 0 && strcmp(m, "O-") == 0){
printf("{A-,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(m, "A+") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(m, "A-") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "O-") == 0 && strcmp(m, "A+") == 0){
printf("{A+,A-,O+,O-}");
}else if(strcmp(f, "O-") == 0 && strcmp(m, "A-") == 0){
printf("{A-,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(m, "O+") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(m, "O-") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "B-") == 0 && strcmp(m, "O+") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "B-") == 0 && strcmp(m, "O-") == 0){
printf("{B-,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(m, "B+") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(m, "B-") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "O-") == 0 && strcmp(m, "B+") == 0){
printf("{B+,B-,O+,O-}");
}else if(strcmp(f, "O-") == 0 && strcmp(m, "B-") == 0){
printf("{B-,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(m, "O+") == 0){
printf("{O+,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(m, "O-") == 0){
printf("{O+,O-}");
}else if(strcmp(f, "O-") == 0 && strcmp(m, "O+") == 0){
printf("{O+,O-}");
}else if(strcmp(f, "O-") == 0 && strcmp(m, "O-") == 0){
printf("O-");
}else if(strcmp(f, "AB+") == 0 && strcmp(m, "AB+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(m, "AB-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(m, "AB+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(m, "AB-") == 0){
printf("{A-,AB-,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(m, "A+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(m, "A-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(m, "A+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(m, "A-") == 0){
printf("{A-,AB-,B-}");
}else if(strcmp(f, "A+") == 0 && strcmp(m, "AB+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "A+") == 0 && strcmp(m, "AB-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "A-") == 0 && strcmp(m, "AB+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "A-") == 0 && strcmp(m, "AB-") == 0){
printf("{A-,AB-,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(m, "B+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(m, "B-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(m, "B+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(m, "B-") == 0){
printf("{A-,AB-,B-}");
}else if(strcmp(f, "B+") == 0 && strcmp(m, "AB+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "B+") == 0 && strcmp(m, "AB-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "B-") == 0 && strcmp(m, "AB+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "B-") == 0 && strcmp(m, "AB-") == 0){
printf("{A-,AB-,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(m, "O+") == 0){
printf("{A+,A-,B+,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(m, "O-") == 0){
printf("{A+,A-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(m, "O+") == 0){
printf("{A+,A-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(m, "O-") == 0){
printf("{A-,B-}");
}else if(strcmp(f, "O+") == 0 && strcmp(m, "AB+") == 0){
printf("{A+,A-,B+,B-}");
}else if(strcmp(f, "O+") == 0 && strcmp(m, "AB-") == 0){
printf("{A+,A-,B+,B-}");
}else if(strcmp(f, "O-") == 0 && strcmp(m, "AB+") == 0){
printf("{A+,A-,B+,B-}");
}else if(strcmp(f, "O-") == 0 && strcmp(m, "AB-") == 0){
printf("{A-,B-}");
}
}
void FindFather(char f[], char k[])
{
if(strcmp(f, "A+") == 0 && strcmp(k, "A+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(k, "A-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "A-") == 0 && strcmp(k, "A+") == 0){
printf("{A+,AB+,B+,O+}");
}else if(strcmp(f, "A-") == 0 && strcmp(k, "A-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(k, "B+") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "A+") == 0 && strcmp(k, "B-") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "A-") == 0 && strcmp(k, "B+") == 0){
printf("{AB+,B+}");
}else if(strcmp(f, "A-") == 0 && strcmp(k, "B-") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "B+") == 0 && strcmp(k, "A+") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "B+") == 0 && strcmp(k, "A-") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "B-") == 0 && strcmp(k, "A+") == 0){
printf("{A+,AB+}");
}else if(strcmp(f, "B-") == 0 && strcmp(k, "A-") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "B+") == 0 && strcmp(k, "B+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(k, "B-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "B-") == 0 && strcmp(k, "B+") == 0){
printf("{A+,AB+,B+,O+}");
}else if(strcmp(f, "B-") == 0 && strcmp(k, "B-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(k, "O+") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(k, "O-") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "A-") == 0 && strcmp(k, "O+") == 0){
printf("{A+,B+,O+}");
}else if(strcmp(f, "A-") == 0 && strcmp(k, "O-") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(k, "A+") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "O+") == 0 && strcmp(k, "A-") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "O-") == 0 && strcmp(k, "A+") == 0){
printf("{A+,AB+}");
}else if(strcmp(f, "O-") == 0 && strcmp(k, "A-") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "B+") == 0 && strcmp(k, "O+") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(k, "O-") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "B-") == 0 && strcmp(k, "O+") == 0){
printf("{A+,B+,O+}");
}else if(strcmp(f, "B-") == 0 && strcmp(k, "O-") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(k, "B+") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "O+") == 0 && strcmp(k, "B-") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "O-") == 0 && strcmp(k, "B+") == 0){
printf("{AB+,B+}");
}else if(strcmp(f, "O-") == 0 && strcmp(k, "B-") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "O+") == 0 && strcmp(k, "O+") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "O+") == 0 && strcmp(k, "O-") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "O-") == 0 && strcmp(k, "O+") == 0){
printf("{A+,B+,O+}");
}else if(strcmp(f, "O-") == 0 && strcmp(k, "O-") == 0){
printf("{A+,A-,B+,B-,O+,O-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(k, "AB+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(k, "AB-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(k, "AB+") == 0){
printf("{A+,AB+,B+}");
}else if(strcmp(f, "AB-") == 0 && strcmp(k, "AB-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(k, "A+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(k, "A-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(k, "A+") == 0){
printf("{A+,AB+,B+,O+}");
}else if(strcmp(f, "AB-") == 0 && strcmp(k, "A-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "A+") == 0 && strcmp(k, "AB+") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "A+") == 0 && strcmp(k, "AB-") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "A-") == 0 && strcmp(k, "AB+") == 0){
printf("{AB+,B+}");
}else if(strcmp(f, "A-") == 0 && strcmp(k, "AB-") == 0){
printf("{AB+,AB-,B+,B-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(k, "B+") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(k, "B-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "AB-") == 0 && strcmp(k, "B+") == 0){
printf("{A+,AB+,B+,O+}");
}else if(strcmp(f, "AB-") == 0 && strcmp(k, "B-") == 0){
printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
}else if(strcmp(f, "B+") == 0 && strcmp(k, "AB+") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "B+") == 0 && strcmp(k, "AB-") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "B-") == 0 && strcmp(k, "AB+") == 0){
printf("{A+,AB+}");
}else if(strcmp(f, "B-") == 0 && strcmp(k, "AB-") == 0){
printf("{A+,A-,AB+,AB-}");
}else if(strcmp(f, "AB+") == 0 && strcmp(k, "O+") == 0){
printf("impossible");
}else if(strcmp(f, "AB+") == 0 && strcmp(k, "O-") == 0){
printf("impossible");
}else if(strcmp(f, "AB-") == 0 && strcmp(k, "O+") == 0){
printf("impossible");
}else if(strcmp(f, "AB-") == 0 && strcmp(k, "O-") == 0){
printf("impossible");
}else if(strcmp(f, "O+") == 0 && strcmp(k, "AB+") == 0){
printf("impossible");
}else if(strcmp(f, "O+") == 0 && strcmp(k, "AB-") == 0){
printf("impossible");
}else if(strcmp(f, "O-") == 0 && strcmp(k, "AB+") == 0){
printf("impossible");
}else if(strcmp(f, "O-") == 0 && strcmp(k, "AB-") == 0){
printf("impossible");}
}
//其实没啥代码……
int main(void){
    char f[5], m[5], k[5];
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
    scanf("%s %s %s", f, m, k);
    if(strcmp(k, "?") == 0){
    printf("%s %s ", f, m);
    PrintPhenotype(f, m);
    }else if(strcmp(m, "?") == 0){
    printf("%s ", f);
    FindFather(f, k);
    printf(" %s", k);
    }else if(strcmp(f, "?") == 0){//
    FindFather(m, k);
    printf(" %s %s", m, k);
    }
    if(i != t - 1){ printf("\n");}
    }
    return 0;
}