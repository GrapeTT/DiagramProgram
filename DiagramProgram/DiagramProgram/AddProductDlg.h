#pragma once
#include "afxwin.h"
#include "Chart.h"
#include "MainFrm.h"
#include "AddProductMonthYieldDlg.h"

// CAddProductDlg 对话框

class CAddProductDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddProductDlg)

public:
	CAddProductDlg(CString name, int shape, COLORREF color, int yield[], CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddProductDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDPRODUCT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_productName;
	int m_shape;
	COLORREF m_color;
	CButton colorButton;
	CChart * m_chart;
	int m_yield[100];
	afx_msg void OnBnClickedAddcolor();
	afx_msg void OnBnClickedAddmonthyield();
};
