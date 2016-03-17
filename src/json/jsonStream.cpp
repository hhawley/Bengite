#include "json/jsonStream.h"

using namespace bengite::content;

fstream JsonStream::_stream;

Json::Value JsonStream::OpenJson(const string& name) {
	
	Json::Value out;
	_stream.open(name, fstream::in | fstream::binary);
	
	if(_stream.is_open()) {
		
		_stream >> out;

	}
	
	_stream.close();
	
	return out;
	
}

bool JsonStream::SaveJson(const string& name, const Json::Value& save) {
	
	_stream.open(name, fstream::out | fstream::binary);
	
	if(_stream.is_open()) {
		
		_stream << save;
		
		_stream.close();
		
		return true;
		
	} else {
		
		_stream.close();
		
		return false;
		
	}
	
	
}
