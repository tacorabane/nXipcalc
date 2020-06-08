#include <stdio.h>
#include <stdlib.h>

#include "usage.h"
#include "checking.h"
#include "addressing.h"

#define MINIMUM_ARGS 2
#define ERROR_ARGS -1
#define ERROR -2
#define DEBUG 1

int main( int argc, char** argv ) {
    if (argc < MINIMUM_ARGS) {
        usage();
        return ERROR_ARGS;
    }

    IPV4* ipv4 = (IPV4*)malloc(sizeof(IPV4));
    char* input_str = argv[1];

    if (checkTypeArg(input_str) == 1) {
        #if DEBUG
        printf("Argument IPV4\n");
        #endif

        if (getIpv4(ipv4, input_str)) {
            printf("%d.%d.%d.%d\n", ipv4->first_block, ipv4->second_block, ipv4->third_block, ipv4->fourth_block);
            /* Vérification de la classe de l'adresse IP */
        }

    } else if (checkTypeArg(input_str) == 2) {
        #if DEBUG
        printf("Argument IPV6\n");
        #endif
    } else {
        #if DEBUG
        printf("Argument not IP Address\n");
        #endif
    }

    free(ipv4);
    return 0;
}
