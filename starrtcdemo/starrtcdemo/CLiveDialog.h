#pragma once

#include "CUserManager.h"
#include "CReceiveDataCallback.h"
#include "CLiveVideoInterface.h"
// CLiveDialog 对话框

enum SHOW_TYPE
{
	SHOW_TYPE_CENTER = 0
};

class CLiveDialog : public CDialogEx, public CReceiveDataCallback
{
	DECLARE_DYNAMIC(CLiveDialog)

public:
	CLiveDialog(CUserManager* pUserManager,CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLiveDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOW_LIVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	void showBitmap(HBITMAP hBitmap);
	void ImageDataToHBITMAP(char* pData, HBITMAP *m_pHbitmap);
	void revData(int upid, int w, int h, uint8_t* videoData, int videoDataLen);
	CLiveVideoInterface* m_pStartRtcLive;
	CStatic m_picControl;
	
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();

	int m_nShowWidth;
	int m_nShowHeight;
};
