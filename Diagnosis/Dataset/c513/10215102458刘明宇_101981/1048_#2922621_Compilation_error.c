int main()
{
    char s1[100],s2[100];
    scanf("%s",s1);
    int *p1 = xishu(s1);
    int *p2 = xishu(s2);
    int m1[51],m2[51];
    while(*p1){
        int i = 0;
        printf("%d ",*p1);
        m1[i++] = *p1;
        p1++;
    }
    while(*p2){
        int i = 0;
        m2[i++] = *p2;
        p2++;
    }
    //for(int x = 0;x<10;x++){
    //    printf("%d ",m1[x]);
    //}
    int mul[51];
    memset(mul,0,50);
    for(int j = 0;j < 51;j++){
        for(int k = 0;k < 51;k++){
            if(m1[j] != 0 && m2[k] != 0){
                mul[j+k] += m1[j] * m2[k];
            }
        }
    }
    int *ppp = mul;
    int len = 0;
    while(*ppp){
        len++;
        ppp++;
    }
    //for(int x = 0;x<len;x++){
    //    printf("%d ",mul[x]);
    //}
    return 0;
}
