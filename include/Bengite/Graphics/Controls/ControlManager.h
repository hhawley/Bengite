#pragma once

#include <map>
#include <memory>
#include <string>

#include "Core/GameTime.h"
#include "Graphics/Controls/Control.h"

using namespace std;
using namespace bengite::core;

namespace bengite { namespace graphics {

typedef shared_ptr<Control> ControlPtr;
typedef map<string, ControlPtr> ControlManagerMap;
typedef unique_ptr<ControlManagerMap> ControlManagerMapPtr;

class ControlManager {
private:

	static ControlManagerMap _controlDictionary;

public:

	static void Update(const GameTime&);
	static void add(Control*);
	static Control* getByName(const string&);
	static void clear();

	static void readTemplate(const string&);
	static void saveCurrentTemplate(const string&);

protected:

};

}}