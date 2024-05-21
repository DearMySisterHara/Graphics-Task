
// MFCApplication2View.cpp: CMFCApplication2View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication2View 생성/소멸

CMFCApplication2View::CMFCApplication2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View 그리기
void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPoint mousePos;
	GetCursorPos(&mousePos);
	ScreenToClient(&mousePos);

	// 별 그리기
	int starSize = 50; // 별의 크기
	CPoint vertices[10]; // 별의 꼭짓점 좌표 배열
	double angle = 3.141592 / 2.0; // 시작 각도
	double angleIncrement = 2.0 * 3.141592 / 5.0; // 5개의 꼭짓점을 가진 별

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			vertices[i].x = mousePos.x + static_cast<int>(cos(angle) * starSize);
			vertices[i].y = mousePos.y + static_cast<int>(sin(angle) * starSize);
		}
		else {
			vertices[i].x = mousePos.x + static_cast<int>(cos(angle) * (starSize / 2.0));
			vertices[i].y = mousePos.y + static_cast<int>(sin(angle) * (starSize / 2.0));
		}
		angle += angleIncrement;
	}

	pDC->Polygon(vertices, 10); // 별 그리기

	// TODO: 기타 그리기 코드를 추가합니다.
}


// CMFCApplication2View 인쇄

BOOL CMFCApplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication2View 진단

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View 메시지 처리기


void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Invalidate(true);
	CView::OnMouseMove(nFlags, point);
}
