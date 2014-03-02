#ifndef TASK3_5_FUNCS_H
#define TASK3_5_FUNCS_H

#ifndef __cplusplus
typedef unsigned char bool;
#define true ((bool)1)
#define false ((bool)0)
#endif /* __cplusplus */

#ifndef NULL
#define NULL (void*)0
#endif /* NULL */

#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
typedef unsigned long long int    size_t;
#else
typedef unsigned int   size_t;
#endif
#define _SIZE_T_DEFINED
#endif

size_t StrLen( const char* str );
char* MemChr( const void* buf, char c, size_t len );
bool IsDigit( char chr );
bool IsUpper( char chr );
bool IsLower( char chr );
bool IsAlpha( char chr );
bool IsAlnum( char chr );
void removeWords( char *str, char *chars );

char* Input( void );

#endif /* TASK3_5_FUNCS_H */