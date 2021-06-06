#include "notesContent.h"
BEGIN_EVENT_TABLE(notesContent, wxPanel)
EVT_BUTTON(555, notesContent::refreshFunc)
EVT_BUTTON(556, notesContent::modifiedFunc)
EVT_BUTTON(557, notesContent::okFunc)
END_EVENT_TABLE()
notesContent::notesContent(wxBoxSizer* parent, wxPanel* parentpn, string* filePath):
    wxPanel(parentpn, 333, wxPoint(-1, -1), wxSize(-1, -1))
{
    //Parents reference
    NotesParent = parentpn;
    fileDir = filePath;
    //Bitmaps
    wxBitmap refresh(wxT("refresh.png"), wxBITMAP_TYPE_PNG);

    //Sizers
    wxBoxSizer* PanelContentSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* LeftPanelSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* RightPanelSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* LCtSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* SearchPnSz = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* btnNotePnSz = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* RCtSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* grid1Sizer = new wxBoxSizer(wxVERTICAL);

    //Definition
    wxPanel* LeftPanel = new wxPanel(this, 12, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN);
    wxPanel* RightContent = new wxPanel(this, 1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN);
    wxStaticText* m_text = new wxStaticText(LeftPanel, -1, wxT("Day"),
        wxPoint(0, 0), wxSize(-1, -1), wxALIGN_CENTRE_HORIZONTAL);
    LeftPanelCt = new wxPanel(LeftPanel, 4, wxPoint(-1, -1),
        wxSize(-1, -1), wxTOP | wxBORDER_SUNKEN);
    wxStaticText* m_text_r = new wxStaticText(RightContent, -1, wxT("Infomations"),
        wxPoint(0, 0), wxSize(-1, -1), wxALIGN_CENTRE_HORIZONTAL);
    wxPanel* RightPanelCt = new wxPanel(RightContent, 4, wxPoint(-1, -1),
        wxSize(-1, -1), wxTOP | wxBORDER_SUNKEN);
    wxPanel* SearchPn = new wxPanel(LeftPanelCt);
    wxSearchCtrl* SearchCtrl = new wxSearchCtrl(SearchPn, wxID_ANY,
        wxT(""), wxPoint(0, 0), wxSize(-1, -1));
    wxBitmapButton* refreshBtn = new wxBitmapButton(SearchPn, 555, refresh);
    wxStaticText* NotesLabel = new wxStaticText(LeftPanelCt, wxID_ANY,
        wxT("\nDay: " + ReadEx->Time() + "\n" + "Max: " + "\n" + "Min: "));
    wxPanel* blank = new wxPanel(LeftPanelCt);
    wxStaticText* TextLabel = new wxStaticText(LeftPanelCt, wxID_ANY, wxT("Note:"));
    Tnote = new wxTextCtrl(LeftPanelCt, wxID_ANY, wxT(""), wxPoint(0, 0), wxSize(0, 0), wxTE_MULTILINE);
    wxPanel* btnNotePn = new wxPanel(LeftPanelCt);
    TnoteBtn1 = new wxButton(btnNotePn, 556, wxT("Modify"),
        wxPoint(0, 0), wxSize(-1, -1));
    TnoteBtn2 = new wxButton(btnNotePn, 557, wxT("Ok"),
        wxPoint(0, 0), wxSize(-1, -1));
    wxNotebook* nb = new wxNotebook(RightPanelCt, -1, wxPoint(-1, -1),
        wxSize(-1, -1), wxNB_BOTTOM);
    wxPanel* grid1 = new wxPanel(nb);
    wxPanel* grid2 = new wxPanel(nb);
    RList = new wxListBox(grid1, wxID_ANY, wxPoint(-1, -1),
        wxSize(this->NotesParent->GetClientSize()));

    //Set Sizers
    this->SetSizer(PanelContentSizer);
    LeftPanel->SetSizer(LeftPanelSizer);
    RightContent->SetSizer(RightPanelSizer);
    LeftPanelCt->SetSizer(LCtSizer);
    SearchPn->SetSizer(SearchPnSz);
    btnNotePn->SetSizer(btnNotePnSz);
    RightPanelCt->SetSizer(RCtSizer);
    grid1->SetSizer(grid1Sizer);

    //Add Sizers 
    parent->Add(this, 15, wxEXPAND | wxBOTTOM, 0);
    PanelContentSizer->Add(LeftPanel, 4, wxEXPAND | wxRight, 1);
    PanelContentSizer->Add(RightContent, 8, wxEXPAND | wxALL, 0);
    LeftPanelSizer->Add(m_text, 1, wxEXPAND | wxBOTTOM, 0);
    LeftPanelSizer->Add(LeftPanelCt, 40, wxEXPAND | wxBOTTOM, 0);
    RightPanelSizer->Add(m_text_r, 1, wxEXPAND | wxBOTTOM, 0);
    RightPanelSizer->Add(RightPanelCt, 40, wxEXPAND | wxBOTTOM, 0);
    SearchPnSz->Add(SearchCtrl, 2, wxEXPAND | wxBOTTOM, 0);
    SearchPnSz->Add(refreshBtn, 1, wxEXPAND | wxBOTTOM, 0);
    btnNotePnSz->Add(TnoteBtn1, 1, wxEXPAND | wxBOTTOM, 0);
    btnNotePnSz->Add(TnoteBtn2, 1, wxEXPAND | wxBOTTOM, 0);
    LCtSizer->Add(SearchPn, 1, wxEXPAND | wxBOTTOM, 0);
    LCtSizer->Add(NotesLabel, 1, wxEXPAND | wxBOTTOM, 0);
    LCtSizer->Add(blank, 25, wxEXPAND | wxBOTTOM, 0);
    LCtSizer->Add(TextLabel, 1, wxEXPAND | wxBOTTOM, 0);
    LCtSizer->Add(Tnote, 15, wxEXPAND | wxBOTTOM, 0);
    LCtSizer->Add(btnNotePn, 1, wxEXPAND | wxBOTTOM, 0);
    RCtSizer->Add(nb, 1, wxEXPAND | wxBOTTOM, 0);
    grid1Sizer->Add(RList, 1, wxEXPAND | wxBOTTOM, 0);

    //BackgroundColours
    m_text->SetBackgroundColour("#e7e7e7");
    m_text_r->SetBackgroundColour("#e7e7e7");
    NotesLabel->SetBackgroundColour("#e9e9e9");
    blank->SetBackgroundColour("#e9e9e9");
    TextLabel->SetBackgroundColour("#afafaf");

    //Font
    wxFont sum_font = m_text->GetFont();
    sum_font.SetWeight(wxFONTWEIGHT_BOLD);
    m_text->SetFont(sum_font);    
    wxFont sum_font_r = m_text_r->GetFont();
    sum_font_r.SetWeight(wxFONTWEIGHT_BOLD);
    m_text_r->SetFont(sum_font_r);

    //Enable
    Tnote->Enable(false);
    TnoteBtn2->Enable(false);
        
    //notebook add pages
    nb->AddPage(grid1, wxT("  Data"));
    nb->AddPage(grid2, wxT("  Chart"));
    
    //Rlist append data
    curDayDir = ReadEx->Time();
    // Get the data from CSV File
    std::vector<std::vector<std::string> > dataList = ReadEx->readEx(curDayDir, fileDir);
    //Print the content of row by row on screen
    for (int i = dataList.size() - 1; i >= 0; i--) {

        RList->AppendString(dataList[i][0] + "\tMuc nang luong: " + dataList[i][1]);
    }
    std::vector<std::string> text_note = ReadEx->readText(curDayDir, fileDir);
    if (text_note.size() != 0) {
        for (int i = 0; i < text_note.size() - 1; i++) {
            Tnote->AppendText(text_note[i] + "\n");
        }
    }
}
//Functions
void notesContent::hide() {
    this->Hide();
}
void notesContent::show() {
    this->SetClientSize(this->NotesParent->GetClientSize());
    this->Show();
}
void notesContent::refreshFunc(wxCommandEvent& WXUNUSED(event)) {
    RList->Clear();
    string fileName = ReadEx->Time();
    // Get the data from CSV File
    std::vector<std::vector<std::string> > dataList = ReadEx->readEx(fileName, fileDir);
    // Print the content of row by row on screen
    for (int i = dataList.size() - 1; i >= 0; i--) {
        RList->AppendString(dataList[i][0] + "\tMuc nang luong: " + dataList[i][1]);
    }
}
void notesContent::modifiedFunc(wxCommandEvent& WXUNUSED(event)) {
    Tnote->Enable(true);
    TnoteBtn1->Enable(false);
    TnoteBtn2->Enable(true);
}
void notesContent::okFunc(wxCommandEvent& WXUNUSED(event)) {
    Tnote->Enable(false);
    TnoteBtn1->Enable(true);
    TnoteBtn2->Enable(false);
    //Convert wxString to string; 
    wxString a = Tnote->GetValue();
    string b = string(a.mb_str(wxConvUTF8));

    writeNote->writeText(curDayDir, fileDir, b);
}