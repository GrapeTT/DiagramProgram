// ChangeProductInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "ChangeProductInfoDlg.h"
#include "afxdialogex.h"


// CChangeProductInfoDlg 对话框

IMPLEMENT_DYNAMIC(CChangeProductInfoDlg, CDialogEx)

CChangeProductInfoDlg::CChangeProductInfoDlg(int n, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHANGEPRODUCTINFO, pParent)
{
	this->n = n;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
	m_productName = m_chart->m_product[n]->GetName();
	m_shape = m_chart->m_product[n]->GetShape();
	m_color = m_chart->m_product[n]->GetColor();
	int i;
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		m_yield[i] = m_chart->m_product[n]->m_monthYield[i].yield;
	}
}

CChangeProductInfoDlg::~CChangeProductInfoDlg()
{
}

void CChangeProductInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PRODUCTNAME, m_productName);
	DDX_Text(pDX, IDC_SHAPE, m_shape);
}


BEGIN_MESSAGE_MAP(CChangeProductInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_COLOR, &CChangeProductInfoDlg::OnBnClickedColor)
	ON_BN_CLICKED(IDC_MONTHYIELD, &CChangeProductInfoDlg::OnBnClickedMonthyield)
END_MESSAGE_MAP()


// CChangeProductInfoDlg 消息处理程序


void CChangeProductInfoDlg::OnBnClickedColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
		m_color = dlg.m_cc.rgbResult;
}


void CChangeProductInfoDlg::OnBnClickedMonthyield()
{
	CChangeMonthYieldDlg dlg(n);
	if (dlg.DoModal() == IDOK)
	{
		int i;
		for (i = 0; i < m_chart->m_monthNum; i++)
		{
			m_yield[i] = dlg.m_yield[i];
		}
	}
}
