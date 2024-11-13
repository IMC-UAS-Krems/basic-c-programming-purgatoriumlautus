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
    int x = atoi(argv[1]); //will return 0 for non-integer input
    int y = atoi(argv[2]);
    if (x > 0 && y > 0){
        printf("x is %d\ny is %d\n",x,y);
    }
    else{
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
    }

    return 0;
}
