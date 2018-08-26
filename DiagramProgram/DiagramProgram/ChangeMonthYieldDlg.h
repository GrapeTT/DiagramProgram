#pragma once
#include "afxcmn.h"
#include "Chart.h"
#include "MainFrm.h"
#include "afxwin.h"


// CChangeMonthYieldDlg �Ի���

class CChangeMonthYieldDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeMonthYieldDlg)

public:
	CChangeMonthYieldDlg(int n, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeMonthYieldDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEMONTHYIELD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int n;//������ĸ���Ʒ
	CListCtrl m_monthYield;
	CChart * m_chart;
	CEdit m_edit;
	CString tem;
	int m_yield[100];
	int m_Row, m_Col;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickMonthyieldlc(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnKillfocusMonthyield();
};
