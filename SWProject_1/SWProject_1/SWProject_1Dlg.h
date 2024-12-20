
// SWProject_1Dlg.h: 헤더 파일
//

#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// CSWProject1Dlg 대화 상자
class CSWProject1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CSWProject1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SWPROJECT_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CStatic m_image;
	Mat m_matImage;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int x1;
	int y1;
	int x2;
	int y2;

	int cnt = 1;
	void GetMatImage(CDC& dc, Mat& saveImg, int width, int height);
	void SaveImageToFolder(const Mat& matImage, const CString& fileName);

	Mat CImageToMat(CImage& cimage);
	void DetectCircle(Mat matImage);
	
	int padding = 0;
	int border = 0;
	BITMAPINFO* m_pBitmapInfo;
	Mat mat_temp;
	CImage cimage;
	void CreateBitmapInfo(int imageWidth, int imageHeight);
	void DrawImage(Mat matImage, BITMAPINFO* requestBmpInfo);

	CImage picImage;
	void SaveCurrentFrame(CDC& dc, int width, int height);
};
