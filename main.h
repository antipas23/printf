#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>



/**
 * struct specifiers - match the conversion specifiers for printf
 * @identity: type char pointer of the specifier i.e
 * @flag: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int printfPointer(va_list args);

/******** HexDecimals ******************/
int printfHexAux(unsigned long int num);
int printfHEXAux(unsigned int num);
int printfHEX(va_list args);
int printfHex(va_list args);

/******** Binary and octal ******************/
int printfOct(va_list args);
int printfBin(va_list args);


/******** Integers ******************/
int printfInt(va_list args);
int printfUnsigned(va_list args);
int printfDec(va_list args);


/******** Reverse ******************/
int revString(char *s);
int printfRev(va_list args);
int printfRot13(va_list args);


/******** handler ******************/
int _strlen(char *s);
int _strlenc(const char *str);
int *_strcpy(char *dest, char *src);
int printfpercent(void);

/******** string ***********/
int printfChar(va_list val);
int printfString(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);
int printfExclusiveString(va_list args);


#endif
