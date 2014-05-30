/*

Remarks:

Issuing SetUnhandledExceptionFilter replaces the existing top-level exception filter for all existing and all future threads in the calling process.

The exception handler specified by lpTopLevelExceptionFilter is executed in the context of the thread that caused the fault. This can affect the exception handler's ability to recover from certain exceptions, such as an invalid stack.

Requirements:

Client: Included in Windows XP, Windows 2000 Professional, Windows NT Workstation 3.5 and later, Windows Me, Windows 98, and Windows 95.
Server: Included in Windows Server 2003, Windows 2000 Server, and Windows NT Server 3.5 and later.
Header: Declared in Winbase.h; include Windows.h.
Library: Use Kernel32.lib.

�޷���һ���������ڵ��Դ�ģ�鹦�ܣ���Ϊ�쳣������������VCZ�������ˡ�

*/

#pragma once

#include "dbghelp.h"

class MiniDumper
{
private:
	static LPCSTR m_szAppName;

	static LONG WINAPI TopLevelFilter(struct _EXCEPTION_POINTERS *pExceptionInfo);

	static char	m_szCmdLinePrefix[MAX_PATH];		// �쳣������ִ�е�������
	static char	m_szExeNameToReboot[MAX_PATH];	// �쳣������������������ִ�еĳ����ļ���

public:
	// ȱʡ��ʽ��ֻ���� Dump �ļ�������
	// �������Ի���֪ͨ
	MiniDumper(LPCSTR DumpFileNamePrefix);

	// BugReport��ʽ�������ļ���ִ�� CmdLine
	// �����������ʹ��󱨸��

	// Param List:	
	//		DumpFileNamePrefix		������Dump�ļ����ļ���ǰ׺
	//		CmdLine					����Dump֮��ִ�е�WinExec��������ʽΪ��"Bugreport.exe + �ո� + ������������, + �˿ڲ���, +·������"
	//		ExeNameToReboot			���Dump����������Crash���ĳ�����ļ�����Ŀǰֻ���BugReporter.exe��
	MiniDumper(LPCSTR DumpFileNamePrefix, LPCSTR CmdLine, LPCSTR ExeNameToReboot = NULL);
};