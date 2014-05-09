#ifndef __CommonDefs_H__
#define __CommonDefs_H__

#include <string.h>
#include <assert.h>

#if defined(_WIN32)

#pragma warning(disable: 4996)

#ifndef COMMON_INCLUDE

#if defined(COMMON_EXPORTS)

#define COMMON_API __declspec(dllexport)
#define COMMON_CAPI extern "C" __declspec(dllexport)

#else

#define COMMON_API __declspec(dllimport)
#define COMMON_CAPI extern "C" __declspec(dllimport)

#endif

#else

#define COMMON_API
#define COMMON_CAPI

#endif

#else

#define COMMON_API
#define COMMON_CAPI

#endif

#define BEGINNAMESPACE	namespace Common {
#define ENDNAMESPACE	};

typedef signed char         INT8, *PINT8;
typedef signed short        INT16, *PINT16;
typedef signed int          INT32, *PINT32;
#ifdef _WIN32
typedef signed __int64      INT64, *PINT64;
#else
typedef signed long long    INT64, *PINT64;
#endif
typedef unsigned char       UINT8, *PUINT8;
typedef unsigned short      UINT16, *PUINT16;
typedef unsigned int        UINT32, *PUINT32;
#ifndef _WIN32
typedef unsigned __int64    UINT64, *PUINT64;
#else
typedef unsigned long long  UINT64, *PUINT64;
#endif
typedef signed int          LONG32, *PLONG32;
typedef unsigned int        ULONG32, *PULONG32;
typedef unsigned int        DWORD32, *PDWORD32;
typedef float               REAL32, *PREAL32;
typedef double              REAL64, *PREAL64;


BEGINNAMESPACE

class IRegisterHelper
{
public:
	virtual	void*	New() = 0;
	virtual	void	Free(void*) = 0;
};

template<class T>
class CRegisterHelper : public IRegisterHelper
{
public:
	void* New()
	{
		return new T;
	}

	void	Free(void* ptr)
	{
		delete((T*)ptr);
	}
};

template < class T, int nSize = 1024 >
class CRegisterMgr
{
public:
	CRegisterMgr()
	{
		for (int i = 0; i < nSize; i++)
		{
			m_pHelper[i] = NULL;
		}
	}

	~CRegisterMgr()
	{

	}

	void Register(int nID, IRegisterHelper* pHelper)
	{
		if (nID >= nSize
			|| m_pHelper[nID] != NULL)
		{
			return;
		}

		m_pHelper[nID] = pHelper;
	}

	T*	Alloc(int nID)
	{
		if (nID >= nSize
			|| m_pHelper[nID] == NULL)
		{
			return NULL;
		}

		return	(T*)(m_pHelper[nID]->New());
	}

	void		Free(T* ptr)
	{
		delete ptr;
	}

private:
	IRegisterHelper*	m_pHelper[nSize];
};

inline char* SafeStringCopy(char* strDst, const char* strSrc, int nSize)
{
#ifdef _WIN32
	strncpy_s(strDst, nSize, strSrc, nSize - 1);
#else
	strncpy(strDst, strSrc, nSize - 1);
#endif
	strDst[nSize - 1] = '\0';

	return strDst;
}

inline UINT64 MakeUInt64(UINT32 nHigh, UINT32 nLower)
{
	return ((((UINT64)(nHigh)) << 32) | ((UINT64)(nLower)));
}

inline UINT32 MakeUInt32(UINT16 nHigh, UINT16 nLower)
{
	return ((((UINT32)(nHigh)) << 16) | ((UINT32)(nLower)));
}

inline UINT32 GetHighUInt32(UINT64 nGuid)
{
	return static_cast<UINT32>(nGuid >> 32);
}

inline UINT32 GetLowerUInt32(UINT64 nGuid)
{
	return static_cast<UINT32>(nGuid & 0xffffffff);
}

inline UINT16 GetHighUInt16(UINT32 nGuid)
{
	return static_cast<UINT16>(nGuid >> 16);
}

inline UINT16 GetLowerUInt16(UINT32 nGuid)
{
	return static_cast<UINT16>(nGuid & 0xffff);
}


inline UINT32 MakeUInt16(UINT8 nHigh, UINT8 nLower)
{
	return ((((UINT32)(nHigh)) << 8) | ((UINT32)(nLower)));
}

inline UINT8 GetHighUInt8(UINT16 nGuid)
{
	return (nGuid >> 8);
}

inline UINT8 GetLowerUInt8(UINT16 nGuid)
{
	return (nGuid & 0xff);
}

ENDNAMESPACE

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

#endif