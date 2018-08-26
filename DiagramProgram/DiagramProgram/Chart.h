#pragma once
#include "Product.h"
#include <vector>
using namespace std;
// CChart 命令目标

class CChart : public CObject
{
public:
	CChart();
	virtual ~CChart();

	vector<CProduct *> m_product;//需绘制曲线的产品
	int m_monthNum;//产品月产量记录数

	void SetTitle(CString title);//设置曲线图标题
	CString GetTitle();//获取曲线图标题
	void Draw(CDC *pDC);//绘制图表
	void DrawCurve(CDC *pDC);//绘制曲线
private:
	CString m_title;//曲线图标题
	int xAdd;//坐标轴距左边界的像素距离
	int m_high;//图表绘图区高度
	int m_width;//图表绘图区宽度
	int m_scale;//列标中每一刻度间表示的数据量
	int m_xInterval;//行标的间隔
	int m_yInterval;//列标的间隔
	int m_maxData;//列标能表示的最大数据量
	CPen m_pen;//绘制图表的笔
public:
	virtual void Serialize(CArchive& ar);
};


