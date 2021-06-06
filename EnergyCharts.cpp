#include "EnergyCharts.h"

//IMPLEMENT_DYNAMIC_CLASS(EnergyCharts, wxPanel)
BEGIN_EVENT_TABLE(EnergyCharts, wxPanel)
EVT_BUTTON(6666, EnergyCharts::onPlus)
EVT_BUTTON(6667, EnergyCharts::onDecrease)
EVT_BUTTON(6668, EnergyCharts::onSet)
EVT_TIMER(5555, EnergyCharts::OnProgressTimer)
END_EVENT_TABLE()

EnergyCharts::EnergyCharts(wxPanel* parentpn, ceSerial* portCom, string* filePath)
    : wxPanel(parentpn, -1, wxPoint(-1, -1), wxSize(-1, -1))
{
    //Parents setting
    com = portCom;
    fileDir = filePath;
    // Create a mpFXYVector layer
    vectorLayer = new mpFXYVector(_("LightScale"));
    vectorLayer->SetContinuity(true);
    wxPen vectorpen(*wxBLUE, 2, wxPENSTYLE_SOLID);
    vectorLayer->SetPen(vectorpen);
    vectorLayer->SetDrawOutsideMargins(false);

    //Definition
    m_plot = new mpWindow(this, 5555);
    m_log = new wxPanel(this, -1, wxPoint(-1, -1), wxSize(0, 0));
    wxStaticText* m_text = new wxStaticText(m_log, -1, wxT("Settings:"),
        wxPoint(0, 0), wxSize(-1, -1), wxALIGN_LEFT);
    mpScaleX* xaxis = new mpScaleX(wxT("Time(s)"), mpALIGN_BOTTOM, true, mpX_NORMAL);
    mpScaleY* yaxis = new mpScaleY(wxT("Energy/LightIntensity"), mpALIGN_LEFT, true);
    wxPanel* m_logCt = new wxPanel(m_log, wxID_ANY);
    wxPanel* m_logLCt = new wxPanel(m_logCt, wxID_ANY, wxPoint(-1, -1),
        wxSize(-1, -1), wxBORDER_SUNKEN);
    wxPanel* m_logRCt = new wxPanel(m_logCt, wxID_ANY, wxPoint(-1, -1),
        wxSize(-1, -1), wxBORDER_SUNKEN);
    comLabel = new wxTextCtrl(m_logRCt, wxID_ANY, "Gate: " + com->GetPort() + "\n",
        wxPoint(0, 0), wxSize(-1, 50), wxTE_MULTILINE);
    wxStaticText* m_sliderLable = new wxStaticText(m_logLCt, wxID_ANY, " -Angle adjustment: (o)",
        wxPoint(0, 0), wxSize(120, -1));
    m_slider = new wxSlider(m_logLCt, wxID_ANY, 90, 0, 180, wxPoint(0, 15),
        wxSize(150, -1), wxSL_LABELS);
    Setbutton = new wxButton(m_logLCt, 6668, "Set",
        wxPoint(155, 30), wxSize(50, -1));
    //Font
    wxFont graphFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont sum_font = m_text->GetFont();
    sum_font.SetWeight(wxFONTWEIGHT_BOLD);
    m_text->SetFont(sum_font);
    xaxis->SetFont(graphFont);
    yaxis->SetFont(graphFont);

    //Timer
    static const int INTERVAL = 1000; // milliseconds
    m_timer = new wxTimer(this, 5555);
    m_timer->Start(INTERVAL);


    //SetDrawOutsideMargins
    xaxis->SetDrawOutsideMargins(false);
    yaxis->SetDrawOutsideMargins(false);

    //SetMargins
    m_plot->SetMargins(30, 30, 50, 50);

    //Add layer
    m_plot->AddLayer(xaxis);
    m_plot->AddLayer(yaxis);
    m_plot->AddLayer(vectorLayer);
    
    //Sizers
    wxBoxSizer* parentsz = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* m_logSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* m_logCtSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* m_logRCtSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* topsizer = new wxBoxSizer(wxVERTICAL);

    //SetSizer
    this->SetSizer(topsizer);
    parentpn->SetSizer(parentsz);
    m_log->SetSizer(m_logSizer);
    m_logCt->SetSizer(m_logCtSizer);
    m_logRCt->SetSizer(m_logRCtSizer);

    //BackgroundColor
    m_text->SetBackgroundColour("#afafaf");
    m_logLCt->SetBackgroundColour("#e7e7e7");
    comLabel->SetBackgroundColour("white");

    //Add Sizer
    parentsz->Add(this, 1, wxEXPAND);
    m_logSizer->Add(m_text, 1, wxEXPAND);
    m_logSizer->Add(m_logCt, 11, wxEXPAND);
    m_logCtSizer->Add(m_logLCt, 7, wxEXPAND | wxALL, 0);
    m_logCtSizer->Add(m_logRCt, 5, wxEXPAND | wxALL, 0);
    m_logRCtSizer->Add(comLabel, 1, wxEXPAND | wxALL, 0);
    topsizer->Add(m_plot, 8, wxEXPAND);
    topsizer->Add(m_log, 4, wxEXPAND | wxALL, 1);

    //Enable
    comLabel->Enable(false);
    m_slider->Enable(false);

}
//Functions 
EnergyCharts::~EnergyCharts() {
    m_timer->Stop();

}
void EnergyCharts::onPlus(wxCommandEvent& WXUNUSED(event)) {
    wxPen vectorpen2(*wxRED, 2, wxPENSTYLE_SOLID);
    vectorLayer->SetPen(vectorpen2);
    com->Open();
    m_plot->UpdateAll();

}
void EnergyCharts::onDecrease(wxCommandEvent& WXUNUSED(event)) {
    wxPen vectorpen2(*wxBLUE, 2, wxPENSTYLE_SOLID);
    vectorLayer->SetPen(vectorpen2);
    m_plot->UpdateAll();
}
void EnergyCharts::onSet(wxCommandEvent& WXUNUSED(event)) {
    if (!m_slider->IsEnabled()) {
        m_slider->Enable(true);
        Setbutton->SetLabel("Ok");
    }
    else if (m_slider->IsEnabled()) {
        m_slider->Enable(false);
        Setbutton->SetLabel("Set");
    }
}
void EnergyCharts::OnProgressTimer(wxTimerEvent& WXUNUSED(event)){
    srand(time(NULL));
    now = time(0);
    ltm = gmtime(&now);
    comLabel->Clear();
    comLabel->AppendText("Gate: " + com->GetPort() + "\n");
    comLabel->AppendText("Open: " + to_string(com->IsOpened()) + "\n");
    comLabel->AppendText("Baud Rate: " + to_string(com->GetBaudRate()) + "\n");
    comLabel->AppendText("Day: " + to_string(ltm->tm_mday) + " - " + to_string(ltm->tm_mon + 1) + " - " + to_string(ltm->tm_year + 1900) + "\n");
    comLabel->AppendText("Time: " + to_string(ltm->tm_hour + 7) + "h : " + to_string(ltm->tm_min) + "m : " + to_string(ltm->tm_sec) + "s\n");
    comLabel->AppendText(*fileDir);

    if (com->IsOpened()) {
        if (ltm->tm_sec == 0) {
            vectorx.clear();
            vectory.clear();
            vectorLayer->Clear();
            vectorx.push_back(ltm->tm_sec);
            resy = rand() % (100 - 0 + 1) + 3;
            vectory.push_back(resy);
            vectorLayer->SetData(vectorx, vectory);
        }
        else if (ltm->tm_sec > 0) {
            vectorx.push_back(ltm->tm_sec);
            resy = rand() % (100 - 0 + 1) + 3;
            vectory.push_back(resy);
            vectorLayer->SetContinuity(true);
            vectorLayer->SetData(vectorx, vectory);
        }
        m_plot->Fit();
        m_plot->UpdateAll();
        //
        string_name = to_string(vectorLayer->GetMaxY());
        Excel->writeEx(string_name, fileDir);
        Excel->writeAllDays(fileDir);
    }
    else if (!com->IsOpened()) {
        if (ltm->tm_sec == 0) {
            vectorx.clear();
            vectory.clear();
            vectorLayer->Clear();
            vectorx.push_back(ltm->tm_sec);
            vectory.push_back(0);
            vectorLayer->SetData(vectorx, vectory);
        }
        else if (ltm->tm_sec > 0) {
            vectorx.push_back(ltm->tm_sec);
            resy = 0;
            vectory.push_back(resy);
            vectorLayer->SetContinuity(true);
            vectorLayer->SetData(vectorx, vectory);
        }
            m_plot->Fit();
            m_plot->UpdateAll();
    }
}