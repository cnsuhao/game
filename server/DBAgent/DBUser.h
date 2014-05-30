#ifndef __DBUser_H__
#define __DBUser_H__

struct eITEM_INFO
{
	GD_PlayerItem eBaseInfo;
	GD_ItemInfo eExtInfo;
	BOOL bDelete;			//��¼��Ʒ�Ƿ���Ҫɾ����Ĭ��ΪTRUE��Ҫɾ��������Ҫɾ����������ΪFALSE
	BOOL bNeedUpdate;		//�Ƿ���Ҫ�����û�����, Ĭ��FALSE����Ҫ���£� ��Ҫ���µ�����ΪTRUE
	eITEM_INFO()
	{
		memset(this, 0, sizeof(*this));
	}
};
typedef std::map<Sg_UInt32, eITEM_INFO*> MAP_ITEM_INFO;
typedef std::vector<GD_AttackLog> VEC_ATTACK_INFO;

class CDBUser
{
public:
	CDBUser();
	~CDBUser();

	SG_DF_PROPERTY(Sg_UInt32, AccountID);	// �ʺ�ID
	SG_DF_PROPERTY(Sg_UInt8, SceneSvrID);
	SG_DF_PROPERTY(Sg_UInt8, WorldSvrID);

	// DB ���ݻ���
public:
	void Release();
	void ResetItemInfoMap();
	GD_BaseCharInfo	m_CharInfo;

	Sg_UInt8		m_nFriendAmount;
	GD_FriendData	m_FriendData[FRIEND_MAXAMOUNT];

	std::vector<GD_MailInfo> m_MailInfoVec;//������Ϣ
public:
	MAP_ITEM_INFO* GetItemInfoset();
	VEC_ATTACK_INFO* GetAttackInfoVec();

private:
	MAP_ITEM_INFO m_mapItemInfoset;
	VEC_ATTACK_INFO m_vecAttackInfo;
};

#endif