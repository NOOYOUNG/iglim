
// SWProject_1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "SWProject_1.h"
#include "SWProject_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSWProject1Dlg 대화 상자



CSWProject1Dlg::CSWProject1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SWPROJECT_1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

void CSWProject1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_PICTURE, m_image);
}

BEGIN_MESSAGE_MAP(CSWProject1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSWProject1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSWProject1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSWProject1Dlg::OnBnClickedButton3)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSWProject1Dlg 메시지 처리기

BOOL CSWProject1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	srand((unsigned)time(NULL));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSWProject1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSWProject1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSWProject1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSWProject1Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString str = _T("");
	m_edit1.GetWindowTextW(str);

	int pos = str.Find(_T(','));

	if (pos != -1) {
		CString strX1 = str.Left(pos);
		CString strY1 = str.Mid(pos+1);

		x1 = _ttoi(strX1);
		y1 = _ttoi(strY1);

		CClientDC dc(GetDlgItem(IDC_PICTURE));
		CRect rect;
		GetDlgItem(IDC_PICTURE)->GetClientRect(&rect);
		dc.FillSolidRect(&rect, RGB(255, 255, 255));

		CPen myPen(PS_SOLID, 1, RGB(0, 0, 0));
		CBrush myBrush(RGB(0, 0, 0));
		dc.SelectObject(&myPen);
		dc.SelectObject(&myBrush);

		int radius = rand() % 21 + 10; // 랜덤한 반지름의 길이는 10 ~ 30 사이로 생성

		if (x1 - radius < 0 || y1 - radius < 0) {
			AfxMessageBox(_T("Picture Control 범위를 초과하였습니다.\n최소 30,30 이상의 좌표를 다시 입력하세요."));
		}
		else {
			dc.Ellipse(x1 - radius, y1 - radius, x1 + radius, y1 + radius);
		}
	}
	else {
		AfxMessageBox(_T("시작좌표를 입력하세요."));
	}
}


void CSWProject1Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString str1 = _T("");
	m_edit1.GetWindowTextW(str1);
	int pos1 = str1.Find(_T(','));

	CString str2 = _T("");
	m_edit2.GetWindowTextW(str2);
	int pos2 = str2.Find(_T(','));

	if (pos1 != -1 && pos2 != -1) {

		CString strX1 = str1.Left(pos1);
		CString strY1 = str1.Mid(pos1 + 1);

		x1 = _ttoi(strX1);
		y1 = _ttoi(strY1);

		CString strX2 = str2.Left(pos2);
		CString strY2 = str2.Mid(pos2 + 1);

		x2 = _ttoi(strX2);
		y2 = _ttoi(strY2);

		SetTimer(0, 100, NULL);
	}

}


void CSWProject1Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));

	if (fileDlg.DoModal()) {

		CString path = fileDlg.GetPathName();

		CImage image;
		HRESULT hr = image.Load(path);
		if (FAILED(hr)) {
			AfxMessageBox(_T("파일을 불러오는데 실패했습니다."));
			return;
		}

		CRect rect;
		CClientDC dc(GetDlgItem(IDC_PICTURE));
		GetDlgItem(IDC_PICTURE)->GetClientRect(&rect);

		image.Draw(dc.m_hDC, rect);

		m_matImage = CImageToMat(image);

		DetectCircle(m_matImage);
		CreateBitmapInfo(m_matImage.cols, m_matImage.rows);
		DrawImage(m_matImage, m_pBitmapInfo);
	}
}


Mat CSWProject1Dlg::CImageToMat(CImage& cimage)
{
	if (cimage.IsNull()) {
		AfxMessageBox(_T("이미지가 비어 있습니다."));
		return Mat();
	}

	int width = cimage.GetWidth();
	int height = cimage.GetHeight();
	int bpp = cimage.GetBPP();

	unsigned char* pPixels = (unsigned char*)cimage.GetBits();
	int pitch = cimage.GetPitch();

	if (pPixels == nullptr) {
		AfxMessageBox(_T("이미지에서 픽셀 데이터를 가져올 수 없습니다."));
		return Mat();
	}

	Mat mat;

	if (bpp == 24) {
		mat = Mat(height, width, CV_8UC3).clone();
		for (int i = 0; i < height; i++) {
			memcpy(mat.ptr(i), pPixels + i * pitch, width * 3);
		}
		cvtColor(mat, mat, COLOR_RGB2BGR);
	}
	else if (bpp == 8) {
		mat= Mat(height, width, CV_8UC1).clone();
		for (int i = 0; i < height; i++) {
			memcpy(mat.ptr(i), pPixels + i * pitch, width);
		}
	}
	else {
		AfxMessageBox(_T("이미지 변환을 지원하지 않는 색 깊이입니다."));
	}

	return mat;
}

void CSWProject1Dlg::DetectCircle(Mat matImage)
{
	if (matImage.empty()) {
		AfxMessageBox(_T("이미지가 비어 있습니다."));
		return;
	}
	
	Mat grayImage;
	cvtColor(matImage, grayImage, COLOR_BGR2GRAY); // 허프 원 검출을 위해 그레이스케일 이미지로 변환

	Mat blurredImage;
	GaussianBlur(grayImage, blurredImage, Size(9, 9), 2, 2); // 노이즈를 줄이기 위한 가우시안 블러

	vector<Vec3f> circles;
	HoughCircles(blurredImage, circles, HOUGH_GRADIENT, 1, 50, 100, 20, 10, 100);
	
	if (circles.empty()) {
		AfxMessageBox(_T("원 검출에 실패했습니다."));
		return;
	}

	Mat dst=matImage.clone();

	for (Vec3f c : circles) {
		Point center(cvRound(c[0]), cvRound(c[1]));
		int radius = cvRound(c[2]);
	
		CString centerStr;
		centerStr.Format(_T("Center (%d, %d)"), center.x, center.y);
		putText(dst, string(CT2CA(centerStr)), Point(center.x - radius, center.y - radius - 25), 1, 1, Scalar(0, 0, 255));
		
		CString radiusStr;
		radiusStr.Format(_T("Radius = %d"), radius);
		putText(dst, string(CT2CA(radiusStr)), Point(center.x - radius, center.y - radius - 10), 1, 1, Scalar(0, 0, 255));

		circle(dst, center, 1, Scalar(0, 0, 255), -1, LINE_AA);
	}

	//imshow("dst", dst);

	m_matImage=dst.clone();
}

void CSWProject1Dlg::CreateBitmapInfo(int imageWidth, int imageHeight)
{
	m_pBitmapInfo = new BITMAPINFO;

	int bpp = 8 * m_matImage.elemSize();
	
	if (bpp < 32) {
		padding = 4 - (m_matImage.cols % 4);
	}

	if (padding == 4) {
		padding = 0;
	}

	if (bpp < 32) {
		border = 4 - (m_matImage.cols % 4);
	}
		
	if (border > 0 || m_matImage.isContinuous() == false) {
		copyMakeBorder(m_matImage, mat_temp, 0, 0, 0, border, BORDER_CONSTANT, 0);
	}
	else {
		mat_temp = m_matImage;
	}

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biWidth = mat_temp.cols;
	m_pBitmapInfo->bmiHeader.biHeight = -mat_temp.rows;
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	
	int rowSize = (imageWidth * 3 + 3) / 4 * 4;
	vector<BYTE> buffer(rowSize * imageHeight);

	for (int y = 0; y < imageHeight; y++) {
		for (int x = 0; x < imageWidth; x++) {
			int bufferIdx = y * rowSize + x * 3;
			Vec3b& pixel = m_matImage.at<Vec3b>(y, x);
			buffer[bufferIdx] = pixel[0];
			buffer[bufferIdx + 1] = pixel[1];
			buffer[bufferIdx + 2] = pixel[2];
		}
	}
}

void CSWProject1Dlg::DrawImage(Mat matImage, BITMAPINFO* requestBmpInfo)
{
	int imgWidth = matImage.cols;
	int imgHeight = matImage.rows;

	CRect cRect;
	m_image.GetClientRect(&cRect);
	Size winSize(cRect.right, cRect.bottom);

	cimage.Create(winSize.width, winSize.height, 24);

	SetDIBitsToDevice(cimage.GetDC(),
					  0, 0, winSize.width, winSize.height,
					  (int)(m_matImage.cols / 2 - winSize.width / 2),
					  (int)(m_matImage.rows / 2 - winSize.height / 2),
					  0, mat_temp.rows, mat_temp.data,
					  m_pBitmapInfo, DIB_RGB_COLORS);

	HDC hdc = ::GetDC(m_image.m_hWnd);
	cimage.BitBlt(hdc, 0, 0);

	::ReleaseDC(m_image.m_hWnd, hdc);

	cimage.ReleaseDC();
	cimage.Destroy();
}


void CSWProject1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nIDEvent == 0) {
		CClientDC dc(GetDlgItem(IDC_PICTURE));
		CRect rect;
		GetDlgItem(IDC_PICTURE)->GetClientRect(&rect);
		dc.FillSolidRect(&rect, RGB(255, 255, 255));

		int radius = 30;

		if (x1 != x2) {
			x1 += 1;
		}

		if (y1 != y2) {
			y1 += 1;
		}

		CPen myPen(PS_SOLID, 1, RGB(0, 0, 0));
		CBrush myBrush(RGB(0, 0, 0));
		dc.SelectObject(&myPen);
		dc.SelectObject(&myBrush);
		dc.Ellipse(x1 - radius, y1 - radius, x1 + radius, y1 + radius);

		int width = rect.Width();
		int height = rect.Height();
		Mat saveImg;
		saveImg.create(height, width, CV_8UC3);

		GetMatImage(dc, saveImg, width, height);
		SaveImageToFolder(saveImg, _T("Action"));

		if (x1 == x2 && y1 == y2) {
			KillTimer(0);
		}

	}

	CDialogEx::OnTimer(nIDEvent);
}

void CSWProject1Dlg::GetMatImage(CDC& dc, Mat& saveImg, int width, int height)
{
	HDC hdc = CreateCompatibleDC(dc);
	HBITMAP hbm = CreateCompatibleBitmap(dc, width, height);
	SelectObject(hdc, hbm);

	BitBlt(hdc, 0, 0, width, height, dc, 0, 0, SRCCOPY);

	BITMAPINFOHEADER bmiHeader = { 0 };
	bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmiHeader.biWidth = width;
	bmiHeader.biHeight = -height;
	bmiHeader.biPlanes = 1;
	bmiHeader.biBitCount = 24;
	bmiHeader.biCompression = BI_RGB;

	int rowSize = (width * 3 + 3) / 4 * 4;
	vector<BYTE> buffer(rowSize * height);

	GetDIBits(hdc, hbm, 0, height, buffer.data(), (BITMAPINFO*)&bmiHeader, DIB_RGB_COLORS);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int bufferIdx = y * rowSize + x * 3;
			saveImg.at<Vec3b>(y, x) = Vec3b(buffer[bufferIdx], buffer[bufferIdx + 1], buffer[bufferIdx + 2]);
		}
	}

	//imshow("Capture", saveImg);

	DeleteObject(hbm);
	DeleteDC(hdc);
}

void CSWProject1Dlg::SaveImageToFolder(const Mat& matImage, const CString& fileName)
{
	CString defaultName;
	defaultName.Format(_T("%s%d"), fileName, cnt);

	CString path = _T("C:\\User\\\user\\Desktop\\iglim\\SWProject_1\\image\\");
	CString fullPath = path + defaultName + _T(".jpg");
	string strPath = CW2A(fullPath.GetString());

	imwrite(strPath, matImage);
	cnt++;
}
