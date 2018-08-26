#pragma once
#include "Chart.h"
#include "MainFrm.h"
#include "SetMonthYieldDlg.h"


// CAddMonthDlg 对话框

class CAddMonthDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddMonthDlg)

public:
	CAddMonthDlg(int year, int month, int yield[], CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddMonthDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDMONTH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_year;
	int m_month;
	int m_yield[100];
	CChart * m_chart;
	afx_msg void OnBnClickedYield2();
};
