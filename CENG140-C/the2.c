#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
char *Ptr;
char **Ptrresult;
int **numbers;
int number,uzunluk;
int *result;
char *ptrarray;
int index1 = 0;
int find(char c,char *p){
char *e;
int index;

e = strchr(p, c);
index = (int)(e - p);
return index;
}
void rechelper(char **c,int num,int len){
    int i,j,k,l,m,n,y,z;
    int *array;
    int ind = 0;
    array = calloc(len+5,sizeof(int));
        for(i=0;i<len;i++){
        c[0][i]= 'T';
        
    }
    for(m=len-1;m>=0;m--){
        array[m] = pow(2,len-1-m);
        /*printf("%d ",array[m]);*/
    }
    
        for(j=1;j<num;j++){
            for(k=0;k<len;k++){
                c[j][k] = 'T';
                
                
            }
        }
        for(j=1;j<num;j++){
            for(k=0;k<len;k++){
                if((j%array[k]) < 0.01 && (j/array[k])%2>0.1){
                    for(l=j;l<j+array[k];l++){
                    c[l][k] = 'F';
                    }
                }
            }
        }
    
   
}
int eval(int *ind){
    int left, right,i,j,k;
    char oper;
    if(*Ptr == '('){
    Ptr++;
    left = eval(ind);
    oper = *Ptr++;
    right = eval(ind);
    Ptr++;
    switch(oper){
        case '|':
        return left || right;
        case '&':
        return left && right;
        case '>':
        return left <= right;
        case '=':
        return left == right;
        
    }
    }
    else{
        if (*Ptr == '-'){
            Ptr++;
            if(eval(ind) == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
        left = ind[find(*Ptr,ptrarray)];
        /*index1 +=1;*/
        Ptr++;
        return left;
       }
        }
    }
    



int eval2(char *res,int* ind){
    Ptr = res;
    return eval(ind);
}
int main() {
    int nonchar = 0;
    int nonspace = 0;
    char temp;
    char *string;
    int *pr;
    int count = 0;
    int length;
    int strcount = 0;
    int k,m=0;
    int i,j,y,z,for1,for2,v,b,n,for3,for4;
    int l = 0;
    ptrarray = malloc(2*sizeof(char));
    string = malloc(2*sizeof(char));
    while(1){
    	string[count] = getchar();
        string = realloc(string,(count+5)*sizeof(char));
        if(string[count] == EOF){
        	string[count] = '\0';
        	break;
        	}
        	count++;
    }
    /*string[count] = '\0';*/
    /*printf("%s\n",string);*/
    for(k = 0;string[k];k++){
        if(islower(string[k])&&string[k]!='\0'&&string[k]!=' '&&string[k]&&string[k]!='\n'){
            ptrarray[l] = string[k];
            l++;
            strcount +=1;
            ptrarray = realloc(ptrarray,(strcount+5)*sizeof(char));
            if(string[k] == EOF){
            ptrarray[l] = '\0';
            }
        }
    }
    for(i=0;ptrarray[i];i++){
        for(j=i+1;ptrarray[j];j++){
            if(ptrarray[i]==ptrarray[j]){
                for(z=j;z<strlen(ptrarray);z++){
                    ptrarray[z] = ptrarray[z+1];
                }
                j--;
        }
    }
    }
    for(for1=0;for1<strlen(ptrarray)-1;for1++){
        for(for2=0;for2<strlen(ptrarray)-for1-1;for2++){
            if(ptrarray[for2] > ptrarray[for2 + 1]){
                temp = ptrarray[for2];
                ptrarray[for2] = ptrarray[for2 + 1];
                ptrarray[for2 + 1] = temp;
            }
        }
    }
/*printf("%s\n",string);*/
length = strlen(string);
  for(i=0;string[i]!='\0';i++){
  if(string[i]!=' '&& string[i]!='\n'){
  	string[nonspace] =string[i];
  	nonspace ++;
  	}
  	} 
  	string[nonspace] = '\0';
/*printf("%s",string);*/
/*for(i=0;ptrarray[i]!='\0';i++){
	if((int)ptrarray[i]!=2){
		ptrarray[nonchar] = ptrarray[i];
		nonchar ++;
		}
		}*/
if((int)ptrarray[0] == 2){
ptrarray++;}
ptrarray[strlen(ptrarray)] = 'R';
uzunluk= strlen(ptrarray);
number = pow(2,uzunluk-1);
Ptrresult = malloc(sizeof(char*)*(number+5));
for(n=0;n<number;n++){
    Ptrresult[n] = malloc(sizeof(char)*(uzunluk+31));}
    rechelper(Ptrresult,number,uzunluk-1);
for(i=0;ptrarray[i];i++){
    if(i==(strlen(ptrarray)-1)){
        printf("%c",ptrarray[i]);
    }
    else{
    printf("%c ",ptrarray[i]);
}
}
printf("\n");
numbers = malloc(sizeof(char*)*(number+5));
for(n=0;n<number;n++){
    numbers[n] = malloc(sizeof(char)*(uzunluk+31));}
for(i=0;i<number;i++){
    for(j=0;j<uzunluk-1;j++){
        if (Ptrresult[i][j] == 'T'){
            numbers[i][j] = 1;
        }
        else{
            numbers[i][j] = 0;
        }
    }
}
/*for(for3=0;for3<number;for3++){
    for(for4=0;for4<uzunluk;for4++){
        printf("%d ",numbers[for3][for4]);
        if(for4==uzunluk-1){
        printf("\n");
    }
    }
    
}*/




    
result = malloc(sizeof(int)*(number+5));
for(i=0;i<number;i++){
    result[i] = eval2(string,numbers[i]);
    /*printf("%d\n",result[i]);*/
}
for(i=0;i<number;i++){
    if(result[i]==0){
        Ptrresult[i][uzunluk-1] = 'F';
    }
    else{
        Ptrresult[i][uzunluk-1] = 'T';
    }
}
for(for3=0;for3<number;for3++){
    for(for4=0;for4<uzunluk;for4++){
        if(for4==uzunluk-1){
            printf("%c",Ptrresult[for3][for4]);
        }
        else{
        printf("%c ",Ptrresult[for3][for4]);}
        if(for4==uzunluk-1){
        printf("\n");
    }
    }
    
}
/*for(i=0;ptrarray[i];i++){
    if(i==(strlen(ptrarray)-1)){
        printf("%c",ptrarray[i]);
    }
    else{
    printf("%c ",ptrarray[i]);
}
}
printf("%d",uzunluk);
for(i=0;i<uzunluk;i++){
printf("%d\n",ptrarray[i]);}
for(i=0;ptrarray[i];i++){
    if(i==(strlen(ptrarray)-1)){
        printf("%c",ptrarray[i]);
    }
    else{
    printf("%c ",ptrarray[i]);
}
}*/
/*printf("%s",string);*/
return 0;
}
