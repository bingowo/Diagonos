 #include <stdio.h>

int main() {
  
    double dval;
    int ival;
    scanf("%lf", &dval);
    ival = (int)dval;

   
  
    unsigned char *p = (unsigned char *)&ival;
    for (int i = 0; i < sizeof(ival); i++) {
        printf("%02x ", *(p+i));
    }
    printf("\n");

 
    printf("double 变量的字节：\n");
    p = (unsigned char *)&dval;
    for (int i = 0; i < sizeof(dval); i++) {
        printf("%02x ", *(p+i));
    }
    printf("\n");

    return 0;
}
