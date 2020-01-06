#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/time.h>
#define CPUs 4

void child_function(int wd, int value){
   
   int result = value;
   
   write(wd, &result, sizeof(result));
      
}

int main(){
    
    int x[CPUs] = {3,70,52,11};
    
    int g = 52;
    
    int fd[2];
    pipe(fd);
    
    pid_t child[CPUs];
    
    for(int j = 0; j < CPUs; j++){
        
        child[j] = fork();
        if(child[j] == 0){
            child_function(fd[1],x[j]);
            printf("Pe pozitia %d avem %d\n",j,x[j]);
            if(g == x[j]){
                printf("Value %d found in vector\n", g);
                break;
            }
            return 0;
        }
        if(x[j] == g){
            break;
        }
    }  
      
    
    for(int i = 0; i< CPUs; i++){
        wait(NULL);
    }
    
    return 0;    

}