#include "Core/RNG.h"

#include <chrono>

using namespace bengite::core;

unsigned int RNG::_seed = chrono::system_clock::now().time_since_epoch().count();

mt19937 RNG::_RNGBase;
Real_RNG RNG::_floatGen = nullptr;
Int_RNG RNG::_intGen = nullptr;

void RNG::Initialize() {
	
	_RNGBase.seed(_seed);
	_floatGen.reset(new uniform_real_distribution<float>(0.0f, 100.0f));
	_intGen.reset(new uniform_int_distribution<int>(0, 100));
	
}

int RNG::getInt() {
	
	return _intGen->operator()(_RNGBase);
	
}

int RNG::getInt(const int& max) {
	
	return (max / 100) * _intGen->operator()(_RNGBase);
	
}

int RNG::getInt(const int& min, const int& max) {
	
	return (max / 100.0f) * _intGen->operator()(_RNGBase) + min;
	
}

float RNG::getFloat() {
	
	return _floatGen->operator()(_RNGBase);
	
}

float RNG::getFloat(const float& max) {
	
	return (max / 100.0f) * _floatGen->operator()(_RNGBase);
	
}

float RNG::getFloat(const float& min, const float& max) {
	
	return (max / 100.0f) * _floatGen->operator()(_RNGBase) + min;
	
}

unsigned int RNG::getSeed() {
	
	return _seed;
	
}