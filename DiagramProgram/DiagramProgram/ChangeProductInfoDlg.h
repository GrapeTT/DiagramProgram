#pragma once
#include "afxwin.h"
#include "Chart.h"
#include "MainFrm.h"
#include "ChangeMonthYieldDlg.h"


// CChangeProductInfoDlg �Ի���

class CChangeProductInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeProductInfoDlg)

public:
	CChangeProductInfoDlg(int n, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeProductInfoDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEPRODUCTINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int n;//������ĸ���Ʒ
	CChart * m_chart;
	CString m_productName;
	int m_shape;
	int m_yield[100];
	COLORREF m_color;
	CButton colorButton;
	afx_msg void OnBnClickedColor();
	afx_msg void OnBnClickedMonthyield();
};
