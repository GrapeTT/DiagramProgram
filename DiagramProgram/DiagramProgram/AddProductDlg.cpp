// AddProductDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "AddProductDlg.h"
#include "afxdialogex.h"


// CAddProductDlg 对话框

IMPLEMENT_DYNAMIC(CAddProductDlg, CDialogEx)

CAddProductDlg::CAddProductDlg(CString name, int shape, COLORREF color, int yield[], CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADDPRODUCT, pParent)
	, m_productName(name)
	, m_shape(shape)
	, m_color(color)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
	int i;
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		m_yield[i] = yield[i];
	}
}

CAddProductDlg::~CAddProductDlg()
{
}

void CAddProductDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADDPRODUCTNAME, m_productName);
	DDX_Text(pDX, IDC_ADDSHAPE, m_shape);
}


BEGIN_MESSAGE_MAP(CAddProductDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADDCOLOR, &CAddProductDlg::OnBnClickedAddcolor)
	ON_BN_CLICKED(IDC_ADDMONTHYIELD, &CAddProductDlg::OnBnClickedAddmonthyield)
END_MESSAGE_MAP()


// CAddProductDlg 消息处理程序


void CAddProductDlg::OnBnClickedAddcolor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
		m_color = dlg.m_cc.rgbResult;
}


void CAddProductDlg::OnBnClickedAddmonthyield()
{
	CAddProductMonthYieldDlg dlg(m_yield);
	if (dlg.DoModal() == IDOK)
	{
		int i;
		for (i = 0; i < m_chart->m_monthNum; i++)
		{
			m_yield[i] = dlg.m_yield[i];
		}
	}
}
