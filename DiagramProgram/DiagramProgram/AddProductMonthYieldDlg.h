#pragma once
#include "afxcmn.h"
#include "Chart.h"
#include "MainFrm.h"
#include "afxwin.h"


// CAddProductMonthYieldDlg �Ի���

class CAddProductMonthYieldDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddProductMonthYieldDlg)

public:
	CAddProductMonthYieldDlg(int yield[], CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddProductMonthYieldDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDPRODUCTMONTHYIELD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_monthYield;
	int m_yield[100];
	CChart * m_chart;
	CEdit m_edit;
	int m_Row, m_Col;
	CString tem;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnKillfocusAddproductmonthyield();
	afx_msg void OnNMClickAddproductmonthyieldlc(NMHDR *pNMHDR, LRESULT *pResult);
};
