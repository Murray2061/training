#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char str[1024];
    int	fd,bn,i;
    
    if ((fd = open("fread.man",O_RDONLY,0644)) == -1) {
        printf("File could not be opened");
    }else {
        while ((bn=read(fd, str, sizeof(str)))>0) {
             for (i = 0; i < bn; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[i] = str[i] - 32;
                }
            }
            write(1,str,bn);
        }

		}

    close(fd);

    return 0;
}
