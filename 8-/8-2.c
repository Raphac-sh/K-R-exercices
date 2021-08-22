#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define PERMS 0666

#undef NULL
#undef BUFSIZ
#undef stdin
#undef stdout
#undef stderr

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

struct flags {
    unsigned int _read : 1;
    unsigned int _write : 1;
    unsigned int _unbuf : 1;
    unsigned int _eof : 1;
    unsigned int _err : 1;
}; 

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    struct flags flag;
    int fd;
} FILE;

FILE _iob[OPEN_MAX];

#define stdin (&_iob[0]);
#define stdout (&_iob[1]);
#define stderr (&_iob[2]);

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *p->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE *fopen(char *name, char *mode);

FILE *fopen(char *name, char *mode) {
    int fd;
    FILE *fp;

    if(*mode != 'r' && *mode != 'w' && *mode != 'a') return NULL;
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if(!(fp->flag._read && fp->flag._write)) break;
    if(fp >= _iob + OPEN_MAX) return NULL;

    if(*mode == 'w') fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if((fd = open(name, O_WRONLY, 0)) == -1) fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else fd = open(name, O_RDONLY, 0);

    if(fd == -1) return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    (*mode == 'r') ? (fp->flag._read = 1) : (fp->flag._write = 1);
    return fp;

}

int _fillbuf(FILE *fp) {
    int sizebuf;

    if(fp->flag._eof == 1 || fp->flag._err == 1) return EOF;
    sizebuf = (fp->flag._unbuf) ? 1 : BUFSIZ;
    if(fp->base == NULL)
        if((fp->base = (char *) malloc(sizebuf)) == NULL) return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, sizebuf);
    if(--fp->cnt < 0) {
        if(fp->cnt == -1) fp->flag._eof = 1;
        else fp->flag._err = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

int main(void) {
    FILE *fp = fopen("lol", "a");
}
