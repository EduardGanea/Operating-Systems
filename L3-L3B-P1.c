#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/time.h>
#define CPUs 4

void child_function(int wd, int value){
   int result = result + value;
   write(wd, &result, sizeof(result));
      
}

int main(){
    
    int x[CPUs] = {3,70,52,11};
    
    int fd[2];
    pipe(fd);
    
    pid_t child[CPUs];
    
    for(int j = 0; j < CPUs; j++){
        
        child[j] = fork();
        if(child[j] == 0){
            for(int k =0 ; k < CPUs; k++)
            child_function(fd[1],x[k]);
            return 0;
        }
    }  
      
    
    for(int i = 0; i< CPUs; i++){
        wait(NULL);
    }
    
    int result[CPUs];
    read(fd[0], &result, sizeof(int)*CPUs);
    for(int i = 0; i < CPUs; i++){
        printf("Pe pozitia %d, avem %d\n",i,result[i]);    
    }
    return 0;    

}