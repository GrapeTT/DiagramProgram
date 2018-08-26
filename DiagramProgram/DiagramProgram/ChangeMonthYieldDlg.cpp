// ChangeNameAndYieldDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "ChangeMonthYieldDlg.h"
#include "afxdialogex.h"


// CChangeMonthYieldDlg �Ի���

IMPLEMENT_DYNAMIC(CChangeMonthYieldDlg, CDialogEx)

CChangeMonthYieldDlg::CChangeMonthYieldDlg(int n, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHANGEMONTHYIELD, pParent)
	, n(n)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
	int i;
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		m_yield[i] = m_chart->m_product[n]->m_monthYield[i].yield;
	}
}

CChangeMonthYieldDlg::~CChangeMonthYieldDlg()
{
}

void CChangeMonthYieldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MONTHYIELDLC, m_monthYield);
	DDX_Control(pDX, IDC_MONTHYIELD, m_edit);
}


BEGIN_MESSAGE_MAP(CChangeMonthYieldDlg, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_MONTHYIELDLC, &CChangeMonthYieldDlg::OnNMClickMonthyieldlc)
	ON_EN_KILLFOCUS(IDC_MONTHYIELD, &CChangeMonthYieldDlg::OnEnKillfocusMonthyield)
END_MESSAGE_MAP()


// CChangeMonthYieldDlg ��Ϣ�������


BOOL CChangeMonthYieldDlg::OnInitDialog()
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
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		s.Format(L"%d��%d��", m_chart->m_product[0]->m_monthYield[i].year, m_chart->m_product[0]->m_monthYield[i].month);
		m_monthYield.InsertColumn(i + 1, s, LVCFMT_CENTER, 80);
	}
	int num;
	CString numstr;
	m_monthYield.InsertItem(0, m_chart->m_product[n]->GetName());
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		num = m_chart->m_product[n]->m_monthYield[i].yield;
		numstr.Format(L"%d", num);
		m_monthYield.SetItemText(0, i + 1, numstr);
	}
	m_monthYield.SetItemData(0, (DWORD_PTR)&m_chart->m_product[n]);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void CChangeMonthYieldDlg::OnNMClickMonthyieldlc(NMHDR *pNMHDR, LRESULT *pResult)
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

void CChangeMonthYieldDlg::OnEnKillfocusMonthyield()
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
