#ifndef __Version_H__
#define __Version_H__

#define MAKE_VER(v1, v2, v3, v4)	(MAKELONG(MAKEWORD(v1, v2), MAKEWORD(v3, v4)))
#define VER_STR(v1, v2, v3, v4)		#v1 "." #v2 "." #v3 "." #v4;

#define BUILD_VER				MAKE_VER(1, 0, 6, 5)					// ��ǰ�汾��
#define MINI_VER				MAKE_VER(1, 0, 6, 5)					// ��Ͱ汾��
#define CLIENT_VER				1,0,6,5									// �ͻ�����ʾ�汾��
#define CLIENT_VER_STR			VER_STR(1, 0, 6, 5)						// �ͻ�����ʾ�汾��

const unsigned int CLIENT_VERSION				= BUILD_VER;			// ��ǰ�汾��
const unsigned int CLIENT_VERSION_ADMISSION		= MINI_VER;				// �����¼��С�汾��

const unsigned int SERVER_VERSION				= BUILD_VER;

static unsigned int GetSvrVersion()
{
	int nH = HIWORD(SERVER_VERSION);
	int nL = LOWORD(SERVER_VERSION);

	return HIBYTE(nH) + LOBYTE(nH)*10 + HIBYTE(nL)*100 + LOBYTE(nL)*1000;
}

#endif