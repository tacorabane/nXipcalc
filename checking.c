#include <stdio.h>

#include "checking.h"

#define ERROR -2

int checkTypeArg ( char* input ) {
    if ( input == NULL ) {
        printf("Error 100: checkTypeArg: No input argument\n");
        return ERROR;
    }
    
    unsigned short i = 0;
    unsigned short countV4 = 0;
    unsigned short countV6 = 0;
    
    while( input[i] != '\0' ) {
        if( input[i] == '.' ) {
            countV4++;
            i++;
        }
        else if( input[i] == ':' ) {
            countV6++;
            i++;
        }
        else i++;
    }
    
    if( countV4 == 3 ) return 1;
    else if( countV6 == 7 ) return 2;
    else return 0;
}