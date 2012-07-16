#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char	str[1024];
    int		fd, fd2, bn, i;

    if ((fd2 = open("fread3.man", O_WRONLY | O_CREAT, 0644)) == -1) {
        printf("Write file could not be opened");
        exit(1);
    }

    if ((fd = open("fread.man", O_RDONLY, 0644)) == -1) {
        printf("Read file could not be opened");
        exit(1);

    }

    while ((bn = read(fd, str, sizeof (str))) > 0) {
        for (i = 0; i < bn; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
        write(fd2, str, bn);
    }

    close(fd);
    close(fd2);

    return 0;
}


