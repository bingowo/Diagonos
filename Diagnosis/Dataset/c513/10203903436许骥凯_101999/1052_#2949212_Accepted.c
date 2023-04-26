#include<stdio.h>
#include<string.h>

void trans(char *s){
    int alpha[130]; memset(alpha, 0, 520);
    int num[10] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) alpha[s[i]]++;
    while(alpha['Z']){
        alpha['Z']--; alpha['E']--; alpha['R']--; alpha['O']--;
        num[0]++;
    }
    while(alpha['W']){
        alpha['T']--; alpha['W']--; alpha['O']--;
        num[2]++;
    }
    while(alpha['U']){
        alpha['F']--; alpha['O']--; alpha['U']--; alpha['R']--;
        num[4]++;
    }
    while(alpha['F']){
        alpha['F']--; alpha['I']--; alpha['V']--; alpha['E']--;
        num[5]++;
    }
    while(alpha['X']){
        alpha['S']--; alpha['I']--; alpha['X']--;
        num[6]++;
    }
    while(alpha['S'])
    {
        alpha['S']--; alpha['E']--; alpha['V']--;
        alpha['E']--; alpha['N']--;
        num[7]++;
    }
    while(alpha['G'])
    {
        alpha['E']--; alpha['I']--; alpha['G']--;
        alpha['H']--; alpha['T']--;
        num[8]++;
    }
    while(alpha['I'])
    {
        alpha['N']--; alpha['I']--; alpha['N']--; alpha['E']--;
        num[9]++;
    }
    while(alpha['O'])
    {
        alpha['O']--; alpha['N']--; alpha['E']--;
        num[1]++;
    }
    while(alpha['R'])
    {
        alpha['T']--; alpha['H']--; alpha['E']-=2; alpha['R']--;
        num[3]++;
    }
    for (int i = 0; i != 10; i++){
        while(num[i]){
            printf("%d", i);
            num[i]--;
        }
    }
    printf("\n");
}
int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        char s[21]; scanf("%s", s);
        printf("case #%d:\n", i);
        trans(s);
    }
    return 0;
}