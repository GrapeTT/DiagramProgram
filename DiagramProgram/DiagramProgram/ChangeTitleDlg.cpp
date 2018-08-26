// ChangeTitleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "ChangeTitleDlg.h"
#include "afxdialogex.h"


// CChangeTitleDlg 对话框

IMPLEMENT_DYNAMIC(CChangeTitleDlg, CDialogEx)

CChangeTitleDlg::CChangeTitleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHANGETITLE, pParent)
	, m_diagramTitle(_T(""))
{

}

CChangeTitleDlg::~CChangeTitleDlg()
{
}

void CChangeTitleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DIAGRAMTITLE, m_diagramTitle);
}


BEGIN_MESSAGE_MAP(CChangeTitleDlg, CDialogEx)
END_MESSAGE_MAP()


// CChangeTitleDlg 消息处理程序
