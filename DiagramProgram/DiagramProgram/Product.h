#pragma once

// CProduct ����Ŀ��

class CProduct : public CObject
{
public:
	struct monthYield
	{
		int year;
		int month;
		int yield;
	}m_monthYield[100];//�²���
	int m_monthNum;//�·���

	CProduct();
	CProduct(CString name, int monthNum, int year[], int month[], int yield[], COLORREF color, int shape);
	virtual ~CProduct();

	CString GetName();//��ȡ��Ʒ��
	void SetName(CString name);//���ò�Ʒ��
	void ChangeMonthYield(int i, int year, int month, int yield);//�޸��²���
	void DeleteMonthYield(int i, int n);//ɾ���·�
	void AddMonthYield(int i, int year, int month, int yield);//�����·�
	COLORREF GetColor();//��ȡ��ɫ
	void SetColor(COLORREF color);//������ɫ
	int GetShape();//��ȡ�ڵ���״
	void SetShape(int shape);//���ýڵ���״
	void Draw(CDC * pDC, CPoint p);//�����Լ��Ľڵ���״
	int GetmaxMY();//��ȡ��󼾶Ȳ���

private:
	CString m_name;//��Ʒ����
	COLORREF m_color;//�ʵ���ɫ
	int m_shape;//�ڵ���״
	int m_maxMY;//����²���
public:
	virtual void Serialize(CArchive& ar);
};


