// C program to implement one side of FIFO
// This side writes 
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    int fd;
 
    // FIFO file path
    char * myfifo = (char*)"/tmp/myfifo";
 
    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
 
    char arr1[80], arr2[80];
    
    // Open FIFO for write only
    fd = open(myfifo, O_WRONLY);
    for (int i = 0; i < 900000; ++i)
    {

        sprintf(arr2, "%d\n", i);
        write(fd, arr2, strlen(arr2)+1);
      
        // // Open FIFO for Read only
        // fd = open(myfifo, O_RDONLY);
 
        // // Read from FIFO
        // read(fd, arr1, sizeof(arr1));
 
        // // Print the read message
        // printf("User2: %s\n", arr1);
        // close(fd);
    } 
    close(fd);
    return 0;
}