// OTLDataBase.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "OTLDataBase.h"


// ���ǵ���������һ��ʾ��
OTLDATABASE_API int nOTLDataBase=0;

// ���ǵ���������һ��ʾ����
OTLDATABASE_API int fnOTLDataBase(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� OTLDataBase.h
COTLDataBase::COTLDataBase()
{
	return;
}
