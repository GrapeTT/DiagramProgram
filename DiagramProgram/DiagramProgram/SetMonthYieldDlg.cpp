// SetMonthYieldDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "SetMonthYieldDlg.h"
#include "afxdialogex.h"


// CSetMonthYieldDlg 对话框

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


// CSetMonthYieldDlg 消息处理程序
BOOL CSetMonthYieldDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_edit.ShowWindow(SW_HIDE);
	DWORD extStyle = m_monthYield.GetExtendedStyle();
	extStyle |= LVS_EX_FULLROWSELECT;
	extStyle |= LVS_EX_GRIDLINES;
	m_monthYield.SetExtendedStyle(extStyle);
	m_monthYield.InsertColumn(0, L"产品", LVCFMT_CENTER, 50);
	int i;
	CString s;
	for (i = 0; i < m_chart->m_product.size(); i++)
	{
		s = m_chart->m_product[i]->GetName();
		m_monthYield.InsertColumn(i + 1, s, LVCFMT_CENTER, 80);
	}
	CString numstr;
	m_monthYield.InsertItem(0, L"月产量");
	for (i = 0; i < m_chart->m_product.size(); i++)
	{
		numstr.Format(L"%d", m_yield[i]);
		m_monthYield.SetItemText(0, i + 1, numstr);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CSetMonthYieldDlg::OnNMClickSetmonthyieldlc(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CRect rc;
	m_Row = pNMItemActivate->iItem;//获得选中的行  
	m_Col = pNMItemActivate->iSubItem;//获得选中列  

	if (pNMItemActivate->iSubItem != 0) //如果选择的是子项;  
	{
		m_monthYield.GetSubItemRect(m_Row, m_Col, LVIR_LABEL, rc);//获得子项的RECT；  
		m_edit.SetParent(&m_monthYield);//转换坐标为列表框中的坐标  
		m_edit.MoveWindow(rc);//移动Edit到RECT坐标的位置;  
		m_edit.SetWindowText(m_monthYield.GetItemText(m_Row, m_Col));//将该子项中的值放在Edit控件中；  
		m_edit.ShowWindow(SW_SHOW);//显示Edit控件；  
		m_edit.SetFocus();//设置Edit焦点  
		m_edit.ShowCaret();//显示光标  
		m_edit.SetSel(-1);//将光标移动到最后  
	}
	*pResult = 0;
}


void CSetMonthYieldDlg::OnEnKillfocusYield3()
{
	m_edit.GetWindowText(tem);    //得到用户输入的新的内容  
	int yield = _ttoi(tem);
	if (yield < 0)
		MessageBox(L"输入错误！请重新输入！");
	else
	{
		m_yield[m_Col - 1] = yield;
		m_monthYield.SetItemText(m_Row, m_Col, tem);   //设置编辑框的新内容  
	}
	m_edit.ShowWindow(SW_HIDE);  //隐藏编辑框
}
