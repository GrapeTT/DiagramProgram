#pragma once
#include "Chart.h"
#include "MainFrm.h"
#include "SetMonthYieldDlg.h"


// CAddMonthDlg �Ի���

class CAddMonthDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddMonthDlg)

public:
	CAddMonthDlg(int year, int month, int yield[], CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddMonthDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDMONTH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_year;
	int m_month;
	int m_yield[100];
	CChart * m_chart;
	afx_msg void OnBnClickedYield2();
};
