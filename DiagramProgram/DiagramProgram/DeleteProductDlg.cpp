// DeleteProductDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "DeleteProductDlg.h"
#include "afxdialogex.h"


// CDeleteProductDlg �Ի���

IMPLEMENT_DYNAMIC(CDeleteProductDlg, CDialogEx)

CDeleteProductDlg::CDeleteProductDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DELETEPRODUCT, pParent)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
}

CDeleteProductDlg::~CDeleteProductDlg()
{
}

void CDeleteProductDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DELETEPRODUCTLC, m_productList);
}


BEGIN_MESSAGE_MAP(CDeleteProductDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_DELETEPRODUCTLC, &CDeleteProductDlg::OnLvnItemchangedDeleteproductlc)
END_MESSAGE_MAP()


// CDeleteProductDlg ��Ϣ�������


BOOL CDeleteProductDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	DWORD extStyle = m_productList.GetExtendedStyle();
	extStyle |= LVS_EX_FULLROWSELECT;
	extStyle |= LVS_EX_GRIDLINES;
	m_productList.SetExtendedStyle(extStyle);
	m_productList.InsertColumn(0, L"��Ʒ", LVCFMT_CENTER, 50);
	int i;
	for (i = 0; i < m_chart->m_product.size(); i++)
	{
		m_productList.InsertItem(i, m_chart->m_product[i]->GetName());
		m_productList.SetItemData(i, (DWORD_PTR)&m_chart->m_product[i]);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDeleteProductDlg::OnLvnItemchangedDeleteproductlc(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	selectId = pNMLV->iItem;

	*pResult = 0;
}
