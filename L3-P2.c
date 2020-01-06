#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    pid_t firstBorn;
    pid_t secondBorn;
    pid_t thirdBorn;
    char Intr1[] = "adevarat";
    char Intr2[] = "fals";
    char Intr3[] = "D";
    char Intr4[] = "C";
    char Nume[100];
    firstBorn = fork();
    if(firstBorn == 0)
    {
        exit(0);
    }
    secondBorn = fork();
    if(secondBorn == 0)
    {
        exit(0);
    }
    thirdBorn = fork();
    if(thirdBorn == 0){
        exit(0);
    }
    int count = 10;
    for(int i = 0; i < 3; i++)
    {
        pid_t id = wait(NULL);
        if(id == firstBorn)
        {
            for(int i = 1; i <= 4; i++){
                printf("Intrebare %d\n",i);
            }
        }
        else if(id == secondBorn)
        {
            for(int j = 1; j<=4 ; j++){
                if(j==1){
                    printf("Raspunsul la intrebarea %d este %s\n ",j,Intr1);
                }
                else if(j==2){
                    printf("Raspunsul la intrebarea %d este %s\n ",j,Intr2);
                }
                else if(j==3){
                    printf("Raspunsul la intrebarea %d este %s\n ",j,Intr3);
                }
                else{
                    printf("Raspunsul la intrebarea %d este %s\n ",j,Intr4);
                }
            }
        }
        else if(id == thirdBorn){
            for(int i =0; i<= 10; i++){
                sleep(1);
                printf("%d\n",count-i);
            }
        }
    }
    printf("Numele Candidatului este:");
    scanf("%s\n",Nume);
    return 0;    
}