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

#define MAX_SIMULT_CONNECTIONS 1

#ifndef SRV_FILE
#define SRV_FILE "srv_data.bin"
#endif

#ifndef FILE_SIZE
#define FILE_SIZE (1 << 30) /* 1 GB */
#endif

static void srv_send(int pipe, FILE *file)
{
    ssize_t ret;
    char buf[1024];
    ssize_t i = 0;

    while (true)
    {
        ret = fread(buf, sizeof(char), 1024, file);
        i += ret;

        if (ret == 0)
        {
            printf("[%s] sent %ld bytes\n", __func__, i);
            return;
        }

        if (ret < 0)
        {
            perror("listen() error");
            exit(EXIT_FAILURE);
        }

        if (write(pipe, buf, ret) != ret)
        {
            perror("write() error");
            exit(EXIT_FAILURE);
        }
    }
}

void srv_start(int pipe)
{
    FILE *file;

    /* file init */
    file = fopen(SRV_FILE, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    /* client connected */
    srv_send(pipe, file);

    fclose(file);
}
