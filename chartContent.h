#pragma once
#include <wx/wx.h>
#include "EnergyCharts.h"
#include "ceSerial.h"
using namespace ce;
class chartContent : wxPanel
{
public:
	chartContent(wxBoxSizer* parent, wxPanel* parentpn, ceSerial* portCom);
	wxPanel* chartParent;
	wxPanel* PanelContent;
	EnergyCharts* chart1;
	void hide();
	void show();

};

