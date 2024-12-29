#include "Schedule.h"

string dayoftheweek, aday, amonth, ayear, timeframe, ahour, aminute, asecond;
int  mondaystart, tusedaystart, wensdaystart, thursdaystart, fridaystart, sundaystart;
int  eventsunday, eventmonday, eventtuesday, eventwensday, eventthursday, eventfriday, eventsatday;

vector<string> event_split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		internal.push_back(temp);
	}
	return internal;
}

void SCHEDULE::setup() {

}

void SCHEDULE::update() {
	Poco::Timestamp now;
	Poco::LocalDateTime nowLocal(now);

	std::string fmt = Poco::DateTimeFormat::RFC1123_FORMAT + " %F ";
	string timestamp = ofxTime::Utils::format(nowLocal, fmt);

	vector<string>event_vector = event_split(timestamp, ',');
	for (int i = 0; i < event_vector.size(); ++i) {
		dayoftheweek = event_vector[0];
	}
	vector<string>event_vector1 = event_split(timestamp, ' ');
	for (int i = 0; i < event_vector1.size(); ++i) {
		aday = event_vector1[1];
		amonth = event_vector1[2];
		ayear = event_vector1[3];
		timeframe = event_vector1[4];
	}
	vector<string>event_vector2 = event_split(timeframe, ':');
	for (int i = 0; i < event_vector2.size(); ++i) {
		ahour = event_vector2[0];
		aminute = event_vector2[1];
		asecond = event_vector2[2];
	}
	if (dayoftheweek.compare("Mon") == 0) {
		mondaystart = 1;
		eventmonday = 1;
	}
	if (dayoftheweek.compare("Tue") == 0) {
		tusedaystart = 1;
		eventtuesday = 1;
	}
	if (dayoftheweek.compare("Wed") == 0) {
		wensdaystart = 1;
		eventwensday = 1;
	}
	if (dayoftheweek.compare("Thu") == 0) {
		thursdaystart = 1;
		eventthursday = 1;
	}
	if (dayoftheweek.compare("Fri") == 0) {
		fridaystart = 1;
		eventfriday = 1;
	}
}

void SCHEDULE::draw() {

}