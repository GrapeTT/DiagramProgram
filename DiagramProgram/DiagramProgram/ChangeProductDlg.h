#pragma once
#include "afxcmn.h"
#include "Chart.h"
#include "MainFrm.h"


// CChangeProductDlg 对话框

class CChangeProductDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeProductDlg)

public:
	CChangeProductDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeProductDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEPRODUCT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_productList;
	CChart * m_chart;
	int selectId;//记录选中的listcontrol的行号
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedChangeproductlc(NMHDR *pNMHDR, LRESULT *pResult);
};
