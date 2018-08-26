#pragma once
#include "Product.h"
#include <vector>
using namespace std;
// CChart ����Ŀ��

class CChart : public CObject
{
public:
	CChart();
	virtual ~CChart();

	vector<CProduct *> m_product;//��������ߵĲ�Ʒ
	int m_monthNum;//��Ʒ�²�����¼��

	void SetTitle(CString title);//��������ͼ����
	CString GetTitle();//��ȡ����ͼ����
	void Draw(CDC *pDC);//����ͼ��
	void DrawCurve(CDC *pDC);//��������
private:
	CString m_title;//����ͼ����
	int xAdd;//���������߽�����ؾ���
	int m_high;//ͼ���ͼ���߶�
	int m_width;//ͼ���ͼ�����
	int m_scale;//�б���ÿһ�̶ȼ��ʾ��������
	int m_xInterval;//�б�ļ��
	int m_yInterval;//�б�ļ��
	int m_maxData;//�б��ܱ�ʾ�����������
	CPen m_pen;//����ͼ��ı�
public:
	virtual void Serialize(CArchive& ar);
};


