for(int i=2;i<=a[0];i++) c[0]+=((int)(s[a[0]-i])-48)*pow(10,i-2);
    if(a[1]==-1) c[1]=0;
    else {
            int z=a[1];
        while(1)
        {
            if(s[z]=='x') break;
            else z++;
        }
        for(int i=1;i<z-a[1];z++) c[1]+=((int)(s[z-i])-48)*pow(10,i-1);
        if(s[a[1]]=='-') c[1]*=(-1);
    }
    if(a[2]==-1) c[2]=0;
    else {
        for(int i=0;i<len-a[2];i++) c[2]+=((int)(s[len-i])-48)*pow(10,i);
        if(s[2]=='-') c[2]*=(-1);
    }