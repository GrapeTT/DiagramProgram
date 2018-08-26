#pragma once

// CProduct 命令目标

class CProduct : public CObject
{
public:
	struct monthYield
	{
		int year;
		int month;
		int yield;
	}m_monthYield[100];//月产量
	int m_monthNum;//月份数

	CProduct();
	CProduct(CString name, int monthNum, int year[], int month[], int yield[], COLORREF color, int shape);
	virtual ~CProduct();

	CString GetName();//获取产品名
	void SetName(CString name);//设置产品名
	void ChangeMonthYield(int i, int year, int month, int yield);//修改月产量
	void DeleteMonthYield(int i, int n);//删除月份
	void AddMonthYield(int i, int year, int month, int yield);//增加月份
	COLORREF GetColor();//获取颜色
	void SetColor(COLORREF color);//设置颜色
	int GetShape();//获取节点形状
	void SetShape(int shape);//设置节点形状
	void Draw(CDC * pDC, CPoint p);//绘制自己的节点形状
	int GetmaxMY();//获取最大季度产量

private:
	CString m_name;//产品名字
	COLORREF m_color;//笔的颜色
	int m_shape;//节点形状
	int m_maxMY;//最大月产量
public:
	virtual void Serialize(CArchive& ar);
};


