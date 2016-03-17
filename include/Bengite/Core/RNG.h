/*
*	Name: Static Random Number Generator
*	Description: manages RNG with C++ functions
*/

#pragma once

#include <random>
#include <memory>

using namespace std;

namespace bengite { namespace core {
	
typedef unique_ptr<uniform_real_distribution<float>> Real_RNG;
typedef unique_ptr<uniform_int_distribution<int>> Int_RNG;
	
class RNG {
private:

	static unsigned int _seed;
	static mt19937 _RNGBase;
	static Real_RNG _floatGen;
	static Int_RNG _intGen;
 
public:

	static void Initialize();
	
	static int getInt();
	static int getInt(const int&);
	static int getInt(const int&, const int&);
	
	static float getFloat();
	static float getFloat(const float&);
	static float getFloat(const float&, const float&);
	
	static unsigned int getSeed();

protected:
	
};
	
	
}}