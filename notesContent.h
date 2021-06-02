#pragma once
#include <wx/wx.h>
#include "RandWExcel.h"
#include <wx/notebook.h>
#include <wx/srchctrl.h>
class notesContent : public wxPanel
{
public:
	notesContent(wxBoxSizer* parent, wxPanel* parentpn);
	wxPanel* NotesParent;
	wxBoxSizer* PanelContentSizer;
	CSVReader* ReadEx;
	wxListBox* LList;
	wxListBox* RList;
	wxPanel* LeftPanelCt;
	//
	wxBitmapButton* refreshBtn;
	//
	wxTextCtrl* Tnote;
	//
	wxButton* TnoteBtn1;
	wxButton* TnoteBtn2;
	//
	void hide();
	void show();
	DECLARE_EVENT_TABLE()
	void refreshFunc(wxCommandEvent& WXUNUSED(event));
	void modifiedFunc(wxCommandEvent& WXUNUSED(event));
	void okFunc(wxCommandEvent& WXUNUSED(event));


};

