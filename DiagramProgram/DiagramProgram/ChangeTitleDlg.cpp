// ChangeTitleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "ChangeTitleDlg.h"
#include "afxdialogex.h"


// CChangeTitleDlg �Ի���

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


// CChangeTitleDlg ��Ϣ�������
