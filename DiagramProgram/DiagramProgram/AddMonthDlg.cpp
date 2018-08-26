// AddMonthDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "AddMonthDlg.h"
#include "afxdialogex.h"


// CAddMonthDlg 对话框

IMPLEMENT_DYNAMIC(CAddMonthDlg, CDialogEx)

CAddMonthDlg::CAddMonthDlg(int year, int month, int yield[], CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADDMONTH, pParent)
	, m_year(year)
	, m_month(month)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
	int i;
	for (i = 0; i < m_chart->m_product.size(); i++)
	{
		m_yield[i] = yield[i];
	}
}

CAddMonthDlg::~CAddMonthDlg()
{
}

void CAddMonthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADDYEAR, m_year);
	DDX_Text(pDX, IDC_ADDMONTH, m_month);
}


BEGIN_MESSAGE_MAP(CAddMonthDlg, CDialogEx)
	ON_BN_CLICKED(IDC_YIELD2, &CAddMonthDlg::OnBnClickedYield2)
END_MESSAGE_MAP()


// CAddMonthDlg 消息处理程序


void CAddMonthDlg::OnBnClickedYield2()
{
	CSetMonthYieldDlg dlg(m_yield);
	if (dlg.DoModal() == IDOK)
	{
		int i;
		for (i = 0; i < m_chart->m_product.size(); i++)
		{
			m_yield[i] = dlg.m_yield[i];
		}
	}
}
