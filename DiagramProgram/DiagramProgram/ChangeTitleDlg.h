#pragma once


// CChangeTitleDlg �Ի���

class CChangeTitleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeTitleDlg)

public:
	CChangeTitleDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeTitleDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGETITLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_diagramTitle;
};
