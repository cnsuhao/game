#ifndef __NetMsgID_H__
#define __NetMsgID_H__

const int	BaseMsgID_ClientToLogin = 0;
const int	BaseMsgID_LoginToClient = 200;
const int	BaseMsgID_ClientToGate = 400;
const int	BaseMsgID_GateToClient = 800;

#pragma pack(push, 1)

//=====================================================================================
// Client To Login
//=====================================================================================
enum
{
	eMsg_Login_CL = BaseMsgID_ClientToLogin,	// �û������½
	eMsg_QueryCharInfo_CL,						// �����ɫ��Ϣ
	eMsg_CreateChar_CL,							// ������ɫ
	eMsg_DeleteChar_CL,							// ɾ����ɫ
	eMsg_EnterGame_CL,							// ������Ϸ����
	eMsg_BackToLogin_CL,						// ���ص�½����
	eMsg_LoginInfo_CL,							// ��¼�����+����MD5��Ϣ
	eMsg_QueueLogin_LC,							// �Ŷ�ϵͳ��Ϣ
};
//=====================================================================================
// Login To Client
//=====================================================================================
enum
{
	eMsg_LoginResult_LC = BaseMsgID_LoginToClient,	// �û���½���
	eMsg_QueryCharInfo_LC,							// ��ѯ���Ľ�ɫ��Ϣ
	eMsg_GateLinkInfo_LC,
	eMsg_SceneMapInfo_LC,
	eMsg_GameTime_LC,
	eMsg_MessageVer_LC,
	eMsg_CreateCharResult_LC,						// ������ɫ�Ľ��
	eMsg_DeleteCharResult_LC,						// ɾ����ɫ�Ľ��
	eMsg_EnterGameResult_LC,						// ������Ϸ����Ľ��
	eMsg_BackToLoginResult_LC,						// ���ص�½������
	eMsg_SocketDisconnect_LC,
	eMsg_LoginInfo_LC,								// ��¼�������Ϣ
	eMsg_SvrLocalTime_LC,							// ��Ϸ����������ʱ����Ϣ
};
//=====================================================================================
// Client To Gate
//=====================================================================================
enum
{
	eMsg_ClientLogin_CG = BaseMsgID_ClientToGate,
	eMsg_Logout_CG,									// �˳���Ϣ
};
//=====================================================================================
// Gate To Client
//=====================================================================================
enum
{
	eMsg_ClientLoadSuccess_GC = BaseMsgID_GateToClient,

	eMsg_MaxCount,
};
#pragma pack(pop)
#endif