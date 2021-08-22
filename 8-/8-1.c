#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int f;
    void copyfile(int, int);

    if(argc == 1) copyfile(0, 1);
    else while(--argc > 0) {
        if((f = open(*++argv, O_RDONLY)) == -1) {
            printf("cat : cannot open %s\n", *argv);
            return 1;
        } else {
            copyfile(f, 1);
            close(f);
        }
    }
    return 0;
}

void copyfile(int fin, int fout) {
    char buff[BUFSIZ];

    while((read(fin, buff, 1)) > 0) write(fout, buff, 1);
}
