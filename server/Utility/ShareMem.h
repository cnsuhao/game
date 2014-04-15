#ifndef __ShareMem_H__
#define __ShareMem_H__
#include "CommonDefs.h"
#ifdef _WIN32
#include <Windows.h>
#endif
namespace ShareMem
{
typedef	unsigned long	SM_KEY;
#ifdef _WIN32
typedef	HANDLE	SMHandle;
#define INVALID_SM_HANDLE	 (HANDLE)(-1)
#else
typedef	int	SMHandle;
#define INVALID_SM_HANDLE	 (0)
#endif
	/*����ShareMem �ڴ���
	*
	*	key   ����ShareMem �Ĺؼ�ֵ
	*
	*   Size  ������С
	*
	*	���� ��ӦShareMem����ֵ
	*/
	COMMON_API SMHandle		CreateShareMem(SM_KEY key, unsigned int Size);
	/*��ShareMem �ڴ���
	*
	* key   ��ShareMem �Ĺؼ�ֵ
	*
	* Size  �򿪴�С
	*
	* ����  ��ӦShareMem ����ֵ
	*/
	COMMON_API SMHandle		OpenShareMem(SM_KEY key, unsigned int Size);

	/*ӳ��ShareMem �ڴ���
	*
	*	handle ӳ��ShareMem �ı���ֵ
	*
	*   ���� ShareMem ������ָ��
	*/
	COMMON_API char*			MapShareMem(SMHandle handle);

	/*�ر�ӳ�� ShareMem �ڴ���
	*
	*	MemoryPtr			ShareMem ������ָ��
	*
	*
	*/
	COMMON_API void 		UnMapShareMem(char* MemoryPtr);

	/*	�ر�ShareMem
	* 	handle  ��Ҫ�رյ�ShareMem ����ֵ
	*/
	COMMON_API void 		CloseShareMem(SMHandle handle);
}
#endif