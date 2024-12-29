#ifndef _GUI_H
#define _GUI_H

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxCsv.h"
#include "ofxNetwork.h"
#include "extern.h"
#include "ofThread.h"
#include "ofxTimerEventTable.h"
#include "ofxFontStash.h"
#include "ofxImGui.h"
#include "MyTheme.h"

class GUI : public ofThread {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void groupbuttonbanner(int index, string labeltitle, int posx, int posy, int sx, int sy);
	//void groupnumberbanner(int padnum, int posx, int posy, int sx, int sy);
	void clientline(int padnum, int posx, int posy, int sx, int sy);
	void colormark(int r, int g, int b, int posx, int posy, int dim);
	void clientnamebannerbutton(int index, string labeltitle, int posx, int posy, int sx, int sy);
	void clientpwronbanner(int index, string labeltitle, int posx, int posy, int sx, int sy);
	void clientpwroffbanner(int index, string labeltitle, int posx, int posy, int sx, int sy);
	void clientinfoline1banner(int index, string labeltitle, int posx, int posy, int sx, int sy);
	void clientgroupbuttonbanner(int index, string labeltitle, int posx, int posy, int sx, int sy);
	void grouppwronbanner(string labeltitle, int posx, int posy, int sx, int sy);
	void grouppwroffbanner(string labeltitle, int posx, int posy, int sx, int sy);
	void savebuttonbanner(string labeltitle, int posx, int posy, int sx, int sy);
	void loadbuttonbanner(string labeltitle, int posx, int posy, int sx, int sy);
	
	
	void getbannerboxfont30(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontx, int fonty);
	void getbannerboxfont15(string title, int posx, int posy, int r, int g, int b, int fontr, int fontg, int fontb, int sx, int sy, int fontx, int fonty);
	void getbannerboxfont12(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontx, int fonty);
	void getbannerboxfont10(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontr, int fontg, int fontb, int fontx, int fonty);
	void getbannerboxfontbold10(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontx, int fonty);
	void getbannerboxfontcolor10(string title, int posx, int posy, int r, int g, int b, int fontr, int fontg, int fontb, int sx, int sy, int fontx, int fonty);
	void groupnumberbanner(int padnum, int posx, int posy, int r, int g, int b, int sx, int sy);
	
	void getbannerboxfont8(string title, int posx, int posy, int r, int g, int b, int fontr, int fontg, int fontb, int sx, int sy, int fontx, int fonty);
	void getbannerboxfont15(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontx, int fonty);

	void threadedFunction() {
		while (isThreadRunning() != 0) {

		}
		ofSleepMillis(100);    // 180ms
	}
	ofTrueTypeFont verdana8, verdana10, verdana15, verdana12 ,verdana30 , verdanabold10;

	ofxCsv csv;
	ofxCsvRow row;

	ofxTCPServer TCP;
	ofxTCPManager TCPmanager;
	vector <string> storeText;

	string hangulstr, hangulstr1, hangulstr2;
	ofxFontStash font;
	ofxFontStash unicodeFont;
	ofFile datalog;
	ofxDatGuiButton* groupbutton[21];
	ofxDatGuiButton* GROUPCLEARBUTTON;
	ofxDatGuiButton* GROUPAPPLYBUTTON;
	ofxDatGuiButton* GROUPPOPUPAPPLYBUTTON;
	ofxDatGuiButton* GROUPPOPUPCANCELBUTTON;
	ofxDatGuiButton* clientnameline1button[91];
	ofxDatGuiTextInput* groupconfigurationinput[16];      // 
	ofxDatGuiTextInput* clientconfigurationinput[4];
	ofxDatGuiHeader* line1typeHeader[91];
	ofxDatGuiButton* clientpwronbutton[91];
	ofxDatGuiButton* clientpwroffbutton[91];
	ofxDatGuiHeader* line1infoHeader[91];

	ofxDatGuiButton* CLIENTPCBUTTON;
	ofxDatGuiButton* CLIENTPRJBUTTON;
	ofxDatGuiButton* CLIENTRELAYBUTTON;
	ofxDatGuiButton* CLIENTCONTACTBUTTON;
	/*
	ofxDatGuiToggle* CLIENTPCBUTTON;
	ofxDatGuiToggle* CLIENTPRJBUTTON;
	ofxDatGuiToggle* CLIENTRELAYBUTTON;
	ofxDatGuiToggle* CLIENTCONTACTBUTTON;
	*/
	//ofxDatGuiToggle* clientgroupnumberbutton[21];
	ofxDatGuiButton* clientgroupnumberbutton[21];
	ofxDatGuiButton* CLIENTCLEARBUTTON;
	ofxDatGuiButton* CLIENTAPPLYBUTTON;
	ofxDatGuiLabel* blanklabel;
	//ofxDatGuiLabel* blanklabel1;
	ofxDatGuiButton* blanklabel1;
	ofxDatGuiButton* GROUPPWRON;
	ofxDatGuiButton* GROUPPWROFF;
	ofxDatGuiButton* SAVEBUTTON;
	ofxDatGuiButton* LOADBUTTON;
	ofxDatGuiButton* POPUPCLIENTAPPLYBUTTON;
	ofxDatGuiButton* POPUPCLIENTCANCELBUTTON;
	ofxDatGuiButton* POPUPGROUPOK;
	ofxDatGuiButton* POPUPGROUPCANCEL;
	ofxDatGuiButton* POPUPGROUPOFFOK;
	ofxDatGuiButton* POPUPGROUPOFFCANCEL;
	ofxDatGuiButton* POPUPGROUPCLEAROK;       // 그룹에 클리어 이벤트를 위한 팝업 버튼
	ofxDatGuiButton* POPUPGROUPCLEARCANCEL;      // 그룹에 클리어 이벤트 취소 팝업 버튼
	ofxDatGuiButton* POPUPCLIENTCLEAROK;		// 클라이언트 정보 클리어 이벤트 팝업 버튼
	ofxDatGuiButton* POPUPCLIENTCLEARCANCEL;	// 클라이언트 정보 클리어 이벤트 취소 팝업 버튼
	ofxDatGuiButton* DONTREGISTEROK;
	/*--------------------------------*/
	ofxDatGuiButton* ALLBUTTON;
	ofxDatGuiLabel* grouplabel;
	ofxDatGuiLabel* clientlabel;
	void allbuttonEvent(ofxDatGuiButtonEvent e);
	/*--------------------------------*/
	/*--------------------------------*/
	ofxImGui::Gui gui;
	ImVec4 backgroundColor;
	bool show_test_window;
	bool show_another_window;

	float floatValue;
	ofImage imageButtonSource;
	GLuint imageButtonID;

	ofPixels pixelsButtonSource;
	GLuint pixelsButtonID;

	ofTexture textureSource;
	GLuint textureSourceID;

	std::vector<std::string> fileNames;
	std::vector<ofFile> files;
	/*--------------------------------*/
	void groupbannerbuttonevent(ofxDatGuiButtonEvent e);
	void groupclearbuttonevent(ofxDatGuiButtonEvent e);
	void groupapplybuttonevent(ofxDatGuiButtonEvent e);
	void grouppopupbuttonevent(ofxDatGuiButtonEvent e);
	void groupnumberinputEvent(ofxDatGuiTextInputEvent e);
	void groupnameinputEvent(ofxDatGuiTextInputEvent e);
	void sundaypwronevent(ofxDatGuiTextInputEvent e);
	void sundaypwroffevent(ofxDatGuiTextInputEvent e);
	void mondaypwronevent(ofxDatGuiTextInputEvent e);
	void mondaypwroffevent(ofxDatGuiTextInputEvent e);
	void tuesdaypwronevent(ofxDatGuiTextInputEvent e);
	void tuesdaypwroffevent(ofxDatGuiTextInputEvent e);
	void wensedaypwronevent(ofxDatGuiTextInputEvent e);
	void wensedaypwroffevent(ofxDatGuiTextInputEvent e);
	void thursdaypwronevent(ofxDatGuiTextInputEvent e);
	void thursdaypwroffevent(ofxDatGuiTextInputEvent e);
	void fridaypwronevent(ofxDatGuiTextInputEvent e);
	void fridaypwroffevent(ofxDatGuiTextInputEvent e);
	void saturdaypwronevent(ofxDatGuiTextInputEvent e);
	void saturdaypwroffevent(ofxDatGuiTextInputEvent e);
	void clientnameButtonEvent(ofxDatGuiButtonEvent e);
	void clientpwrline1ButtonEvent(ofxDatGuiButtonEvent e);
	void clientnumberinputevent(ofxDatGuiTextInputEvent e);
	void clientnameinputevent(ofxDatGuiTextInputEvent e);
	void clientipaddressinputevent(ofxDatGuiTextInputEvent e);
	void clientinfoinputevent(ofxDatGuiTextInputEvent e);
	//void clientgrouptoggleevent(ofxDatGuiToggleEvent e);
	void clientgrouptoggleevent(ofxDatGuiButtonEvent e);
	//void clientgroupbuttonnumberevent(ofxDatGuiToggleEvent e);
	void clientgroupbuttonnumberevent(ofxDatGuiButtonEvent e);
	void clientclearbuttonEvent(ofxDatGuiButtonEvent e);
	void clientapplybuttonEvent(ofxDatGuiButtonEvent e);
	void onButtonEvent(ofxDatGuiButtonEvent e);
	void popupclientapplyEvent(ofxDatGuiButtonEvent e);
	void popupclientcancelEvent(ofxDatGuiButtonEvent e);
	void onScrollViewEvent(ofxDatGuiScrollViewEvent e);
	void closewindowEvent(ofxDatGuiButtonEvent e);
	void clienttypeline1banner(int index, string labeltitle, int posx, int posy, int sx, int sy);
	/*--------------------------------*/
	ofxTE::ofxTimerEvents events;
	ofxTE::ofxTimerEvents timeover[91];
	//ofxTE::ofxTimerEvents timeover1;
	/*--------------------------------*/
private:
};



#endif