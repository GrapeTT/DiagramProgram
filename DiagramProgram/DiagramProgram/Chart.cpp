// Chart.cpp : 实现文件
//

#include "stdafx.h"
#include "Chart.h"


// CChart

CChart::CChart()
{
	m_title = "生产数据图";
	m_monthNum = 12;
	m_high = 180;
	m_yInterval = m_high / 6;
	m_xInterval = 60;
	m_width = m_xInterval * m_monthNum;
	m_pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	/*int year[12] = {2017, 2017, 2017 , 2017, 2017, 2017, 2017 , 2017, 2017, 2017, 2017 , 2017};
	int month[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int yield1[12] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 60, 110, 20};
	COLORREF color1 = RGB(255, 0, 255);
	int shape1 = 1;
	m_product.push_back(new CProduct(L"产品1", m_monthNum, year, month, yield1, color1, shape1));

	int yield2[12] = { 120, 50, 90, 10, 60, 110, 40, 60, 50, 100, 10, 120 };
	COLORREF color2 = RGB(0, 0, 255);
	int shape2 = 2;
	m_product.push_back(new CProduct(L"产品2", m_monthNum, year, month, yield2, color2, shape2));

	int yield3[12] = { 100, 10, 80, 50, 90, 40, 100, 40, 60, 110, 30, 80 };
	COLORREF color3 = RGB(0,255,0);
	int shape3 = 3;
	m_product.push_back(new CProduct(L"产品3", m_monthNum, year, month, yield3, color3, shape3));

	int yield4[12] = { 60, 100, 30, 80, 30, 80, 40, 50, 100, 10, 50, 60 };
	COLORREF color4 = RGB(255,0,0);
	int shape4 = 4;
	m_product.push_back(new CProduct(L"产品4", m_monthNum, year, month, yield4, color4, shape4));*/
}

CChart::~CChart()
{
}


// CChart 成员函数

void CChart::SetTitle(CString title)
{
	m_title = title;
}

 CString CChart::GetTitle()
{
	return m_title;
}

void CChart::Draw(CDC *pDC)
{
	int maxMY = 0, i;
	if (m_product.empty() == 1)
		m_monthNum = 0;
	else
	{
		m_monthNum = m_product[0]->m_monthNum;
		for (i = 0; i < m_product.size(); i++)
		{
			if (maxMY < m_product[i]->GetmaxMY())
				maxMY = m_product[i]->GetmaxMY();
		}
	}
	if (maxMY == 0)
	{
		m_scale = 10;
		maxMY = 60;
	}
	else
	{
		if (maxMY % 60 == 0)
			m_scale = maxMY / 6;
		else
			m_scale = ((maxMY / 60) + 1) * 10;
	}
	m_maxData = m_scale * 6;

	if (m_monthNum == 0)
		m_width = m_xInterval * 12;
	else
		m_width = m_xInterval * m_monthNum;

	if (m_monthNum == 1)
		pDC->TextOutW(50, 0, m_title);
	else
	    pDC->TextOutW(m_width / 2, 0, m_title);
	
	CPen * pen;
	pen = pDC->SelectObject(&m_pen);
	CString s;
	s.Format(L"%d", maxMY);
	CSize size = pDC->GetTextExtent(s);
	xAdd = size.cx + 3;
	CPoint p[2];
	//画y轴箭头
	p[0].y = 20;
	p[0].x = xAdd;
	p[1].y = 25;
	p[1].x = xAdd - 5;
	pDC->Polyline(p, 2);
	p[0].y = 20;
	p[0].x = xAdd;
	p[1].y = 25;
	p[1].x = xAdd + 5;
	pDC->Polyline(p, 2);
	//画y轴
	p[0].y = 20;
	p[0].x = xAdd;
	p[1].y = 40 + m_high;
	p[1].x = xAdd;
	pDC->Polyline(p, 2);
	pDC->TextOutW(xAdd - 22, 0, L"月产量");
	//画x轴箭头
	p[0].y = 35 + m_high;
	p[0].x = xAdd + 15 + m_width;
	p[1].y = 40 + m_high;
	p[1].x = xAdd + 20 + m_width;
	pDC->Polyline(p, 2);
	p[0].y = 45 + m_high;
	p[0].x = xAdd + 15 + m_width;
	p[1].y = 40 + m_high;
	p[1].x = xAdd + 20 + m_width;
	pDC->Polyline(p, 2);
	//画x轴
	p[0].y = 40 + m_high;
	p[0].x = xAdd;
	p[1].y = 40 + m_high;
	p[1].x = xAdd + 20 + m_width;
	pDC->Polyline(p, 2);
	pDC->TextOutW(p[1].x + 3, p[1].y - 8, L"月份");
	//画横坐标
	p[1].y = 40 + m_high - 4;
	if (m_product.empty() != 1)
	{
		CString year, month;
		for (i = 0; i < m_monthNum; i++)
		{
			p[0].x = xAdd + m_xInterval + i * m_xInterval;
			p[1].x = p[0].x;
			pDC->Polyline(p, 2);
			year.Format(L"%d年", m_product[0]->m_monthYield[i].year);
			size = pDC->GetTextExtent(year);
			pDC->TextOutW(xAdd + (m_xInterval - size.cx) / 2 + i * m_xInterval, m_high + 43, year);
			month.Format(L"%d月", m_product[0]->m_monthYield[i].month);
			size = pDC->GetTextExtent(month);
			pDC->TextOutW(xAdd + (m_xInterval - size.cx) / 2 + i * m_xInterval, m_high + 63, month);
		}
	}
	//画纵坐标
	CPen pen1;
	pen1.CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	pen = pDC->SelectObject(&pen1);
	p[0].x = xAdd;
	for (i = 0; i < 6; i++)
	{
		p[0].y = 40 + i * m_yInterval;
		p[1].y = p[0].y;
		p[1].x = p[0].x + m_width;
		s.Format(L"%d", (6 - i)*m_scale);
		size = pDC->GetTextExtent(s);
		pDC->TextOutW((xAdd - size.cx) / 2, p[0].y - 7, s);
		pDC->Polyline(p, 2);
	}
	s.Format(L"%d", 0);
	size = pDC->GetTextExtent(s);
	pDC->TextOutW((xAdd - size.cx) / 2, 40 + m_high - 7, s);
	pDC->SelectObject(pen);
	//画折线
	DrawCurve(pDC);
}

void CChart::DrawCurve(CDC *pDC)
{
	int i, j;
	CPoint p[2];
	CString s;
	if (m_product.empty() != 1)
	{
		for (i = 0; i < m_product.size(); i++)
		{
			for (j = 0; j < m_monthNum; j++)
			{
				p[0] = p[1];
				p[1].x = xAdd + m_xInterval / 2 + j * m_xInterval;
				p[1].y = 40 + m_high - (double)m_product[i]->m_monthYield[j].yield / m_maxData * m_high;
				m_product[i]->Draw(pDC, p[1]);
				if (j == 0)
					p[0] = p[1];
				pDC->Polyline(p, 2);
			}
			s = m_product[i]->GetName();
			p[0].y = 60 + m_high / 7 + i * 20 - 10;
			p[0].x = xAdd + 70 + m_width;
			m_product[i]->Draw(pDC, p[0]);
			p[0].x = xAdd + 60 + m_width;
			p[1].x = xAdd + 80 + m_width;
			p[1].y = p[0].y;
			pDC->Polyline(p, 2);
			pDC->TextOutW(xAdd + 90 + m_width, 40 + m_high / 7 + i * 20 + 2, s);
		}
	}
}

void CChart::Serialize(CArchive& ar)
{
	CObList m_List;
	CProduct * product;
	if (ar.IsStoring())
	{	
		int i, n;
		if (m_product.empty() == 1)
			n = 0;
		else
		    n = m_product.size();
		for (i = n - 1; i >= 0; i--)
		{
			m_List.AddHead(m_product[i]);
		}
		m_List.GetCount();
		ar << n;
		ar << m_high << m_maxData << m_monthNum << m_scale << m_title << m_width << m_xInterval << m_yInterval;
		POSITION pos = m_List.GetHeadPosition();
		while (pos)
		{
			product = (CProduct *)m_List.GetNext(pos);
			product->Serialize(ar);
		}
	}
	else
	{	
		int n;
		ar >> n;
		ar >> m_high >> m_maxData >> m_monthNum >> m_scale >> m_title >> m_width >> m_xInterval >> m_yInterval;
		product = new CProduct();
		while (n--)
		{
			product->Serialize(ar);
			int year[100], month[100], yield[100];
			int i;
			for (i = 0; i < product->m_monthNum; i++)
			{
				year[i] = product->m_monthYield[i].year;
				month[i] = product->m_monthYield[i].month;
				yield[i] = product->m_monthYield[i].yield;
			}
			m_product.push_back(new CProduct(product->GetName(), product->m_monthNum, year, month, yield, product->GetColor(), product->GetShape()));
		}
	}
}
