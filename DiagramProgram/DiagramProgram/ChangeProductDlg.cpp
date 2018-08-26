// ChangeProductDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "ChangeProductDlg.h"
#include "afxdialogex.h"


// CChangeProductDlg 对话框

IMPLEMENT_DYNAMIC(CChangeProductDlg, CDialogEx)

CChangeProductDlg::CChangeProductDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHANGEPRODUCT, pParent)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
}

CChangeProductDlg::~CChangeProductDlg()
{
}

void CChangeProductDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHANGEPRODUCTLC, m_productList);
}


BEGIN_MESSAGE_MAP(CChangeProductDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_CHANGEPRODUCTLC, &CChangeProductDlg::OnLvnItemchangedChangeproductlc)
END_MESSAGE_MAP()


// CChangeProductDlg 消息处理程序


BOOL CChangeProductDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	DWORD extStyle = m_productList.GetExtendedStyle();
	extStyle |= LVS_EX_FULLROWSELECT;
	extStyle |= LVS_EX_GRIDLINES;
	m_productList.SetExtendedStyle(extStyle);
	m_productList.InsertColumn(0, L"产品", LVCFMT_CENTER, 50);
	int i;
	for (i = 0; i < m_chart->m_product.size(); i++)
	{
		m_productList.InsertItem(i, m_chart->m_product[i]->GetName());
		m_productList.SetItemData(i, (DWORD_PTR)&m_chart->m_product[i]);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CChangeProductDlg::OnLvnItemchangedChangeproductlc(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	selectId = pNMLV->iItem;
	
	*pResult = 0;
}
