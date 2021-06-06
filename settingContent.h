#pragma once
#include <wx/wx.h>
#include "ceSerial.h"
#include <stdlib.h>     //for using the function sleep

using namespace std;
using namespace ce;
class settingContent : public wxPanel
{
public:
	ceSerial* com;
	string* fileDir;
	settingContent(wxBoxSizer* parent, wxPanel* parentpn, ceSerial* sePort, string& filePath);
	wxPanel* NotesParent;
	wxPanel* PanelContent;
	wxBoxSizer* PanelContentSizer;
	wxListBox* settingLabels;
	wxTextCtrl* txtSend;
	wxTextCtrl* txtRx;
	wxButton* openSeBtn;
	wxPanel* RightContent1;
	wxPanel* RightContent2;
	wxPanel* RightContent3;
	wxPanel* RightContent4;
	wxTextCtrl* fileHrefTextCtrl;
	void hide();
	void show();
	DECLARE_EVENT_TABLE()
	void onSelect(wxCommandEvent& WXUNUSED(event));
	void onSetPort(wxCommandEvent& WXUNUSED(event));
	void onOpenPort(wxCommandEvent& WXUNUSED(event));
	void onSetFileRef(wxCommandEvent& WXUNUSED(event));

};

