#ifndef ADDRESSING_H
#define ADDRESSING_H

typedef struct Addr_Ipv4 {
    unsigned short first_block;
    unsigned short second_block;
    unsigned short third_block;
    unsigned short fourth_block;
} IPV4;

signed int getIpv4( IPV4*, char* );

char* extraxtFirstBlock( char* );
char* extractSecondBlock( char* );
char* extractThridBlock( char* );
char* extractFourthBlock( char* );

signed int lenInBlock( char*, unsigned short int, unsigned short int );

int length( char* );

int dotPosition(char*, int);

#endif
