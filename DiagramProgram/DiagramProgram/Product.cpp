// Product.cpp : 实现文件
//

#include "stdafx.h"
#include "Product.h"


// CProduct
CProduct::CProduct()
{
	m_name = L"产品";
	m_maxMY = 0;
	m_monthNum = 0;
	m_shape = 1;
	m_color = RGB(255, 255, 255);
}

CProduct::CProduct(CString name, int monthNum, int year[], int month[], int yield[], COLORREF color, int shape)
{
	m_name = name;
	m_maxMY = 0;
	m_monthNum = monthNum;
	int i;
	for (i = 0; i < monthNum; i++)
	{
		m_monthYield[i].year = year[i];
		m_monthYield[i].month = month[i];
		m_monthYield[i].yield = yield[i];
		if (m_maxMY < yield[i])
			m_maxMY = yield[i];
	}
	m_color = color;
	m_shape = shape;
}

CProduct::~CProduct()
{
}


// CProduct 成员函数
CString CProduct::GetName()
{
	return m_name;
}

void CProduct::SetName(CString name)
{
	m_name = name;
}

void CProduct::ChangeMonthYield(int i, int year, int month, int yield)
{
	m_monthYield[i].year = year;
	m_monthYield[i].month = month;
	m_monthYield[i].yield = yield;
	if (yield > m_maxMY)
		m_maxMY = yield;
}

void CProduct::DeleteMonthYield(int i, int n)
{
	int j = i;
	m_maxMY = 0;
	for (; j < n - 1; j++)
	{
		m_monthYield[j].year = m_monthYield[j + 1].year;
		m_monthYield[j].month = m_monthYield[j + 1].month;
		m_monthYield[j].yield = m_monthYield[j + 1].yield;
		if (m_monthYield[j].yield > m_maxMY)
			m_maxMY = m_monthYield[j + 1].yield;
	}
	for (j = 0; j < i; j++)
	{
		if (m_monthYield[j].yield > m_maxMY)
			m_maxMY = m_monthYield[j].yield;
	}
	m_monthNum--;
}

void CProduct::AddMonthYield(int i, int year, int month, int yield)
{
	int j;
	for (j = 0; j < i - 1; j++)
	{
		if (m_monthYield[j].year >= year)
			break;
	}
	int k;
	for (k = j; k < i - 1; k++)
	{
		if (m_monthYield[k].year > year)
			break;
	}
	int l = j;
	for (; l < k; l++)
	{
		if (m_monthYield[l].month > month)
			break;
	}
	for (j = i - 1; j > l; j--)
	{
		m_monthYield[j] = m_monthYield[j - 1];
	}
	m_monthYield[l].year = year;
	m_monthYield[l].month = month;
	m_monthYield[l].yield = yield;
	m_monthNum++;
}

COLORREF CProduct::GetColor()
{
	return m_color;
}

void CProduct::SetColor(COLORREF color)
{
	m_color = color;
}

int CProduct::GetShape()
{
	return m_shape;
}

void CProduct::SetShape(int shape)
{
	m_shape = shape;
}

int CProduct::GetmaxMY()
{
	return m_maxMY;
}

void CProduct::Draw(CDC * pDC, CPoint p)
{
	CPen m_pen;//绘制节点的笔
	m_pen.CreatePen(PS_SOLID, 2, m_color);

	CPen * pen;
	pen = pDC->SelectObject(&m_pen);
	if (m_shape == 1)
	{
		CPoint point[5];
		point[0].y = p.y - 5;
		point[0].x = p.x;
		point[1].y = p.y;
		point[1].x = p.x - 5;
		point[2].y = p.y + 5;
		point[2].x = p.x;
		point[3].y = p.y;
		point[3].x = p.x + 5;
		point[4] = point[0];
		pDC->Polyline(point, 5);
	}
	else if (m_shape == 2)
	{
		CPoint point[5];
		point[0].y = p.y - 4;
		point[0].x = p.x - 4;
		point[1].y = p.y + 4;
		point[1].x = p.x - 4;
		point[2].y = p.y + 4;
		point[2].x = p.x + 4;
		point[3].y = p.y - 4;
		point[3].x = p.x + 4;
		point[4] = point[0];
		pDC->Polyline(point, 5);
	}
	else if (m_shape == 3)
	{
		CPoint point[4];
		point[0].y = p.y - 6;
		point[0].x = p.x;
		point[1].y = p.y + 3;
		point[1].x = p.x - 4;
		point[2].y = p.y + 3;
		point[2].x = p.x + 4;
		point[3] = point[0];
		pDC->Polyline(point, 4);
	}
	else if (m_shape == 4)
	{
		CPoint point[7];
		point[0].y = p.y - 4;
		point[0].x = p.x - 4;
		point[1] = p;
		point[2].y = p.y + 4;
		point[2].x = p.x - 4;
		point[3] = p;
		point[4].y = p.y - 4;
		point[4].x = p.x + 4;
		point[5] = p;
		point[6].y = p.y + 4;
		point[6].x = p.x + 4;
		pDC->Polyline(point, 7);
	}
	else if (m_shape == 5)
	{
		pDC->Ellipse(p.x - 5, p.y - 5, p.x + 5, p.y + 5);
	}
}

void CProduct::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	
		ar << m_name << m_color << m_shape << m_maxMY << m_monthNum;
		int i;
		for (i = 0; i < m_monthNum; i++)
		{
			ar << m_monthYield[i].year << m_monthYield[i].month << m_monthYield[i].yield;
		}
	}
	else
	{	
		ar >> m_name >> m_color >> m_shape >> m_maxMY >> m_monthNum;
		int i;
		for (i = 0; i < m_monthNum; i++)
		{
			ar >> m_monthYield[i].year >> m_monthYield[i].month >> m_monthYield[i].yield;
		}
	}
}
