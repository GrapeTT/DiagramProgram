#pragma once
#include "afxcmn.h"
#include "MainFrm.h"
#include "Chart.h"


// CDeleteProductDlg �Ի���

class CDeleteProductDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteProductDlg)

public:
	CDeleteProductDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteProductDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETEPRODUCT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_productList;
	CChart * m_chart;
	int selectId;//��¼ѡ�е�listcontrol���к�
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedDeleteproductlc(NMHDR *pNMHDR, LRESULT *pResult);
};
