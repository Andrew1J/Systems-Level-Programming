int mystrlen (char *s) {
    int len = 0;
    while(*(s++)){
        len++;
    }
    return len;
}

char * mystrcpy(char *dest, char *source ) {
    int i;
    for(i=0;source[i]!='\0';i++){
        dest[i]=source[i];
    }
    dest[i]=source[i];
    return dest;
}

char * mystrncat( char *dest, char *source, int n) {
    int i, destlen = mystrlen(dest);
    for(i=0;source[i]!='\0'&&i<n;i++){
        dest[i+destlen]=source[i];
    }
    dest[i+destlen]='\0';
    return dest;
}

int mystrcmp( char *s1, char *s2 ) {
    while(*s1!='\0'||*s2!='\0') {
        if(*s1>*s2) return 1;
        if(*s2>*s1) return -1;
        *(s1++); *(s2++);
    }
    return 0;
}

char * mystrchr( char *s, char c) {
    int i;
    for(i=0;s[i]!='\0';i++){
        if(s[i]==c) return &s[i];
    }
    if(s[i]==c) return &s[i];
    return 0;
}
