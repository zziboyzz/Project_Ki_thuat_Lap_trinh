#pragma once
#include <wx/wx.h>
#include "ceSerial.h"
using namespace ce;
class settingContent : public wxPanel
{
public:
	ceSerial* com;
	settingContent(wxBoxSizer* parent, wxPanel* parentpn, ceSerial* sePort);
	wxPanel* NotesParent;
	wxPanel* PanelContent;
	wxBoxSizer* PanelContentSizer;
	wxListBox* settingLabels;
	wxTextCtrl* txtSend;
	wxTextCtrl* txtRx;
	wxButton* openSeBtn;
	wxPanel* RightContent1;
	wxPanel* RightContent2;
	void hide();
	void show();
	DECLARE_EVENT_TABLE()
	void onSelect(wxCommandEvent& WXUNUSED(event));
	void onSetPort(wxCommandEvent& WXUNUSED(event));
	void onOpenPort(wxCommandEvent& WXUNUSED(event));

};

