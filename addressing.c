#include <stdio.h>
#include <stdlib.h>

#include "addressing.h"

#define ERROR -2

signed int lenInBlock(char* input, unsigned short int start, unsigned short int end) {
    if (input == NULL) {
        printf("Error 202: lenInBlock: Argument missing\n");
        return ERROR;
    }

    unsigned short int i;
    unsigned short int count = 0;

    for (i = start; input[i] != '.'; i++) {
        count++;
    }

    return (signed)count;
}

int length(char* input) {
    if (input == NULL) {
        printf("Error 203: length: Argument missing\n");
        return ERROR;
    }

    int i = 0;

    while (input[i] != '\0') {
        i++;
    }

    return i;
}

char* extractFirstBlock(char* input) {
    if (input == NULL) {
        printf("Error 201: extractFirstBlock: Argument missing\n");
        return (char*)ERROR;
    }

    char* temp = (char*)malloc(lenInBlock(input, 0, length(input)) * sizeof(char));
    int i = 0;

    while (input[i] != '.') {
        temp[i] = input[i];
        i++;
    }

    temp[i] = '\0';

    return temp;
}

char* extractSecondBlock(char* input) {
    if (input == NULL) {
        printf("Error 201: extractSecondBlock: Missing argument\n");
        return (char*)ERROR;
    }

    char* temp = (char*)malloc(lenInBlock(input, dotPosition(input, 1) + 1, length(input)) * sizeof(char));
    int i = dotPosition(input, 1) + 1;
    int j = 0;

    while ( input[i] != '.' ) {
        temp[j] = input[i];
        j++;
        i++;
    }

    temp[i] = '\0';

    return temp;
}

char* extractThirdBlock(char* input) {
    if (input == NULL) {
        printf("Error 201: extractThirdBlock: Missing argument\n");
        return (char*)ERROR;
    }

    char* temp = (char*)malloc(lenInBlock(input, dotPosition(input, 2) + 1, length(input)) * sizeof(char));
    int i = dotPosition(input, 2) + 1;
    int j = 0;

    while (input[i] != '.') {
        temp[j] = input[i];
        i++;
        j++;
    }

    temp[i] = '\0';

    return temp;
}

char* extractFourthBlock(char* input) {
    if (input == NULL) {
        printf("Error 201 extractFourthBlock: Missing argument\n");
        return (char*)ERROR;
    }

    char* temp = (char*)malloc(lenInBlock(input, dotPosition(input, 3) + 1, length(input)) * sizeof(char));
    int i = dotPosition(input, 3) + 1;
    int j = 0;

    while (input[i] != '.') {
        temp[j] = input[i];
        i++;
        j++;
    }

    temp[i] = '\0';

    return temp;
}

signed int getIpv4(IPV4* ip, char* input) {
    if (input == NULL) {
        printf("Error 200: getIpv4: Argument missing\n");
        return ERROR;
    }

    if (ip == NULL) {
        printf("Error 200: getIpv4: Struct missing\n");
        return ERROR;
    }

    ip->first_block = atoi(extractFirstBlock(input));
    ip->second_block = atoi(extractSecondBlock(input));
    ip->third_block = atoi(extractThirdBlock(input));
    ip->fourth_block = atoi(extractFourthBlock(input));

    return 1;
}

int dotPosition(char* input, int whichDot) {
  if (input == NULL) {
      printf("Error 200: dotPosition: Argument missing\n");
      return ERROR;
  }

  int isDot = 0;
  int i = 0;

  while(whichDot != isDot) {
    i++;
    if(isDot != whichDot && input[i] == '.') isDot++;
  }

  return i;
}
