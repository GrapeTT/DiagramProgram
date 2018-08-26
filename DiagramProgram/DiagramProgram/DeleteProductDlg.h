#pragma once
#include "afxcmn.h"
#include "MainFrm.h"
#include "Chart.h"


// CDeleteProductDlg 对话框

class CDeleteProductDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteProductDlg)

public:
	CDeleteProductDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleteProductDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETEPRODUCT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_productList;
	CChart * m_chart;
	int selectId;//记录选中的listcontrol的行号
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedDeleteproductlc(NMHDR *pNMHDR, LRESULT *pResult);
};
