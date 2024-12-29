#include "Gui.h"

string groupbannername[21];
string groupnumbername_pass[21];

string sundaytime_on[21], mondaytime_on[21], tuesdaytime_on[21], wensdaytime_on[21], thursdaytime_on[21], fridaytime_on[21], saturdaytime_on[21];
string sundaytime_off[21], mondaytime_off[21], tuesdaytime_off[21], wensdaytime_off[21], thursdaytime_off[21], fridaytime_off[21], saturdaytime_off[21];

string clientgroupname_pass[91];
string clientgroupipaddress_pass[91];
string clienttypepc_pass[91];
string clientgroupnumber_pass[91];
string clientgroupinfo_pass[91];

string mondaystr[2], mondaystr1[1], mondaystr2[1], mondaystr3[1];
string mondaystroff[2], mondaystroff1[1], mondaystroff2[1], mondaystroff3[1];

string tuesdaystr[2], tuesdaystr1[1], tuesdaystr2[1], tuesdaystr3[1];
string tuesdaystroff[2], tuesdaystroff1[1], tuesdaystroff2[1], tuesdaystroff3[1];

string wensdaystr[2], wensdaystr1[1], wensdaystr2[1], wensdaystr3[1];
string wensdaystroff[2], wensdaystroff1[1], wensdaystroff2[1], wensdaystroff3[1];

string thursdaystr[2], thursdaystr1[1], thursdaystr2[1], thursdaystr3[1];
string thursdaystroff[2], thursdaystroff1[1], thursdaystroff2[1], thursdaystroff3[1];

string fridaystr[2], fridaystr1[1], fridaystr2[1], fridaystr3[1];
string fridaystroff[2], fridaystroff1[1], fridaystroff2[1], fridaystroff3[1];

string groupstron[1];
string groupstroff[1];

string onofftime[21], csvtime[21], csvtime1[21], csvtime2[21];
string csvtimeoff[21], csvtimeoff1[21], csvtimeoff2[21];

string csvdaton[21];
string csvdatoff[21];

string clientline1name[91];
string autodatapacket;
string autodatapacket1;
string datacmd;

int groupconfigflag;
int grouppopupflag;
int groupclearpopupflag;
int clientclearpopupflag;
int popupclientflag;
int clientconfig;

bool trigger;
bool typetrigger;
bool tusedayevent[21];
bool tusedayoffevent[21];
bool wensdayevent[21];
bool wensdayoffevent[21];
bool thursdayevent[21];
bool thursdayoffevent[21];
bool fridayevent[21];
bool fridayoffevent[21];
bool mondayevent[21];
bool mondayoffevent[21];
bool grouponevent[21];
bool groupoffevent[21];
bool logevent[91];
bool logeventoff[91];

int clientstate[91];
int clientstate1[91];

int init_data_load = 1;

string submitlabel[91];

int grouppwronflag;
int popupgrouppwronflag;
int grouppwroffflag;
int popupgrouppwroffflag;

string grouponpacket[91];
string str, str1, str2, tmp;

string groupnumberlabelstr[1];
string grouplist[21];
string checkstate[91];
string timer_f1[91];

int checklogic = 1;
int clientclearflag;
int pwrtimer;
int csv_check_state;
int timeoverCount[91];
int timeover_check_num[91];
int checkconncetflag[91];
bool devicecheck[91];
string clientnumbercopy[91];
string clientnamecopy[91];
string clienttypecopy[91];
string clientinfocopy[91];
string clientipcopy[91];
string clientgroupnumbercopy1[91];
//string clientgroupnumbercopy[91];
string clientgroupnumbercopy;
int indexcountcopy;
int indexcountcopy1[91];

bool eventdataload = true;
bool eventdataload1 = true;
bool notpushbutton = true;
//bool devicestateload = true;
bool devicestateload[91];
bool devicestateloadcopy[91];


int groupnumbercnt;

string groupnumbercopy[91];
string groupnumberstr[91];   // group number string
string groupnumberpwrstr[91];

int counttest;
vector<string>groupbannermatchnumber;
vector<string>splitvector;
vector<string>splitvector1;
vector<string>devicenum;

string splitvectorcopy[1];

string groupdatapacket;
int numcnt;
int copynumbergroup;
int copygrouppwron;
int copygrouppwroff;

int reverseCount[21];
//int reverseCount;

string groupnumberarray[91][21];
string groupnumbepacket[91];

int notRegister;
int notRegister1;


ofRectangle getBitmapStringBoundingBox(string text) {
	vector<string> lines = ofSplitString(text, "\n");
	int maxLineLength = 0;
	for (int i = 0; i < (int)lines.size(); i++) {
		// tabs are not rendered
		const string& line(lines[i]);
		int currentLineLength = 0;
		for (int j = 0; j < (int)line.size(); j++) {
			if (line[j] == '\t') {
				currentLineLength += 8 - (currentLineLength % 8);
			}
			else {
				currentLineLength++;
			}
		}
		maxLineLength = MAX(maxLineLength, currentLineLength);
	}

	int padding = 4;
	int fontSize = 8;
	float leading = 1.7;
	int height = lines.size() * fontSize * leading - 1;
	int width = maxLineLength * fontSize;
	return ofRectangle(0, 0, width, height);
}

// 전송되는 문자를 구분하는 함수 
vector<string> split(string str, char delimiter)
{
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		internal.push_back(temp);
	}
	return internal;
}

void GUI::setup() {
	int groupbannerbuttoninterval = 17;
	int groupbannerbuttoninterval1 = 17;
	int groupbannerbuttoninterval2 = 17;
	int groupbannerbuttoninterval3 = 17;
	int groupbannerbuttoninterval4 = 17;
	
	int clientnameline1interval = 192;      // 149
	int clientnameline1interval1 = 192;
	int clientnameline1interval2 = 192;
	
	int clienttypeline1interval = 192;
	int clienttypeline1interval1 = 192;
	int clienttypeline1interval2 = 192;

	int clientinfoline1interval = 192;
	int clientinfoline2interval = 192;
	int clientinfoline3interval = 192;
	
	int clientpwronline1interval = 192;
	int clientpwronline1interval1 = 192;
	int clientpwronline1interval2 = 192;

	int clientpwroffline1interval = 192;
	int clientpwroffline1interval1 = 192;
	int clientpwroffline1interval2 = 192;

	int clientgroupline1interval = 1137;
	int clientgroupline2interval = 1137;
	int clientgroupline3interval = 1137;
	int clientgroupline4interval = 1137;
	int clientgroupline5interval = 1137;
	
	//ofSetWindowShape(1920,800); 
	ofSetFullscreen(true);
	ofSetWindowPosition(20,30);
	ofBackground(0, 0, 0);
	/*------------------------------------FONT-------------------------------------------*/
	verdana30.load("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);

	verdana15.load("verdana.ttf", 15, true, true);
	verdana15.setLineHeight(34.0f);
	verdana15.setLetterSpacing(1.035);

	verdana12.load("verdana.ttf", 12, true, true);
	verdana12.setLineHeight(34.0f);
	verdana12.setLetterSpacing(1.035);

	verdana10.load("verdana.ttf", 10, true, true);
	verdana10.setLineHeight(34.0f);
	verdana10.setLetterSpacing(1.035);

	verdanabold10.load("VerdanaBold.ttf", 10, true, true);
	verdanabold10.setLineHeight(34.0f);
	verdanabold10.setLetterSpacing(1.035);
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------------------CSV--------------------------------------*/
	ofSetLogLevel("ofxCsv", OF_LOG_VERBOSE);
	csv.load("powermanagerfile.csv");
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------------------TCP/IP--------------------------------------*/
	ofxTCPSettings settings(8000);
	TCP.setup(settings);
	TCP.setMessageDelimiter("\n");
	/*-----------------------------------DATA LOG----------------------------------------*/
	ofSetLogLevel(OF_LOG_VERBOSE);
	gui.setup();
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	//ImGui::GetIO().ConfigFlags |= ImGuicofig;
	//ImGui::GetIO().ConfigFlags |= ImGuicofig
	ImGui::GetIO().MouseDrawCursor = false;     // false 
	//backgroundColor is stored as an ImVec4 type but can handle ofColor
	backgroundColor = ofColor(114, 144, 154);
	show_test_window = true;
	show_another_window = false;
	floatValue = 0.0f;
	//load your own ofImage
	imageButtonSource.load("of.png");
	imageButtonID = gui.loadImage(imageButtonSource);
	//or have the loading done for you if you don't need the ofImage reference
	//imageButtonID = gui.loadImage("of.png");
	//can also use ofPixels in same manner
	ofLoadImage(pixelsButtonSource, "of_upside_down.png");
	pixelsButtonID = gui.loadPixels(pixelsButtonSource);
	//and alt method
	//pixelsButtonID = gui.loadPixels("of_upside_down.png");
	//pass in your own texture reference if you want to keep it
	textureSourceID = gui.loadTexture(textureSource, "of_upside_down.png");
	//or just pass a path
	//textureSourceID = gui.loadTexture("of_upside_down.png");
	ofLogVerbose() << "textureSourceID: " << textureSourceID;
	ofDirectory dataDirectory(ofToDataPath("", true));
	files = dataDirectory.getFiles();
	for (size_t i = 0; i < files.size(); i++) {
		fileNames.push_back(files[i].getFileName());
	}
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------------GROUP LABEL----------------------------------------*/
	grouplabel = new ofxDatGuiLabel("");
	grouplabel->setWidth(333, .0);
	grouplabel->setPosition(1300, 79);

	clientlabel = new ofxDatGuiLabel("");
	clientlabel->setWidth(333, .0);
	clientlabel->setPosition(1300, 253);             // 1350
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------------GROUP BUTTON---------------------------------------*/
	for (int i = 1; i < 5; i++) {
		groupbannerbuttoninterval = ((31 - i) + i) + groupbannerbuttoninterval;
		groupbuttonbanner(i, groupbannername[i], 161, ((30 - i) + i) + groupbannerbuttoninterval, 183, 30);                // 161
	}
	for (int i = 5; i < 9; i++) {
		groupbannerbuttoninterval1 = ((31 - i) + i) + groupbannerbuttoninterval1;
		groupbuttonbanner(i, groupbannername[i], 376, ((30 - i) + i) + groupbannerbuttoninterval1, 183, 30);
	}
	for (int i = 9; i < 13; i++) {
		groupbannerbuttoninterval2 = ((31 - i) + i) + groupbannerbuttoninterval2;
		groupbuttonbanner(i, groupbannername[i], 591, ((30 - i) + i) + groupbannerbuttoninterval2, 183, 30);
	}
	for (int i = 13; i < 17; i++) {
		groupbannerbuttoninterval3 = ((31 - i) + i) + groupbannerbuttoninterval3;
		groupbuttonbanner(i, groupbannername[i], 806, ((30 - i) + i) + groupbannerbuttoninterval3, 183, 30);
	}
	for (int i = 17; i < 21; i++) {
		groupbannerbuttoninterval4 = ((31 - i) + i) + groupbannerbuttoninterval4;
		groupbuttonbanner(i, groupbannername[i], 1021, ((30 - i) + i) + groupbannerbuttoninterval4, 183, 30);
	}
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT NAME BUTTON------------------------------------*/
	for (int i = 1; i < 31; i++) {
		clientnameline1interval = ((26 - i) + i) + clientnameline1interval;
		clientnamebannerbutton(i, clientline1name[i], 68, ((26 - i) + i) + clientnameline1interval, 136, 25);
	}
	for (int i = 31; i < 61; i++) {
		clientnameline1interval1 = ((26 - i) + i) + clientnameline1interval1;
		clientnamebannerbutton(i, clientline1name[i], 470, ((26 - i) + i) + clientnameline1interval1, 136, 25);
	}
	for (int i = 61; i < 91; i++) {
		clientnameline1interval2 = ((26 - i) + i) + clientnameline1interval2;
		clientnamebannerbutton(i, clientline1name[i], 872, ((26 - i) + i) + clientnameline1interval2, 136, 25);
	}
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT TYPE BANNER------------------------------------*/
	for (int i = 1; i < 31; i++) {
		clienttypeline1interval = ((26 - i) + i) + clienttypeline1interval;
		clienttypeline1banner(i, "", 205, ((26 - i) + i) + clienttypeline1interval, 45, 25);
	}
	for (int i = 31; i < 61; i++) {
		clienttypeline1interval1 = ((26 - i) + i) + clienttypeline1interval1;
		clienttypeline1banner(i, "", 607, ((26 - i) + i) + clienttypeline1interval1, 45, 25);
	}
	for (int i = 61; i < 91; i++) {
		clienttypeline1interval2 = ((26 - i) + i) + clienttypeline1interval2;
		clienttypeline1banner(i, "", 1009, ((26 - i) + i) + clienttypeline1interval2, 45, 25);
	}
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT INFO BANNER------------------------------------*/
	for (int i = 1; i < 31; i++) {
		clientinfoline1interval = ((26 - i) + i) + clientinfoline1interval;
		clientinfoline1banner(i, "", 321, ((26 - i) + i) + clientinfoline1interval, 80, 25);
	}
	for (int i = 31; i < 61; i++) {
		clientinfoline2interval = ((26 - i) + i) + clientinfoline2interval;
		clientinfoline1banner(i, "", 723, ((26 - i) + i) + clientinfoline2interval, 80, 25);
	}
	for (int i = 61; i < 91; i++) {
		clientinfoline3interval = ((26 - i) + i) + clientinfoline3interval;
		clientinfoline1banner(i, "", 1125, ((26 - i) + i) + clientinfoline3interval, 80, 25);
	}
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------CLIENT POWER ON DRAW------------------------------------*/
	for (int i = 1; i < 31; i++) {
		clientpwronline1interval = ((26 - i) + i) + clientpwronline1interval;
		clientpwronbanner(i, "ON", 251, ((26 - i) + i) + clientpwronline1interval, 34, 25);
	}
	for (int i = 31; i < 61; i++) {
		clientpwronline1interval1 = ((26 - i) + i) + clientpwronline1interval1;
		clientpwronbanner(i, "ON", 653, ((26 - i) + i) + clientpwronline1interval1, 34, 25);
	}
	for (int i = 61; i < 91; i++) {
		clientpwronline1interval2 = ((26 - i) + i) + clientpwronline1interval2;
		clientpwronbanner(i, "ON", 1055, ((26 - i) + i) + clientpwronline1interval2, 34, 25);
	}
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------CLIENT POWER OFF DRAW------------------------------------*/
	for (int i = 1; i < 31; i++) {
		clientpwroffline1interval = ((26 - i) + i) + clientpwroffline1interval;
		clientpwroffbanner(i, "OFF", 286, ((26 - i) + i) + clientpwroffline1interval, 34, 25);
	}
	for (int i = 31; i < 61; i++) {
		clientpwroffline1interval1 = ((26 - i) + i) + clientpwroffline1interval1;
		clientpwroffbanner(i, "OFF", 688, ((26 - i) + i) + clientpwroffline1interval1, 34, 25);
	}
	for (int i = 61; i < 91; i++) {
		clientpwroffline1interval2 = ((26 - i) + i) + clientpwroffline1interval2;
		clientpwroffbanner(i, "OFF", 1090, ((26 - i) + i) + clientpwroffline1interval2, 34, 25);
	}
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------GROUP CLEAR BUTTON DRAW--------------------------------*/
	GROUPCLEARBUTTON = new ofxDatGuiButton("CLEAR");
	GROUPCLEARBUTTON->setPosition(1205, 158 + 35);
	GROUPCLEARBUTTON->setWidth(96);
	GROUPCLEARBUTTON->setHeight(43);
	GROUPCLEARBUTTON->onButtonEvent(this, &GUI::groupclearbuttonevent);
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------GROUP APPLY BUTTON DRAW--------------------------------*/
	GROUPAPPLYBUTTON = new ofxDatGuiButton("APPLY");
	GROUPAPPLYBUTTON->setPosition(1302, 158 + 35);
	GROUPAPPLYBUTTON->setWidth(333);
	GROUPAPPLYBUTTON->setHeight(43);
	GROUPAPPLYBUTTON->onButtonEvent(this, &GUI::groupapplybuttonevent);
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT PC BUTTON DRAW---------------------------------*/
	CLIENTPCBUTTON = new ofxDatGuiButton("PC");
	CLIENTPCBUTTON->setPosition(1303, 316);
	CLIENTPCBUTTON->setWidth(82);
	CLIENTPCBUTTON->setHeight(15 + 5);
	CLIENTPCBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------CLIENT PROJECTOR BUTTON DRAW----------------------------*/
	CLIENTPRJBUTTON = new ofxDatGuiButton("PRJ");
	CLIENTPRJBUTTON->setPosition(1386, 316);
	CLIENTPRJBUTTON->setWidth(82);
	CLIENTPRJBUTTON->setHeight(15 + 5);
	CLIENTPRJBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT RELAY BUTTON DRAW------------------------------*/
	CLIENTRELAYBUTTON = new ofxDatGuiButton("RELAY");
	CLIENTRELAYBUTTON->setPosition(1469, 316);
	CLIENTRELAYBUTTON->setWidth(82);
	CLIENTRELAYBUTTON->setHeight(15 + 5);
	CLIENTRELAYBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------CLIENT CONTACT BUTTON DRAW---------------------------*/
	CLIENTCONTACTBUTTON = new ofxDatGuiButton("CONTACT");
	CLIENTCONTACTBUTTON->setPosition(1552, 316);
	CLIENTCONTACTBUTTON->setWidth(82);
	CLIENTCONTACTBUTTON->setHeight(15 + 5);
	CLIENTCONTACTBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------------CLIENT GROUP BUTTON DRAW----------------------------*/
	for (int i = 1; i < 5; i++) {
		clientgroupline1interval = ((83 - i) + i) + clientgroupline1interval;
		clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline1interval,337, 82, 15 + 5);    // 82
	}
	for (int i = 5; i < 9; i++) {
		clientgroupline2interval = ((83 - i) + i) + clientgroupline2interval;
		clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline2interval,358, 82, 15 + 5);     
	}
	
	for (int i = 9; i < 13; i++) {
		clientgroupline3interval = ((83 - i) + i) + clientgroupline3interval;
		clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline3interval, 379, 82, 15 + 5);
	}
	
	for (int i = 13; i < 17; i++) {
		clientgroupline4interval = ((83 - i) + i) + clientgroupline4interval;
		clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline4interval, 400, 82, 15 + 5);
	}
	for (int i = 17; i < 21; i++) {
		clientgroupline5interval = ((83 - i) + i) + clientgroupline5interval;
		clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline5interval, 421, 82, 15 + 5);
	}
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------------CLIENT CLEAR BUTTON DRAW----------------------------*/
	CLIENTCLEARBUTTON = new ofxDatGuiButton("CLEAR");
	CLIENTCLEARBUTTON->setPosition(1206, 442 + 21);
	CLIENTCLEARBUTTON->setWidth(96);
	CLIENTCLEARBUTTON->setHeight(43);
	CLIENTCLEARBUTTON->onButtonEvent(this, &GUI::clientclearbuttonEvent);
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------------CLIENT APPLY BUTTON DRAW----------------------------*/
	CLIENTAPPLYBUTTON = new ofxDatGuiButton("APPLY");
	CLIENTAPPLYBUTTON->setPosition(1303, 442 + 21);         // 1303
	CLIENTAPPLYBUTTON->setWidth(333);
	CLIENTAPPLYBUTTON->setHeight(43);
	CLIENTAPPLYBUTTON->onButtonEvent(this, &GUI::clientapplybuttonEvent);
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------------GROUP INPUT-------------------------------------*/
	groupconfigurationinput[1] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[1]->onTextInputEvent(this, &GUI::groupnameinputEvent);
	groupconfigurationinput[1]->setFocused(false);                    // true                          
	groupconfigurationinput[1]->setOpacity(0);
	groupconfigurationinput[1]->setWidth(333, .0);
	groupconfigurationinput[1]->setHeight(20);
	groupconfigurationinput[1]->setPosition(1302, 101);

	groupconfigurationinput[2] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[2]->onTextInputEvent(this, &GUI::sundaypwronevent);
	groupconfigurationinput[2]->setFocused(false);
	groupconfigurationinput[2]->setOpacity(0);
	groupconfigurationinput[2]->setWidth(46 , .0);
	groupconfigurationinput[2]->setHeight(20);
	groupconfigurationinput[2]->setPosition(1304, 147);

	groupconfigurationinput[3] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[3]->onTextInputEvent(this, &GUI::sundaypwroffevent);
	groupconfigurationinput[3]->setFocused(false);
	groupconfigurationinput[3]->setOpacity(0);
	groupconfigurationinput[3]->setWidth(46, .0);
	groupconfigurationinput[3]->setHeight(20);
	groupconfigurationinput[3]->setPosition(1304, 147 + 23);

	groupconfigurationinput[4] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[4]-> onTextInputEvent(this, &GUI::mondaypwronevent);
	groupconfigurationinput[4]->setFocused(false);
	groupconfigurationinput[4]->setOpacity(0);
	groupconfigurationinput[4]->setWidth(46, .0);
	groupconfigurationinput[4]->setHeight(20);
	groupconfigurationinput[4]->setPosition(1351, 147);

	groupconfigurationinput[5] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[5]->onTextInputEvent(this, &GUI::mondaypwroffevent);
	groupconfigurationinput[5]->setFocused(false);
	groupconfigurationinput[5]->setOpacity(0);
	groupconfigurationinput[5]->setWidth(46, .0);
	groupconfigurationinput[5]->setHeight(20);
	groupconfigurationinput[5]->setPosition(1351, 147 + 23);

	groupconfigurationinput[6] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[6]->onTextInputEvent(this, &GUI::tuesdaypwronevent);
	groupconfigurationinput[6]->setFocused(false);
	groupconfigurationinput[6]->setOpacity(0);
	groupconfigurationinput[6]->setWidth(46, .0);
	groupconfigurationinput[6]->setHeight(20);
	groupconfigurationinput[6]->setPosition(1351 + 46, 147);

	groupconfigurationinput[7] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[7]->onTextInputEvent(this, &GUI::tuesdaypwroffevent);
	groupconfigurationinput[7]->setFocused(false);
	groupconfigurationinput[7]->setOpacity(0);
	groupconfigurationinput[7]->setWidth(46, .0);
	groupconfigurationinput[7]->setHeight(20);
	groupconfigurationinput[7]->setPosition(1351 + 46, 147 + 23);

	groupconfigurationinput[8] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[8]->onTextInputEvent(this, &GUI::wensedaypwronevent);
	groupconfigurationinput[8]->setFocused(false);
	groupconfigurationinput[8]->setOpacity(0);
	groupconfigurationinput[8]->setWidth(46, .0);
	groupconfigurationinput[8]->setHeight(20);
	groupconfigurationinput[8]->setPosition(1398 + 46, 147);

	groupconfigurationinput[9] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[9]->onTextInputEvent(this, &GUI::wensedaypwroffevent);
	groupconfigurationinput[9]->setFocused(false);
	groupconfigurationinput[9]->setOpacity(0);
	groupconfigurationinput[9]->setWidth(46, .0);
	groupconfigurationinput[9]->setHeight(20);
	groupconfigurationinput[9]->setPosition(1398 + 46, 147 + 23);

	groupconfigurationinput[10] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[10]->onTextInputEvent(this, &GUI::thursdaypwronevent);
	groupconfigurationinput[10]->setFocused(false);
	groupconfigurationinput[10]->setOpacity(0);
	groupconfigurationinput[10]->setWidth(46, .0);
	groupconfigurationinput[10]->setHeight(20);
	groupconfigurationinput[10]->setPosition(1445 + 46, 147);

	groupconfigurationinput[11] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[11]->onTextInputEvent(this, &GUI::thursdaypwroffevent);
	groupconfigurationinput[11]->setFocused(false);
	groupconfigurationinput[11]->setOpacity(0);
	groupconfigurationinput[11]->setWidth(46, .0);
	groupconfigurationinput[11]->setHeight(20);
	groupconfigurationinput[11]->setPosition(1445 + 46, 147 + 23);

	groupconfigurationinput[12] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[12]->onTextInputEvent(this, &GUI::fridaypwronevent);
	groupconfigurationinput[12]->setFocused(false);
	groupconfigurationinput[12]->setOpacity(0);
	groupconfigurationinput[12]->setWidth(46, .0);
	groupconfigurationinput[12]->setHeight(20);
	groupconfigurationinput[12]->setPosition(1492 + 46, 147);

	groupconfigurationinput[13] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[13]->onTextInputEvent(this, &GUI::fridaypwroffevent);
	groupconfigurationinput[13]->setFocused(false);
	groupconfigurationinput[13]->setOpacity(0);
	groupconfigurationinput[13]->setWidth(46, .0);
	groupconfigurationinput[13]->setHeight(20);
	groupconfigurationinput[13]->setPosition(1492 + 46, 147 + 23);

	groupconfigurationinput[14] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[14]->onTextInputEvent(this, &GUI::saturdaypwronevent);
	groupconfigurationinput[14]->setFocused(false);
	groupconfigurationinput[14]->setOpacity(0);
	groupconfigurationinput[14]->setWidth(46, .0);
	groupconfigurationinput[14]->setHeight(20);
	groupconfigurationinput[14]->setPosition(1539 + 46, 147);

	groupconfigurationinput[15] = new ofxDatGuiTextInput("", "");
	groupconfigurationinput[15]->onTextInputEvent(this, &GUI::saturdaypwroffevent);
	groupconfigurationinput[15]->setFocused(false);
	groupconfigurationinput[15]->setOpacity(0);
	groupconfigurationinput[15]->setWidth(46, .0);
	groupconfigurationinput[15]->setHeight(20);
	groupconfigurationinput[15]->setPosition(1539 + 46, 147 + 23);
	
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------------CLIENT INPUT-------------------------------------*/
	clientconfigurationinput[1] = new ofxDatGuiTextInput("", "");
	clientconfigurationinput[1]->onTextInputEvent(this, &GUI::clientnameinputevent);
	clientconfigurationinput[1]->setFocused(false);
	clientconfigurationinput[1]->setOpacity(0);
	clientconfigurationinput[1]->setWidth(333, .0);
	clientconfigurationinput[1]->setHeight(20);
	clientconfigurationinput[1]->setPosition(1302, 274);

	clientconfigurationinput[2] = new ofxDatGuiTextInput("", "");
	clientconfigurationinput[2]->onTextInputEvent(this, &GUI::clientipaddressinputevent);
	clientconfigurationinput[2]->setFocused(false);
	clientconfigurationinput[2]->setOpacity(0);
	clientconfigurationinput[2]->setWidth(333, .0);
	clientconfigurationinput[2]->setHeight(20);
	clientconfigurationinput[2]->setPosition(1302, 295);

	clientconfigurationinput[3] = new ofxDatGuiTextInput("", "");
	clientconfigurationinput[3]->onTextInputEvent(this, &GUI::clientinfoinputevent);
	clientconfigurationinput[3]->setFocused(false);
	clientconfigurationinput[3]->setOpacity(0);
	clientconfigurationinput[3]->setWidth(333, .0);
	clientconfigurationinput[3]->setHeight(20);
	clientconfigurationinput[3]->setPosition(1302, 442);
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------------SAVE BUTTON--------------------------------------*/
	//blanklabel1 = new ofxDatGuiLabel("CLOSE");
	//blanklabel1->setWidth(430);
	//blanklabel1->setHeight(58);
	//blanklabel1->setPosition(1202, 2);
	
	blanklabel1 = new ofxDatGuiButton("CLOSE");
	blanklabel1->setWidth(430);
	blanklabel1->setHeight(58);
	blanklabel1->setPosition(1202, 2);
	blanklabel1->onButtonEvent(this, &GUI::closewindowEvent);
	
	
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------------CLIENT INPUT-------------------------------------*/
	ALLBUTTON = new ofxDatGuiButton("ALL");
	ALLBUTTON->setPosition(0, 78);
	ALLBUTTON->setWidth(129);
	ALLBUTTON->setHeight(123);
	ALLBUTTON->onButtonEvent(this, &GUI::allbuttonEvent);
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------------GROUP POWER ON-------------------------------------*/
	GROUPPWRON = new ofxDatGuiButton("GROUP PWR ON");
	GROUPPWRON->setPosition(656, 1024);
	GROUPPWRON->setWidth(285 - 11);
	GROUPPWRON->setHeight(55);
	GROUPPWRON->onButtonEvent(this, &GUI::onButtonEvent);
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------------GROUP POWER OFF-------------------------------------*/
	GROUPPWROFF = new ofxDatGuiButton("GROUP PWR OFF");
	GROUPPWROFF->setPosition(943 - 11, 1024);
	GROUPPWROFF->setWidth(285 - 11);
	GROUPPWROFF->setHeight(55);
	GROUPPWROFF->onButtonEvent(this, &GUI::onButtonEvent);
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------GROUP POPUP APPLY / CANCEL------------------------------*/
	GROUPPOPUPAPPLYBUTTON = new ofxDatGuiButton("OK");
	GROUPPOPUPAPPLYBUTTON->setPosition(700, 390);
	GROUPPOPUPAPPLYBUTTON->setWidth(200);
	GROUPPOPUPAPPLYBUTTON->setHeight(50);
	GROUPPOPUPAPPLYBUTTON->onButtonEvent(this, &GUI::grouppopupbuttonevent);

	GROUPPOPUPCANCELBUTTON = new ofxDatGuiButton("CANCEL");
	GROUPPOPUPCANCELBUTTON->setPosition(499, 390);
	GROUPPOPUPCANCELBUTTON->setWidth(200);
	GROUPPOPUPCANCELBUTTON->setHeight(50);
	GROUPPOPUPCANCELBUTTON->onButtonEvent(this, &GUI::grouppopupbuttonevent);
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------CLIENT POPUP APPLY / CANCEL------------------------------*/
	POPUPCLIENTAPPLYBUTTON = new ofxDatGuiButton("OK");
	POPUPCLIENTAPPLYBUTTON->setPosition(700, 390);
	POPUPCLIENTAPPLYBUTTON->setWidth(200);
	POPUPCLIENTAPPLYBUTTON->setHeight(50);
	POPUPCLIENTAPPLYBUTTON->onButtonEvent(this, &GUI::popupclientapplyEvent);

	POPUPCLIENTCANCELBUTTON = new ofxDatGuiButton("CANCEL");
	POPUPCLIENTCANCELBUTTON->setPosition(499, 390);
	POPUPCLIENTCANCELBUTTON->setWidth(200);
	POPUPCLIENTCANCELBUTTON->setHeight(50);
	POPUPCLIENTCANCELBUTTON->onButtonEvent(this, &GUI::popupclientcancelEvent);
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------GROUP POPUP CLEAR OK / CANCEL-----------------------------*/
	POPUPGROUPCLEAROK = new ofxDatGuiButton("OK");
	POPUPGROUPCLEAROK->setPosition(700, 390);
	POPUPGROUPCLEAROK->setWidth(200);
	POPUPGROUPCLEAROK->setHeight(50);
	POPUPGROUPCLEAROK->onButtonEvent(this, &GUI::onButtonEvent);

	POPUPGROUPCLEARCANCEL = new ofxDatGuiButton("CANCEL");
	POPUPGROUPCLEARCANCEL->setPosition(499, 390);
	POPUPGROUPCLEARCANCEL->setWidth(200);
	POPUPGROUPCLEARCANCEL->setHeight(50);
	POPUPGROUPCLEARCANCEL->onButtonEvent(this, &GUI::onButtonEvent);
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------CLIENT POPUP CLEAR OK / CANCEL----------------------------*/
	POPUPCLIENTCLEAROK = new ofxDatGuiButton("OK");
	POPUPCLIENTCLEAROK->setPosition(700, 390);
	POPUPCLIENTCLEAROK->setWidth(200);
	POPUPCLIENTCLEAROK->setHeight(50);
	POPUPCLIENTCLEAROK->onButtonEvent(this, &GUI::onButtonEvent);

	POPUPCLIENTCLEARCANCEL = new ofxDatGuiButton("CANCEL");
	POPUPCLIENTCLEARCANCEL->setPosition(499, 390);
	POPUPCLIENTCLEARCANCEL->setWidth(200);
	POPUPCLIENTCLEARCANCEL->setHeight(50);
	POPUPCLIENTCLEARCANCEL->onButtonEvent(this, &GUI::onButtonEvent);
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------GROUP POPUP PWR ON OK / CANCEL----------------------------*/
	POPUPGROUPOK = new ofxDatGuiButton("OK");
	POPUPGROUPOK->setPosition(700, 390);
	POPUPGROUPOK->setWidth(200);
	POPUPGROUPOK->setHeight(50);
	POPUPGROUPOK->onButtonEvent(this, &GUI::onButtonEvent);

	POPUPGROUPCANCEL = new ofxDatGuiButton("CANCEL");
	POPUPGROUPCANCEL->setPosition(499, 390);
	POPUPGROUPCANCEL->setWidth(200);
	POPUPGROUPCANCEL->setHeight(50);
	POPUPGROUPCANCEL->onButtonEvent(this, &GUI::onButtonEvent);
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------GROUP POPUP PWR OFF OK / CANCEL---------------------------*/
	POPUPGROUPOFFOK = new ofxDatGuiButton("OK");
	POPUPGROUPOFFOK->setPosition(700, 390);
	POPUPGROUPOFFOK->setWidth(200);
	POPUPGROUPOFFOK->setHeight(50);
	POPUPGROUPOFFOK->onButtonEvent(this, &GUI::onButtonEvent);

	POPUPGROUPOFFCANCEL = new ofxDatGuiButton("CANCEL");
	POPUPGROUPOFFCANCEL->setPosition(499, 390);
	POPUPGROUPOFFCANCEL->setWidth(200);
	POPUPGROUPOFFCANCEL->setHeight(50);
	POPUPGROUPOFFCANCEL->onButtonEvent(this, &GUI::onButtonEvent);
	/*-----------------------------------------------------------------------------------*/
}

void GUI::groupclearbuttonevent(ofxDatGuiButtonEvent e) {
	if (e.target == GROUPCLEARBUTTON) {
		groupclearpopupflag = 1;
	}
}

void GUI::getbannerboxfont30(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontx, int fonty) {
	string bannertitle = title;
	ofRectangle rect = getBitmapStringBoundingBox(bannertitle);
	rect.x = posx;
	rect.y = posy;
	ofSetColor(r, g, b);
	ofRect(rect.x, rect.y, sx, sy);
	ofSetColor(ofColor::white);
	verdana30.drawString(bannertitle, rect.x + fontx, rect.y + fonty);
}

void GUI::getbannerboxfont15(string title, int posx, int posy, int r, int g, int b, int fontr, int fontg, int fontb, int sx, int sy, int fontx, int fonty) {
	string bannertitle = title;
	ofRectangle rect = getBitmapStringBoundingBox(bannertitle);
	rect.x = posx;
	rect.y = posy;
	ofSetColor(r, g, b);
	ofRect(rect.x, rect.y, sx, sy);
	ofSetColor(fontr, fontg, fontb);
	verdana15.drawString(bannertitle, rect.x + fontx, rect.y + fonty);
}

void GUI::getbannerboxfont12(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontx, int fonty) {
	string bannertitle = title;
	ofRectangle rect = getBitmapStringBoundingBox(bannertitle);
	rect.x = posx;
	rect.y = posy;
	ofSetColor(r, g, b);
	ofRect(rect.x, rect.y, sx, sy);
	ofSetColor(ofColor::white);
	verdana12.drawString(bannertitle, rect.x + fontx, rect.y + fonty);
}

void GUI::getbannerboxfont10(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontr, int fontg, int fontb ,int fontx, int fonty) {
	string bannertitle = title;
	ofRectangle rect = getBitmapStringBoundingBox(bannertitle);
	rect.x = posx;
	rect.y = posy;
	ofSetColor(r, g, b);
	ofRect(rect.x, rect.y, sx, sy);
	ofSetColor(ofColor::white);
	verdana10.drawString(bannertitle, rect.x + fontx, rect.y + fonty);
}

void GUI::getbannerboxfontbold10(string title, int posx, int posy, int r, int g, int b, int sx, int sy, int fontx, int fonty) {
	string bannertitle = title;
	ofRectangle rect = getBitmapStringBoundingBox(bannertitle);
	rect.x = posx;
	rect.y = posy;
	ofSetColor(r, g, b);
	ofRect(rect.x, rect.y, sx, sy);
	ofSetColor(ofColor::black);
	verdanabold10.drawString(bannertitle, rect.x + fontx, rect.y + fonty);
}

void GUI::getbannerboxfontcolor10(string title, int posx, int posy, int r, int g, int b, int fontr, int fontg, int fontb, int sx, int sy, int fontx, int fonty) {
	string bannertitle = title;
	ofRectangle rect = getBitmapStringBoundingBox(bannertitle);
	rect.x = posx;
	rect.y = posy;
	ofSetColor(r, g, b);
	ofRect(rect.x, rect.y, sx, sy);
	ofSetColor(fontr, fontg, fontb);
	verdana10.drawString(bannertitle, rect.x + fontx, rect.y + fonty);
}

void GUI::groupnumberbanner(int padnum, int posx, int posy, int r, int g, int b,int sx, int sy) {
	for (int pos = 0; pos < padnum * 4; pos += padnum) {
		ofSetColor(r,g,b);
		ofDrawRectangle(posx, posy + pos, sx, sy);
	}
}

void GUI::groupbuttonbanner(int index, string labeltitle, int posx, int posy, int sx, int sy) {
	groupbutton[index] = new ofxDatGuiButton(labeltitle);
	groupbutton[index]->setPosition(posx, posy);
	groupbutton[index]->setWidth(sx);
	groupbutton[index]->setHeight(sy);
	groupbutton[index]->onButtonEvent(this, &GUI::groupbannerbuttonevent);
}

void GUI::clientline(int padnum, int posx, int posy, int sx, int sy) {
	for (int pos = 0; pos < padnum * 30; pos += padnum) {
		ofSetColor(76,71,67);
		ofDrawRectangle(posx, posy + pos, sx, sy);
	}
}

void GUI::colormark(int r, int g, int b, int posx, int posy, int dim) {
	ofSetColor(r,g,b);
	ofDrawCircle(posx,posy,dim);
}

void GUI::clientnamebannerbutton(int index, string labeltitle, int posx, int posy, int sx, int sy) {
	clientnameline1button[index] = new ofxDatGuiButton(labeltitle);
	clientnameline1button[index]->setPosition(posx,posy);
	clientnameline1button[index]->setWidth(sx);
	clientnameline1button[index]->setHeight(sy);
	clientnameline1button[index]->onButtonEvent(this, &GUI::clientnameButtonEvent);
}


void GUI::clienttypeline1banner(int index, string labeltitle, int posx, int posy, int sx, int sy) {
	line1typeHeader[index] = new ofxDatGuiHeader("");
	line1typeHeader[index]->setPosition(posx, posy);
	line1typeHeader[index]->setWidth(sx);
	line1typeHeader[index]->setHeight(sy);
}

void GUI::clientpwronbanner(int index, string labeltitle, int posx, int posy, int sx, int sy) {
	clientpwronbutton[index] = new ofxDatGuiButton(labeltitle);
	clientpwronbutton[index]->setPosition(posx, posy);
	clientpwronbutton[index]->setWidth(sx);
	clientpwronbutton[index]->setHeight(sy);
	clientpwronbutton[index]->onButtonEvent(this, &GUI::clientpwrline1ButtonEvent);
}

void GUI::clientpwroffbanner(int index, string labeltitle, int posx, int posy, int sx, int sy) {
	clientpwroffbutton[index] = new ofxDatGuiButton(labeltitle);
	clientpwroffbutton[index]->setPosition(posx, posy);
	clientpwroffbutton[index]->setWidth(sx);
	clientpwroffbutton[index]->setHeight(sy);
	clientpwroffbutton[index]->onButtonEvent(this, &GUI::clientpwrline1ButtonEvent);
}

void GUI::clientgroupbuttonbanner(int index, string labeltitle, int posx, int posy, int sx, int sy) {
	clientgroupnumberbutton[index] = new ofxDatGuiButton(labeltitle);
	clientgroupnumberbutton[index]->setPosition(posx, posy);
	clientgroupnumberbutton[index]->setWidth(sx);
	clientgroupnumberbutton[index]->setHeight(sy);
	clientgroupnumberbutton[index]->onButtonEvent(this, &GUI::clientgroupbuttonnumberevent);
}


// CLIENT INFO BANNER FUNCTION
void GUI::clientinfoline1banner(int index, string labeltitle, int posx, int posy, int sx, int sy) {
	line1infoHeader[index] = new ofxDatGuiHeader("");
	line1infoHeader[index]->setPosition(posx, posy);
	line1infoHeader[index]->setWidth(sx);
	line1infoHeader[index]->setHeight(sy);
}

// 클라이언트 이름을 입력 하는 함수
void GUI::clientnameinputevent(ofxDatGuiTextInputEvent e) {
	for (int i = 1; i < 91; i++) {
		if (clientconfig == i) {
			clientgroupname_pass[i] = e.text;
		}
	}
}


void GUI::groupbannerbuttonevent(ofxDatGuiButtonEvent e) {
	for (int groupindex = 1; groupindex < 21; groupindex++) {
		if (e.target == groupbutton[groupindex]) {
			ALLBUTTON->setOpacity(1.0);
			//CLIENTAPPLYBUTTON->setOpacity(0.0);
			//CLIENTCLEARBUTTON->setOpacity(0.0);
			clientlabel = new ofxDatGuiLabel("");
			clientlabel->setWidth(333, .0);
			clientlabel->setPosition(1300, 253);
			
			CLIENTPCBUTTON->setOpacity(1.0);
			CLIENTPRJBUTTON->setOpacity(1.0);
			CLIENTRELAYBUTTON->setOpacity(1.0);
			CLIENTCONTACTBUTTON->setOpacity(1.0);

			for (int i = 1; i < 21; i++)clientgroupnumberbutton[i]->setOpacity(1.0);

			clientconfigurationinput[1] = new ofxDatGuiTextInput("", "");
			clientconfigurationinput[1]->onTextInputEvent(this, &GUI::clientnameinputevent);
			clientconfigurationinput[1]->setFocused(false);
			clientconfigurationinput[1]->setOpacity(0);
			clientconfigurationinput[1]->setWidth(333, .0);
			clientconfigurationinput[1]->setHeight(20);
			clientconfigurationinput[1]->setPosition(1302, 274);

			clientconfigurationinput[2] = new ofxDatGuiTextInput("", "");
			clientconfigurationinput[2]->onTextInputEvent(this, &GUI::clientipaddressinputevent);
			clientconfigurationinput[2]->setFocused(false);
			clientconfigurationinput[2]->setOpacity(0);
			clientconfigurationinput[2]->setWidth(333, .0);
			clientconfigurationinput[2]->setHeight(20);
			clientconfigurationinput[2]->setPosition(1302, 295);

			clientconfigurationinput[3] = new ofxDatGuiTextInput("", "");
			clientconfigurationinput[3]->onTextInputEvent(this, &GUI::clientinfoinputevent);
			clientconfigurationinput[3]->setFocused(false);
			clientconfigurationinput[3]->setOpacity(0);
			clientconfigurationinput[3]->setWidth(333, .0);
			clientconfigurationinput[3]->setHeight(20);
			clientconfigurationinput[3]->setPosition(1302, 442);

			CLIENTCLEARBUTTON = new ofxDatGuiButton("");
			CLIENTCLEARBUTTON->setPosition(1176, 296);
			CLIENTCLEARBUTTON->setWidth(75);
			CLIENTCLEARBUTTON->setHeight(38);
			CLIENTCLEARBUTTON->setOpacity(0.0);
			CLIENTCLEARBUTTON->onButtonEvent(this, &GUI::clientclearbuttonEvent);

			CLIENTAPPLYBUTTON = new ofxDatGuiButton("");
			CLIENTAPPLYBUTTON->setPosition(1252, 296);
			CLIENTAPPLYBUTTON->setWidth(244);
			CLIENTAPPLYBUTTON->setHeight(38);
			CLIENTAPPLYBUTTON->setOpacity(0.0);
			CLIENTAPPLYBUTTON->onButtonEvent(this, &GUI::clientapplybuttonEvent);

			groupbutton[groupindex]->setOpacity(0.5);

			eventdataload = false;
			eventdataload1 = false;
			//devicestateload = true;
			indexcountcopy = 0;

			groupconfigflag = groupindex;
			string numberpage = "num:" + ofToString(int(groupindex));

			for (int i = 0; i < csv.getNumRows(); i++) {
				for (int j = 0; j < csv.getNumCols(i); j++) {
					if (numberpage.compare(csv[i][j]) == 0) {
						groupnumbercopy[i] = numberpage;         // 그룹 인덱스 넘버를 검색하고 복사 한다.
						groupbannermatchnumber = ofSplitString(csv[i][j], ":");
						for (int i = 0; i < groupbannermatchnumber.size(); ++i)groupbannermatchnumber[i];

						for (int i = 1; i < 91; i++) {
							clientnameline1button[i]->setLabel("");
							line1infoHeader[i]->setLabel("");
							line1typeHeader[i]->setLabel("");
							clientstate[i] = 0;
							checkstate[i] = "0";
						}
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
								for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
									if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
										vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");    // 클라이언트에 등록된 그룹넘버를 추출
										for (int i = 0; i < clientgroupnumber.size(); ++i) {
											clientgroupnumber[i];
											if (groupbannermatchnumber[1].compare(clientgroupnumber[i]) == 0) {
												//std::cout << clientgroupnumber[i] << endl;
												//std::cout << csv[groupindex1][groupindex2 + 3] << endl;
												indexcountcopy1[indexcountcopy + 1] = indexcountcopy++;

												clientnumbercopy[indexcountcopy] = csv[groupindex1][groupindex2];
												clientnamecopy[indexcountcopy] = csv[groupindex1][groupindex2 + 1];
												clientipcopy[indexcountcopy] = csv[groupindex1][groupindex2 + 2];
												clienttypecopy[indexcountcopy] = csv[groupindex1][groupindex2 + 3];
												clientgroupnumbercopy1[indexcountcopy] = csv[groupindex1][groupindex2 + 4];    // 그룹 단위로 정렬된 그룹넘버 복사

												//std::cout << csv[groupindex1][groupindex2 + 3] << endl;
												//std::cout << clienttypecopy[indexcountcopy] << endl;

												clientnameline1button[indexcountcopy]->setLabel(csv[groupindex1][groupindex2 + 1]);
												line1typeHeader[indexcountcopy]->setLabel(csv[groupindex1][groupindex2 + 3]);
												line1infoHeader[indexcountcopy]->setLabel(csv[groupindex1][groupindex2 + 5]);

												/*
												for (int i = 1; i < 91; i++) {
													if (indexcountcopy == i) {
														devicestateload[indexcountcopy] = false;     // 가상의 인덱스
													}
												}
												*/
												devicestateload[indexcountcopy] = false;

												groupdatapacket = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + clientipcopy[indexcountcopy] + ":" + clienttypecopy[indexcountcopy] + ":";
												for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, groupdatapacket);
											}
										}
									}
								}
							}
						}
						vector<string> groupnumberlabel_vector = ofSplitString(csv[i][j], ":");
						for (int i = 0; i < groupnumberlabel_vector.size(); ++i) {
							groupnumberlabelstr[i] = groupnumberlabel_vector[i];
						}
						grouplabel = new ofxDatGuiLabel(groupnumberlabelstr[1]);
						grouplabel->setWidth(333, .0);
						grouplabel->setPosition(1300, 79);

						groupconfigurationinput[1] = new ofxDatGuiTextInput("", csv[i][j + 1]);
						groupconfigurationinput[1]->onTextInputEvent(this, &GUI::groupnameinputEvent);
						groupconfigurationinput[1]->setFocused(false);
						groupconfigurationinput[1]->setOpacity(0);
						groupconfigurationinput[1]->setWidth(333, .0);
						groupconfigurationinput[1]->setHeight(20);
						groupconfigurationinput[1]->setPosition(1302, 101);
						
						groupconfigurationinput[2] = new ofxDatGuiTextInput("", csv[i][j + 2]);
						groupconfigurationinput[2]->onTextInputEvent(this, &GUI::sundaypwronevent);
						groupconfigurationinput[2]->setFocused(false);
						groupconfigurationinput[2]->setOpacity(0);
						groupconfigurationinput[2]->setWidth(46, .0);
						groupconfigurationinput[2]->setHeight(20);
						groupconfigurationinput[2]->setPosition(1304, 147);
						
						groupconfigurationinput[3] = new ofxDatGuiTextInput("", csv[i][j + 3]);
						groupconfigurationinput[3]->onTextInputEvent(this, &GUI::sundaypwroffevent);
						groupconfigurationinput[3]->setFocused(false);
						groupconfigurationinput[3]->setOpacity(0);
						groupconfigurationinput[3]->setWidth(46, .0);
						groupconfigurationinput[3]->setHeight(20);
						groupconfigurationinput[3]->setPosition(1304, 147 + 23);
						
						groupconfigurationinput[4] = new ofxDatGuiTextInput("", csv[i][j + 4]);
						groupconfigurationinput[4]->onTextInputEvent(this, &GUI::mondaypwronevent);
						groupconfigurationinput[4]->setFocused(false);
						groupconfigurationinput[4]->setOpacity(0);
						groupconfigurationinput[4]->setWidth(46, .0);
						groupconfigurationinput[4]->setHeight(20);
						groupconfigurationinput[4]->setPosition(1351, 147);
						
						groupconfigurationinput[5] = new ofxDatGuiTextInput("", csv[i][j + 5]);
						groupconfigurationinput[5]->onTextInputEvent(this, &GUI::mondaypwroffevent);
						groupconfigurationinput[5]->setFocused(false);
						groupconfigurationinput[5]->setOpacity(0);
						groupconfigurationinput[5]->setWidth(46, .0);
						groupconfigurationinput[5]->setHeight(20);
						groupconfigurationinput[5]->setPosition(1351, 147 + 23);

						groupconfigurationinput[6] = new ofxDatGuiTextInput("", csv[i][j + 6]);
						groupconfigurationinput[6]->onTextInputEvent(this, &GUI::tuesdaypwronevent);
						groupconfigurationinput[6]->setFocused(false);
						groupconfigurationinput[6]->setOpacity(0);
						groupconfigurationinput[6]->setWidth(46, .0);
						groupconfigurationinput[6]->setHeight(20);
						groupconfigurationinput[6]->setPosition(1351 + 46, 147);
						
						groupconfigurationinput[7] = new ofxDatGuiTextInput("", csv[i][j + 7]);
						groupconfigurationinput[7]->onTextInputEvent(this, &GUI::tuesdaypwroffevent);
						groupconfigurationinput[7]->setFocused(false);
						groupconfigurationinput[7]->setOpacity(0);
						groupconfigurationinput[7]->setWidth(46, .0);
						groupconfigurationinput[7]->setHeight(20);
						groupconfigurationinput[7]->setPosition(1351 + 46, 147 + 23);
						
						groupconfigurationinput[8] = new ofxDatGuiTextInput("", csv[i][j + 8]);
						groupconfigurationinput[8]->onTextInputEvent(this, &GUI::wensedaypwronevent);
						groupconfigurationinput[8]->setFocused(false);
						groupconfigurationinput[8]->setOpacity(0);
						groupconfigurationinput[8]->setWidth(46, .0);
						groupconfigurationinput[8]->setHeight(20);
						groupconfigurationinput[8]->setPosition(1398 + 46, 147);
						
						groupconfigurationinput[9] = new ofxDatGuiTextInput("", csv[i][j + 9]);
						groupconfigurationinput[9]->onTextInputEvent(this, &GUI::wensedaypwroffevent);
						groupconfigurationinput[9]->setFocused(false);
						groupconfigurationinput[9]->setOpacity(0);
						groupconfigurationinput[9]->setWidth(46, .0);
						groupconfigurationinput[9]->setHeight(20);
						groupconfigurationinput[9]->setPosition(1398 + 46, 147 + 23);
						
						groupconfigurationinput[10] = new ofxDatGuiTextInput("", csv[i][j + 10]);
						groupconfigurationinput[10]->onTextInputEvent(this, &GUI::thursdaypwronevent);
						groupconfigurationinput[10]->setFocused(false);
						groupconfigurationinput[10]->setOpacity(0);
						groupconfigurationinput[10]->setWidth(46, .0);
						groupconfigurationinput[10]->setHeight(20);
						groupconfigurationinput[10]->setPosition(1445 + 46, 147);

						groupconfigurationinput[11] = new ofxDatGuiTextInput("", csv[i][j + 11]);
						groupconfigurationinput[11]->onTextInputEvent(this, &GUI::thursdaypwroffevent);
						groupconfigurationinput[11]->setFocused(false);
						groupconfigurationinput[11]->setOpacity(0);
						groupconfigurationinput[11]->setWidth(46, .0);
						groupconfigurationinput[11]->setHeight(20);
						groupconfigurationinput[11]->setPosition(1445 + 46, 147 + 23);
						
						groupconfigurationinput[12] = new ofxDatGuiTextInput("", csv[i][j + 12]);
						groupconfigurationinput[12]->onTextInputEvent(this, &GUI::fridaypwronevent);
						groupconfigurationinput[12]->setFocused(false);
						groupconfigurationinput[12]->setOpacity(0);
						groupconfigurationinput[12]->setWidth(46, .0);
						groupconfigurationinput[12]->setHeight(20);
						groupconfigurationinput[12]->setPosition(1492 + 46, 147);
						
						groupconfigurationinput[13] = new ofxDatGuiTextInput("", csv[i][j + 13]);
						groupconfigurationinput[13]->onTextInputEvent(this, &GUI::fridaypwroffevent);
						groupconfigurationinput[13]->setFocused(false);
						groupconfigurationinput[13]->setOpacity(0);
						groupconfigurationinput[13]->setWidth(46, .0);
						groupconfigurationinput[13]->setHeight(20);
						groupconfigurationinput[13]->setPosition(1492 + 46, 147 + 23);
						
						groupconfigurationinput[14] = new ofxDatGuiTextInput("", csv[i][j + 14]);
						groupconfigurationinput[14]->onTextInputEvent(this, &GUI::saturdaypwronevent);
						groupconfigurationinput[14]->setFocused(false);
						groupconfigurationinput[14]->setOpacity(0);
						groupconfigurationinput[14]->setWidth(46, .0);
						groupconfigurationinput[14]->setHeight(20);
						groupconfigurationinput[14]->setPosition(1539 + 46, 147);
						
						groupconfigurationinput[15] = new ofxDatGuiTextInput("", csv[i][j + 15]);
						groupconfigurationinput[15]->onTextInputEvent(this, &GUI::saturdaypwroffevent);
						groupconfigurationinput[15]->setFocused(false);
						groupconfigurationinput[15]->setOpacity(0);
						groupconfigurationinput[15]->setWidth(46, .0);
						groupconfigurationinput[15]->setHeight(20);
						groupconfigurationinput[15]->setPosition(1539 + 46, 147 + 23);
					}
				}
			}
		}
	}
	for (int groupindex = 1; groupindex < 21; groupindex++) {
		if (e.target != groupbutton[groupindex]) {
			groupbutton[groupindex]->setOpacity(1.0);
		}
	}
}

void GUI::closewindowEvent(ofxDatGuiButtonEvent e) {
	if (e.target == blanklabel1) {
		OF_EXIT_APP(0);
	}
}

void GUI::clientnameButtonEvent(ofxDatGuiButtonEvent e) {
	int clientgroupline1interval = 1137;     // 1130      // 947
	int clientgroupline2interval = 1137;    //
	int clientgroupline3interval = 1137;
	int clientgroupline4interval = 1137;
	int clientgroupline5interval = 1137;
	int logiclable = 0;

	for (int buttonindex = 1; buttonindex < 91; buttonindex++) {
		if (e.target == clientnameline1button[buttonindex] && eventdataload == true && notpushbutton == true) {
			CLIENTPCBUTTON = new ofxDatGuiButton("PC");
			CLIENTPCBUTTON->setPosition(1303, 316);
			CLIENTPCBUTTON->setWidth(82);
			CLIENTPCBUTTON->setHeight(15 + 5);
			CLIENTPCBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);

			CLIENTPRJBUTTON = new ofxDatGuiButton("PRJ");
			CLIENTPRJBUTTON->setPosition(1386, 316);
			CLIENTPRJBUTTON->setWidth(82);
			CLIENTPRJBUTTON->setHeight(15 + 5);
			CLIENTPRJBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);

			CLIENTRELAYBUTTON = new ofxDatGuiButton("RELAY");
			CLIENTRELAYBUTTON->setPosition(1469, 316);
			CLIENTRELAYBUTTON->setWidth(82);
			CLIENTRELAYBUTTON->setHeight(15 + 5);
			CLIENTRELAYBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);

			CLIENTCONTACTBUTTON = new ofxDatGuiButton("CONTACT");
			CLIENTCONTACTBUTTON->setPosition(1552, 316);
			CLIENTCONTACTBUTTON->setWidth(82);
			CLIENTCONTACTBUTTON->setHeight(15 + 5);
			CLIENTCONTACTBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);

			for (int i = 1; i < 5; i++) {
				clientgroupline1interval = ((83 - i) + i) + clientgroupline1interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline1interval, 337, 82, 15 + 5);     // 1130 - 183
			}
			for (int i = 5; i < 9; i++) {
				clientgroupline2interval = ((83 - i) + i) + clientgroupline2interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline2interval, 358, 82, 15 + 5);
			}
			for (int i = 9; i < 13; i++) {
				clientgroupline3interval = ((83 - i) + i) + clientgroupline3interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline3interval, 379, 82, 15 + 5);
			}
			for (int i = 13; i < 17; i++) {
				clientgroupline4interval = ((83 - i) + i) + clientgroupline4interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline4interval, 400, 82, 15 + 5);
			}
			for (int i = 17; i < 21; i++) {
				clientgroupline5interval = ((83 - i) + i) + clientgroupline5interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline5interval, 421, 82, 15 + 5);
			}
			clientconfig = buttonindex;

			clientnameline1button[buttonindex]->setOpacity(0.5);

			string numberpage = "dev:" + ofToString(int(buttonindex));
			for (int i = 0; i < csv.getNumRows(); i++) {
				for (int j = 0; j < csv.getNumCols(i); j++) {
					if (numberpage.compare(csv[i][j]) == 0) {
						vector<string> clientlabelnumber = ofSplitString(csv[i][j], ":");
						for (int i = 0; i < clientlabelnumber.size(); ++i)clientlabelnumber[i];
						clientlabel = new ofxDatGuiLabel(clientlabelnumber[1]);
						clientlabel->setWidth(333, .0);
						clientlabel->setPosition(1300, 253);

						clientconfigurationinput[1] = new ofxDatGuiTextInput("", csv[i][j + 1]);
						clientconfigurationinput[1]->onTextInputEvent(this, &GUI::clientnameinputevent);
						clientconfigurationinput[1]->setFocused(false);
						clientconfigurationinput[1]->setOpacity(0);
						clientconfigurationinput[1]->setWidth(333, .0);
						clientconfigurationinput[1]->setHeight(20);
						clientconfigurationinput[1]->setPosition(1302, 274);
						
						clientconfigurationinput[2] = new ofxDatGuiTextInput("", csv[i][j + 2]);
						clientconfigurationinput[2]->onTextInputEvent(this, &GUI::clientipaddressinputevent);
						clientconfigurationinput[2]->setFocused(false);
						clientconfigurationinput[2]->setOpacity(0);
						clientconfigurationinput[2]->setWidth(333, .0);
						clientconfigurationinput[2]->setHeight(20);
						clientconfigurationinput[2]->setPosition(1302, 295);
						
						if (csv[i][j + 3].compare("PC") == 0)CLIENTPCBUTTON->setOpacity(0.2);
						if (csv[i][j + 3].compare("PRJ") == 0)CLIENTPRJBUTTON->setOpacity(0.2);
						if (csv[i][j + 3].compare("RELAY") == 0)CLIENTRELAYBUTTON->setOpacity(0.2);
						if (csv[i][j + 3].compare("CONTACT") == 0)CLIENTCONTACTBUTTON->setOpacity(0.2);

						if (csv[i][j + 4].length() > 0) {
							vector<string>grouplablenumber1 = ofSplitString(csv[i][j + 4], ":");
							for (int i = 0; i < grouplablenumber1.size(); ++i)grouplablenumber1[i];
							for (int count = 1; count < 21; count++) {
								if (grouplablenumber1[count].compare(ofToString(int(count))) == 0) {
									//clientgroupnumberbutton[ofToInt(grouplablenumber1[count])]->setChecked(true);
									clientgroupnumberbutton[ofToInt(grouplablenumber1[count])]->setOpacity(0.2);
								}
								if (grouplablenumber1[count].compare(" ") == 0) {                                           // " "
									//clientgroupnumberbutton[ofToInt(grouplablenumber1[count])]->setChecked(false);
									clientgroupnumberbutton[ofToInt(grouplablenumber1[count])]->setOpacity(1.0);
								}
							}
						}
						clientconfigurationinput[3] = new ofxDatGuiTextInput("", csv[i][j + 5]);
						clientconfigurationinput[3]->onTextInputEvent(this, &GUI::clientinfoinputevent);
						clientconfigurationinput[3]->setFocused(false);
						clientconfigurationinput[3]->setOpacity(0);
						clientconfigurationinput[3]->setWidth(333, .0);
						clientconfigurationinput[3]->setHeight(20);
						clientconfigurationinput[3]->setPosition(1302, 442);
					}
				}
			}
		}
		if (e.target == clientnameline1button[buttonindex] && eventdataload == false) {
			clientconfig == buttonindex;
			indexcountcopy = 0;

			clientnameline1button[buttonindex]->setOpacity(0.5);

			CLIENTPCBUTTON = new ofxDatGuiButton("PC");
			CLIENTPCBUTTON->setPosition(1303, 316);
			CLIENTPCBUTTON->setWidth(82);
			CLIENTPCBUTTON->setHeight(15 + 5);
			CLIENTPCBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);

			CLIENTPRJBUTTON = new ofxDatGuiButton("PRJ");
			CLIENTPRJBUTTON->setPosition(1386, 316);
			CLIENTPRJBUTTON->setWidth(82);
			CLIENTPRJBUTTON->setHeight(15 + 5);
			CLIENTPRJBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);

			CLIENTRELAYBUTTON = new ofxDatGuiButton("RELAY");
			CLIENTRELAYBUTTON->setPosition(1469, 316);
			CLIENTRELAYBUTTON->setWidth(82);
			CLIENTRELAYBUTTON->setHeight(15 + 5);
			CLIENTRELAYBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);

			CLIENTCONTACTBUTTON = new ofxDatGuiButton("CONTACT");
			CLIENTCONTACTBUTTON->setPosition(1552, 316);
			CLIENTCONTACTBUTTON->setWidth(82);
			CLIENTCONTACTBUTTON->setHeight(15 + 5);
			CLIENTCONTACTBUTTON->onButtonEvent(this, &GUI::clientgrouptoggleevent);

			for (int i = 1; i < 5; i++) {
				clientgroupline1interval = ((83 - i) + i) + clientgroupline1interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline1interval, 337, 82, 15 + 5);
			}
			for (int i = 5; i < 9; i++) {
				clientgroupline2interval = ((83 - i) + i) + clientgroupline2interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline2interval, 358, 82, 15 + 5);
			}
			for (int i = 9; i < 13; i++) {
				clientgroupline3interval = ((83 - i) + i) + clientgroupline3interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline3interval, 379, 82, 15 + 5);
			}
			for (int i = 13; i < 17; i++) {
				clientgroupline4interval = ((83 - i) + i) + clientgroupline4interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline4interval, 400, 82, 15 + 5);
			}
			for (int i = 17; i < 21; i++) {
				clientgroupline5interval = ((83 - i) + i) + clientgroupline5interval;
				clientgroupbuttonbanner(i, ofToString(int(i)), ((83 - i) + i) + clientgroupline5interval, 421, 82, 15 + 5);
			}

			clientlabel = new ofxDatGuiLabel(ofToString(int(buttonindex)));
			clientlabel->setWidth(333, .0);
			clientlabel->setPosition(1300, 253);

			string numberpage1 = "dev:" + ofToString(int(indexcountcopy1[buttonindex] + 1));

			for (int searchindex = 0; searchindex < csv.getNumRows(); searchindex++) {
				for (int searchindex1 = 0; searchindex1 < csv.getNumCols(searchindex); searchindex1++) {
					for (int indexy = 1; indexy < 91; indexy++) {
						if (buttonindex == indexy) {
							vector<string>grouplablenumber1 = ofSplitString(clientgroupnumbercopy1[indexy], ":");
							for (int i = 0; i < grouplablenumber1.size(); ++i) {
								grouplablenumber1[i];
								if (ofToString(int(groupconfigflag)).compare(grouplablenumber1[i]) == 0) {
									if (numberpage1.compare(csv[searchindex][searchindex1]) == 0) {
										clientconfigurationinput[1] = new ofxDatGuiTextInput("", clientnamecopy[buttonindex]);
										clientconfigurationinput[1]->onTextInputEvent(this, &GUI::clientnameinputevent);
										clientconfigurationinput[1]->setFocused(false);
										clientconfigurationinput[1]->setOpacity(0);
										clientconfigurationinput[1]->setWidth(333, .0);
										clientconfigurationinput[1]->setHeight(20);
										clientconfigurationinput[1]->setPosition(1302, 274);
										
										clientconfigurationinput[2] = new ofxDatGuiTextInput("", clientipcopy[buttonindex]);
										clientconfigurationinput[2]->onTextInputEvent(this, &GUI::clientipaddressinputevent);
										clientconfigurationinput[2]->setFocused(false);
										clientconfigurationinput[2]->setOpacity(0);
										clientconfigurationinput[2]->setWidth(333, .0);
										clientconfigurationinput[2]->setHeight(20);
										clientconfigurationinput[2]->setPosition(1302, 295);
										
										if (clienttypecopy[buttonindex].compare("PC") == 0)CLIENTPCBUTTON->setOpacity(0.2);
										if (clienttypecopy[buttonindex].compare("PRJ") == 0)CLIENTPRJBUTTON->setOpacity(0.2);
										if (clienttypecopy[buttonindex].compare("RELAY") == 0)CLIENTRELAYBUTTON->setOpacity(0.2);
										if (clienttypecopy[buttonindex].compare("CONTACT") == 0)CLIENTCONTACTBUTTON->setOpacity(0.2);

										if (clientgroupnumbercopy1[buttonindex].length() > 0) {
											vector<string>grouplablenumber1 = ofSplitString(clientgroupnumbercopy1[buttonindex], ":");
											for (int i = 0; i < grouplablenumber1.size(); ++i)grouplablenumber1[i];
											for (int count = 1; count < 21; count++) {
												if (grouplablenumber1[count].compare(ofToString(int(count))) == 0) {
													//clientgroupnumberbutton[ofToInt(grouplablenumber1[count])]->setChecked(true);
													clientgroupnumberbutton[ofToInt(grouplablenumber1[count])]->setOpacity(0.2);
													//reverseCount[count] = 1;
													reverseCount[count] = 1;
												}
												if (grouplablenumber1[count].compare(" ") == 0) {
													//clientgroupnumberbutton[ofToInt(grouplablenumber1[count])]->setChecked(false);
													clientgroupnumberbutton[ofToInt(grouplablenumber1[count])]->setOpacity(1.0);
													reverseCount[count] = 0;
												}
											}
										}
										clientconfigurationinput[3] = new ofxDatGuiTextInput("", clientinfocopy[buttonindex]);
										clientconfigurationinput[3]->onTextInputEvent(this, &GUI::clientinfoinputevent);
										clientconfigurationinput[3]->setFocused(false);
										clientconfigurationinput[3]->setOpacity(0);
										clientconfigurationinput[3]->setWidth(333, .0);
										clientconfigurationinput[3]->setHeight(20);
										clientconfigurationinput[3]->setPosition(1302, 442);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int buttonindex = 1; buttonindex < 91; buttonindex++) {
		if (e.target != clientnameline1button[buttonindex] && eventdataload == true) {
			clientnameline1button[buttonindex]->setOpacity(1.0);
		}
		if (e.target != clientnameline1button[buttonindex] && eventdataload == false) {
			clientnameline1button[buttonindex]->setOpacity(1.0);
		}
	}
}

void GUI::clientpwrline1ButtonEvent(ofxDatGuiButtonEvent e) {
	int searchindex, searchindex1 = 0;
	string groupnumberstr;
	string clientnamedat;
	string clientipdat;
	string clienttypedat;
#if 1
	for (int i = 1; i < 91; i++) {
		if (e.target == clientpwronbutton[i]) {
			logevent[i] = false;
			devicecheck[i] = false;

			string numberpage = "dev:" + ofToString(int(i));
			string numberpage1 = "dev:" + ofToString(int(indexcountcopy1[i] + 1));

			for (int searchindex = 0; searchindex < csv.getNumRows(); searchindex++) {
				for (searchindex1 = 0; searchindex1 < csv.getNumCols(searchindex); searchindex1++) {
					if (numberpage.compare(csv[searchindex][searchindex1]) == 0 && logevent[i] == false && eventdataload == true) {
						autodatapacket = ":" + ofToString(int(0)) + ":" + ofToString(int(i)) + ":" + csv[searchindex][searchindex1 + 2] + ":" + csv[searchindex][searchindex1 + 3] + ":" + "on" + ":";
						//std::cout << autodatapacket << endl;
						for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket);
						logevent[i] = true;
					}
					for (int indexy = 1; indexy < 91; indexy++) {
						if (i == indexy && logevent[i] == false && eventdataload == false) {
							groupnumberpwrstr[indexy] = clientgroupnumbercopy1[indexy];
							if (groupnumberpwrstr[indexy].compare(csv[searchindex][searchindex1]) == 0)
							{
								vector<string>grouplablenumber1 = ofSplitString(csv[searchindex][searchindex1], ":");
								for (int i = 0; i < grouplablenumber1.size(); ++i) {
									grouplablenumber1[i];
									if (ofToString(int(groupconfigflag)).compare(grouplablenumber1[i]) == 0) {
										copygrouppwron = ofToInt(grouplablenumber1[i]);
									}
								}
								if (groupconfigflag == copygrouppwron) {
									autodatapacket = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy1[i] + 1)) + ":" + csv[searchindex][searchindex1 - 2] + ":" + csv[searchindex][searchindex1 - 1] + ":" + "on" + ":";
									std::cout << autodatapacket << endl;
									for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket);
									logevent[i] = true;
								}
							}
						}
					}
				}
			}
		}
		if (e.target == clientpwroffbutton[i]) {
			logeventoff[i] = false;
			devicecheck[i] = false;

			string numberpage = "dev:" + ofToString(int(i));
			string numberpage1 = "dev:" + ofToString(int(indexcountcopy1[i] + 1));

			for (int searchindex = 0; searchindex < csv.getNumRows(); searchindex++) {
				for (searchindex1 = 0; searchindex1 < csv.getNumCols(searchindex); searchindex1++) {
					if (numberpage.compare(csv[searchindex][searchindex1]) == 0 && logeventoff[i] == false && eventdataload == true) {
						autodatapacket = ":" + ofToString(int(0)) + ":" + ofToString(int(i)) + ":" + csv[searchindex][searchindex1 + 2] + ":" + csv[searchindex][searchindex1 + 3] + ":" + "off" + ":";
						for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket);
						logeventoff[i] = true;
					}
					for (int indexy = 1; indexy < 91; indexy++) {
						if (i == indexy && logeventoff[i] == false && eventdataload == false) {
							groupnumberpwrstr[indexy] = clientgroupnumbercopy1[indexy];
							if (groupnumberpwrstr[indexy].compare(csv[searchindex][searchindex1]) == 0)
							{
								vector<string>grouplablenumber1 = ofSplitString(csv[searchindex][searchindex1], ":");
								for (int i = 0; i < grouplablenumber1.size(); ++i) {
									grouplablenumber1[i];
									if (ofToString(int(groupconfigflag)).compare(grouplablenumber1[i]) == 0) {
										copygrouppwroff = ofToInt(grouplablenumber1[i]);
									}
								}
								if (groupconfigflag == copygrouppwroff) {
									autodatapacket = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy1[i] + 1)) + ":" + csv[searchindex][searchindex1 - 2] + ":" + csv[searchindex][searchindex1 - 1] + ":" + "off" + ":";
									std::cout << autodatapacket << endl;
									for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket);
									logeventoff[i] = true;
								}
							}
						}
					}
				}
			}
			//checklogic = 0;  // 장비의 상태를 구분하는 변수
		}
	}
#endif
}

void GUI::groupapplybuttonevent(ofxDatGuiButtonEvent e) {
	if (e.target == GROUPAPPLYBUTTON) {
		grouppopupflag = 1;
	}
}

void GUI::clientgrouptoggleevent(ofxDatGuiButtonEvent e) {
	if (e.target == CLIENTPCBUTTON) {
		CLIENTPCBUTTON->setOpacity(0.2);
		CLIENTPRJBUTTON->setOpacity(1.0);
		CLIENTRELAYBUTTON->setOpacity(1.0);
		CLIENTCONTACTBUTTON->setOpacity(1.0);
		for (int i = 1; i < 91; i++) {
			if (clientconfig == i) {
				clienttypepc_pass[i] = "PC";
			}
		}
	}
	if (e.target == CLIENTPRJBUTTON) {
		CLIENTPRJBUTTON->setOpacity(0.2);
		CLIENTPCBUTTON->setOpacity(1.0);
		CLIENTRELAYBUTTON->setOpacity(1.0);
		CLIENTCONTACTBUTTON->setOpacity(1.0);
		for (int i = 1; i < 91; i++) {
			if (clientconfig == i) {
				clienttypepc_pass[i] = "PRJ";
			}
		}
	}
	if (e.target == CLIENTRELAYBUTTON) {
		CLIENTRELAYBUTTON->setOpacity(0.2);
		CLIENTPRJBUTTON->setOpacity(1.0);
		CLIENTPCBUTTON->setOpacity(1.0);
		CLIENTCONTACTBUTTON->setOpacity(1.0);
		for (int i = 1; i < 91; i++) {
			if (clientconfig == i) {
				clienttypepc_pass[i] = "RELAY";
			}
		}
	}
	if (e.target == CLIENTCONTACTBUTTON) {
		CLIENTCONTACTBUTTON->setOpacity(0.2);
		CLIENTRELAYBUTTON->setOpacity(1.0);
		CLIENTPRJBUTTON->setOpacity(1.0);
		CLIENTPCBUTTON->setOpacity(1.0);
		for (int i = 1; i < 91; i++) {
			if (clientconfig == i) {
				clienttypepc_pass[i] = "CONTACT";
			}
		}
	}
}

void GUI::clientgroupbuttonnumberevent(ofxDatGuiButtonEvent e) {
	for (int groupindex = 1; groupindex < 21; groupindex++) {
		if (e.target == clientgroupnumberbutton[groupindex]) {
			reverseCount[groupindex]++;
			if (reverseCount[groupindex] == 1) {
				clientgroupnumberbutton[groupindex]->setOpacity(0.2);
				groupnumberarray[clientconfig][groupindex] = ofToString(int(groupindex));
				string numberstr = "num1:";
				clientgroupnumber_pass[clientconfig] = numberstr + groupnumberarray[clientconfig][1] + ":" + groupnumberarray[clientconfig][2] + ":" + groupnumberarray[clientconfig][3] + ":" + groupnumberarray[clientconfig][4] + ":" + groupnumberarray[clientconfig][5]
					+ ":" + groupnumberarray[clientconfig][6] + ":" + groupnumberarray[clientconfig][7] + ":" + groupnumberarray[clientconfig][8] + ":" + groupnumberarray[clientconfig][9] + ":" + groupnumberarray[clientconfig][10] + ":" + groupnumberarray[clientconfig][11]
					+ ":" + groupnumberarray[clientconfig][12] + ":" + groupnumberarray[clientconfig][13] + ":" + groupnumberarray[clientconfig][14] + ":" + groupnumberarray[clientconfig][15] + ":" + groupnumberarray[clientconfig][16] + ":" + groupnumberarray[clientconfig][17]
					+ ":" + groupnumberarray[clientconfig][18] + ":" + groupnumberarray[clientconfig][19] + ":" + groupnumberarray[clientconfig][20] + ":" + "0";
			}
			if (reverseCount[groupindex] == 2) {
				clientgroupnumberbutton[groupindex]->setOpacity(1.0);
				groupnumberarray[clientconfig][groupindex] = ofToString(int(" "));
				string numberstr = "num1:";
				clientgroupnumber_pass[clientconfig] = numberstr + groupnumberarray[clientconfig][1] + ":" + groupnumberarray[clientconfig][2] + ":" + groupnumberarray[clientconfig][3] + ":" + groupnumberarray[clientconfig][4] + ":" + groupnumberarray[clientconfig][5]
					+ ":" + groupnumberarray[clientconfig][6] + ":" + groupnumberarray[clientconfig][7] + ":" + groupnumberarray[clientconfig][8] + ":" + groupnumberarray[clientconfig][9] + ":" + groupnumberarray[clientconfig][10] + ":" + groupnumberarray[clientconfig][11]
					+ ":" + groupnumberarray[clientconfig][12] + ":" + groupnumberarray[clientconfig][13] + ":" + groupnumberarray[clientconfig][14] + ":" + groupnumberarray[clientconfig][15] + ":" + groupnumberarray[clientconfig][16] + ":" + groupnumberarray[clientconfig][17]
					+ ":" + groupnumberarray[clientconfig][18] + ":" + groupnumberarray[clientconfig][19] + ":" + groupnumberarray[clientconfig][20] + ":" + " ";
				reverseCount[groupindex] = 0;
			}
		}
	}
}

void GUI::clientclearbuttonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == CLIENTCLEARBUTTON && eventdataload == true) {
		clientclearpopupflag = 1;
	}
}

void GUI::clientapplybuttonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == CLIENTAPPLYBUTTON && eventdataload == true) {
		popupclientflag = 1;
	}
}

void GUI::groupnameinputEvent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			groupnumbername_pass[i] = e.text;
		}
	}
}

void GUI::sundaypwronevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			sundaytime_on[i] = e.text;
		}
	}
}

void GUI::sundaypwroffevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			sundaytime_off[i] = e.text;
		}
	}
}

void GUI::mondaypwronevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			mondaytime_on[i] = e.text;
		}
	}
}

void GUI::mondaypwroffevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			mondaytime_off[i] = e.text;
		}
	}
}

void GUI::tuesdaypwronevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			tuesdaytime_on[i] = e.text;
		}
	}
}

void GUI::tuesdaypwroffevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			tuesdaytime_off[i] = e.text;
		}
	}
}

void GUI::wensedaypwronevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			wensdaytime_on[i] = e.text;
		}
	}
}

void GUI::wensedaypwroffevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			wensdaytime_off[i] = e.text;
		}
	}
}

void GUI::thursdaypwronevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			thursdaytime_on[i] = e.text;
		}
	}
}

void GUI::thursdaypwroffevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			thursdaytime_off[i] = e.text;
		}
	}
}

void GUI::fridaypwronevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			fridaytime_on[i] = e.text;
		}
	}
}

void GUI::fridaypwroffevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			fridaytime_off[i] = e.text;
		}
	}
}

void GUI::saturdaypwronevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			saturdaytime_on[i] = e.text;
		}
	}
}

void GUI::saturdaypwroffevent(ofxDatGuiTextInputEvent e) {
	for (int i = 0; i < 21; i++) {
		if (groupconfigflag == i) {
			saturdaytime_off[i] = e.text;
		}
	}
}

void GUI::clientipaddressinputevent(ofxDatGuiTextInputEvent e) {
	for (int i = 1; i < 91; i++) {
		if (clientconfig == i) {
			clientgroupipaddress_pass[i] = e.text;
		}
	}
}

void GUI::clientinfoinputevent(ofxDatGuiTextInputEvent e) {
	for (int i = 1; i < 91; i++) {
		if (clientconfig == i) {
			clientgroupinfo_pass[i] = e.text;
		}
	}
}

void GUI::allbuttonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == ALLBUTTON) {
		eventdataload = true;                   // 디바이스 상태값을 구분 하기 위한 변수  true
		eventdataload1 = true;                  // 그룹 단위 전원을 구분하기 위한 변수 true
		notpushbutton = true;
		//devicestateload = false;
		//init_data_load = 1;
		groupconfigflag = 0;
		ALLBUTTON->setOpacity(0.2);

		clientlabel = new ofxDatGuiLabel("0");
		clientlabel->setWidth(333, .0);
		clientlabel->setPosition(1300, 253);

		CLIENTPCBUTTON->setOpacity(1.0);
		CLIENTPRJBUTTON->setOpacity(1.0);
		CLIENTRELAYBUTTON->setOpacity(1.0);
		CLIENTCONTACTBUTTON->setOpacity(1.0);

		for (int i = 1; i < 21; i++)clientgroupnumberbutton[i]->setOpacity(1.0);
		
		CLIENTCLEARBUTTON = new ofxDatGuiButton("CLEAR");
		CLIENTCLEARBUTTON->setPosition(1206, 442 + 21);
		CLIENTCLEARBUTTON->setWidth(96);
		CLIENTCLEARBUTTON->setHeight(43);
		CLIENTCLEARBUTTON->setOpacity(1.0);
		CLIENTCLEARBUTTON->onButtonEvent(this, &GUI::clientclearbuttonEvent);

		CLIENTAPPLYBUTTON = new ofxDatGuiButton("APPLY");
		CLIENTAPPLYBUTTON->setPosition(1303, 442 + 21);
		CLIENTAPPLYBUTTON->setWidth(333);
		CLIENTAPPLYBUTTON->setHeight(43);
		CLIENTAPPLYBUTTON->setOpacity(1.0);
		CLIENTAPPLYBUTTON->onButtonEvent(this, &GUI::clientapplybuttonEvent);

		
		clientconfigurationinput[1] = new ofxDatGuiTextInput("", "");
		clientconfigurationinput[1]->onTextInputEvent(this, &GUI::clientnameinputevent);
		clientconfigurationinput[1]->setFocused(false);
		clientconfigurationinput[1]->setOpacity(0);
		clientconfigurationinput[1]->setWidth(333, .0);
		clientconfigurationinput[1]->setHeight(20);
		clientconfigurationinput[1]->setPosition(1302, 274);

		clientconfigurationinput[2] = new ofxDatGuiTextInput("", "");
		clientconfigurationinput[2]->onTextInputEvent(this, &GUI::clientipaddressinputevent);
		clientconfigurationinput[2]->setFocused(false);
		clientconfigurationinput[2]->setOpacity(0);
		clientconfigurationinput[2]->setWidth(333, .0);
		clientconfigurationinput[2]->setHeight(20);
		clientconfigurationinput[2]->setPosition(1302, 295);

		clientconfigurationinput[3] = new ofxDatGuiTextInput("", "");
		clientconfigurationinput[3]->onTextInputEvent(this, &GUI::clientinfoinputevent);
		clientconfigurationinput[3]->setFocused(false);
		clientconfigurationinput[3]->setOpacity(0);
		clientconfigurationinput[3]->setWidth(333, .0);
		clientconfigurationinput[3]->setHeight(20);
		clientconfigurationinput[3]->setPosition(1302, 442);


		for (int i = 1; i < 21; i++)groupbutton[i]->setOpacity(1.0);
		for (int i = 1; i < 91; i++) {
			clientstate[i] = 0;
			checkstate[i] = "0";
			clientnameline1button[i]->setOpacity(1.0);
		}
		/*client information load*/
		for (int index = 1; index < 91; index++) {
			string numberpage = "dev:" + ofToString(int(index));
			for (int index1 = 0; index1 < csv.getNumRows(); index1++) {
				for (int index2 = 0; index2 < csv.getNumCols(index1); index2++) {
					if (numberpage.compare(csv[index1][index2]) == 0) {
						if (csv[index1][index2 + 6].compare("0") == 0) {
							devicenum = ofSplitString(csv[index1][index2], ":");
							for (int i = 0; i < devicenum.size(); ++i)devicenum[i];
							for (int i = 1; i < 91; i++) {
								if (ofToInt(devicenum[1]) == i) {
									std::cout << i << endl;
									devicestateload[i] = true;
								}
							}
						}
						clienttypepc_pass[index] = csv[index1][index2 + 3];			// device type 
						clientgroupnumber_pass[index] = csv[index1][index2 + 4];    // client/group number

						splitvector = ofSplitString(csv[index1][index2], ":");
						for (int i = 0; i < splitvector.size(); ++i)splitvector[i];

						splitvector1 = ofSplitString(clientgroupnumber_pass[index], ":");
						for (int i = 0; i < splitvector1.size(); ++i) {
							groupnumberarray[index][i] = splitvector1[i];
							string numheader = "num1:";
							// number 1 ~ 91
							groupnumbepacket[index] = numheader + groupnumberarray[index][1] + ":" + groupnumberarray[index][2] + ":" + groupnumberarray[index][3] + ":" + groupnumberarray[index][4] + ":" + groupnumberarray[index][5]
								+ ":" + groupnumberarray[index][6] + ":" + groupnumberarray[index][7] + ":" + groupnumberarray[index][8] + ":" + groupnumberarray[index][9] + ":" + groupnumberarray[index][10] + ":" + groupnumberarray[index][11]
								+ ":" + groupnumberarray[index][12] + ":" + groupnumberarray[index][13] + ":" + groupnumberarray[index][14] + ":" + groupnumberarray[index][15] + ":" + groupnumberarray[index][16] + ":" + groupnumberarray[index][17]
								+ ":" + groupnumberarray[index][18] + ":" + groupnumberarray[index][19] + ":" + groupnumberarray[index][20];
							//std::cout << index << ":" << groupnumbepacket[index] << endl;
						}

						//:GROUPNUMBER:CLIENTNUMBER:CLIENTIP:CLIENTTYPE:
						string devicestetastr = ":" + ofToString(int(0)) + ":" + splitvector[1] + ":" + csv[index1][index2 + 2] + ":" + csv[index1][index2 + 3] + ":";
						for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, devicestetastr);

						clientnameline1button[index]->setLabel(csv[index1][index2 + 1]);
						line1typeHeader[index]->setLabel(csv[index1][index2 + 3]);
						line1infoHeader[index]->setLabel(csv[index1][index2 + 5]);    // 

						clientstate[index] = index;
						checkstate[index] = csv[index1][index2 + 6];
					}
				}
			}
		}

		string numberpage1 = "num:" + ofToString(int(groupconfigflag));
		for (int index1 = 0; index1 < csv.getNumRows(); index1++) {
			for (int index2 = 0; index2 < csv.getNumCols(index1); index2++) {
				if (numberpage1.compare(csv[index1][index2]) == 0) {
					grouplabel = new ofxDatGuiLabel(ofToString(int(groupconfigflag)));
					grouplabel->setWidth(333, .0);
					grouplabel->setPosition(1300, 79);

					groupconfigurationinput[1] = new ofxDatGuiTextInput("", csv[index1][index2 + 1]);
					groupconfigurationinput[1]->onTextInputEvent(this, &GUI::groupnameinputEvent);
					groupconfigurationinput[1]->setFocused(false);
					groupconfigurationinput[1]->setOpacity(0);
					groupconfigurationinput[1]->setWidth(333, .0);
					groupconfigurationinput[1]->setHeight(20);
					groupconfigurationinput[1]->setPosition(1302, 101);
					
					groupconfigurationinput[2] = new ofxDatGuiTextInput("", csv[index1][index2 + 2]);
					groupconfigurationinput[2]->onTextInputEvent(this, &GUI::sundaypwronevent);
					groupconfigurationinput[2]->setFocused(false);
					groupconfigurationinput[2]->setOpacity(0);
					groupconfigurationinput[2]->setWidth(46, .0);
					groupconfigurationinput[2]->setHeight(20);
					groupconfigurationinput[2]->setPosition(1304, 147);

					groupconfigurationinput[3] = new ofxDatGuiTextInput("", csv[index1][index2 + 3]);
					groupconfigurationinput[3]->onTextInputEvent(this, &GUI::sundaypwroffevent);
					groupconfigurationinput[3]->setFocused(false);
					groupconfigurationinput[3]->setOpacity(0);
					groupconfigurationinput[3]->setWidth(46, .0);
					groupconfigurationinput[3]->setHeight(20);
					groupconfigurationinput[3]->setPosition(1304, 147 + 23);
					

					groupconfigurationinput[4] = new ofxDatGuiTextInput("", csv[index1][index2 + 4]);
					groupconfigurationinput[4]->onTextInputEvent(this, &GUI::mondaypwronevent);
					groupconfigurationinput[4]->setFocused(false);
					groupconfigurationinput[4]->setOpacity(0);
					groupconfigurationinput[4]->setWidth(46, .0);
					groupconfigurationinput[4]->setHeight(20);
					groupconfigurationinput[4]->setPosition(1351, 147);

					groupconfigurationinput[5] = new ofxDatGuiTextInput("", csv[index1][index2 + 5]);
					groupconfigurationinput[5]->onTextInputEvent(this, &GUI::mondaypwroffevent);
					groupconfigurationinput[5]->setFocused(false);
					groupconfigurationinput[5]->setOpacity(0);
					groupconfigurationinput[5]->setWidth(46, .0);
					groupconfigurationinput[5]->setHeight(20);
					groupconfigurationinput[5]->setPosition(1351, 147 + 23);
					
					groupconfigurationinput[6] = new ofxDatGuiTextInput("", csv[index1][index2 + 6]);
					groupconfigurationinput[6]->onTextInputEvent(this, &GUI::tuesdaypwronevent);
					groupconfigurationinput[6]->setFocused(false);
					groupconfigurationinput[6]->setOpacity(0);
					groupconfigurationinput[6]->setWidth(46, .0);
					groupconfigurationinput[6]->setHeight(20);
					groupconfigurationinput[6]->setPosition(1351 + 46, 147);
					
					groupconfigurationinput[7] = new ofxDatGuiTextInput("", csv[index1][index2 + 7]);
					groupconfigurationinput[7]->onTextInputEvent(this, &GUI::tuesdaypwroffevent);
					groupconfigurationinput[7]->setFocused(false);
					groupconfigurationinput[7]->setOpacity(0);
					groupconfigurationinput[7]->setWidth(46, .0);
					groupconfigurationinput[7]->setHeight(20);
					groupconfigurationinput[7]->setPosition(1351 + 46, 147 + 23);
					
					groupconfigurationinput[8] = new ofxDatGuiTextInput("", csv[index1][index2 + 8]);
					groupconfigurationinput[8]->onTextInputEvent(this, &GUI::wensedaypwronevent);
					groupconfigurationinput[8]->setFocused(false);
					groupconfigurationinput[8]->setOpacity(0);
					groupconfigurationinput[8]->setWidth(46, .0);
					groupconfigurationinput[8]->setHeight(20);
					groupconfigurationinput[8]->setPosition(1398 + 46, 147);
					
					groupconfigurationinput[9] = new ofxDatGuiTextInput("", csv[index1][index2 + 9]);
					groupconfigurationinput[9]->onTextInputEvent(this, &GUI::wensedaypwroffevent);
					groupconfigurationinput[9]->setFocused(false);
					groupconfigurationinput[9]->setOpacity(0);
					groupconfigurationinput[9]->setWidth(46, .0);
					groupconfigurationinput[9]->setHeight(20);
					groupconfigurationinput[9]->setPosition(1398 + 46, 147 + 23);
					
					groupconfigurationinput[10] = new ofxDatGuiTextInput("", csv[index1][index2 + 10]);
					groupconfigurationinput[10]->onTextInputEvent(this, &GUI::thursdaypwronevent);
					groupconfigurationinput[10]->setFocused(false);
					groupconfigurationinput[10]->setOpacity(0);
					groupconfigurationinput[10]->setWidth(46, .0);
					groupconfigurationinput[10]->setHeight(20);
					groupconfigurationinput[10]->setPosition(1445 + 46, 147);

					groupconfigurationinput[11] = new ofxDatGuiTextInput("", csv[index1][index2 + 11]);
					groupconfigurationinput[11]->onTextInputEvent(this, &GUI::thursdaypwroffevent);
					groupconfigurationinput[11]->setFocused(false);
					groupconfigurationinput[11]->setOpacity(0);
					groupconfigurationinput[11]->setWidth(46, .0);
					groupconfigurationinput[11]->setHeight(20);
					groupconfigurationinput[11]->setPosition(1445 + 46, 147 + 23);

					groupconfigurationinput[12] = new ofxDatGuiTextInput("", csv[index1][index2 + 12]);
					groupconfigurationinput[12]->onTextInputEvent(this, &GUI::fridaypwronevent);
					groupconfigurationinput[12]->setFocused(false);
					groupconfigurationinput[12]->setOpacity(0);
					groupconfigurationinput[12]->setWidth(46, .0);
					groupconfigurationinput[12]->setHeight(20);
					groupconfigurationinput[12]->setPosition(1492 + 46, 147);

					groupconfigurationinput[13] = new ofxDatGuiTextInput("", csv[index1][index2 + 13]);
					groupconfigurationinput[13]->onTextInputEvent(this, &GUI::fridaypwroffevent);
					groupconfigurationinput[13]->setFocused(false);
					groupconfigurationinput[13]->setOpacity(0);
					groupconfigurationinput[13]->setWidth(46, .0);
					groupconfigurationinput[13]->setHeight(20);
					groupconfigurationinput[13]->setPosition(1492 + 46, 147 + 23);

					groupconfigurationinput[14] = new ofxDatGuiTextInput("", csv[index1][index2 + 14]);
					groupconfigurationinput[14]->onTextInputEvent(this, &GUI::saturdaypwronevent);
					groupconfigurationinput[14]->setFocused(false);
					groupconfigurationinput[14]->setOpacity(0);
					groupconfigurationinput[14]->setWidth(46, .0);
					groupconfigurationinput[14]->setHeight(20);
					groupconfigurationinput[14]->setPosition(1539 + 46, 147);

					groupconfigurationinput[15] = new ofxDatGuiTextInput("", csv[index1][index2 + 15]);
					groupconfigurationinput[15]->onTextInputEvent(this, &GUI::saturdaypwroffevent);
					groupconfigurationinput[15]->setFocused(false);
					groupconfigurationinput[15]->setOpacity(0);
					groupconfigurationinput[15]->setWidth(46, .0);
					groupconfigurationinput[15]->setHeight(20);
					groupconfigurationinput[15]->setPosition(1539 + 46, 147 + 23);
				}
			}
		}
		for (int index = 1; index < 21; index++) {
			string numberpage2 = "num:" + ofToString(int(index));
			for (int index1 = 0; index1 < csv.getNumRows(); index1++) {
				for (int index2 = 0; index2 < csv.getNumCols(index1); index2++) {
					if (numberpage2.compare(csv[index1][index2]) == 0) {
						groupbutton[index]->setLabel(csv[index1][index2 + 1]);
					}
				}
			}
		}
		/*--------------------------------------*/
		//grouplabel = new ofxDatGuiLabel(ofToString(int(groupconfigflag)));
		//grouplabel->setPosition(1252, 56);
		//grouplabel->setWidth(244, .0);
		/*--------------------------------------*/
		//checklogic = 0;
		//std::cout << "all button event" << endl;
		//for (int i = 1; i < 91; i++)clientnameline1button[i]->setLabel(clientgroupname_pass[i]);
		//for (int i = 1; i < 91; i++)line1typeHeader[i]->setLabel(clienttypepc_pass[i]);
		//for (int i = 1; i < 91; i++)line1infoHeader[i]->setLabel(clientgroupinfo_pass[i]);
	}
}

void GUI::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == GROUPPWRON) {
		grouppwronflag = 1;
	}
	if (e.target == GROUPPWROFF) {
		grouppwroffflag = 1;
	}
	if (e.target == POPUPGROUPCANCEL) {
		grouppwronflag = 0;
	}
	if (e.target == POPUPGROUPOK) {
		for (int i = 1; i < 21; i++) {
			grouponevent[i] = false;
			popupgrouppwronflag = 1;
		}
	}
	if (e.target == POPUPGROUPOFFCANCEL) {
		grouppwroffflag = 0;
	}
	if (e.target == POPUPGROUPOFFOK) {
		for (int i = 1; i < 21; i++) {
			groupoffevent[i] = false;
			popupgrouppwroffflag = 1;
		}
	}
	if (e.target == POPUPGROUPCLEARCANCEL) {
		groupclearpopupflag = 0;
	}
	if (e.target == POPUPGROUPCLEAROK) {
		for (int i = 0; i < 21; i++) {
			if (groupconfigflag == i) {
				string numberpage = "num:" + ofToString(int(i));
				for (int index = 0; index < csv.getNumRows(); index++) {
					for (int index1 = 0; index1 < csv.getNumCols(index); index1++) {
						if (numberpage.compare(csv[index][index1]) == 0) {
							for (int index2 = 1; index2 < 16; index2++) {
								csv[index][index1 + index2] = "";

								row.addString(csv[index][index1 + index2]);
								csv.save("powermanagerfile.csv");
							}
							if (groupconfigflag != 0)groupbutton[i]->setLabel("");

							groupconfigurationinput[1] = new ofxDatGuiTextInput("", csv[index][index1 + 1]);
							groupconfigurationinput[1]->onTextInputEvent(this, &GUI::groupnameinputEvent);
							groupconfigurationinput[1]->setFocused(false);
							groupconfigurationinput[1]->setOpacity(0);
							groupconfigurationinput[1]->setWidth(333, .0);
							groupconfigurationinput[1]->setHeight(20);
							groupconfigurationinput[1]->setPosition(1302, 101);
							
							groupconfigurationinput[2] = new ofxDatGuiTextInput("", csv[index][index1 + 2]);
							groupconfigurationinput[2]->onTextInputEvent(this, &GUI::sundaypwronevent);
							groupconfigurationinput[2]->setFocused(false);
							groupconfigurationinput[2]->setOpacity(0);
							groupconfigurationinput[2]->setWidth(46, .0);
							groupconfigurationinput[2]->setHeight(20);
							groupconfigurationinput[2]->setPosition(1304, 147);

							groupconfigurationinput[3] = new ofxDatGuiTextInput("", csv[index][index1 + 3]);
							groupconfigurationinput[3]->onTextInputEvent(this, &GUI::sundaypwroffevent);
							groupconfigurationinput[3]->setFocused(false);
							groupconfigurationinput[3]->setOpacity(0);
							groupconfigurationinput[3]->setWidth(46, .0);
							groupconfigurationinput[3]->setHeight(20);
							groupconfigurationinput[3]->setPosition(1304, 147 + 23);


							groupconfigurationinput[4] = new ofxDatGuiTextInput("", csv[index][index1 + 4]);
							groupconfigurationinput[4]->onTextInputEvent(this, &GUI::mondaypwronevent);
							groupconfigurationinput[4]->setFocused(false);
							groupconfigurationinput[4]->setOpacity(0);
							groupconfigurationinput[4]->setWidth(46, .0);
							groupconfigurationinput[4]->setHeight(20);
							groupconfigurationinput[4]->setPosition(1351, 147);

							groupconfigurationinput[5] = new ofxDatGuiTextInput("", csv[index][index1 + 5]);
							groupconfigurationinput[5]->onTextInputEvent(this, &GUI::mondaypwroffevent);
							groupconfigurationinput[5]->setFocused(false);
							groupconfigurationinput[5]->setOpacity(0);
							groupconfigurationinput[5]->setWidth(46, .0);
							groupconfigurationinput[5]->setHeight(20);
							groupconfigurationinput[5]->setPosition(1351, 147 + 23);


							groupconfigurationinput[6] = new ofxDatGuiTextInput("", csv[index][index1 + 6]);
							groupconfigurationinput[6]->onTextInputEvent(this, &GUI::tuesdaypwronevent);
							groupconfigurationinput[6]->setFocused(false);
							groupconfigurationinput[6]->setOpacity(0);
							groupconfigurationinput[6]->setWidth(46, .0);
							groupconfigurationinput[6]->setHeight(20);
							groupconfigurationinput[6]->setPosition(1351 + 46, 147);

							groupconfigurationinput[7] = new ofxDatGuiTextInput("", csv[index][index1 + 7]);
							groupconfigurationinput[7]->onTextInputEvent(this, &GUI::tuesdaypwroffevent);
							groupconfigurationinput[7]->setFocused(false);
							groupconfigurationinput[7]->setOpacity(0);
							groupconfigurationinput[7]->setWidth(46, .0);
							groupconfigurationinput[7]->setHeight(20);
							groupconfigurationinput[7]->setPosition(1351 + 46, 147 + 23);

							groupconfigurationinput[8] = new ofxDatGuiTextInput("", csv[index][index1 + 8]);
							groupconfigurationinput[8]->onTextInputEvent(this, &GUI::wensedaypwronevent);
							groupconfigurationinput[8]->setFocused(false);
							groupconfigurationinput[8]->setOpacity(0);
							groupconfigurationinput[8]->setWidth(46, .0);
							groupconfigurationinput[8]->setHeight(20);
							groupconfigurationinput[8]->setPosition(1398 + 46, 147);

							groupconfigurationinput[9] = new ofxDatGuiTextInput("", csv[index][index1 + 9]);
							groupconfigurationinput[9]->onTextInputEvent(this, &GUI::wensedaypwroffevent);
							groupconfigurationinput[9]->setFocused(false);
							groupconfigurationinput[9]->setOpacity(0);
							groupconfigurationinput[9]->setWidth(46, .0);
							groupconfigurationinput[9]->setHeight(20);
							groupconfigurationinput[9]->setPosition(1398 + 46, 147 + 23);


							groupconfigurationinput[10] = new ofxDatGuiTextInput("", csv[index][index1 + 10]);
							groupconfigurationinput[10]->onTextInputEvent(this, &GUI::thursdaypwronevent);
							groupconfigurationinput[10]->setFocused(false);
							groupconfigurationinput[10]->setOpacity(0);
							groupconfigurationinput[10]->setWidth(46, .0);
							groupconfigurationinput[10]->setHeight(20);
							groupconfigurationinput[10]->setPosition(1445 + 46, 147);

							groupconfigurationinput[11] = new ofxDatGuiTextInput("", csv[index][index1 + 11]);
							groupconfigurationinput[11]->onTextInputEvent(this, &GUI::thursdaypwroffevent);
							groupconfigurationinput[11]->setFocused(false);
							groupconfigurationinput[11]->setOpacity(0);
							groupconfigurationinput[11]->setWidth(46, .0);
							groupconfigurationinput[11]->setHeight(20);
							groupconfigurationinput[11]->setPosition(1445 + 46, 147 + 23);

							groupconfigurationinput[12] = new ofxDatGuiTextInput("", csv[index][index1 + 12]);
							groupconfigurationinput[12]->onTextInputEvent(this, &GUI::fridaypwronevent);
							groupconfigurationinput[12]->setFocused(false);
							groupconfigurationinput[12]->setOpacity(0);
							groupconfigurationinput[12]->setWidth(46, .0);
							groupconfigurationinput[12]->setHeight(20);
							groupconfigurationinput[12]->setPosition(1492 + 46, 147);


							groupconfigurationinput[13] = new ofxDatGuiTextInput("", csv[index][index1 + 13]);
							groupconfigurationinput[13]->onTextInputEvent(this, &GUI::fridaypwroffevent);
							groupconfigurationinput[13]->setFocused(false);
							groupconfigurationinput[13]->setOpacity(0);
							groupconfigurationinput[13]->setWidth(46, .0);
							groupconfigurationinput[13]->setHeight(20);
							groupconfigurationinput[13]->setPosition(1492 + 46, 147 + 23);

							groupconfigurationinput[14] = new ofxDatGuiTextInput("", csv[index][index1 + 14]);
							groupconfigurationinput[14]->onTextInputEvent(this, &GUI::saturdaypwronevent);
							groupconfigurationinput[14]->setFocused(false);
							groupconfigurationinput[14]->setOpacity(0);
							groupconfigurationinput[14]->setWidth(46, .0);
							groupconfigurationinput[14]->setHeight(20);
							groupconfigurationinput[14]->setPosition(1539 + 46, 147);

							groupconfigurationinput[15] = new ofxDatGuiTextInput("", csv[index][index1 + 15]);
							groupconfigurationinput[15]->onTextInputEvent(this, &GUI::saturdaypwroffevent);
							groupconfigurationinput[15]->setFocused(false);
							groupconfigurationinput[15]->setOpacity(0);
							groupconfigurationinput[15]->setWidth(46, .0);
							groupconfigurationinput[15]->setHeight(20);
							groupconfigurationinput[15]->setPosition(1539 + 46, 147 + 23);

							groupclearpopupflag = 0;
						}
					}
				}
			}
		}
#if 0
		for (int i = 0; i < 21; i++) {
			if (groupconfigflag == i) {
				string numberpage = "num:" + ofToString(int(i));
				for (int index = 0; index < csv.getNumRows(); index++) {
					for (int index1 = 0; index1 < csv.getNumCols(index); index1++) {
						if (numberpage.compare(csv[index][index1]) == 0) {
							//for (int index2 = 1; index2 < 16; index2++) {
								//csv[index][index1 + index2] = "";
								//row.addString(csv[index][index1 + index2]);
							//}
							groupbutton[i]->setLabel("");

							groupconfigurationinput[1] = new ofxDatGuiTextInput("", csv[index][index1 + 1]);
							groupconfigurationinput[1]->onTextInputEvent(this, &GUI::groupnameinputEvent);
							groupconfigurationinput[1]->setFocused(false);
							groupconfigurationinput[1]->setWidth(244, .0);
							groupconfigurationinput[1]->setPosition(1252, 68);

							groupconfigurationinput[2] = new ofxDatGuiTextInput("", csv[index][index1 + 2]);
							groupconfigurationinput[2]->onTextInputEvent(this, &GUI::sundaypwronevent);
							groupconfigurationinput[2]->setFocused(false);
							groupconfigurationinput[2]->setWidth(34, .0);
							groupconfigurationinput[2]->setPosition(1252, 92);

							groupconfigurationinput[3] = new ofxDatGuiTextInput("", csv[index][index1 + 3]);
							groupconfigurationinput[3]->onTextInputEvent(this, &GUI::sundaypwroffevent);
							groupconfigurationinput[3]->setFocused(false);
							groupconfigurationinput[3]->setWidth(34, .0);
							groupconfigurationinput[3]->setPosition(1252, 104);

							groupconfigurationinput[4] = new ofxDatGuiTextInput("", csv[index][index1 + 4]);
							groupconfigurationinput[4]->onTextInputEvent(this, &GUI::mondaypwronevent);
							groupconfigurationinput[4]->setFocused(false);
							groupconfigurationinput[4]->setWidth(34, .0);
							groupconfigurationinput[4]->setPosition(1287, 92);

							groupconfigurationinput[5] = new ofxDatGuiTextInput("", csv[index][index1 + 5]);
							groupconfigurationinput[5]->onTextInputEvent(this, &GUI::mondaypwroffevent);
							groupconfigurationinput[5]->setFocused(false);
							groupconfigurationinput[5]->setWidth(34, .0);
							groupconfigurationinput[5]->setPosition(1287, 104);

							groupconfigurationinput[6] = new ofxDatGuiTextInput("", csv[index][index1 + 6]);
							groupconfigurationinput[6]->onTextInputEvent(this, &GUI::tuesdaypwronevent);
							groupconfigurationinput[6]->setFocused(false);
							groupconfigurationinput[6]->setWidth(34, .0);
							groupconfigurationinput[6]->setPosition(1322, 92);

							groupconfigurationinput[7] = new ofxDatGuiTextInput("", csv[index][index1 + 7]);
							groupconfigurationinput[7]->onTextInputEvent(this, &GUI::tuesdaypwroffevent);
							groupconfigurationinput[7]->setFocused(false);
							groupconfigurationinput[7]->setWidth(34, .0);
							groupconfigurationinput[7]->setPosition(1322, 104);

							groupconfigurationinput[8] = new ofxDatGuiTextInput("", csv[index][index1 + 8]);
							groupconfigurationinput[8]->onTextInputEvent(this, &GUI::wensedaypwronevent);
							groupconfigurationinput[8]->setFocused(false);
							groupconfigurationinput[8]->setWidth(34, .0);
							groupconfigurationinput[8]->setPosition(1357, 92);

							groupconfigurationinput[9] = new ofxDatGuiTextInput("", csv[index][index1 + 9]);
							groupconfigurationinput[9]->onTextInputEvent(this, &GUI::wensedaypwroffevent);
							groupconfigurationinput[9]->setFocused(false);
							groupconfigurationinput[9]->setWidth(34, .0);
							groupconfigurationinput[9]->setPosition(1357, 104);

							groupconfigurationinput[10] = new ofxDatGuiTextInput("", csv[index][index1 + 10]);
							groupconfigurationinput[10]->onTextInputEvent(this, &GUI::thursdaypwronevent);
							groupconfigurationinput[10]->setFocused(false);
							groupconfigurationinput[10]->setWidth(34, .0);
							groupconfigurationinput[10]->setPosition(1392, 92);

							groupconfigurationinput[11] = new ofxDatGuiTextInput("", csv[index][index1 + 11]);
							groupconfigurationinput[11]->onTextInputEvent(this, &GUI::thursdaypwroffevent);
							groupconfigurationinput[11]->setFocused(false);
							groupconfigurationinput[11]->setWidth(34, .0);
							groupconfigurationinput[11]->setPosition(1392, 104);

							groupconfigurationinput[12] = new ofxDatGuiTextInput("", csv[index][index1 + 12]);
							groupconfigurationinput[12]->onTextInputEvent(this, &GUI::fridaypwronevent);
							groupconfigurationinput[12]->setFocused(false);
							groupconfigurationinput[12]->setWidth(34, .0);
							groupconfigurationinput[12]->setPosition(1427, 92);

							groupconfigurationinput[13] = new ofxDatGuiTextInput("", csv[index][index1 + 13]);
							groupconfigurationinput[13]->onTextInputEvent(this, &GUI::fridaypwroffevent);
							groupconfigurationinput[13]->setFocused(false);
							groupconfigurationinput[13]->setWidth(34, .0);
							groupconfigurationinput[13]->setPosition(1427, 104);

							groupconfigurationinput[14] = new ofxDatGuiTextInput("", csv[index][index1 + 14]);
							groupconfigurationinput[14]->onTextInputEvent(this, &GUI::saturdaypwronevent);
							groupconfigurationinput[14]->setFocused(false);
							groupconfigurationinput[14]->setWidth(34, .0);
							groupconfigurationinput[14]->setPosition(1462, 92);

							groupconfigurationinput[15] = new ofxDatGuiTextInput("", csv[index][index1 + 15]);
							groupconfigurationinput[15]->onTextInputEvent(this, &GUI::saturdaypwroffevent);
							groupconfigurationinput[15]->setFocused(false);
							groupconfigurationinput[15]->setWidth(34, .0);
							groupconfigurationinput[15]->setPosition(1462, 104);

							csv.save("powermanagerfile.csv");

							groupclearpopupflag = 0;
						}
					}
				}
			}
		}
#endif	
	}
	if (e.target == POPUPCLIENTCLEARCANCEL) {
		clientclearpopupflag = 0;
	}
	if (e.target == POPUPCLIENTCLEAROK) {
		for (int i = 1; i < 91; i++) {
			if (clientconfig == i) {
				string numberpage = "dev:" + ofToString(int(i));
				for (int index = 0; index < csv.getNumRows(); index++) {
					for (int index1 = 0; index1 < csv.getNumCols(index); index1++) {
						if (numberpage.compare(csv[index][index1]) == 0) {
							for (int i = 0; i < TCP.getLastID(); i++) {
								string clearkey = "clear";
								string clearpacket = numberpage + ":" + csv[index][index1 + 2] + ":" + clearkey + ":";
								//std::cout << clearpacket << endl;
								TCP.send(i, clearpacket);
							}
							csv[index][index1 + 1] = "";           // client name
							csv[index][index1 + 2] = "";           // client ip
							csv[index][index1 + 3] = "";           // client type
							csv[index][index1 + 4] = "";           // client group number 
							csv[index][index1 + 5] = "";           // client info
							csv[index][index1 + 6] = "0";          // device condition state check

							devicestateload[clientconfig] = true;
							//clientstate[i] = ofToInt(csv[index][index1 + 6]);
							checkstate[i] = ofToInt(csv[index][index1 + 6]);

							row.addString(csv[index][index1 + 1]);
							row.addString(csv[index][index1 + 2]);
							row.addString(csv[index][index1 + 3]);
							row.addString(csv[index][index1 + 4]);
							row.addString(csv[index][index1 + 5]);
							row.addString(csv[index][index1 + 6]);

							clientnameline1button[i]->setLabel(csv[index][index1 + 1]);
							line1typeHeader[i]->setLabel(csv[index][index1 + 3]);
							line1infoHeader[i]->setLabel(csv[index][index1 + 5]);
							//for (int i = 1; i < 91; i++)clientnameline1button[i]->setLabel(csv[index][index1 + 1]);
							//for (int i = 1; i < 91; i++)line1typeHeader[i]->setLabel(csv[index][index1 + 3]);
							//for (int i = 1; i < 91; i++)line1infoHeader[i]->setLabel(csv[index][index1 + 5]);
							csv.save("powermanagerfile.csv");

							for (int clearindex = 1; clearindex < 91; clearindex++) {
								for (int i = 0; i < 21; i++) {
									groupnumberarray[clearindex][i] = "";
								}
							}

							//devicestateload = false;
						}
					}
				}
				devicecheck[i] = true;
				clientclearpopupflag = 0;
			}
		}
	}
}

void GUI::grouppopupbuttonevent(ofxDatGuiButtonEvent e) {
	int index = 0;
	if (e.target == GROUPPOPUPAPPLYBUTTON) {
		for (int i = 1; i < 21; i++) groupbutton[i]->setLabel(groupnumbername_pass[i]);       
		for (index = 0; index < 21; index++) {
			string numberpage = "num:" + ofToString(int(index));
			groupbannername[index] = groupnumbername_pass[index];
			for (int i = 0; i < csv.getNumRows(); i++) {
				for (int j = 0; j < csv.getNumCols(i); j++) {
					if (numberpage.compare(csv[i][j]) == 0) {
						csv[i][j + 1] = groupbannername[index];
						csv[i][j + 2] = sundaytime_on[index];
						csv[i][j + 3] = sundaytime_off[index];
						csv[i][j + 4] = mondaytime_on[index];
						csv[i][j + 5] = mondaytime_off[index];
						csv[i][j + 6] = tuesdaytime_on[index];
						csv[i][j + 7] = tuesdaytime_off[index];
						csv[i][j + 8] = wensdaytime_on[index];
						csv[i][j + 9] = wensdaytime_off[index];
						csv[i][j + 10] = thursdaytime_on[index];
						csv[i][j + 11] = thursdaytime_off[index];
						csv[i][j + 12] = fridaytime_on[index];
						csv[i][j + 13] = fridaytime_off[index];
						csv[i][j + 14] = saturdaytime_on[index];
						csv[i][j + 15] = saturdaytime_off[index];

						row.addString(csv[i][j + 1]);
						row.addString(csv[i][j + 2]);
						row.addString(csv[i][j + 3]);
						row.addString(csv[i][j + 4]);
						row.addString(csv[i][j + 5]);
						row.addString(csv[i][j + 6]);
						row.addString(csv[i][j + 7]);
						row.addString(csv[i][j + 8]);
						row.addString(csv[i][j + 9]);
						row.addString(csv[i][j + 10]);
						row.addString(csv[i][j + 11]);
						row.addString(csv[i][j + 12]);
						row.addString(csv[i][j + 13]);
						row.addString(csv[i][j + 14]);
						row.addString(csv[i][j + 15]);

						csv.save("powermanagerfile.csv");
					}
				}
			}
		}
#if 1
		if (mondaystart == 1) {
			for (int i = 0; i < 21; i++) {
				mondayevent[i] = false;
				mondayoffevent[i] = false;

			}
			datalog.open("datalog.xml", ofFile::Append);
			datacmd = ">> " + dayoftheweek + "," + ahour + ":" + aminute + ":" + asecond + " group button event" + "\n";
			datalog << datacmd;
			datalog.close();
			grouppopupflag = 0;
		}
		if (tusedaystart == 1) {
			for (int i = 0; i < 21; i++) {
				tusedayevent[i] = false;
				tusedayoffevent[i] = false;
			}
			datalog.open("datalog.xml", ofFile::Append);
			datacmd = ">> " + dayoftheweek + "," + ahour + ":" + aminute + ":" + asecond + " group button event" + "\n";
			datalog << datacmd;
			datalog.close();
			grouppopupflag = 0;
		}
		if (wensdaystart == 1) {
			for (int i = 0; i < 21; i++) {
				wensdayevent[i] = false;
				wensdayoffevent[i] = false;
			}
			datalog.open("datalog.xml", ofFile::Append);
			datacmd = ">> " + dayoftheweek + "," + ahour + ":" + aminute + ":" + asecond + " group button event" + "\n";
			datalog << datacmd;
			datalog.close();
			grouppopupflag = 0;
		}
		if (thursdaystart == 1) {
			for (int i = 0; i < 21; i++) {
				thursdayevent[i] = false;
				thursdayoffevent[i] = false;
			}
			datalog.open("datalog.xml", ofFile::Append);
			datacmd = ">> " + dayoftheweek + "," + ahour + ":" + aminute + ":" + asecond + " group button event" + "\n";
			datalog << datacmd;
			datalog.close();
			grouppopupflag = 0;
		}
		if (fridaystart == 1) {
			for (int i = 0; i < 21; i++) {
				fridayevent[i] = false;
				fridayoffevent[i] = false;
			}
			datalog.open("datalog.xml", ofFile::Append);
			datacmd = ">> " + dayoftheweek + "," + ahour + ":" + aminute + ":" + asecond + " group button event" + "\n";
			datalog << datacmd;
			datalog.close();
			grouppopupflag = 0;
		}
#endif	
	}
	if (e.target == GROUPPOPUPCANCELBUTTON) {
		grouppopupflag = 0;
	}
}

void GUI::popupclientapplyEvent(ofxDatGuiButtonEvent e) {
	int index = 0;
	int clientgroupline1interval = 1130;
	int clientgroupline2interval = 1130;
	int clientgroupline3interval = 1130;
	int clientgroupline4interval = 1130;
	int clientgroupline5interval = 1130;

	if (e.target == POPUPCLIENTAPPLYBUTTON && eventdataload == true) {
		notpushbutton = true;
		for (index = 1; index < 91; index++) {
			string numberpage = "dev:" + ofToString(int(index));    // 1~90 번 검사
			for (int i = 0; i < csv.getNumRows(); i++) {
				for (int j = 0; j < csv.getNumCols(i); j++) {
					if (numberpage.compare(csv[i][j]) == 0) {
						if (clientconfig == index) {
							csv[i][j + 1] = clientgroupname_pass[index];
							csv[i][j + 2] = clientgroupipaddress_pass[index];
							csv[i][j + 3] = clienttypepc_pass[index];
							csv[i][j + 4] = clientgroupnumber_pass[index];
							csv[i][j + 5] = clientgroupinfo_pass[index];
							csv[i][j + 6] = "1";

							clientstate[index] = clientconfig;
							checkstate[index] = csv[i][j + 6];
							devicestateload[index] = false;

							row.addString(csv[i][j + 1]);
							row.addString(csv[i][j + 2]);
							row.addString(csv[i][j + 3]);
							row.addString(csv[i][j + 4]);
							row.addString(csv[i][j + 5]);
							row.addString(csv[i][j + 6]);

							csv.save("powermanagerfile.csv");

							clientnameline1button[index]->setLabel(clientgroupname_pass[index]);
							line1typeHeader[index]->setLabel(clienttypepc_pass[index]);
							line1infoHeader[index]->setLabel(clientgroupinfo_pass[index]);
						}
					}
				}
			}
		}
		popupclientflag = 0;
		checklogic = 1;
	}
}

void GUI::popupclientcancelEvent(ofxDatGuiButtonEvent e) {
	if (e.target == POPUPCLIENTCANCELBUTTON) {
		popupclientflag = 0;
		notpushbutton = true;
	}
}

void GUI::update() {
	int searchindex1, searchindex2, searchindex3, searchindex4, searchindex5, searchindex6 = 0;
	int splitindex = 0;
	int clientinedx = 0;
	string splitvector2 = "";
	string splitvector3 = "";
	int rxflag = 0;

	if (init_data_load == 1) {
		eventdataload = true;
		eventdataload1 = true;                  // 그룹 단위 전원을 구분하기 위한 변수 true
		notpushbutton = true;
		//devicestateload = false;
		//init_data_load = 1;
		groupconfigflag = 0;
		ALLBUTTON->setOpacity(0.2);

		CLIENTCLEARBUTTON = new ofxDatGuiButton("CLEAR");
		CLIENTCLEARBUTTON->setPosition(1206, 442 + 21);
		CLIENTCLEARBUTTON->setWidth(96);
		CLIENTCLEARBUTTON->setHeight(43);
		CLIENTCLEARBUTTON->setOpacity(1.0);
		CLIENTCLEARBUTTON->onButtonEvent(this, &GUI::clientclearbuttonEvent);

		CLIENTAPPLYBUTTON = new ofxDatGuiButton("APPLY");
		CLIENTAPPLYBUTTON->setPosition(1303, 442 + 21);
		CLIENTAPPLYBUTTON->setWidth(333);
		CLIENTAPPLYBUTTON->setHeight(43);
		CLIENTAPPLYBUTTON->setOpacity(1.0);
		CLIENTAPPLYBUTTON->onButtonEvent(this, &GUI::clientapplybuttonEvent);

		for (int i = 1; i < 21; i++)groupbutton[i]->setOpacity(1.0);
		for (int i = 1; i < 91; i++) {
			clientstate[i] = 0;
			checkstate[i] = "0";
			clientnameline1button[i]->setOpacity(1.0);
		}
		/*client information load*/
		for (int index = 1; index < 91; index++) {
			string numberpage = "dev:" + ofToString(int(index));
			for (int index1 = 0; index1 < csv.getNumRows(); index1++) {
				for (int index2 = 0; index2 < csv.getNumCols(index1); index2++) {
					if (numberpage.compare(csv[index1][index2]) == 0) {
						if (csv[index1][index2 + 6].compare("0") == 0) {
							devicenum = ofSplitString(csv[index1][index2], ":");
							for (int i = 0; i < devicenum.size(); ++i)devicenum[i];
							for (int i = 1; i < 91; i++) {
								if (ofToInt(devicenum[1]) == i) {
									devicestateload[i] = true;
								}
							}
						}
						clienttypepc_pass[index] = csv[index1][index2 + 3];
						clientgroupnumber_pass[index] = csv[index1][index2 + 4];

						splitvector = ofSplitString(csv[index1][index2], ":");
						for (int i = 0; i < splitvector.size(); ++i)splitvector[i];

						splitvector1 = ofSplitString(clientgroupnumber_pass[index], ":");
						for (int i = 0; i < splitvector1.size(); ++i) {
							groupnumberarray[index][i] = splitvector1[i];
							string numheader = "num1:";
							groupnumbepacket[index] = numheader + groupnumberarray[index][1] + ":" + groupnumberarray[index][2] + ":" + groupnumberarray[index][3] + ":" + groupnumberarray[index][4] + ":" + groupnumberarray[index][5]
								+ ":" + groupnumberarray[index][6] + ":" + groupnumberarray[index][7] + ":" + groupnumberarray[index][8] + ":" + groupnumberarray[index][9] + ":" + groupnumberarray[index][10] + ":" + groupnumberarray[index][11]
								+ ":" + groupnumberarray[index][12] + ":" + groupnumberarray[index][13] + ":" + groupnumberarray[index][14] + ":" + groupnumberarray[index][15] + ":" + groupnumberarray[index][16] + ":" + groupnumberarray[index][17]
								+ ":" + groupnumberarray[index][18] + ":" + groupnumberarray[index][19] + ":" + groupnumberarray[index][20];
						}
						string devicestetastr = ":" + ofToString(int(0)) + ":" + splitvector[1] + ":" + csv[index1][index2 + 2] + ":" + csv[index1][index2 + 3] + ":";
						for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, devicestetastr);

						clientnameline1button[index]->setLabel(csv[index1][index2 + 1]);
						line1typeHeader[index]->setLabel(csv[index1][index2 + 3]);
						line1infoHeader[index]->setLabel(csv[index1][index2 + 5]);    // 

						clientstate[index] = index;
						checkstate[index] = csv[index1][index2 + 6];
					}
				}
			}
		}
		string numberpage1 = "num:" + ofToString(int(groupconfigflag));
		for (int index1 = 0; index1 < csv.getNumRows(); index1++) {
			for (int index2 = 0; index2 < csv.getNumCols(index1); index2++) {
				if (numberpage1.compare(csv[index1][index2]) == 0) {
					grouplabel = new ofxDatGuiLabel(ofToString(int(groupconfigflag)));
					grouplabel->setWidth(333, .0);
					grouplabel->setPosition(1300, 79);

					groupconfigurationinput[1] = new ofxDatGuiTextInput("", csv[index1][index2 + 1]);
					groupconfigurationinput[1]->onTextInputEvent(this, &GUI::groupnameinputEvent);
					groupconfigurationinput[1]->setFocused(false);
					groupconfigurationinput[1]->setOpacity(0);
					groupconfigurationinput[1]->setWidth(333, .0);
					groupconfigurationinput[1]->setHeight(20);
					groupconfigurationinput[1]->setPosition(1302, 101);

					groupconfigurationinput[2] = new ofxDatGuiTextInput("", csv[index1][index2 + 2]);
					groupconfigurationinput[2]->onTextInputEvent(this, &GUI::sundaypwronevent);
					groupconfigurationinput[2]->setFocused(false);
					groupconfigurationinput[2]->setOpacity(0);
					groupconfigurationinput[2]->setWidth(46, .0);
					groupconfigurationinput[2]->setHeight(20);
					groupconfigurationinput[2]->setPosition(1304, 147);

					groupconfigurationinput[3] = new ofxDatGuiTextInput("", csv[index1][index2 + 3]);
					groupconfigurationinput[3]->onTextInputEvent(this, &GUI::sundaypwroffevent);
					groupconfigurationinput[3]->setFocused(false);
					groupconfigurationinput[3]->setOpacity(0);
					groupconfigurationinput[3]->setWidth(46, .0);
					groupconfigurationinput[3]->setHeight(20);
					groupconfigurationinput[3]->setPosition(1304, 147 + 23);

					groupconfigurationinput[4] = new ofxDatGuiTextInput("", csv[index1][index2 + 4]);
					groupconfigurationinput[4]->onTextInputEvent(this, &GUI::mondaypwronevent);
					groupconfigurationinput[4]->setFocused(false);
					groupconfigurationinput[4]->setWidth(46, .0);
					groupconfigurationinput[4]->setHeight(20);
					groupconfigurationinput[4]->setPosition(1351, 147);

					groupconfigurationinput[5] = new ofxDatGuiTextInput("", csv[index1][index2 + 5]);
					groupconfigurationinput[5]->onTextInputEvent(this, &GUI::mondaypwroffevent);
					groupconfigurationinput[5]->setFocused(false);
					groupconfigurationinput[5]->setOpacity(0);
					groupconfigurationinput[5]->setWidth(46, .0);
					groupconfigurationinput[5]->setHeight(20);
					groupconfigurationinput[5]->setPosition(1351, 147 + 23);
					
					groupconfigurationinput[6] = new ofxDatGuiTextInput("", csv[index1][index2 + 6]);
					groupconfigurationinput[6]->onTextInputEvent(this, &GUI::tuesdaypwronevent);
					groupconfigurationinput[6]->setFocused(false);
					groupconfigurationinput[6]->setOpacity(0);
					groupconfigurationinput[6]->setWidth(46, .0);
					groupconfigurationinput[6]->setHeight(20);
					groupconfigurationinput[6]->setPosition(1351 + 46, 147);
					
					groupconfigurationinput[7] = new ofxDatGuiTextInput("", csv[index1][index2 + 7]);
					groupconfigurationinput[7]->onTextInputEvent(this, &GUI::tuesdaypwroffevent);
					groupconfigurationinput[7]->setFocused(false);
					groupconfigurationinput[7]->setOpacity(0);
					groupconfigurationinput[7]->setWidth(46, .0);
					groupconfigurationinput[7]->setHeight(20);
					groupconfigurationinput[7]->setPosition(1351 + 46, 147 + 23);

					groupconfigurationinput[8] = new ofxDatGuiTextInput("", csv[index1][index2 + 8]);
					groupconfigurationinput[8]->onTextInputEvent(this, &GUI::wensedaypwronevent);
					groupconfigurationinput[8]->setFocused(false);
					groupconfigurationinput[8]->setOpacity(0);
					groupconfigurationinput[8]->setWidth(46, .0);
					groupconfigurationinput[8]->setHeight(20);
					groupconfigurationinput[8]->setPosition(1398 + 46, 147);

					groupconfigurationinput[9] = new ofxDatGuiTextInput("", csv[index1][index2 + 9]);
					groupconfigurationinput[9]->onTextInputEvent(this, &GUI::wensedaypwroffevent);
					groupconfigurationinput[9]->setFocused(false);
					groupconfigurationinput[9]->setOpacity(0);
					groupconfigurationinput[9]->setWidth(46, .0);
					groupconfigurationinput[9]->setHeight(20);
					groupconfigurationinput[9]->setPosition(1398 + 46, 147 + 23);
					

					groupconfigurationinput[10] = new ofxDatGuiTextInput("", csv[index1][index2 + 10]);
					groupconfigurationinput[10]->onTextInputEvent(this, &GUI::thursdaypwronevent);
					groupconfigurationinput[10]->setFocused(false);
					groupconfigurationinput[10]->setOpacity(0);
					groupconfigurationinput[10]->setWidth(46, .0);
					groupconfigurationinput[10]->setHeight(20);
					groupconfigurationinput[10]->setPosition(1445 + 46, 147);
					
					groupconfigurationinput[11] = new ofxDatGuiTextInput("", csv[index1][index2 + 11]);
					groupconfigurationinput[11]->onTextInputEvent(this, &GUI::thursdaypwroffevent);
					groupconfigurationinput[11]->setFocused(false);
					groupconfigurationinput[11]->setOpacity(0);
					groupconfigurationinput[11]->setWidth(46, .0);
					groupconfigurationinput[11]->setHeight(20);
					groupconfigurationinput[11]->setPosition(1445 + 46, 147 + 23);
					
					groupconfigurationinput[12] = new ofxDatGuiTextInput("", csv[index1][index2 + 12]);
					groupconfigurationinput[12]->onTextInputEvent(this, &GUI::fridaypwronevent);
					groupconfigurationinput[12]->setFocused(false);
					groupconfigurationinput[12]->setOpacity(0);
					groupconfigurationinput[12]->setWidth(46, .0);
					groupconfigurationinput[12]->setHeight(20);
					groupconfigurationinput[12]->setPosition(1492 + 46, 147);
					
					groupconfigurationinput[13] = new ofxDatGuiTextInput("", csv[index1][index2 + 13]);
					groupconfigurationinput[13]->onTextInputEvent(this, &GUI::fridaypwroffevent);
					groupconfigurationinput[13]->setFocused(false);
					groupconfigurationinput[13]->setOpacity(0);
					groupconfigurationinput[13]->setWidth(46, .0);
					groupconfigurationinput[13]->setHeight(20);
					groupconfigurationinput[13]->setPosition(1492 + 46, 147 + 23);
					
					groupconfigurationinput[14] = new ofxDatGuiTextInput("", csv[index1][index2 + 14]);
					groupconfigurationinput[14]->onTextInputEvent(this, &GUI::saturdaypwronevent);
					groupconfigurationinput[14]->setFocused(false);
					groupconfigurationinput[14]->setOpacity(0);
					groupconfigurationinput[14]->setWidth(46, .0);
					groupconfigurationinput[14]->setHeight(20);
					groupconfigurationinput[14]->setPosition(1539 + 46, 147);
					
					groupconfigurationinput[15] = new ofxDatGuiTextInput("", csv[index1][index2 + 15]);
					groupconfigurationinput[15]->onTextInputEvent(this, &GUI::saturdaypwroffevent);
					groupconfigurationinput[15]->setFocused(false);
					groupconfigurationinput[15]->setOpacity(0);
					groupconfigurationinput[15]->setWidth(46, .0);
					groupconfigurationinput[15]->setHeight(20);
					groupconfigurationinput[15]->setPosition(1539 + 46, 147 + 23);
				}
			}
		}
		for (int index = 1; index < 21; index++) {
			string numberpage2 = "num:" + ofToString(int(index));
			for (int index1 = 0; index1 < csv.getNumRows(); index1++) {
				for (int index2 = 0; index2 < csv.getNumCols(index1); index2++) {
					if (numberpage2.compare(csv[index1][index2]) == 0) {
						groupbutton[index]->setLabel(csv[index1][index2 + 1]);
						init_data_load = 0;
					}
				}
			}
		}
	}
	for (unsigned int i = 0; i < (unsigned int)TCP.getLastID(); i++) {
#if 0
		for (int i = 1; i < 91; i++) {
			if (checkconncetflag[i] == i) {
				timeover[i].start();
				timer_f1[i] = ofToString(timeover[i].getCurrentTime());
				timeover_check_num[i] = ofToInt(timer_f1[i]);
				if (i * 30 < timeover_check_num[i] && devicecheck[i] == false) {
					clientstate[i] = i;
					checkstate[i] = "1";
				}
			}
		}
#endif		
		if (!TCP.isClientConnected(i)) {
			continue;
		}
		if (i >= storeText.size()) {
			storeText.push_back(string());
		}
		do {
			str = tmp;
			tmp = TCP.receive(i);
		} while (tmp != "");
		if (str.length() > 0) {
			storeText[i] = str;
			vector<string>line_vector = split(str, ':');
			for (int i = 0; i < line_vector.size(); ++i) {
				str = line_vector[0];                 // group number
				str1 = line_vector[1];                // client number 
				str2 = line_vector[2];                // led state 
			}
			for (int i = 1; i < 91; i++) {
				// 그룹 안에 장비의 상태값을 받고 모든 데이터가 로드가 해제된 상태
				// modify history , devicestateload[i] = false;
				if (ofToInt(str) == groupconfigflag && ofToInt(str1) == i && devicestateload[i] == false && eventdataload == false) {
					clientstate[i] = i;
					checkconncetflag[i] = i;
					// 클라이언트 장비 완전 해제 관련 함수
#if 0
					if (ofToInt(str) == groupconfigflag && clientstate[i] == i && ofToInt(str2) == 1) {
						timeoverCount[i]++;
						if (timeoverCount[i] == 1) {
							timeover[i].reset();
							timeoverCount[i] = 0;
							timeover_check_num[i] = 0;
						}
					}
#endif					
					if (ofToInt(str2) == 2 || ofToInt(str2) == 3) {
						checkstate[i] = str2;
					}
				}
				// allbutton stage
				if (devicestateload[i] == false && ofToInt(str) == 0 && ofToInt(str1) == i && eventdataload == true) {
					if (ofToInt(str2) == 2 || ofToInt(str2) == 3) {
						checkstate[i] = str2;
					}
				}

			}
		}
	}
	if (eventmonday == 1) {
#if 1
		for (int searchindex = 0; searchindex < 21; searchindex++) {
			if (searchindex == groupconfigflag) {
				string numberpage = "num:" + ofToString(int(searchindex));
				for (searchindex1 = 0; searchindex1 < csv.getNumRows(); searchindex1++) {
					for (searchindex2 = 0; searchindex2 < csv.getNumCols(searchindex1); searchindex2++) {
						if (numberpage.compare(csv[searchindex1][searchindex2]) == 0) {
							vector<string> mondaytime_vector_on = ofSplitString(csv[searchindex1][searchindex2 + 4], ":");
							for (int i = 0; i < mondaytime_vector_on.size(); ++i) {
								mondaystr[i] = mondaytime_vector_on[i];
							}
							csvtime[searchindex] = mondaystr[0];
							csvtime1[searchindex] = mondaystr[1];
							mondaystr[0] = "";
							mondaystr[1] = "";
							vector<string> mondaytime_vector_off = ofSplitString(csv[searchindex1][searchindex2 + 5], ":");
							for (int i = 0; i < mondaytime_vector_off.size(); ++i) {
								mondaystroff[i] = mondaytime_vector_off[i];
							}
							csvtimeoff[searchindex] = mondaystroff[0];
							csvtimeoff1[searchindex] = mondaystroff[1];
							mondaystroff[0] = "";
							mondaystroff[1] = "";
						}
					}
				}
				if (csvtime[searchindex].compare(ahour) == 0 && csvtime1[searchindex].compare(aminute) == 0) {
					if (searchindex == searchindex && mondayevent[searchindex] == false && eventdataload1 == true) {
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
								for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
									if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
										vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
										for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "on" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										mondayevent[searchindex] = true;
									}
								}
							}
						}
					}
					if (searchindex == searchindex && mondayevent[searchindex] == false && eventdataload1 == false) {
						indexcountcopy = 0;
						for (int groupindex = 1; groupindex < 21; groupindex++) {
							if (groupindex == groupconfigflag) {
								for (int i = 1; i < 91; i++) {
									string numberpage1 = "dev:" + ofToString(int(i));
									for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
										for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
											if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
												vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
												for (int i = 0; i < clientgroupnumber.size(); ++i) {
													if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
														indexcountcopy++;
														autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "on" + ":";
														for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
														Sleep(25.0);
														autodatapacket1 = "";
														mondayevent[searchindex] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (csvtimeoff[searchindex].compare(ahour) == 0 && csvtimeoff1[searchindex].compare(aminute) == 0) {
					if (searchindex == searchindex && mondayoffevent[searchindex] == false && eventdataload1 == true) {
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
								for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
									if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
										vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
										for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "off" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										mondayoffevent[searchindex] = true;
									}
								}
							}
						}
					}
					if (searchindex == searchindex && mondayoffevent[searchindex] == false && eventdataload1 == false) {
						indexcountcopy = 0;
						for (int groupindex = 1; groupindex < 21; groupindex++) {
							if (groupindex == groupconfigflag) {
								for (int i = 1; i < 91; i++) {
									string numberpage1 = "dev:" + ofToString(int(i));
									for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
										for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
											if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
												vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
												for (int i = 0; i < clientgroupnumber.size(); ++i) {
													if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
														indexcountcopy++;
														autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "off" + ":";
														for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
														Sleep(25.0);
														autodatapacket1 = "";
														mondayoffevent[searchindex] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
#endif	
	}
	if (eventtuesday == 1) {
		for (int searchindex = 0; searchindex < 21; searchindex++) {
			if (searchindex == groupconfigflag) {
				string numberpage = "num:" + ofToString(int(searchindex));
				for (searchindex1 = 0; searchindex1 < csv.getNumRows(); searchindex1++) {
					for (searchindex2 = 0; searchindex2 < csv.getNumCols(searchindex1); searchindex2++) {
						if (numberpage.compare(csv[searchindex1][searchindex2]) == 0) {
							vector<string> tuesdaytime_vector_on = ofSplitString(csv[searchindex1][searchindex2 + 6], ":");
							for (int i = 0; i < tuesdaytime_vector_on.size(); ++i)tuesdaystr[i] = tuesdaytime_vector_on[i];
							csvtime[searchindex] = tuesdaystr[0];
							csvtime1[searchindex] = tuesdaystr[1];
							tuesdaystr[0] = "";
							tuesdaystr[1] = "";
							vector<string> tuesdaytime_vector_off = ofSplitString(csv[searchindex1][searchindex2 + 7], ":");
							for (int i = 0; i < tuesdaytime_vector_off.size(); ++i)tuesdaystroff[i] = tuesdaytime_vector_off[i];
							csvtimeoff[searchindex] = tuesdaystroff[0];
							csvtimeoff1[searchindex] = tuesdaystroff[1];
							tuesdaystroff[0] = "";
							tuesdaystroff[1] = "";
						}
					}
				}
				if (csvtime[searchindex].compare(ahour) == 0 && csvtime1[searchindex].compare(aminute) == 0) {
					if (searchindex == searchindex && tusedayevent[searchindex] == false && eventdataload1 == true) {
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
								for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
									if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
										vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
										for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "on" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										tusedayevent[searchindex] = true;
									}
								}
							}
						}
					}
					if (searchindex == searchindex && tusedayevent[searchindex] == false && eventdataload1 == false) {
						indexcountcopy = 0;
						for (int groupindex = 1; groupindex < 21; groupindex++) {
							if (groupindex == groupconfigflag) {
								for (int i = 1; i < 91; i++) {
									string numberpage1 = "dev:" + ofToString(int(i));
									for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
										for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
											if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
												vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
												for (int i = 0; i < clientgroupnumber.size(); ++i) {
													if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
														indexcountcopy++;
														autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "on" + ":";
														for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
														Sleep(25.0);
														autodatapacket1 = "";
														tusedayevent[searchindex] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (csvtimeoff[searchindex].compare(ahour) == 0 && csvtimeoff1[searchindex].compare(aminute) == 0) {
					if (searchindex == searchindex && tusedayoffevent[searchindex] == false && eventdataload1 == true) {
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
								for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
									if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
										vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
										for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "off" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										tusedayoffevent[searchindex] = true;
									}
								}
							}
						}
					}
					if (searchindex == searchindex && tusedayoffevent[searchindex] == false && eventdataload1 == false) {
						indexcountcopy = 0;
						for (int groupindex = 1; groupindex < 21; groupindex++) {
							if (groupindex == groupconfigflag) {
								for (int i = 1; i < 91; i++) {
									string numberpage1 = "dev:" + ofToString(int(i));
									for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
										for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
											if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
												vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
												for (int i = 0; i < clientgroupnumber.size(); ++i) {
													if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
														indexcountcopy++;
														autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "off" + ":";
														for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
														Sleep(25.0);
														autodatapacket1 = "";
														tusedayoffevent[searchindex] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (eventwensday == 1) {
		for (int searchindex = 0; searchindex < 21; searchindex++) {
			string numberpage = "num:" + ofToString(int(searchindex));
			for (searchindex1 = 0; searchindex1 < csv.getNumRows(); searchindex1++) {
				for (searchindex2 = 0; searchindex2 < csv.getNumCols(searchindex1); searchindex2++) {
					if (numberpage.compare(csv[searchindex1][searchindex2]) == 0) {
						vector<string> wensedaytime_vector_on = ofSplitString(csv[searchindex1][searchindex2 + 8], ":");
						for (int i = 0; i < wensedaytime_vector_on.size(); ++i)wensdaystr[i] = wensedaytime_vector_on[i];
						csvtime[searchindex] = wensdaystr[0];
						csvtime1[searchindex] = wensdaystr[1];
						wensdaystr[0] = "";
						wensdaystr[1] = "";

						vector<string> wensedaytime_vector_off = ofSplitString(csv[searchindex1][searchindex2 + 9], ":");
						for (int i = 0; i < wensedaytime_vector_off.size(); ++i)wensdaystroff[i] = wensedaytime_vector_off[i];
						csvtimeoff[searchindex] = wensdaystroff[0];
						csvtimeoff1[searchindex] = wensdaystroff[1];
						wensdaystroff[0] = "";
						wensdaystroff[1] = "";

						if (csvtime[searchindex].compare(ahour) == 0 && csvtime1[searchindex].compare(aminute) == 0 && wensdayevent[searchindex] == false) {
							indexcountcopy = 0;
							vector<string> wensdaytimenum_on = ofSplitString(csv[searchindex1][searchindex2], ":");
							for (int i = 0; i < wensdaytimenum_on.size(); ++i)wensdaytimenum_on[i];
							for (int i = 1; i < 91; i++) {
								string numberpage1 = "dev:" + ofToString(int(i));
								for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
									for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
										if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
											vector<string> clientnumber = ofSplitString(csv[searchindex3][searchindex4], ":");
											for (int i = 0; i < clientnumber.size(); ++i)clientnumber[i];
											vector<string> clientgroupnumber = ofSplitString(csv[searchindex3][searchindex4 + 4], ":");
											for (int i = 0; i < clientgroupnumber.size(); ++i) {
												// all 상태에서 선택적인 그룹에 장비 와 모든 장비에 전원 켜짐을 제어
												if (wensdaytimenum_on[1].compare(clientgroupnumber[i]) == 0 && eventdataload1 == true) {
													autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + clientnumber[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "on" + ":";
													for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
													wensdayevent[searchindex] = true;
												}
												if (wensdaytimenum_on[1].compare(clientgroupnumber[i]) == 0 && eventdataload1 == false) {
													indexcountcopy++;
													autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "on" + ":";
													for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
													wensdayevent[searchindex] = true;
												}
											}
										}
									}
								}
							}
						}
						if (csvtimeoff[searchindex].compare(ahour) == 0 && csvtimeoff1[searchindex].compare(aminute) == 0 && wensdayoffevent[searchindex] == false) {
							indexcountcopy = 0;
							vector<string> wensdaytimenum_off = ofSplitString(csv[searchindex1][searchindex2], ":");
							for (int i = 0; i < wensdaytimenum_off.size(); ++i)wensdaytimenum_off[i];
							for (int i = 1; i < 91; i++) {
								string numberpage1 = "dev:" + ofToString(int(i));
								for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
									for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
										if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
											vector<string> clientnumber = ofSplitString(csv[searchindex3][searchindex4], ":");
											for (int i = 0; i < clientnumber.size(); ++i)clientnumber[i];
											vector<string> clientgroupnumber = ofSplitString(csv[searchindex3][searchindex4 + 4], ":");
											for (int i = 0; i < clientgroupnumber.size(); ++i) {
												if (wensdaytimenum_off[1].compare(clientgroupnumber[i]) == 0 && eventdataload1 == true) {
													autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + clientnumber[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "off" + ":";
													for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
													wensdayoffevent[searchindex] = true;
												}
												if (wensdaytimenum_off[1].compare(clientgroupnumber[i]) == 0 && eventdataload1 == false) {
													indexcountcopy++;
													autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "off" + ":";
													for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
													wensdayoffevent[searchindex] = true;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (eventthursday == 1) {
		for (int searchindex = 0; searchindex < 21; searchindex++) {
			if (searchindex == groupconfigflag) {
				string numberpage = "num:" + ofToString(int(searchindex));
				for (searchindex1 = 0; searchindex1 < csv.getNumRows(); searchindex1++) {
					for (searchindex2 = 0; searchindex2 < csv.getNumCols(searchindex1); searchindex2++) {
						if (numberpage.compare(csv[searchindex1][searchindex2]) == 0) {
							vector<string> thursdaytime_vector_on = ofSplitString(csv[searchindex1][searchindex2 + 10], ":");
							for (int i = 0; i < thursdaytime_vector_on.size(); ++i)thursdaystr[i] = thursdaytime_vector_on[i];
							csvtime[searchindex] = thursdaystr[0];
							csvtime1[searchindex] = thursdaystr[1];
							thursdaystr[0] = "";
							thursdaystr[1] = "";      // < --- point
							vector<string> thursdaytime_vector_off = ofSplitString(csv[searchindex1][searchindex2 + 11], ":");
							for (int i = 0; i < thursdaytime_vector_off.size(); ++i)thursdaystroff[i] = thursdaytime_vector_off[i];
							csvtimeoff[searchindex] = thursdaystroff[0];
							csvtimeoff1[searchindex] = thursdaystroff[1];
							thursdaystroff[0] = "";
							thursdaystroff[1] = "";
						}
					}
				}
				if (csvtime[searchindex].compare(ahour) == 0 && csvtime1[searchindex].compare(aminute) == 0) {
					if (searchindex == searchindex && thursdayevent[searchindex] == false && eventdataload1 == true) {
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
								for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
									if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
										vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
										for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "on" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										thursdayevent[searchindex] = true;
									}
								}
							}
						}
					}
					if (searchindex == searchindex && thursdayevent[searchindex] == false && eventdataload1 == false) {
						indexcountcopy = 0;
						for (int groupindex = 1; groupindex < 21; groupindex++) {
							if (groupindex == groupconfigflag) {
								for (int i = 1; i < 91; i++) {
									string numberpage1 = "dev:" + ofToString(int(i));
									for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
										for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
											if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
												vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
												for (int i = 0; i < clientgroupnumber.size(); ++i) {
													if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
														indexcountcopy++;
														autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "on" + ":";
														for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
														Sleep(25.0);
														autodatapacket1 = "";
														thursdayevent[searchindex] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (csvtimeoff[searchindex].compare(ahour) == 0 && csvtimeoff1[searchindex].compare(aminute) == 0) {
					if (searchindex == searchindex && thursdayoffevent[searchindex] == false && eventdataload1 == true) {
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
								for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
									if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
										vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
										for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "off" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										thursdayoffevent[searchindex] = true;
									}
								}
							}
						}
					}
					if (searchindex == searchindex && thursdayoffevent[searchindex] == false && eventdataload1 == false) {
						indexcountcopy = 0;
						for (int groupindex = 1; groupindex < 21; groupindex++) {
							if (groupindex == groupconfigflag) {
								for (int i = 1; i < 91; i++) {
									string numberpage1 = "dev:" + ofToString(int(i));
									for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
										for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
											if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
												vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
												for (int i = 0; i < clientgroupnumber.size(); ++i) {
													if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
														indexcountcopy++;
														autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "off" + ":";
														for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
														Sleep(25.0);
														autodatapacket1 = "";
														thursdayoffevent[searchindex] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (eventfriday == 1) {
		for (int searchindex = 0; searchindex < 21; searchindex++) {
			string numberpage = "num:" + ofToString(int(searchindex));
			for (searchindex1 = 0; searchindex1 < csv.getNumRows(); searchindex1++) {
				for (searchindex2 = 0; searchindex2 < csv.getNumCols(searchindex1); searchindex2++) {
					if (numberpage.compare(csv[searchindex1][searchindex2]) == 0) {
						vector<string> fridaytime_vector_on = ofSplitString(csv[searchindex1][searchindex2 + 12], ":");
						for (int i = 0; i < fridaytime_vector_on.size(); ++i)fridaystr[i] = fridaytime_vector_on[i];
						csvtime[searchindex] = fridaystr[0];
						csvtime1[searchindex] = fridaystr[1];
						fridaystr[0] = "";
						fridaystr[1] = "";

						vector<string> fridaytime_vector_off = ofSplitString(csv[searchindex1][searchindex2 + 13], ":");
						for (int i = 0; i < fridaytime_vector_off.size(); ++i)fridaystroff[i] = fridaytime_vector_off[i];
						csvtimeoff[searchindex] = fridaystroff[0];
						csvtimeoff1[searchindex] = fridaystroff[1];
						fridaystroff[0] = "";
						fridaystroff[1] = "";

						if (csvtime[searchindex].compare(ahour) == 0 && csvtime1[searchindex].compare(aminute) == 0 && fridayevent[searchindex] == false) {
							vector<string> fridaytimenum_on = ofSplitString(csv[searchindex1][searchindex2], ":");
							for (int i = 0; i < fridaytimenum_on.size(); ++i)fridaytimenum_on[i];
							for (int i = 1; i < 91; i++) {
								string numberpage1 = "dev:" + ofToString(int(i));
								for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
									for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
										if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
											vector<string> clientnumber = ofSplitString(csv[searchindex3][searchindex4], ":");
											for (int i = 0; i < clientnumber.size(); ++i)clientnumber[i];
											vector<string> clientgroupnumber = ofSplitString(csv[searchindex3][searchindex4 + 4], ":");
											for (int i = 0; i < clientgroupnumber.size(); ++i) {
												if (fridaytimenum_on[1].compare(clientgroupnumber[i]) == 0 && eventdataload1 == true) {
													autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + clientnumber[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "on" + ":";

													//std::cout << autodatapacket1 << endl;
													fridayevent[searchindex] = true;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
#if 0
		for (int searchindex = 0; searchindex < 21; searchindex++) {
			if (searchindex == groupconfigflag) {
				string numberpage = "num:" + ofToString(int(searchindex));
				for (searchindex1 = 0; searchindex1 < csv.getNumRows(); searchindex1++) {
					for (searchindex2 = 0; searchindex2 < csv.getNumCols(searchindex1); searchindex2++) {
						if (numberpage.compare(csv[searchindex1][searchindex2]) == 0) {
							vector<string> fridaytime_vector_on = ofSplitString(csv[searchindex1][searchindex2 + 12], ":");
							for (int i = 0; i < fridaytime_vector_on.size(); ++i)fridaystr[i] = fridaytime_vector_on[i];
							csvtime[searchindex] = fridaystr[0];
							csvtime1[searchindex] = fridaystr[1];
							fridaystr[0] = "";
							fridaystr[1] = "";      // < --- point
							vector<string> fridaytime_vector_off = ofSplitString(csv[searchindex1][searchindex2 + 13], ":");
							for (int i = 0; i < fridaytime_vector_off.size(); ++i)fridaystroff[i] = fridaytime_vector_off[i];
							csvtimeoff[searchindex] = fridaystroff[0];
							csvtimeoff1[searchindex] = fridaystroff[1];
							fridaystroff[0] = "";
							fridaystroff[1] = "";
						}
					}
				}
				if (csvtime[searchindex].compare(ahour) == 0 && csvtime1[searchindex].compare(aminute) == 0) {
					if (searchindex == searchindex && fridayevent[searchindex] == false && eventdataload1 == true) {
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
								for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
									if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
										vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
										for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "on" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										fridayevent[searchindex] = true;
									}
								}
							}
						}
					}
					if (searchindex == searchindex && fridayevent[searchindex] == false && eventdataload1 == false) {
						indexcountcopy = 0;
						for (int groupindex = 1; groupindex < 21; groupindex++) {
							if (groupindex == groupconfigflag) {
								for (int i = 1; i < 91; i++) {
									string numberpage1 = "dev:" + ofToString(int(i));
									for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
										for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
											if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
												vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
												for (int i = 0; i < clientgroupnumber.size(); ++i) {
													if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
														indexcountcopy++;
														autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "on" + ":";
														for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
														Sleep(25.0);
														autodatapacket1 = "";
														fridayevent[searchindex] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (csvtimeoff[searchindex].compare(ahour) == 0 && csvtimeoff1[searchindex].compare(aminute) == 0) {
					if (searchindex == searchindex && fridayoffevent[searchindex] == false && eventdataload1 == true) {
						for (int i = 1; i < 91; i++) {
							string numberpage1 = "dev:" + ofToString(int(i));
							for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
								for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
									if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
										vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
										for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "off" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										fridayoffevent[searchindex] = true;
									}
								}
							}
						}
					}
					if (searchindex == searchindex && fridayoffevent[searchindex] == false && eventdataload1 == false) {
						indexcountcopy = 0;
						for (int groupindex = 1; groupindex < 21; groupindex++) {
							if (groupindex == groupconfigflag) {
								for (int i = 1; i < 91; i++) {
									string numberpage1 = "dev:" + ofToString(int(i));
									for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
										for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
											if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
												vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
												for (int i = 0; i < clientgroupnumber.size(); ++i) {
													if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
														indexcountcopy++;
														autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "off" + ":";
														for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
														Sleep(25.0);
														autodatapacket1 = "";
														fridayoffevent[searchindex] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
#endif	
	}
	if (popupgrouppwronflag == 1 && eventdataload1 == true) {
		for (clientinedx = 1; clientinedx < 91; clientinedx++) {
			string numberpage1 = "dev:" + ofToString(int(clientinedx));
			for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
				for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
					if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
						vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
						for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
						autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "on" + ":";
						for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
						Sleep(25.0);
						autodatapacket1 = "";
						popupgrouppwronflag = 0;
						grouppwronflag = 0;
					}
				}
			}
		}
	}
	if (popupgrouppwroffflag == 1 && eventdataload1 == true) {
		for (clientinedx = 1; clientinedx < 91; clientinedx++) {
			string numberpage1 = "dev:" + ofToString(int(clientinedx));
			for (searchindex3 = 0; searchindex3 < csv.getNumRows(); searchindex3++) {
				for (searchindex4 = 0; searchindex4 < csv.getNumCols(searchindex3); searchindex4++) {
					if (numberpage1.compare(csv[searchindex3][searchindex4]) == 0) {
						vector<string>clientgroupmatchnum = ofSplitString(csv[searchindex3][searchindex4], ":");
						for (int i = 0; i < clientgroupmatchnum.size(); ++i)groupstron[i] = clientgroupmatchnum[i];
						autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + groupstron[1] + ":" + csv[searchindex3][searchindex4 + 2] + ":" + csv[searchindex3][searchindex4 + 3] + ":" + "off" + ":";
						for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
						Sleep(25.0);
						autodatapacket1 = "";
						popupgrouppwroffflag = 0;
						grouppwroffflag = 0;
					}
				}
			}
		}
	}
	if (popupgrouppwronflag == 1 && eventdataload1 == false) {
		indexcountcopy = 0;
		for (int groupindex = 1; groupindex < 21; groupindex++) {
			if (groupindex == groupconfigflag) {
				for (int i = 1; i < 91; i++) {
					string numberpage1 = "dev:" + ofToString(int(i));
					for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
						for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
							if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
								vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
								for (int i = 0; i < clientgroupnumber.size(); ++i) {
									if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
										indexcountcopy++;
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "on" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										autodatapacket1 = "";
										popupgrouppwronflag = 0;
										grouppwronflag = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (popupgrouppwroffflag == 1 && eventdataload1 == false) {
		indexcountcopy = 0;
		for (int groupindex = 1; groupindex < 21; groupindex++) {
			if (groupindex == groupconfigflag) {
				for (int i = 1; i < 91; i++) {
					string numberpage1 = "dev:" + ofToString(int(i));
					for (int groupindex1 = 0; groupindex1 < csv.getNumRows(); groupindex1++) {
						for (int groupindex2 = 0; groupindex2 < csv.getNumCols(groupindex1); groupindex2++) {
							if (numberpage1.compare(csv[groupindex1][groupindex2]) == 0) {
								vector<string>clientgroupnumber = ofSplitString(csv[groupindex1][groupindex2 + 4], ":");
								for (int i = 0; i < clientgroupnumber.size(); ++i) {
									if (ofToString(int(groupconfigflag)).compare(clientgroupnumber[i]) == 0) {
										indexcountcopy++;
										autodatapacket1 = ":" + ofToString(int(groupconfigflag)) + ":" + ofToString(int(indexcountcopy)) + ":" + csv[groupindex1][groupindex2 + 2] + ":" + csv[groupindex1][groupindex2 + 3] + ":" + "off" + ":";
										for (int i = 0; i < TCP.getLastID(); i++)TCP.send(i, autodatapacket1);
										Sleep(25.0);
										autodatapacket1 = "";
										popupgrouppwroffflag = 0;
										grouppwroffflag = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i = 1; i < 21; i++)groupbutton[i]->update();
	/*
	for (int i = 1; i < 5; i++)groupbutton[i]->update();
	for (int i = 5; i < 9; i++)groupbutton[i]->update();
	for (int i = 9; i < 13; i++)groupbutton[i]->update();
	for (int i = 13; i < 17; i++)groupbutton[i]->update();
	for (int i = 17; i < 21; i++)groupbutton[i]->update();
	*/
	/*-------------------------CLIENT NAME BUTTON UPDATE---------------------------------*/
	for (int i = 1; i < 91; i++)clientnameline1button[i]->update();
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------CLIENT TYPE BANNER UPDATE---------------------------------*/
	//for (int i = 1; i < 31; i++)line1typeHeader[i]->update();
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------CLIENT POWER ON UPDATE----------------------------------*/
	for (int i = 1; i < 91; i++)clientpwronbutton[i]->update();
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------CLIENT POWER OFF UPDATE----------------------------------*/
	for (int i = 1; i < 91; i++)clientpwroffbutton[i]->update();
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------GROUP CLEAR BUTTON UPDATE--------------------------------*/
	GROUPCLEARBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------GROUP APPLY BUTTON UPDATE--------------------------------*/
	GROUPAPPLYBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------CLIENT PC BUTTON UPDATE--------------------------------*/
	CLIENTPCBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------CLIENT PROJECTOR BUTTON UPDATE---------------------------*/
	CLIENTPRJBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT RELAY BUTTON UPDATE----------------------------*/
	CLIENTRELAYBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------CLIENT CONTACT BUTTON UPDATE---------------------------*/
	CLIENTCONTACTBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT GROUP BUTTON UPDATE----------------------------*/
	for (int i = 1; i < 21; i++)clientgroupnumberbutton[i]->update();
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT CLEAR BUTTON UPDATE----------------------------*/
	CLIENTCLEARBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT APPLY BUTTON UPDATE----------------------------*/
	CLIENTAPPLYBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------GROUP CONFIGURATION UPDATE----------------------------*/
	for(int i=1; i < 16; i++)groupconfigurationinput[i]->update();
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------CLIENT CONFIGURATION UPDATE----------------------------*/
	for (int i = 1; i < 4; i++)clientconfigurationinput[i]->update();
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------------ALLBUTTON UPDATE----------------------------------*/
	ALLBUTTON->update();
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------------GROUP POWER ON UPDATE-------------------------------*/
	GROUPPWRON->update();
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------GROUP POWER OFF UPDATE-------------------------------*/
	GROUPPWROFF->update();
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------CLIENT TYPE BANNER UPDATE----------------------------*/
	for (int i = 1; i < 91; i++)line1typeHeader[i]->update();
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------CLIENT INFO BANNER UPDATE----------------------------*/
	for (int i = 1; i < 91; i++)line1infoHeader[i]->update();
	/*-----------------------------------------------------------------------------------*/
	blanklabel1->update();
	grouplabel->update();
	clientlabel->update();
	/*--------------------------GROUP POPUP APPLY BUTTON UPDATE--------------------------*/
	if (grouppopupflag == 1) {
		GROUPPOPUPAPPLYBUTTON->update();
		GROUPPOPUPCANCELBUTTON->update();
	}
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------CLIENT POPUP APPLY BUTTON UPDATE-------------------------*/
	if (popupclientflag == 1) {
		notpushbutton = false;
		POPUPCLIENTAPPLYBUTTON->update();
		POPUPCLIENTCANCELBUTTON->update();
	}
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------GROUP POPUP CLEAR BUTTON UPDATE-------------------------*/
	if (groupclearpopupflag == 1) {
		POPUPGROUPCLEAROK->update();
		POPUPGROUPCLEARCANCEL->update();
	}
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------CLIENT POPUP CLEAR BUTTON UPDATE------------------------*/
	if (clientclearpopupflag == 1) {
		POPUPCLIENTCLEAROK->update();
		POPUPCLIENTCLEARCANCEL->update();
	}
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------GROUP POPUP PWR ON UPDATE----------------------------*/
	if (grouppwronflag == 1) {
		POPUPGROUPOK->update();
		POPUPGROUPCANCEL->update();
	}
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------GROUP POPUP PWR OFF UPDATE----------------------------*/
	if (grouppwroffflag == 1) {
		POPUPGROUPOFFOK->update();
		POPUPGROUPOFFCANCEL->update();
	}
	/*-----------------------------------------------------------------------------------*/
}

void GUI::draw() {
	int groupnumberinterval = 30;
	int groupnumberinterval1 = 30;
	int groupnumberinterval2 = 30;
	int groupnumberinterval3 = 30;
	int groupnumberinterval4 = 30;

	int clientinterval = 210;
	int clientinterval1 = 210;
	int clientinterval2 = 210;
	
	int circleinterval = 205;
	int circleinterval1 = 205;
	int circleinterval2 = 205;

	getbannerboxfont15("NINES",0,0,0,0,0,192,192,192,1204,60,25,35);
	getbannerboxfont15("PWR MANAGEMENT",100,2,76,71,67,213,213,213,1102,58,25,32);
	getbannerboxfontbold10("GROUP",0,62,211,211,211,1204,15,15,12);							// 0 
	getbannerboxfontbold10("GROUP CONFIGURATION",1205,62,211,211,211,430,15,15,12);
	getbannerboxfont10("GROUP NUM",1205,78, 76, 71, 67,96,15 + 7,250,250,250,5,15);    // 15 + 5
	getbannerboxfont10("GROUP NAME",1205,94 + 7, 76, 71, 67,96,15 + 7,250,250,250, 5, 15);
	getbannerboxfont10("",1205,110 + 14, 76, 71, 67,96,15 + 7,250,250,250,5,12);
	getbannerboxfont10("PWR ON",1205,126 + 21, 76, 71, 67,96,15 + 7,250,250,250,19,15);
	getbannerboxfont10("PWR OFF", 1205, 142 + 28, 76, 71, 67, 96, 15 + 7, 250, 250, 250, 19, 15);
	getbannerboxfontbold10("CLIENT CONFIGURATION", 1205, 237, 211, 211, 211, 430, 15, 15, 12);      //   170
	getbannerboxfont10("CLIENT NUM", 1206, 253, 76, 71, 67, 96, 15 + 5, 250, 250, 250, 5, 15);
	getbannerboxfont10("CLIENT NAME", 1206, 274, 76, 71, 67, 96, 15 + 5, 250, 250, 250, 5, 15);
	getbannerboxfont10("IP ADDRESS", 1206, 274 + 21, 76, 71, 67, 96, 15 + 5, 250, 250, 250, 5, 15);
	getbannerboxfont10("TYPE", 1206, 316, 76, 71, 67, 96, 15 + 5, 250, 250, 250, 28, 15);
	getbannerboxfont10("SUN", 1302, 110 + 14, 76, 71, 67, 50 - 4, 15 + 7, 250, 250, 250, 10, 15);      // 96
	getbannerboxfont10("MON", 1353-4, 110 + 14, 76, 71, 67, 50 - 4, 15 + 7, 250 + 5, 250, 250, 10, 15);
	getbannerboxfont10("TUE", 1404-8, 110 + 14, 76, 71, 67, 50 - 4, 15 + 7, 250, 250, 250, 10, 15);
	getbannerboxfont10("WED", 1455-12, 110 + 14, 76, 71, 67, 50 - 4, 15 + 7, 250, 250, 250, 10, 15);
	getbannerboxfont10("THU", 1506-16, 110 + 14, 76, 71, 67, 50 - 4, 15 + 7, 250, 250, 250, 10, 15);
	getbannerboxfont10("FRI", 1557-20, 110 + 14, 76, 71, 67, 50 - 4, 15 + 7, 250, 250, 250, 10, 15);
	getbannerboxfont10("SAT", 1608-24, 110 + 14, 76, 71, 67, 50 - 4, 15 + 7, 250, 250, 250, 10, 15);
	getbannerboxfont10("GROUP", 1206, 337, 76, 71, 67, 96, 104, 250, 250, 250, 25, 45);     // 79
	getbannerboxfont10("INFO", 1206, 337 + 105, 76, 71, 67, 96, 15 + 5, 250, 250, 250, 30, 12);
	getbannerboxfontbold10("CLIENT", 0, 202, 211, 211, 211, 1204, 15, 15, 12);
	getbannerboxfontcolor10("#", 0, 218, 76, 71, 67, 255, 255, 255, 32, 25, 10, 15);
	getbannerboxfontcolor10("PWR", 33, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);
	getbannerboxfontcolor10("NAME", 68, 218, 76, 71, 67, 255, 255, 255, 204 - 68, 25, 50, 15);						   
	getbannerboxfontcolor10("TYPE", 273 - 68, 218, 76, 71, 67, 255, 255, 255, 45, 25, 6, 15);                        // type                           
	getbannerboxfontcolor10("PWR", 319 - 68, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);                            
	getbannerboxfontcolor10("PWR", 354 - 68, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);                            
	getbannerboxfontcolor10("INFO", 389 - 68, 218, 76, 71, 67, 255, 255, 255, 80, 25, 25, 15);                          
	getbannerboxfontcolor10("#", 402, 218, 76, 71, 67, 255, 255, 255, 32, 25, 10, 15);
	getbannerboxfontcolor10("PWR", 503 - 68, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);
	getbannerboxfontcolor10("NAME", 538 - 68, 218, 76, 71, 67, 255, 255, 255, 204 - 68, 25, 50, 15);
	getbannerboxfontcolor10("TYPE", 743 - 136, 218, 76, 71, 67, 255, 255, 255, 45, 25, 6, 15);
	getbannerboxfontcolor10("PWR", 789 - 136, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);
	getbannerboxfontcolor10("PWR", 824 - 136, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);
	getbannerboxfontcolor10("INFO", 859 - 136, 218, 76, 71, 67, 255, 255, 255, 80, 25, 25, 15);
	getbannerboxfontcolor10("#", 940 - 136, 218, 76, 71, 67, 255, 255, 255, 32, 25, 10, 15);
	getbannerboxfontcolor10("PWR", 973 - 136, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);
	getbannerboxfontcolor10("NAME", 1008 - 136, 218, 76, 71, 67, 255, 255, 255, 204 - 68, 25, 50, 15);
	getbannerboxfontcolor10("TYPE", 1284 - 275, 218, 76, 71, 67, 255, 255, 255, 45, 25, 6, 15);
	getbannerboxfontcolor10("PWR", 1311 - 256, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);
	getbannerboxfontcolor10("PWR", 1346 - 256, 218, 76, 71, 67, 255, 255, 255, 34, 25, 2, 15);
	getbannerboxfontcolor10("INFO", 1381 - 256, 218, 76, 71, 67, 255, 255, 255, 80, 25, 25, 15);
	getbannerboxfont10("", 0, 1024, 76, 71, 67, 655, 70, 250, 250, 250, 30, 12);
	/*----------------------GROUP NUMBER BANNER DRAW-------------------------------------*/
	groupnumberbanner(31, 130, 78, 76 , 71, 67, 30, 30);
	for (int i = 1; i < 5; i++) {
		groupnumberinterval = ((32 - i) + i) + groupnumberinterval;
		ofSetColor(ofColor::white);
		verdana10.drawString(ofToString(int(i)),125 + 15,((32 - i) + i)+ groupnumberinterval);
	}
	groupnumberbanner(31, 345, 78, 76, 71, 67, 30, 30);
	for (int i = 5; i < 9; i++) {
		groupnumberinterval1 = ((32 - i) + i) + groupnumberinterval1;
		ofSetColor(ofColor::white);
		verdana10.drawString(ofToString(int(i)), 340 + 15, ((32 - i) + i) + groupnumberinterval1);
	}
	groupnumberbanner(31, 560, 78, 76, 71, 67, 30, 30);
	for (int i = 9; i < 13; i++) {
		groupnumberinterval2 = ((32 - i) + i) + groupnumberinterval2;
		ofSetColor(ofColor::white);
		verdana10.drawString(ofToString(int(i)), 555 + 13, ((32 - i) + i) + groupnumberinterval2);
	}
	groupnumberbanner(31, 775, 78, 76, 71, 67, 30, 30);
	for (int i = 13; i < 17; i++) {
		groupnumberinterval3 = ((32 - i) + i) + groupnumberinterval3;
		ofSetColor(ofColor::white);
		verdana10.drawString(ofToString(int(i)), 770 + 13, ((32 - i) + i) + groupnumberinterval3);
	}
	groupnumberbanner(31, 990, 78, 76, 71, 67, 30, 30);
	for (int i = 17; i < 21; i++) {
		groupnumberinterval4 = ((32 - i) + i) + groupnumberinterval4;
		ofSetColor(ofColor::white);
		verdana10.drawString(ofToString(int(i)), 985 + 13, ((32 - i) + i) + groupnumberinterval4);
	}
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------CLIENT STATE NUMBER------------------------------------*/
	clientline(26, 0, 244, 32, 25);
	for (int i = 1; i < 31; i++) {
		clientinterval = ((26 - i) + i) + clientinterval;
		ofSetColor(ofColor::white);
		if (i >= 1 && i < 10)verdana10.drawString(ofToString(int(i)), 10, (((26 - i) + i) + clientinterval));
		if (i >= 10 && i < 31)verdana10.drawString(ofToString(int(i)), 6, (((26 - i) + i) + clientinterval));
	}
	clientline(26, 402, 244, 32, 25);
	for (int i = 31; i < 61; i++) {
		clientinterval1 = ((26 - i) + i) + clientinterval1;
		ofSetColor(ofColor::white);
		verdana10.drawString(ofToString(int(i)), 408, (((26 - i) + i) + clientinterval1));
	}
	clientline(26, 804, 244, 32, 25);
	for (int i = 61; i < 91; i++) {
		clientinterval2 = ((26 - i) + i) + clientinterval2;
		ofSetColor(ofColor::white);
		verdana10.drawString(ofToString(int(i)), 810, (((26 - i) + i) + clientinterval2));
	}
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT STATE CHECK------------------------------------*/
	clientline(26, 33, 244, 34, 25);
	for (int i = 1; i < 31; i++) {
		circleinterval = ((26 - i) + i) + circleinterval;
		colormark(0, 0, 0, 49, ((26 - i) + i) + circleinterval, 5);
		if (clientstate[i] == i) {
			if (ofToInt(checkstate[i]) == 0) {
				colormark(0, 0, 0, 49, ((26 - i) + i) + circleinterval, 5);
			}
			if (ofToInt(checkstate[i]) == 1) {
				colormark(255, 255, 255, 49, ((26 - i) + i) + circleinterval, 5);
			}
			if (ofToInt(checkstate[i]) == 2) {                                            // on   
				colormark(0, 255, 0, 49, ((26 - i) + i) + circleinterval, 5);
			}
			if (ofToInt(checkstate[i]) == 3) {
				colormark(255, 0, 0, 49, ((26 - i) + i) + circleinterval, 5);
			}
		}
	}
	clientline(26, 435, 244, 34, 25);
	for (int i = 31; i < 61; i++) {
		circleinterval1 = ((26 - i) + i) + circleinterval1;
		colormark(0, 0, 0, 451, ((26 - i) + i) + circleinterval1, 5);
		if (clientstate[i] == i) {
			if (ofToInt(checkstate[i]) == 0) {
				colormark(0, 0, 0, 451, ((26 - i) + i) + circleinterval1, 5);
			}
			if (ofToInt(checkstate[i]) == 1) {
				colormark(255, 255, 255, 451, ((26 - i) + i) + circleinterval1, 5);
			}
			if (ofToInt(checkstate[i]) == 2) {                                            // on   
				colormark(0, 255, 0, 451, ((26 - i) + i) + circleinterval1, 5);
			}
			if (ofToInt(checkstate[i]) == 3) {
				colormark(255, 0, 0, 451, ((26 - i) + i) + circleinterval1, 5);
			}
		}
	}
	clientline(26, 837, 244, 34, 25);
	for (int i = 61; i < 91; i++) {
		circleinterval2 = ((26 - i) + i) + circleinterval2;
		colormark(0, 0, 0, 853, ((26 - i) + i) + circleinterval2, 5);
		if (clientstate[i] == i) {
			if (ofToInt(checkstate[i]) == 0) {
				colormark(0, 0, 0, 853, ((26 - i) + i) + circleinterval2, 5);
			}
			if (ofToInt(checkstate[i]) == 1) {
				colormark(255, 255, 255, 853, ((26 - i) + i) + circleinterval2, 5);
			}
			if (ofToInt(checkstate[i]) == 2) {                                            // on   
				colormark(0, 255, 0, 853, ((26 - i) + i) + circleinterval2, 5);
			}
			if (ofToInt(checkstate[i]) == 3) {
				colormark(255, 0, 0, 853, ((26 - i) + i) + circleinterval2, 5);
			}
		}
	}
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------CLIENT NAME BUTTON DRAW----------------------------------*/
	for (int i = 1; i < 91; i++)clientnameline1button[i]->draw();    // 91
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------CLIENT TYPE BANNER DRAW-----------------------------------*/
	//for (int i = 1; i < 31; i++)line1typeHeader[i]->draw();
	//clientline(26, 205, 244, 45, 25);
	//clientline(26, 607, 244, 45, 25);
	//clientline(26, 1009, 244, 45, 25);
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------CLIENT POWER ON DRAW------------------------------------*/
	for (int i = 1; i < 91; i++)clientpwronbutton[i]->draw();
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------CLIENT POWER OFF DRAW------------------------------------*/
	for (int i = 1; i < 91; i++)clientpwroffbutton[i]->draw();
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------CLIENT INFO BANNER DRAW----------------------------------*/
	//clientline(26,321,244,80,25);
	//clientline(26,723,244,80,25);
	//clientline(26,1125,244,80,25);     
	/*-----------------------------------------------------------------------------------*/
	for (int i = 1; i < 5; i++)groupbutton[i]->draw();
	for (int i = 5; i < 9; i++)groupbutton[i]->draw();
	for (int i = 9; i < 13; i++)groupbutton[i]->draw();
	for (int i = 13; i < 17; i++)groupbutton[i]->draw();
	for (int i = 17; i < 21; i++)groupbutton[i]->draw();
	/*---------------------------GROUP CLEAR BUTTON DRAW---------------------------------*/
	GROUPCLEARBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------GROUP APPLY BUTTON DRAW---------------------------------*/
	GROUPAPPLYBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT PC BUTTON DRAW---------------------------------*/
	CLIENTPCBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*---------------------------CLIENT PROJECTOR BUTTON DRAW----------------------------*/
	CLIENTPRJBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------CLIENT RELAY BUTTON DRAW------------------------------*/
	CLIENTRELAYBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------CLIENT CONTACT BUTTON DRAW-----------------------------*/
	CLIENTCONTACTBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------CLIENT GROUP BUTTON DRAW-----------------------------*/
	for (int i = 1; i < 21; i++)clientgroupnumberbutton[i]->draw();    // 1 ~ 21
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------CLIENT CLEAR BUTTON DRAW-----------------------------*/
	CLIENTCLEARBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------CLIENT APPLY BUTTON DRAW-----------------------------*/
	CLIENTAPPLYBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------------GROUP INPUT DRAW---------------------------------*/
	for (int i = 1; i < 16; i++)groupconfigurationinput[i]->draw();
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------------CLIENT INPUT DRAW----------------------------------*/
	for (int i = 1; i < 4; i++)clientconfigurationinput[i]->draw();
	/*-----------------------------------------------------------------------------------*/
	/*----------------------------------ALLBUTTON DRAW-----------------------------------*/
	ALLBUTTON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*--------------------------------GROUP POWER ON DRAW--------------------------------*/
	GROUPPWRON->draw();
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------------GROUP POWER OFF DRAW--------------------------------*/
	GROUPPWROFF->draw();
	/*-----------------------------------------------------------------------------------*/
	/*-------------------------------CLIENT TYPE BANNER DRAW-----------------------------*/
	for (int i = 1; i < 91; i++)line1typeHeader[i]->draw();
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------CLIENT INFO BANNER DRAW------------------------------*/
	for (int i = 1; i < 91; i++)line1infoHeader[i]->draw();
	/*-----------------------------------------------------------------------------------*/
	blanklabel1->draw();
	grouplabel->draw();
	clientlabel->draw();
	/*------------------------------GROUP APPLY BANNER DRAW------------------------------*/
	if (grouppopupflag == 1) {
		getbannerboxfontcolor10("Are you sure you want to apply?", 499, 339, 76, 71, 67, 250, 250, 250, 401, 50, 20, 30);
		GROUPPOPUPAPPLYBUTTON->draw();
		GROUPPOPUPCANCELBUTTON->draw();
	}
	/*-----------------------------------------------------------------------------------*/
	/*------------------------------CLIENT APPLY BANNER DRAW-----------------------------*/
	if (popupclientflag == 1) {
		getbannerboxfontcolor10("Are you sure you want to apply?", 499, 339, 76, 71, 67, 250, 250, 250, 401, 50, 20, 30);
		POPUPCLIENTAPPLYBUTTON->draw();
		POPUPCLIENTCANCELBUTTON->draw();
	}
	/*-----------------------------------------------------------------------------------*/
	if (groupclearpopupflag == 1) {
		getbannerboxfontcolor10("Are you sure you want to delete?", 499, 339, 76, 71, 67, 250, 250, 250, 401, 50, 20, 30);
		POPUPGROUPCLEAROK->draw();
		POPUPGROUPCLEARCANCEL->draw();
	}
	if (clientclearpopupflag == 1) {
		getbannerboxfontcolor10("Are you sure you want to delete?", 499, 339, 76, 71, 67, 250, 250, 250, 401, 50, 20, 30);
		POPUPCLIENTCLEAROK->draw();
		POPUPCLIENTCLEARCANCEL->draw();
	}
	/*------------------------------GROUP PWR ON BANNER DRAW------------------------------*/
	if (grouppwronflag == 1) {
		getbannerboxfontcolor10("Do you want to turn on all clients in the current group?", 499, 339, 76, 71, 67, 250, 250, 250, 401, 50, 20, 30);
		POPUPGROUPOK->draw();
		POPUPGROUPCANCEL->draw();
	}
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------GROUP PWR OFF BANNER DRAW-----------------------------*/
	if (grouppwroffflag == 1) {
		getbannerboxfontcolor10("Do you want to turn off all clients in the current group?", 499, 339, 76, 71, 67, 250, 250, 250, 401, 50, 20, 30);
		POPUPGROUPOFFOK->draw();
		POPUPGROUPOFFCANCEL->draw();
	}
	/*-----------------------------------------------------------------------------------*/

#if 1
	gui.begin();
	ImGui::Begin("LOG DATA", &show_another_window);
	ImGui::SetWindowPos(ofVec2f(1206.0, 508.0));
	ImGui::SetWindowSize(ImVec2(430, 570));
	datalog.open("datalog.xml", ofFile::ReadOnly);
	ofBuffer buf = datalog.readToBuffer();
	datalog.close();
	string dataoutput = buf.getText();
	const char* datadate = dataoutput.c_str();
	ImGui::Text(datadate);
	ImGui::End();
	gui.end();
#endif
}

