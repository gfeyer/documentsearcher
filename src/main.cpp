#include <iostream>

#include "lucene_api/api.h"
#include "lucene_api/search.h"
#include "lucene_api/index.h"

// WxWidgets
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "ui/noname.h"
#include "logger.h"
#include "app.h"

/*
TODO:
	- Word checkboxes: only create once on new search and use them throughout the session.
	- Refactor settings into its own class rather than reading file from everywhere
*/

class MainApp : public wxApp
{
public:
	// test git
	MainApp() {}
	~MainApp() {}

public:
	bool OnInit();

private:
	App* ui_frame = nullptr;
};

//wxIMPLEMENT_APP(MainApp);
wxIMPLEMENT_APP_CONSOLE(MainApp);		// VS2019: if switching to console app, also change under Linker->System->Subsystem

bool MainApp::OnInit()
{
	//logger::SetLevelTrace();
	logger::SetLevelDebug();
	//logger::WriteToFile("log.txt");

	ui_frame = new App(nullptr);
	ui_frame->SetTitle(VERSION);
	ui_frame->Show();

	//wxIcon mainicon;
	//wxBitmap bitmap(logo4_png);
	//mainicon.CopyFromBitmap(bitmap);
	//ui_frame->SetIcon(mainicon);
	return true;
}

/*int main()
{
    
}*/