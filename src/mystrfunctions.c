#include "../include/mystrfunctions.h"

int mystrlen(const char* s){
int count=0;
while(s[count]!='\0')
{count=count+1;}
return count;
}
int mystrcpy(char* dest,const char* src){
int i=0;
while(src[i]!='\0'){
dest[i]=src[i];
i=i+1;
}
dest[i]='\0';
return i;}
int mystrncpy(char* dest, const char* src, int n) {
int srclen = mystrlen(src);
int i;
if (srclen <= n) {
for (i = 0; i < srclen; i++) {
dest[i] = src[i];
}
dest[i] = '\0';
}
if (srclen > n) {
for (i = 0; i < n; i++) {
dest[i] = src[i];
}
dest[i] = '\0';
}
return i;
}
int mystrcat(char* dest, const char* src){
int i=0;
while(dest[i]!='\0'){
i=i+1;}
int j=0;
while(src[j]!='\0'){
dest[i]=src[j];
i=i+1;
j=j+1;
}
dest[i]='\0';
return i;}
