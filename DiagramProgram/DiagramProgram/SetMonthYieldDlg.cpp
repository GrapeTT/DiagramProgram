// SetMonthYieldDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "SetMonthYieldDlg.h"
#include "afxdialogex.h"


// CSetMonthYieldDlg �Ի���

IMPLEMENT_DYNAMIC(CSetMonthYieldDlg, CDialogEx)

CSetMonthYieldDlg::CSetMonthYieldDlg(int yield[], CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SETMONTHYIELD, pParent)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
	int i;
	for (i = 0; i < m_chart->m_product.size(); i++)
	{
		m_yield[i] = yield[i];
	}
}

CSetMonthYieldDlg::~CSetMonthYieldDlg()
{
}

void CSetMonthYieldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SETMONTHYIELDLC, m_monthYield);
	DDX_Control(pDX, IDC_YIELD3, m_edit);
}


BEGIN_MESSAGE_MAP(CSetMonthYieldDlg, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_SETMONTHYIELDLC, &CSetMonthYieldDlg::OnNMClickSetmonthyieldlc)
	ON_EN_KILLFOCUS(IDC_YIELD3, &CSetMonthYieldDlg::OnEnKillfocusYield3)
END_MESSAGE_MAP()


// CSetMonthYieldDlg ��Ϣ�������
BOOL CSetMonthYieldDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_edit.ShowWindow(SW_HIDE);
	DWORD extStyle = m_monthYield.GetExtendedStyle();
	extStyle |= LVS_EX_FULLROWSELECT;
	extStyle |= LVS_EX_GRIDLINES;
	m_monthYield.SetExtendedStyle(extStyle);
	m_monthYield.InsertColumn(0, L"��Ʒ", LVCFMT_CENTER, 50);
	int i;
	CString s;
	for (i = 0; i < m_chart->m_product.size(); i++)
	{
		s = m_chart->m_product[i]->GetName();
		m_monthYield.InsertColumn(i + 1, s, LVCFMT_CENTER, 80);
	}
	CString numstr;
	m_monthYield.InsertItem(0, L"�²���");
	for (i = 0; i < m_chart->m_product.size(); i++)
	{
		numstr.Format(L"%d", m_yield[i]);
		m_monthYield.SetItemText(0, i + 1, numstr);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void CSetMonthYieldDlg::OnNMClickSetmonthyieldlc(NMHDR *pNMHDR, LRESULT *pResult)
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


void CSetMonthYieldDlg::OnEnKillfocusYield3()
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
