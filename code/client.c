#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef CLIENT_FILE
#define CLIENT_FILE "client_data.bin"
#endif

#ifndef FILE_SIZE
#define FILE_SIZE (1 << 30) /* 1 GB */
#endif

static void client_recv(int pipe, FILE *file)
{
    int ret;
    char buf[1024];
    int wr;
    int total = 0;

    while (true)
    {
        if ((ret = read(pipe, buf, 1024)) < 0)
        {
            perror("read() error");
            exit(EXIT_FAILURE);
        }

        if (ret == 0)
        {
            printf("[%s] written %d bytes\n", __func__, total);
            return;
        }

        /* write to file */
        wr = fwrite(buf, sizeof(char), ret, file);

        if (ret != wr)
        {
            perror("write() error");
            exit(EXIT_FAILURE);
        }

        total += wr;
    }
}

void client_start(int pipe)
{
    FILE *file;

    /* file init */
    file = fopen(CLIENT_FILE, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    client_recv(pipe, file);

    fclose(file);
}
