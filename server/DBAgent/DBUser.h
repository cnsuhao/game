#ifndef __DBUser_H__
#define __DBUser_H__


class CDBUser
{
public:
	CDBUser();
	~CDBUser();

	DF_PROPERTY(UINT32, AccountID);	// �ʺ�ID
	DF_PROPERTY(UINT8, SceneSvrID);
	DF_PROPERTY(UINT8, WorldSvrID);

	// DB ���ݻ���
public:
	void Release();
public:

private:
};

#endif