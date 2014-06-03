#ifndef __GlobalDefine_H__
#define __GlobalDefine_H__

#include <memory.h>
#include <string>
#include <time.h>

#pragma pack(push, 1)

// ��ǰ�İ汾��
#define VERSION_CURRENT		(5)
// ��ǰ���������Խ��ܵ���С�ͻ��˰汾��
#define VERSION_COMPATIBLE	(5)

// �ͻ����շ���Ϣ�����ֵ
#define NETWORK_MaxClientMsgLen	(4096)
// Gate����Ŀͻ������ӵĻ�������С
#define NETWORK_ClientMsgBufLen (NETWORK_MaxClientMsgLen * 100)
#define NETWORK_SessionTimeout	(2592000000)

#define GD_BIT(x)	(1 << x)

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
#ifdef _WIN32
typedef unsigned __int64    UINT64, *PUINT64;
#else
typedef unsigned long long  UINT64, *PUINT64;
#endif
typedef signed int          LONG32, *PLONG32;
typedef unsigned int        ULONG32, *PULONG32;
typedef unsigned int        DWORD32, *PDWORD32;
typedef float               REAL32, *PREAL32;
typedef double              REAL64, *PREAL64;

#ifdef _WIN32
#ifndef VOID
#define VOID void
#endif
#else
typedef void				VOID;
#endif
#ifdef _WIN32
typedef void *				PVOID;
typedef void * __ptr64		PVOID64;
typedef	int					BOOL, *PBOOL;
typedef unsigned long       DWORD, *PDWORD;
#endif
typedef char				CHAR, *PCHAR;
typedef short				SHORT, *PSHORT;
typedef long				LONG, *PLONG;
typedef int					INT, *PINT;
typedef unsigned char       BYTE, *PBYTE;
typedef unsigned short      WORD, *PWORD;
typedef float               FLOAT, *PFLOAT;
typedef double				DOUBLE, *PDOUBLE;
typedef unsigned long		ULONG, *PULONG;
typedef unsigned short		USHORT, *PUSHORT;
typedef unsigned char		UCHAR, *PUCHAR;

enum eRC_LoginResult
{
	RC_LoginResult_Success,				// �ɹ�
	RC_LoginResult_ErrName,				// �û��������
	RC_LoginResult_AgainLogin,			// �ظ���¼
	RC_LoginResult_Disabled,			// �˺Ž���
	RC_LoginResult_NotActivation,		// �˺�û�м���
	RC_LoginResult_OldVersion,			// ��Ϣ�汾��
	RC_LoginResult_OtherError,			// �������⣬�����Ƿ�����û�������
	RC_LoginResult_KEEPLINK,			// �ȴ�������
	RC_LoginResult_SHORTLINK,			// �Ͽ�������
	RC_LoginResult_ISFULL,				// �Ͽ������Ӳ��������
	RC_LoginResult_IMMEDIATELY,			// ֪ͨ���еĵ�һ����ҽ���
};

enum eRC_CreateCharResult
{
	RC_CreateCharResult_Success,		// �����ɹ�
	RC_CreateCharResult_CharExist,		// ��ɫ�Ѵ���
	RC_CreateCharResult_NameExist,		// �����Ѵ���
	RC_CreateCharResult_NameError,		// ���ֲ��Ϸ�
	RC_CreateCharResult_OtherError,		// ��������
};

enum eRC_EnterGameResult
{
	RC_EnterGameResult_Success,			// �ɹ�����
	RC_EnterGameResult_NotExistChar,	// û�н�����ɫ
	RC_EnterGameResult_NotFindMap,		// û���ҵ��ý�ɫ���ڵĵ�ͼ��Ϣ
	RC_EnterGameResult_NotFindScene,	// û���ҵ���ͼ���ڵķ�����
	RC_EnterGameResult_WorldFull,	    // ��������������,���Ժ�����
	RC_EnterGameResult_Unknown,			// δ֪ԭ�򣬷�����ڲ�����
};

#pragma pack(pop)

#endif