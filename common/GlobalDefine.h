#ifndef __GlobalDefine_H__
#define __GlobalDefine_H__

#include <memory.h>

#pragma pack(push, 1)

// �ͻ����շ���Ϣ�����ֵ
#define NETWORK_MaxClientMsgLen	(4096)
// Gate����Ŀͻ������ӵĻ�������С
#define NETWORK_ClientMsgBufLen (NETWORK_MaxClientMsgLen * 100)
#define NETWORK_SessionTimeout	(2592000000)

#define GD_BIT(x)	(1 << x)

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