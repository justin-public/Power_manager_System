#ifndef _EXTERN_H
#define _EXTERN_H

#include "ofMain.h"

extern string groupbannername[21];
extern string groupnumbername_pass[21];
extern string tuesdaytime_on[21], wensdaytime_on[21], thursdaytime_on[21], fridaytime_on[21];
extern string tuesdaytime_off[21], wensdaytime_off[21], thursdaytime_off[21], fridaytime_off[21];
extern string clientgroupname_pass[91];
extern string clientgroupipaddress_pass[91];
extern string clienttypepc_pass[91];
extern string clientgroupnumber_pass[91];
extern string clientgroupinfo_pass[91];

extern string mondaystr[2], mondaystr1[1], mondaystr2[1], mondaystr3[1];
extern string mondaystroff[2], mondaystroff1[1], mondaystroff2[1], mondaystroff3[1];

extern string tuesdaystr[2], tuesdaystr1[1], tuesdaystr2[1], tuesdaystr3[1];
extern string tuesdaystroff[2], tuesdaystroff1[1], tuesdaystroff2[1], tuesdaystroff3[1];

extern string wensdaystr[2], wensdaystr1[1], wensdaystr2[1], wensdaystr3[1];
extern string wensdaystroff[2], wensdaystroff1[1], wensdaystroff2[1], wensdaystroff3[1];

extern string groupstron[1];
extern string groupstroff[1];

extern string onofftime[21], csvtime[21], csvtime1[21], csvtime2[21];
extern string csvtimeoff[21], csvtimeoff1[21], csvtimeoff2[21];
extern string csvdaton[21];
extern string csvdatoff[21];
extern string clientline1name[91];

extern string dayoftheweek, aday, amonth, ayear, timeframe, ahour, aminute, asecond;
extern int  mondaystart, tusedaystart, wensdaystart, thursdaystart, fridaystart, sundaystart;
extern int  eventsunday, eventmonday, eventtuesday, eventwensday, eventthursday, eventfriday, eventsatday;

extern bool trigger;
extern bool typetrigger;

extern int clientstate[91];
extern int init_data_load;

extern string submitlabel[91];
extern string autodatapacket;
extern string autodatapacket1;
extern string grouponpacket[91];

extern int grouppwronflag;
extern int grouppwroffflag;
extern int popupgrouppwronflag;
extern int popupgrouppwroffflag;

extern string datacmd;

/*--------------------------------------------*/
extern string groupnumberlabelstr[1];
extern string grouplist[21];
extern string checkstate[91];
extern int checklogic;
extern int clientclearflag;
/*--------------------------------------------*/
#endif
