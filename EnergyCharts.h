#pragma once
#include <wx/wx.h>
#ifndef WX_PRECOMP
#include <wx/wxprec.h>
#endif
#include"mathplot.h"
#include <wx/image.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/log.h>
#include <wx/intl.h>
#include <wx/print.h>
#include <wx/filename.h>

#include <math.h>
//
#include <time.h>
#include <cstdlib>
#include <ctime>
#include "RandWExcel.h"
#include "ceSerial.h"
using namespace ce;

class EnergyCharts : public wxPanel
{
   enum
    {
        GaugePage_Reset = wxID_HIGHEST,
        GaugePage_Progress,
    };
public:
    //
    ceSerial* com;
    string* fileDir;
    EnergyCharts(wxPanel* parentpn, ceSerial* portCom, string* filePpath);
    mpWindow* m_plot;
    wxPanel* m_log;
    wxPanel* pr;
    //
    std::vector<double> vectorx, vectory;
    mpFXYVector* vectorLayer;
    //
    wxTimer* m_timer;
    wxButton* buton1;
    //
    CSVWriter* Excel;
    //
    wxTextCtrl* comLabel;
    wxSlider* m_slider;
    wxButton* Setbutton;
    //
    time_t now;
    tm* ltm;
    string string_name;
    int resy;
    ~EnergyCharts();

    //DECLARE_DYNAMIC_CLASS(EnergyCharts);
    DECLARE_EVENT_TABLE()
    void onPlus(wxCommandEvent& WXUNUSED(event));
    void onDecrease(wxCommandEvent& WXUNUSED(event));
    void OnProgressTimer(wxTimerEvent& WXUNUSED(event));
    void onSet(wxCommandEvent& WXUNUSED(event));
private:
    int axesPos[2];
    bool ticks;
};
