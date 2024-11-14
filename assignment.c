#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n",argc-1);
        return -1;
    }
    int row = atoi(argv[1]); //convert to integer will return 0 for non-integer input
    int col = atoi(argv[2]); 
    
    FILE *file1 = NULL; //create null pointer to file
    if (row > 0 && col > 0 ){
        printf("x is %d\ny is %d\n",row,col);
        
        int **mtrx = (int **)malloc(sizeof(int *)*row); //mtrx will point to allocated space size of  4bytes*row*col matrix
        
        for(int n=0;n<row;n++){
            mtrx[n] = (int *)malloc(sizeof(int)*col);
        }
        
        file1 = fopen("matrix","a"); 
        
        if (file1 == NULL) {
            printf("Failed to open file %s\n", argv[1]); 
            return -1;
        }


        for (int i = 0; i < row; i++){
            if(i > 0 && i < row){
                fprintf(file1,"\n");
            }

            for (int j = 0; j < col; j++){
                int randn = minrand + rand() % (maxrand - minrand + 1);
                mtrx[i][j] = randn;
                
                if(j == col-1){
                    
                    fprintf(file1,"%d",mtrx[i][j]);
                }
                else{
                    fprintf(file1,"%d ",mtrx[i][j]);
                }
            }
            
        }
    }

    else{
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
    }

     
    return 0;
}
