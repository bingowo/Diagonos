for(m = 0;m<strlen(p);m++){
            if(strchr(b,p[m])) continue;
            else {b[n]=p[m];n++;}
        }
    long long N = 0;
    int a[50];
    int product = 1,m,n=1;
    if(i == 1){
        a[0]=1;
    }else if(i == 2){
        a[0]=1;
        if(p[0]!=p[1]) a[1]=0;
        else a[1] = 1;
    }else if(i>2){
        for(m = 0;m<i;m++){
            if(p[m]==p[0]) a[m]=1;
        }
        m = 1;
        while((p[m++]==p[0])) n++;
        for(m = 0;m<i;m++){
            if(p[m]==p[1]) a[m]=0;
        }
        m = 1;
        while((p[m++]==p[0])) n++;
    }
    for(m = i-1;m>=0;m--){
            N = N + a[m]*product;
            product *= i;
    }
    return N;
} 
