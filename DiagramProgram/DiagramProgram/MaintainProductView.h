#pragma once
#include "Chart.h"
#include "MainFrm.h"
#include "DeleteProductDlg.h"
#include "TipDlg.h"
#include "AddMonthDlg.h"
#include "ChangeProductDlg.h"
#include "ChangeProductInfoDlg.h"
#include "AddProductDlg.h"


// CMaintainProductView 窗体视图

class CMaintainProductView : public CFormView
{
	DECLARE_DYNCREATE(CMaintainProductView)

protected:
	CMaintainProductView();           // 动态创建所使用的受保护的构造函数
	virtual ~CMaintainProductView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAINTAINPRODUCT };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	CChart * m_chart;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDeleteproduct();
	afx_msg void OnBnClickedAddmonth();
	afx_msg void OnBnClickedAddproduct();
	afx_msg void OnBnClickedChangeproduct();
};


