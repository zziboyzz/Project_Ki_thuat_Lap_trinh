#pragma once
#include <wx/wx.h>
#include "RandWExcel.h"
#include <wx/notebook.h>
#include <wx/srchctrl.h>
#include <string>

class notesContent : public wxPanel
{
public:
	string* fileDir;
	notesContent(wxBoxSizer* parent, wxPanel* parentpn, string* filePath);
	wxPanel* NotesParent;
	wxBoxSizer* PanelContentSizer;
	CSVReader* ReadEx;
	CSVWriter* writeNote;
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
	string curDayDir;
	string* note;
public:
	void hide();
	void show();
	DECLARE_EVENT_TABLE()
	void refreshFunc(wxCommandEvent& WXUNUSED(event));
	void modifiedFunc(wxCommandEvent& WXUNUSED(event));
	void okFunc(wxCommandEvent& WXUNUSED(event));


};

