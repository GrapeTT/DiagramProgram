// AddProductMonthYieldDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "AddProductMonthYieldDlg.h"
#include "afxdialogex.h"


// CAddProductMonthYieldDlg �Ի���

IMPLEMENT_DYNAMIC(CAddProductMonthYieldDlg, CDialogEx)

CAddProductMonthYieldDlg::CAddProductMonthYieldDlg(int yield[], CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADDPRODUCTMONTHYIELD, pParent)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
	int i;
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		m_yield[i] = yield[i];
	}
}

CAddProductMonthYieldDlg::~CAddProductMonthYieldDlg()
{
}

void CAddProductMonthYieldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADDPRODUCTMONTHYIELDLC, m_monthYield);
	DDX_Control(pDX, IDC_YIELD1, m_edit);
}


BEGIN_MESSAGE_MAP(CAddProductMonthYieldDlg, CDialogEx)
	ON_EN_KILLFOCUS(IDC_YIELD1, &CAddProductMonthYieldDlg::OnEnKillfocusAddproductmonthyield)
	ON_NOTIFY(NM_CLICK, IDC_ADDPRODUCTMONTHYIELDLC, &CAddProductMonthYieldDlg::OnNMClickAddproductmonthyieldlc)
END_MESSAGE_MAP()


// CAddProductMonthYieldDlg ��Ϣ�������


BOOL CAddProductMonthYieldDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_edit.ShowWindow(SW_HIDE);
	DWORD extStyle = m_monthYield.GetExtendedStyle();
	extStyle |= LVS_EX_FULLROWSELECT;
	extStyle |= LVS_EX_GRIDLINES;
	m_monthYield.SetExtendedStyle(extStyle);
	m_monthYield.InsertColumn(0, L"�·�", LVCFMT_CENTER, 50);
	int i;
	CString s;
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		s.Format(L"%d��%d��", m_chart->m_product[0]->m_monthYield[i].year, m_chart->m_product[0]->m_monthYield[i].month);
		m_monthYield.InsertColumn(i + 1, s, LVCFMT_CENTER, 80);
	}
	CString numstr;
	m_monthYield.InsertItem(0, L"�²���");
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		numstr.Format(L"%d", m_yield[i]);
		m_monthYield.SetItemText(0, i + 1, numstr);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CAddProductMonthYieldDlg::OnEnKillfocusAddproductmonthyield()
{
	m_edit.GetWindowText(tem);    //�õ��û�������µ�����  
	int yield = _ttoi(tem);
	if (yield < 0)
		MessageBox(L"����������������룡");
	else
	{
		m_yield[m_Col - 1] = yield;
		m_monthYield.SetItemText(m_Row, m_Col, tem);   //���ñ༭���������  
	}
	m_edit.ShowWindow(SW_HIDE);  //���ر༭��
}


void CAddProductMonthYieldDlg::OnNMClickAddproductmonthyieldlc(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CRect rc;
	m_Row = pNMItemActivate->iItem;//���ѡ�е���  
	m_Col = pNMItemActivate->iSubItem;//���ѡ����  

	if (pNMItemActivate->iSubItem != 0) //���ѡ���������;  
	{
		m_monthYield.GetSubItemRect(m_Row, m_Col, LVIR_LABEL, rc);//��������RECT��  
		m_edit.SetParent(&m_monthYield);//ת������Ϊ�б���е�����  
		m_edit.MoveWindow(rc);//�ƶ�Edit��RECT�����λ��;  
		m_edit.SetWindowText(m_monthYield.GetItemText(m_Row, m_Col));//���������е�ֵ����Edit�ؼ��У�  
		m_edit.ShowWindow(SW_SHOW);//��ʾEdit�ؼ���  
		m_edit.SetFocus();//����Edit����  
		m_edit.ShowCaret();//��ʾ���  
		m_edit.SetSel(-1);//������ƶ������  
	}
	*pResult = 0;
}
