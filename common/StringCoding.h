#pragma once

//GBK����ת����UTF8����
inline int GBKToUTF8(const char * lpGBKStr,char * lpUTF8Str,int nUTF8StrLen)
{
	//��ʱ���룬�������Ҫȥ��>>>>>>>>>>>>>>>>>
	assert(lpGBKStr && lpUTF8Str);
	if(!(lpGBKStr && lpUTF8Str))
	{
		return 0;
	}
	strcpy_s(lpUTF8Str, nUTF8StrLen, lpGBKStr);
	return (int)(strlen(lpGBKStr));
	//��ʱ���룬�������Ҫȥ��<<<<<<<<<<<<<<<<<<
	wchar_t * lpUnicodeStr = NULL;
	int nRetLen = 0;

	if(!lpGBKStr)  //���GBK�ַ���ΪNULL������˳�
		return 0;

	nRetLen = ::MultiByteToWideChar(CP_ACP,0,(char *)lpGBKStr,-1,NULL,NULL);  //��ȡת����Unicode���������Ҫ���ַ��ռ䳤��
	lpUnicodeStr = new WCHAR[nRetLen + 1];  //ΪUnicode�ַ����ռ�
	nRetLen = ::MultiByteToWideChar(CP_ACP,0,(char *)lpGBKStr,-1,lpUnicodeStr,nRetLen);  //ת����Unicode����
	if(!nRetLen)  //ת��ʧ��������˳�
		return 0;

	nRetLen = ::WideCharToMultiByte(CP_UTF8,0,lpUnicodeStr,-1,NULL,0,NULL,NULL);  //��ȡת����UTF8���������Ҫ���ַ��ռ䳤��

	if(!lpUTF8Str)  //���������Ϊ���򷵻�ת������Ҫ�Ŀռ��С
	{
		if(lpUnicodeStr)
			delete []lpUnicodeStr;
		return nRetLen;
	}

	if(nUTF8StrLen < nRetLen)  //���������������Ȳ������˳�
	{
		if(lpUnicodeStr)
			delete []lpUnicodeStr;
		return 0;
	}

	nRetLen = ::WideCharToMultiByte(CP_UTF8,0,lpUnicodeStr,-1,(char *)lpUTF8Str,nUTF8StrLen,NULL,NULL);  //ת����UTF8����
	if(lpUnicodeStr)
		delete []lpUnicodeStr;

	return nRetLen;
}

// UTF8����ת����GBK����
inline int UTF8ToGBK(const char * lpUTF8Str,char * lpGBKStr,int nGBKStrLen)
{
	//��ʱ���룬�������Ҫȥ��>>>>>>>>>>>>>>>>>
	assert(lpGBKStr && lpUTF8Str);
	if(!(lpGBKStr && lpUTF8Str))
	{
		return 0;
	}
	strcpy_s(lpGBKStr, nGBKStrLen, lpUTF8Str);
	return (int)strlen(lpUTF8Str);
	//��ʱ���룬�������Ҫȥ��<<<<<<<<<<<<<<<<<<
	wchar_t * lpUnicodeStr = NULL;
	int nRetLen = 0;

	if(!lpUTF8Str)  //���UTF8�ַ���ΪNULL������˳�
		return 0;

	nRetLen = ::MultiByteToWideChar(CP_UTF8,0,(char *)lpUTF8Str,-1,NULL,NULL);  //��ȡת����Unicode���������Ҫ���ַ��ռ䳤��
	lpUnicodeStr = new WCHAR[nRetLen + 1];  //ΪUnicode�ַ����ռ�
	nRetLen = ::MultiByteToWideChar(CP_UTF8,0,(char *)lpUTF8Str,-1,lpUnicodeStr,nRetLen);  //ת����Unicode����
	if(!nRetLen)  //ת��ʧ��������˳�
		return 0;

	nRetLen = ::WideCharToMultiByte(CP_ACP,0,lpUnicodeStr,-1,NULL,NULL,NULL,NULL);  //��ȡת����GBK���������Ҫ���ַ��ռ䳤��

	if(!lpGBKStr)  //���������Ϊ���򷵻�ת������Ҫ�Ŀռ��С
	{
		if(lpUnicodeStr)
			delete []lpUnicodeStr;
		return nRetLen;
	}

	if(nGBKStrLen < nRetLen)  //���������������Ȳ������˳�
	{
		if(lpUnicodeStr)
			delete []lpUnicodeStr;
		return 0;
	}

	nRetLen = ::WideCharToMultiByte(CP_ACP,0,lpUnicodeStr,-1,(char *)lpGBKStr,nRetLen,NULL,NULL);  //ת����GBK����

	if(lpUnicodeStr)
		delete []lpUnicodeStr;
	return nRetLen;
}
