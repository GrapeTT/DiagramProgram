#pragma once
#include "afxcmn.h"
#include "Chart.h"
#include "MainFrm.h"


// CChangeProductDlg �Ի���

class CChangeProductDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeProductDlg)

public:
	CChangeProductDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeProductDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEPRODUCT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_productList;
	CChart * m_chart;
	int selectId;//��¼ѡ�е�listcontrol���к�
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedChangeproductlc(NMHDR *pNMHDR, LRESULT *pResult);
};
