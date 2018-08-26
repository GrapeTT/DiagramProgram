// ChangeNameAndYieldDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "ChangeMonthYieldDlg.h"
#include "afxdialogex.h"


// CChangeMonthYieldDlg 对话框

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


// CChangeMonthYieldDlg 消息处理程序


BOOL CChangeMonthYieldDlg::OnInitDialog()
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
	for (i = 0; i < m_chart->m_monthNum; i++)
	{
		s.Format(L"%d年%d月", m_chart->m_product[0]->m_monthYield[i].year, m_chart->m_product[0]->m_monthYield[i].month);
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
				  // 异常: OCX 属性页应返回 FALSE
}

void CChangeMonthYieldDlg::OnNMClickMonthyieldlc(NMHDR *pNMHDR, LRESULT *pResult)
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

void CChangeMonthYieldDlg::OnEnKillfocusMonthyield()
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
