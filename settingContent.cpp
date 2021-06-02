#include "settingContent.h"
#include <stdlib.h>     //for using the function sleep

BEGIN_EVENT_TABLE(settingContent, wxPanel)
EVT_BUTTON(339, settingContent::onSetPort)
EVT_BUTTON(340, settingContent::onOpenPort)
EVT_LISTBOX(341, settingContent::onSelect)
END_EVENT_TABLE()
settingContent::settingContent(wxBoxSizer* parent, wxPanel* parentpn, ceSerial* sePort) : wxPanel(parentpn)
{
    //parents setting
    com = sePort;
    NotesParent = parentpn;

    //Sizers
    wxBoxSizer* PanelContentSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* LeftPanelSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* LeftCtSz = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* RightCt1Sz = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* RightCt2Sz = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* setPortPanelSz = new wxBoxSizer(wxHORIZONTAL);

    // Definition 
    wxPanel* LeftPanel = new wxPanel(this, 41, wxPoint(-1, -1), wxSize(0, 0), wxBORDER_SUNKEN);
    RightContent1 = new wxPanel(this, 42, wxPoint(-1, -1), wxSize(0, 0), wxBORDER_SUNKEN);
    RightContent2 = new wxPanel(RightContent1, 42, wxPoint(-1, -1), wxSize(0, 0));
    wxStaticText* m_text = new wxStaticText(LeftPanel, -1, wxT("Settings"),
        wxPoint(0, 0), wxSize(-1, -1), wxALIGN_CENTRE_HORIZONTAL);
    wxPanel* LeftPanelCt = new wxPanel(LeftPanel, 4, wxPoint(-1, -1),
        wxSize(0, 0));
    settingLabels = new wxListBox(LeftPanelCt, 341, wxPoint(-1, -1), wxSize(-1, -1));

    wxPanel* setPortPanel = new wxPanel(RightContent2, 4, wxPoint(-1, -1),
        wxSize(-1, 35));
    wxButton* btnSend = new wxButton(setPortPanel, 339, wxT("Set Port"), wxPoint(-1, -1), wxSize(0, 0));
    txtSend = new wxTextCtrl(setPortPanel, wxID_ANY, com->GetPort(), wxPoint(-1, -1), wxSize(0, 0));
    txtRx = new wxTextCtrl(RightContent2, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(0, 0), wxTE_MULTILINE);
    //lblRx = new wxStaticText(this, ID_LBLRX, wxT("Rx:"), wxPoint(5, 75), wxSize(35, 25));
    //wxButton* btnOpen = new wxButton(setPortPanel, 339, wxT("open Port"), wxPoint(0, 0), wxSize(0, 0));
    wxPanel* openPortPanel = new wxPanel(RightContent2, 4, wxPoint(-1, -1),
        wxSize(-1, -1) );
    openSeBtn = new wxButton(openPortPanel, 340, wxT("Open Port"), wxPoint( 5, -1), wxSize(60, 25));
    

    //Add to Sizers
    parent->Add(this, 15, wxEXPAND | wxBOTTOM, 0);
    PanelContentSizer->Add(LeftPanel, 4, wxEXPAND | wxRight, 1);
    LeftPanelSizer->Add(m_text, 1, wxEXPAND | wxBOTTOM, 0);
    LeftPanelSizer->Add(LeftPanelCt, 40, wxEXPAND | wxBOTTOM, 0);
    PanelContentSizer->Add(RightContent1, 8, wxEXPAND | wxALL, 0);
    LeftCtSz->Add(settingLabels, 1, wxEXPAND | wxBOTTOM, 0);
    setPortPanelSz->Add(btnSend, 2, wxEXPAND | wxLEFT | wxTOP | wxBOTTOM, 5);
    setPortPanelSz->Add(txtSend, 10, wxEXPAND | wxALL, 5);
    RightCt1Sz->Add(RightContent2, 1, wxEXPAND | wxBOTTOM, 0);
    RightCt2Sz->Add(setPortPanel, 1, wxEXPAND | wxBOTTOM, 0);
    RightCt2Sz->Add(openPortPanel, 1, wxEXPAND | wxBOTTOM, 0);
    RightCt2Sz->Add(txtRx, 25, wxEXPAND | wxBOTTOM, 0);
    
    //SetFont
    wxFont sum_font = m_text->GetFont();
    sum_font.SetWeight(wxFONTWEIGHT_BOLD);
    m_text->SetFont(sum_font);

    //SetSizer
    this->SetSizer(PanelContentSizer);
    LeftPanel->SetSizer(LeftPanelSizer);
    LeftPanelCt->SetSizer(LeftCtSz);
    RightContent1->SetSizer(RightCt1Sz);
    RightContent2->SetSizer(RightCt2Sz);
    setPortPanel->SetSizer(setPortPanelSz);

    //AppendString
    settingLabels->AppendString("COM port");
    settingLabels->AppendString("Other Settings");
    settingLabels->SetSelection(0);
    if (com->IsOpened()) {
        txtRx->AppendText(wxString::Format(wxT("Port %s is open.\n"), com->GetPort()));
    }
    else if (!com->IsOpened()) {
        txtRx->AppendText(wxString::Format(wxT("Port %s is not open.\n"), com->GetPort()));
    }

    //BackgroundColor
    m_text->SetBackgroundColour("#e7e7e7");
    settingLabels->SetBackgroundColour("#e9e9e9");
    txtRx->SetBackgroundColour("#ffffff");

    //Enable
    txtSend->Enable(false);
    txtRx->Enable(false);

    //
    /*wxCheckBox* chkRTS = new wxCheckBox(RightContent, wxID_ANY, wxT("RTS"), wxPoint(5, 170), wxDefaultSize);
    wxCheckBox* chkDTR = new wxCheckBox(RightContent, wxID_ANY, wxT("DTR"), wxPoint(55, 170), wxDefaultSize);
    wxCheckBox* chkCTS = new wxCheckBox(RightContent, wxID_ANY, wxT("CTS"), wxPoint(155, 170), wxDefaultSize);
    wxCheckBox* chkDSR = new wxCheckBox(RightContent, wxID_ANY, wxT("DSR"), wxPoint(205, 170), wxDefaultSize);
    wxCheckBox* chkRI = new wxCheckBox(RightContent, wxID_ANY, wxT("RI"), wxPoint(255, 170), wxDefaultSize);
    wxCheckBox* chkCD = new wxCheckBox(RightContent, wxID_ANY, wxT("CD"), wxPoint(305, 170), wxDefaultSize);
    chkCTS->Disable();
    chkDSR->Disable();
    chkRI->Disable();
    chkCD->Disable();*/

}
//Functions
void settingContent::hide() {
    this->Hide();
}
void settingContent::show() {
    this->SetClientSize(this->NotesParent->GetClientSize());
    this->Show();
}

void settingContent::onSelect(wxCommandEvent& WXUNUSED(event)) {
    if (settingLabels->IsSelected(0)) {
        RightContent2->Show();
        RightContent2->SetClientSize(this->RightContent1->GetClientSize());
    }
    if (settingLabels->IsSelected(1)) {
        RightContent2->Hide();
    }
    
}
void settingContent::onSetPort(wxCommandEvent& WXUNUSED(event)) {
    if (com->IsOpened()) {
        wxMessageDialog* dial = new wxMessageDialog(NULL,
            "Close Port fisrt", wxT("Warning"),
            wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }
    else if (!com->IsOpened()) {
        wxString cdev = wxString::Format(wxT("%s"), com->GetPort());
        wxString device = wxGetTextFromUser(wxT("Enter the port"), wxT("Set Port"), cdev);
        if (device.ToStdString().length() > 0) {
            com->SetPort(device.ToStdString());
            txtRx->Clear();
            txtSend->Clear();
            txtRx->AppendText(wxString::Format(wxT("Port %s is not Opened.\n"), com->GetPort()));
            txtSend->AppendText(com->GetPort());
        }
    }
}
void settingContent::onOpenPort(wxCommandEvent& WXUNUSED(event)) {
    if (com->IsOpened()) {
        com->Close();
        openSeBtn->SetLabel(wxT("Open Port"));
        txtRx->Clear();
        txtRx->AppendText(wxString::Format(wxT("Port %s is not Opened.\n"), com->GetPort()));
    }
    else if (!com->IsOpened()) {

        com->Open();
        txtRx->Clear();
        if (com->IsOpened()) {
            txtRx->AppendText(wxString::Format(wxT("Port %s is Opened.\n"), com->GetPort()));
            openSeBtn->SetLabel(wxT("Close Port"));
        }
        else if (!com->IsOpened()) {
            wxMessageDialog* dial = new wxMessageDialog(NULL,
                com->GetPort() + " not enabled" , wxT("Warning"),
                wxOK | wxICON_EXCLAMATION);
            dial->ShowModal();
            txtRx->AppendText(wxString::Format(wxT("Port %s is not Opened.\n"), com->GetPort()));
        }
    }
}