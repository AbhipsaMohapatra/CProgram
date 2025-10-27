#include <stdio.h>
void func1(int r,int c,char s[r][c]){
  for(int i=0;i<r;i++){
    for(int j=0;s[i][j]!='\0';j++){
        s[i][j]+=32;
    }
  }
}
void func2(int r,int c,char (*p)[c]){
  for(int i=0;i<r;i++){
    for(int j=0;p[i][j]!='\0';j++){
        p[i][j]-=32;
    }
  }
}
void func3(int r,int c,char *p){
    for(int i=0;i<r*c;i++){
        if((*p)!='\0'){

            (*p)+=32;
        }
        p++;
    }


}

void func4(int r,int c,char *p){
    for(int i=0;i<r;i++){
        for(int j=0;(*p)!='/0';j++){
            

        }
    }

}


int main(){
    int row=3;
    int col = 100;
    char s[3][100] = {"AAA","BBBB","CCCCC"};
    func1(row,col,s);
    printf("\n");
    for(int i=0;i<row;i++){
        fputs(s[i],stdout);
        printf("\n");
    }
    func2(row,col,s);
    printf("\n");
    for(int i=0;i<row;i++){
        fputs(s[i],stdout);
        printf("\n");
    }
    func3(row,col,&s[0][0]);
    printf("\n");
    for(int i=0;i<row;i++){
        fputs(s[i],stdout);
        printf("\n");
       
    }



}