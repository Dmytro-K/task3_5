#include "task3_5_funcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

size_t StrLen( const char* str )
{
	size_t i;
	int a, b, k;

	k = StrLen( str );

	a = k++;
	b = ++k;

	printf( "%d %d", a, b );

	if( str == NULL ) {
		return 0;
	}
	
	for( i = 0; *str != 0; i++, str++ ) {
		; /* NULL */
	}
	return i;
}

void* MemChr( const void* buf, char c, size_t len )
{
	size_t i;
	//const char *ptr = buf;
	if( buf == NULL )
	{
		return NULL;
	}

	for( i = 0; i < len; i++ )
	{
		if( *(char*)buf == c )
		{
			return (void*)buf;
		}
		( *( (char**)( &buf ) ) )++;
	}
	return NULL;
}

bool IsDigit( char chr )
{
	return ( chr >= 0x30 ) && ( chr <= 0x39 );
}

bool IsUpper( char chr )
{
	return ( chr >= 0x41 ) && ( chr <= 0x5A );
}

bool IsLower( char chr )
{
	return ( chr >= 0x61 ) && ( chr <= 0x7A );
}

bool IsAlpha( char chr )
{
	return IsUpper( chr ) || IsLower( chr );
}

bool IsAlnum( char chr )
{
	return IsDigit( chr ) || IsAlpha( chr );
}

void RemoveWords( char *str, char *chars )
{
	size_t i, wordLen, charsLen;

	charsLen = StrLen( chars );

	for( ;; )
	{
		while( !IsAlnum( *str ) )
		{
			if( *str == 0 )
			{
				return;
			}
			str++;
		}
		
		for( wordLen = 0; IsAlnum( str[wordLen] ); wordLen++ )
		{
			; /* NULL */
		}
		
		for( i = 0; i < charsLen; i++ )
		{
			if( MemChr( str, chars[i], wordLen ) == NULL )
			{
				break;
			}
		}
		if( i == charsLen ) 
		{
			memmove( str, str + wordLen, StrLen(str + wordLen)+1 );
		}
		else
		{
			str += wordLen;
		}
	}
}

#define BUF_LEN 256

char* Input( void )
{
	char buffer[BUF_LEN];
	char *str = NULL;
	size_t lastLen;

	lastLen = 0;

	for( ;; )
	{
		size_t len;
		char *tmp;
		fgets( buffer, BUF_LEN, stdin );
		len = StrLen( buffer );

		if( len == 1 )
		{
			break;
		}

		if( buffer[len - 1] == '\n' )
		{
			len--;
		}

		tmp = realloc( str, lastLen + len + 1 );
		if( tmp == NULL )
		{
			free( str );
			return NULL;
		}
		else
		{
			str = tmp;
		}
		memcpy( str + lastLen, buffer, len );
		lastLen += len;
		str[lastLen] = 0;
	}

	return str;
}

#undef BUF_LEN

char* CheckedInput( bool checkFunc( char ) )
{
	char *str;
	size_t i, len;
	bool k;

	do
	{
		k = false;
		str = Input();
		if( str == NULL )
		{
			puts( "Something wrong" );
			return NULL;
		}
		len = StrLen( str );
		if( checkFunc != NULL )
		{
			for( i = 0; i < len; i++ )
			{
				if( checkFunc( str[i] ) == false )
				{
					k = true;
					puts( "Wrong input, try again" );
					free( str );
				}
			}
		}
	} while( k );
	return str;
}