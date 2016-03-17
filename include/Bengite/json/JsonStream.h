#pragma once

#include <string>
#include <fstream>
#include <json/json.h>

using namespace std;

namespace bengite { namespace content {
	
class JsonStream {
private:

	static fstream _stream;

public:

	static Json::Value OpenJson(const string&);
	static bool SaveJson(const string&, const Json::Value&);

protected:

};
	
}}