#include "Graphics/Controls/ControlManager.h"

#include "Graphics/DrawingManager.h"

#include "Graphics/Controls/Button.h"
#include "Graphics/Controls/MaskedNumericIndicator.h"
#include "Graphics/Controls/NumericIndicator.h"
#include "Graphics/Controls/ProgressBar.h"
#include "Graphics/Controls/TextBox.h"
#include "Graphics/Controls/TextIndicator.h"

#include <json/json.h>
#include "json/jsonStream.h"

using namespace bengite::core;
using namespace bengite::content;
using namespace bengite::graphics;

ControlManagerMap ControlManager::_controlDictionary;

void ControlManager::Update(const GameTime& gameTime) {
	
	for(const auto& it : _controlDictionary)
		it.second->Update(gameTime);

}

void ControlManager::add(Control* control) {

	_controlDictionary[control->getName()].reset(control);
	DrawingManager::addDraw(*control);

}

Control* ControlManager::getByName(const string& name) {

	return _controlDictionary[name].get();

}

void ControlManager::clear() {

	_controlDictionary.clear();

}

void ControlManager::readTemplate(const string& path) {

	Json::Value mainChunk = JsonStream::OpenJson(path);

	if(mainChunk.isArray()) {

		for(auto& member : mainChunk) {

			string name = member.getMemberNames()[0];
			if(name == "button") {

				Button* control = new Button("", "");
				control->fromJson(member[name]);
				add(control);

			} else if(name == "maskedNumericIndicator") {

				MaskedNumericIndicator* control = new MaskedNumericIndicator("", 3, 0);
				control->fromJson(member[name]);
				add(control);

			} else if(name == "numericIndicator") {

				NumericIndicator* control = new NumericIndicator("", 0);
				control->fromJson(member[name]);
				add(control);

			} else if(name == "progressBar") {

				ProgressBar* control = new ProgressBar("", 100);
				control->fromJson(member[name]);
				add(control);

			} else if(name == "textBox") {

				TextBox* control = new TextBox("");
				control->fromJson(member[name]);
				add(control);

			} else if(name == "textIndicator") {

				TextIndicator* control = new TextIndicator("", "");
				control->fromJson(member[name]);
				add(control);

			}

		}
	}

}

void ControlManager::saveCurrentTemplate(const string& path) {

	Json::Value values(Json::arrayValue);
	int i = 0;
	for(const auto& control : _controlDictionary) {

		values[i++] = control.second->toJson();

	}

	JsonStream::SaveJson(path, values);

}