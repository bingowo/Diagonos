#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[40];
    int ints;
    int *pint;
    double dbs;
    double *pdb;
    int byte;
    unsigned char *ptr;
    while((scanf("%s",s) != EOF)){
        if(strchr(s,'.') == NULL){
            ints = atoi(s);
            pint = &ints;
            ptr = (unsigned char*)pint;
            byte = sizeof(ints);
        }
        else{
            dbs = atof(s);
            pdb = &dbs;
            ptr = (unsigned char*)pdb;
            byte = sizeof(dbs);
        }
        for(int i = 0;i < byte;i++){
            printf("%02x%c",*ptr++,(i != byte - 1)?' ':'\n');
        }
    }
    return 0;
}
