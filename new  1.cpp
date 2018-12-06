#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
 
#define MAX_LEN 70
 
 
int main(int argc, const char *argv[])
{
    FILE *fd;
    char buff[MAX_LEN];
    char *token, *delim = " \n\0";
    unsigned int min_len, tmp;
 
    if ((fd = fopen("./input.DAT", "r+")) == NULL) {
        fprintf(stderr, "Open failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
 
    min_len = MAX_LEN; 
    while (fgets(buff, sizeof(buff), fd) != NULL) {
        printf("%sn", buff);
 
        token = strtok(buff, delim);
        while (token != NULL) {
            min_len = min_len > strlen(token) ? strlen(token) : min_len;
            token = strtok(NULL, delim);
        }
    }
 
    printf("min_len = %d\n", min_len);
 
    fclose(fd);
 
    exit(EXIT_SUCCESS);
}