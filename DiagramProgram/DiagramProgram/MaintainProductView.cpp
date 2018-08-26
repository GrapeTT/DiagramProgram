// MaintainProductView.cpp : 实现文件
//

#include "stdafx.h"
#include "DiagramProgram.h"
#include "MaintainProductView.h"


// CMaintainProductView

IMPLEMENT_DYNCREATE(CMaintainProductView, CFormView)

CMaintainProductView::CMaintainProductView()
	: CFormView(IDD_MAINTAINPRODUCT)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	m_chart = pFrame->m_chart;
}

CMaintainProductView::~CMaintainProductView()
{
}

void CMaintainProductView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMaintainProductView, CFormView)
	ON_BN_CLICKED(IDC_DELETEPRODUCT, &CMaintainProductView::OnBnClickedDeleteproduct)
	ON_BN_CLICKED(IDC_ADDMONTH, &CMaintainProductView::OnBnClickedAddmonth)
	ON_BN_CLICKED(IDC_ADDPRODUCT, &CMaintainProductView::OnBnClickedAddproduct)
	ON_BN_CLICKED(IDC_CHANGEPRODUCT, &CMaintainProductView::OnBnClickedChangeproduct)
END_MESSAGE_MAP()


// CMaintainProductView 诊断

#ifdef _DEBUG
void CMaintainProductView::AssertValid() const
{
	CFormView::AssertValid();
	
}

#ifndef _WIN32_WCE
void CMaintainProductView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMaintainProductView 消息处理程序


void CMaintainProductView::OnBnClickedDeleteproduct()
{
	CDeleteProductDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		while (true)
		{
			CTipDlg tipDlg;
			if (tipDlg.DoModal() == IDOK)
			{
				CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
				pFrame->m_wndOutput.m_operationRecord[pFrame->m_wndOutput.m_operationRecordNum++] = L"删除了产品：" + m_chart->m_product[dlg.selectId]->GetName();
				m_chart->m_product.erase(m_chart->m_product.begin() + dlg.selectId, m_chart->m_product.begin() + dlg.selectId + 1);
				pFrame->m_wndOutput.FillOperationRecordWindow();
				CDocument *pDoc = GetDocument();
				POSITION pos = pDoc->GetFirstViewPosition();
				while (pos != NULL)
				{
					CView *pView = pDoc->GetNextView(pos);
					pView->OnInitialUpdate();
				}
				break;
			}
			else
			{
				CDeleteProductDlg dlg1;
				if (dlg1.DoModal() != IDOK)
					break;
				dlg.selectId = dlg1.selectId;
			}
		}
	}
}


void CMaintainProductView::OnBnClickedAddmonth()
{
	int yield[100] = { 0 };
	int i;
	CAddMonthDlg dlg(1, 1, yield);
	if (dlg.DoModal() == IDOK)
	{
		while (true)
		{
			if (dlg.m_year < 1 || dlg.m_month < 1 || dlg.m_month > 12)
				MessageBox(L"月份输入错误！请重新输入！");
			else
			{
				for (i = 0; i < m_chart->m_monthNum; i++)
				{
					if (dlg.m_year == m_chart->m_product[0]->m_monthYield[i].year && dlg.m_month == m_chart->m_product[0]->m_monthYield[i].month)
						break;
				}
				if (i != m_chart->m_monthNum)
					MessageBox(L"月份已存在！请重新输入！");
				else
				{
					m_chart->m_monthNum++;
					for (i = 0; i < m_chart->m_product.size(); i++)
					{
						m_chart->m_product[i]->AddMonthYield(m_chart->m_monthNum, dlg.m_year, dlg.m_month, dlg.m_yield[i]);
					}
					CString s1, s2;
					s1.Format(L"%d年", dlg.m_year);
					s2.Format(L"%d月", dlg.m_month);
					CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
					pFrame->m_wndOutput.m_operationRecord[pFrame->m_wndOutput.m_operationRecordNum++] = L"增加了月份：" + s1 + s2;
					pFrame->m_wndOutput.FillOperationRecordWindow();
					CDocument *pDoc = GetDocument();
					POSITION pos = pDoc->GetFirstViewPosition();
					while (pos != NULL)
					{
						CView *pView = pDoc->GetNextView(pos);
						pView->OnInitialUpdate();
					}
					break;
				}
			}
			CAddMonthDlg dlg1(dlg.m_year, dlg.m_month, dlg.m_yield);
			if (dlg1.DoModal() == IDOK)
			{
				dlg.m_year = dlg1.m_year;
				dlg.m_month = dlg1.m_month;
				for (i = 0; i < m_chart->m_product.size(); i++)
				{
					dlg.m_yield[i] = dlg1.m_yield[i];
				}
			}
			else
				break;
		}
	}
}


void CMaintainProductView::OnBnClickedAddproduct()
{
	if (m_chart->m_product.size() == 8)
	{
		MessageBox(L"产品数不能超过8个！无法增加！");
		return;
	}
	COLORREF color = NULL;
	int i;
	int yield[100];
	memset(yield, 0, 100);
	CAddProductDlg dlg(L"", 1, color, yield);
	if (dlg.DoModal() == IDOK)
	{
		while (true)
		{
			if (dlg.m_productName == "")
				MessageBox(L"产品名不能为空！请重新输入！");
			else
			{
				if (dlg.m_shape < 1 || dlg.m_shape > 5)
					MessageBox(L"曲线图例设置错误！请重新输入！");
				else
				{
					int year[100], month[100];
					for (i = 0; i < m_chart->m_monthNum; i++)
					{
						year[i] = m_chart->m_product[0]->m_monthYield[i].year;
						month[i] = m_chart->m_product[0]->m_monthYield[i].month;
					}
					m_chart->m_product.push_back(new CProduct(dlg.m_productName, m_chart->m_monthNum, year, month, dlg.m_yield, dlg.m_color, dlg.m_shape));
					CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
					pFrame->m_wndOutput.m_operationRecord[pFrame->m_wndOutput.m_operationRecordNum++] = L"增加了产品：" + dlg.m_productName;
					pFrame->m_wndOutput.FillOperationRecordWindow();
					CDocument *pDoc = GetDocument();
					POSITION pos = pDoc->GetFirstViewPosition();
					while (pos != NULL)
					{
						CView *pView = pDoc->GetNextView(pos);
						pView->OnInitialUpdate();
					}
					break;
				}
			}
			CAddProductDlg dlg1(dlg.m_productName, dlg.m_shape, dlg.m_color, dlg.m_yield);
			if (dlg1.DoModal() == IDOK)
			{
				dlg.m_productName = dlg1.m_productName;
				dlg.m_shape = dlg1.m_shape;
				dlg.m_color = dlg1.m_color;
				for (i = 0; i < m_chart->m_monthNum; i++)
				{
					dlg.m_yield[i] = dlg1.m_yield[i];
				}
			}
			else
				break;
		}
	}
}


void CMaintainProductView::OnBnClickedChangeproduct()
{
	while (true)
	{
		CChangeProductDlg dlg;
		if (dlg.DoModal() == IDOK)
		{
			CChangeProductInfoDlg dlg1(dlg.selectId);
			if (dlg1.DoModal() == IDOK)
			{
				int key = 1;
				int i;
				CString name;
				name = m_chart->m_product[dlg.selectId]->GetName();
				if (name == dlg1.m_productName && m_chart->m_product[dlg.selectId]->GetColor() == dlg1.m_color && m_chart->m_product[dlg.selectId]->GetShape() == dlg1.m_shape)
				{
					for (i = 0; i < m_chart->m_monthNum; i++)
					{
						if (m_chart->m_product[dlg.selectId]->m_monthYield[i].yield != dlg1.m_yield[i])
							break;
					}
					if (i == m_chart->m_monthNum)
					    key = 0;
				}
				if (key == 1)
				{
					CString change = L"修改了产品：" + dlg1.m_productName;
					if (name != dlg1.m_productName)
					{
						change = change + L"（原名：" + name + L"）";
						m_chart->m_product[dlg.selectId]->SetName(dlg1.m_productName);
					}
					if (m_chart->m_product[dlg.selectId]->GetShape() != dlg1.m_shape)
					{
						int shape1, shape2;
						shape1 = m_chart->m_product[dlg.selectId]->GetShape();
						change = change + L"    曲线图例：从";
						if (shape1 == 1)
							change += L"◇";
						else if (shape1 == 2)
							change += L"□";
						else if (shape1 == 3)
							change += L"△";
						else if (shape1 == 4)
							change += L"×";
						else
							change += L"○";
						shape2 = dlg1.m_shape;
						change += L"变为";
						if (shape2 == 1)
							change += L"◇";
						else if (shape2 == 2)
							change += L"□";
						else if (shape2 == 3)
							change += L"△";
						else if (shape2 == 4)
							change += L"×";
						else
							change += L"○";
						m_chart->m_product[dlg.selectId]->SetShape(dlg1.m_shape);
					}
					if (m_chart->m_product[dlg.selectId]->GetColor() != dlg1.m_color)
					{
						CString r1, r2, g1, g2, b1, b2;
						r1.Format(L"%d", GetRValue(m_chart->m_product[dlg.selectId]->GetColor()));
						r2.Format(L"%d", GetRValue(dlg1.m_color));
						g1.Format(L"%d", GetGValue(m_chart->m_product[dlg.selectId]->GetColor()));
						g2.Format(L"%d", GetGValue(dlg1.m_color));
						b1.Format(L"%d", GetBValue(m_chart->m_product[dlg.selectId]->GetColor()));
						b2.Format(L"%d", GetBValue(dlg1.m_color));
						change = change + L"    曲线颜色：从RGB（" + r1 + L"，" + g1 + L"，" + b1 + L"）变为RGB（" + r2 + L"，" + g2 + L"，" + b2 + L"）";
						m_chart->m_product[dlg.selectId]->SetColor(dlg1.m_color);
					}
					for (i = 0; i < m_chart->m_monthNum; i++)
					{
						if (m_chart->m_product[dlg.selectId]->m_monthYield[i].yield != dlg1.m_yield[i])
							break;
					}
					if (i != m_chart->m_monthNum)
					{
						change = change + L"    月产量：从（";
						CString yield;
						for (i = 0; i < m_chart->m_monthNum; i++)
						{
							yield.Format(L"%d", m_chart->m_product[dlg.selectId]->m_monthYield[i].yield);
							if (i < m_chart->m_monthNum - 1)
								change += yield + L"，";
							else
								change += yield + L"）变为（";
						}
						for (i = 0; i < m_chart->m_monthNum; i++)
						{
							yield.Format(L"%d", dlg1.m_yield[i]);
							if (i < m_chart->m_monthNum - 1)
								change += yield + L"，";
							else
								change += yield + L"）";
							m_chart->m_product[dlg.selectId]->ChangeMonthYield(i, m_chart->m_product[dlg.selectId]->m_monthYield[i].year, m_chart->m_product[dlg.selectId]->m_monthYield[i].month, dlg1.m_yield[i]);
						}
					}
					CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
					pFrame->m_wndOutput.m_operationRecord[pFrame->m_wndOutput.m_operationRecordNum++] = change;
					pFrame->m_wndOutput.FillOperationRecordWindow();
				}
				CDocument *pDoc = GetDocument();
				POSITION pos = pDoc->GetFirstViewPosition();
				while (pos != NULL)
				{
					CView *pView = pDoc->GetNextView(pos);
					pView->OnInitialUpdate();
				}
				break;
			}
		}
		else
			break;
	}
}
