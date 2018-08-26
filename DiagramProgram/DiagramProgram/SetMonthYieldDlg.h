#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Chart.h"
#include "MainFrm.h"


// CSetMonthYieldDlg �Ի���

class CSetMonthYieldDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetMonthYieldDlg)

public:
	CSetMonthYieldDlg(int yield[], CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetMonthYieldDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETMONTHYIELD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_monthYield;
	int m_yield[100];
	CEdit m_edit;
	int m_Row, m_Col;
	CChart * m_chart;
	CString tem;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickSetmonthyieldlc(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnKillfocusYield3();
};
