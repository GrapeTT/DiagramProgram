#pragma once


// CChangeTitleDlg 对话框

class CChangeTitleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeTitleDlg)

public:
	CChangeTitleDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeTitleDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGETITLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_diagramTitle;
};
