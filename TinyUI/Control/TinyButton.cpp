#include "../stdafx.h"
#include "TinyButton.h"

namespace TinyUI
{
	TinyButton::TinyButton()
	{
	};
	TinyButton::~TinyButton()
	{

	};
	BOOL TinyButton::Create(HWND hParent, INT x, INT y, INT cx, INT cy)
	{
		INITCOMMONCONTROLSEX initCtrls = { sizeof(INITCOMMONCONTROLSEX), ICC_STANDARD_CLASSES };
		if (InitCommonControlsEx(&initCtrls))
		{
			return TinyControl::Create(hParent, x, y, cx, cy);

		}
		return FALSE;
	};
	DWORD TinyButton::RetrieveStyle()
	{
		return (WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_NOTIFY | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
	}
	DWORD TinyButton::RetrieveExStyle()
	{
		return (WS_EX_LEFT | WS_EX_LTRREADING);
	}
	LPCSTR TinyButton::RetrieveClassName()
	{
		return WC_BUTTON;
	};
	LPCSTR TinyButton::RetrieveTitle()
	{
		return _T("TinyButton");
	};
	BOOL TinyButton::SetText(LPCSTR pzText)
	{
		ASSERT(::IsWindow(m_hWND));
		return ::SetWindowText(m_hWND, pzText);
	}
	BOOL TinyButton::GetText(LPSTR pzText, INT iSize)
	{
		ASSERT(::IsWindow(m_hWND));
		return ::GetWindowText(m_hWND, pzText, iSize);
	}
	UINT TinyButton::GetState() const
	{
		ASSERT(::IsWindow(m_hWND));
		return (UINT)::SendMessage(m_hWND, BM_GETSTATE, 0, 0);
	}
	void TinyButton::SetState(BOOL bHighlight)
	{
		::SendMessage(m_hWND, BM_SETSTATE, bHighlight, 0);
	}
	INT TinyButton::GetCheck() const
	{
		ASSERT(::IsWindow(m_hWND));
		return (INT)::SendMessage(m_hWND, BM_GETCHECK, 0, 0);
	}
	void TinyButton::SetCheck(INT nCheck)
	{
		ASSERT(::IsWindow(m_hWND));
		::SendMessage(m_hWND, BM_SETCHECK, nCheck, 0);
	}
	UINT TinyButton::GetButtonStyle() const
	{
		ASSERT(::IsWindow(m_hWND));
		return (UINT)::GetWindowLong(m_hWND, GWL_STYLE) & 0xFFFF;
	}
	void TinyButton::SetButtonStyle(UINT nStyle, BOOL bRedraw)
	{
		ASSERT(::IsWindow(m_hWND));
		::SendMessage(m_hWND, BM_SETSTYLE, nStyle, (LPARAM)bRedraw);
	}

	HICON TinyButton::SetIcon(HICON hIcon)
	{
		ASSERT(::IsWindow(m_hWND));
		return (HICON)::SendMessage(m_hWND, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon);
	}
	HICON TinyButton::GetIcon() const
	{
		ASSERT(::IsWindow(m_hWND));
		return (HICON)::SendMessage(m_hWND, BM_GETIMAGE, IMAGE_ICON, 0L);
	}
	HBITMAP TinyButton::SetBitmap(HBITMAP hBitmap)
	{
		ASSERT(::IsWindow(m_hWND));
		return (HBITMAP)::SendMessage(m_hWND, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
	}
	HBITMAP TinyButton::GetBitmap() const
	{
		ASSERT(::IsWindow(m_hWND));
		return (HBITMAP)::SendMessage(m_hWND, BM_GETIMAGE, IMAGE_BITMAP, 0L);
	}
	HCURSOR TinyButton::SetCursor(HCURSOR hCursor)
	{
		ASSERT(::IsWindow(m_hWND));
		return (HCURSOR)::SendMessage(m_hWND, BM_SETIMAGE, IMAGE_CURSOR, (LPARAM)hCursor);
	}
	HCURSOR TinyButton::GetCursor()
	{
		ASSERT(::IsWindow(m_hWND));
		return (HCURSOR)::SendMessage(m_hWND, BM_GETIMAGE, IMAGE_CURSOR, 0L);
	}
	BOOL TinyButton::GetIdealSize(SIZE* psize) const
	{
		ASSERT(::IsWindow(m_hWND));
		ASSERT(psize != NULL);
		return Button_GetIdealSize(m_hWND, psize);
	}

	BOOL TinyButton::SetImageList(PBUTTON_IMAGELIST pbuttonImagelist)
	{
		ASSERT(::IsWindow(m_hWND));
		ASSERT(pbuttonImagelist != NULL);
		return Button_SetImageList(m_hWND, pbuttonImagelist);
	}

	BOOL TinyButton::GetImageList(PBUTTON_IMAGELIST pbuttonImagelist) const
	{
		ASSERT(::IsWindow(m_hWND));
		ASSERT(pbuttonImagelist != NULL);
		return Button_GetImageList(m_hWND, pbuttonImagelist);
	}

	BOOL TinyButton::SetTextMargin(RECT* pmargin)
	{
		ASSERT(::IsWindow(m_hWND));
		ASSERT(pmargin != NULL);
		return Button_SetTextMargin(m_hWND, pmargin);
	}

	BOOL TinyButton::GetTextMargin(RECT* pmargin) const
	{
		ASSERT(::IsWindow(m_hWND));
		ASSERT(pmargin != NULL);
		return Button_GetTextMargin(m_hWND, pmargin); // BCM_GETTEXTMARGIN
	}

	BOOL TinyButton::GetNote(LPTSTR lpszNote, UINT* pcchNote) const
	{
		ASSERT(::IsWindow(m_hWND));
		ASSERT(lpszNote != NULL);
		ASSERT(pcchNote != NULL);
		return Button_GetNote(m_hWND, lpszNote, pcchNote); // BCM_GETNOTE
	}

	BOOL TinyButton::SetNote(LPCTSTR lpszNote)
	{
		ASSERT(::IsWindow(m_hWND));
		return Button_SetNote(m_hWND, lpszNote); // BCM_SETNOTE
	}

	UINT TinyButton::GetNoteLength() const
	{
		ASSERT(::IsWindow(m_hWND));
		return (UINT)Button_GetNoteLength(m_hWND); // BCM_GETNOTELENGTH
	}

	BOOL TinyButton::GetSplitInfo(PBUTTON_SPLITINFO pInfo) const
	{
		ASSERT(::IsWindow(m_hWND));
		return Button_GetSplitInfo(m_hWND, pInfo); // BCM_GETSPLITINFO
	}

	BOOL TinyButton::SetSplitInfo(PBUTTON_SPLITINFO pInfo)
	{
		ASSERT(::IsWindow(m_hWND));
		return Button_SetSplitInfo(m_hWND, pInfo); // BCM_SETSPLITINFO
	}

	UINT TinyButton::GetSplitStyle() const
	{
		ASSERT(::IsWindow(m_hWND));
		BUTTON_SPLITINFO buttonSplitInfo = { 0 };
		buttonSplitInfo.mask = BCSIF_STYLE;
		Button_GetSplitInfo(m_hWND, &buttonSplitInfo);
		return buttonSplitInfo.uSplitStyle;
	}

	BOOL TinyButton::SetSplitStyle(UINT nStyle)
	{
		ASSERT(::IsWindow(m_hWND));
		BUTTON_SPLITINFO buttonSplitInfo = { 0 };
		buttonSplitInfo.mask = BCSIF_STYLE;
		buttonSplitInfo.uSplitStyle = nStyle;
		return Button_SetSplitInfo(m_hWND, &buttonSplitInfo);
	}

	BOOL TinyButton::GetSplitSize(LPSIZE pSize) const
	{
		ASSERT(::IsWindow(m_hWND));
		BUTTON_SPLITINFO buttonSplitInfo = { 0 };
		buttonSplitInfo.mask = BCSIF_SIZE;
		BOOL fRet = Button_GetSplitInfo(m_hWND, &buttonSplitInfo);
		pSize->cx = buttonSplitInfo.size.cx;
		pSize->cy = buttonSplitInfo.size.cy;
		return fRet;
	}

	BOOL TinyButton::SetSplitSize(LPSIZE pSize)
	{
		ASSERT(::IsWindow(m_hWND));
		BUTTON_SPLITINFO buttonSplitInfo = { 0 };
		buttonSplitInfo.mask = BCSIF_SIZE;
		buttonSplitInfo.size.cx = pSize->cx;
		buttonSplitInfo.size.cy = pSize->cy;
		return Button_SetSplitInfo(m_hWND, &buttonSplitInfo);
	}

	TCHAR TinyButton::GetSplitGlyph() const
	{
		ASSERT(::IsWindow(m_hWND));
		BUTTON_SPLITINFO buttonSplitInfo = { 0 };
		buttonSplitInfo.mask = BCSIF_GLYPH;
		Button_GetSplitInfo(m_hWND, &buttonSplitInfo);
		return (TCHAR)buttonSplitInfo.himlGlyph;
	}

	BOOL TinyButton::SetSplitGlyph(TCHAR chGlyph)
	{
		ASSERT(::IsWindow(m_hWND));
		BUTTON_SPLITINFO buttonSplitInfo = { 0 };
		buttonSplitInfo.mask = BCSIF_GLYPH;
		buttonSplitInfo.himlGlyph = (HIMAGELIST)chGlyph;
		return Button_SetSplitInfo(m_hWND, &buttonSplitInfo);
	}

	BOOL TinyButton::SetDropDownState(BOOL fDropDown)
	{
		ASSERT(::IsWindow(m_hWND));
		return Button_SetDropDownState(m_hWND, fDropDown); // BCM_SETDROPDOWNSTATE
	}

	HICON TinyButton::SetShield(BOOL fElevationRequired)
	{
		ASSERT(::IsWindow(m_hWND));
		return (HICON)(Button_SetElevationRequiredState(m_hWND, fElevationRequired)); // BCM_SETSHIELD
	}
	void TinyButton::OnDoubleClick(void* sender, INT ctrlID)
	{
		DoubleClick(sender, ctrlID);
	}
	void TinyButton::OnDisable(void* sender, INT ctrlID)
	{
		Disable(sender, ctrlID);
	}
	void TinyButton::OnClick(void* sender, INT ctrlID)
	{
		Click(sender, ctrlID);
	}
	void TinyButton::OnGotFocus(void* sender, INT ctrlID)
	{
		GotFocus(sender, ctrlID);
	}
	void TinyButton::OnLostFocus(void* sender, INT ctrlID)
	{
		LostFocus(sender, ctrlID);
	}

	LRESULT TinyButton::OnCommandReflect(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		bHandled = FALSE;
		UINT code = HIWORD(wParam);
		UINT ctlID = LOWORD(wParam);
		switch (code)
		{
		case BN_CLICKED:
			OnClick(this, ctlID);
			break;
		case BN_DISABLE:
			OnDisable(this, ctlID);
			break;
		case BN_DOUBLECLICKED:
			OnDoubleClick(this, ctlID);
			break;
		case BN_SETFOCUS:
			OnGotFocus(this, ctlID);
			break;
		case BN_KILLFOCUS:
			OnLostFocus(this, ctlID);
			break;
		}
		return FALSE;
	}

}

