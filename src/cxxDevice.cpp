/*===================================================================================
 	Python Call C++ double Copy framework
	
	Passing :
	- String
 	- Json 


======================================================================================*/
#include <iostream>
#include <vector>
#include "json.hpp"  // https://github.com/nlohmann/json/tree/develop/include/nlohmann
#include "cxxDevice_impl.hpp"

namespace CxxDevice{
	std::string StringInput,StringOutput;
	nlohmann::json JsonInput,JsonOutput;
	std::string JsonStrOutput;
	std::vector<float> FloatVectorInput,FloatVectorOutput;
};


extern "C"{

	const char* passString(const char* funcname,const char* c_str){
		CxxDevice::StringInput = std::string(c_str);
		CxxDevice::StringOutput = CxxDevice::StringFuncList(funcname,CxxDevice::StringInput);
		return CxxDevice::StringOutput.data();
	}//end_passString


	const char* passJson(const char* funcname,const char* json_ptr){
		CxxDevice::JsonInput = nlohmann::json::parse(json_ptr);
		CxxDevice::JsonOutput = CxxDevice::JsonFuncList(funcname,CxxDevice::JsonInput);  // practical implementation 
		CxxDevice::JsonStrOutput = CxxDevice::JsonOutput.dump();
		return CxxDevice::JsonStrOutput.data();
	}//endhandleJson

	float* passFloatPointer(const char* funcname,float* f,size_t n){
		CxxDevice::FloatVectorInput.assign(f,f+n);
		CxxDevice::FloatVectorOutput = CxxDevice::FloatVectorFuncList(funcname,CxxDevice::FloatVectorInput);
		return CxxDevice::FloatVectorOutput.data();
	}//end_



};
