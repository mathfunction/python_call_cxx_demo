/*===================================================================================
 	Python Call C++ 
	
	Passing :
	- String
 	- Json 


======================================================================================*/
#include <iostream>
#include <vector>
#include "json.hpp"  // https://github.com/nlohmann/json/tree/develop/include/nlohmann
#include "cxxDevice_impl.hpp"

extern "C"{

	std::string CxxDeviceStringOutput = "";
	char* passString(const char* funcname,const char* c_str){
		std::string str(c_str);
		CxxDeviceStringOutput = CxxDeviceStringFuncList(funcname,str);
		return &CxxDeviceStringOutput[0];
	}//end_passString


	std::string CxxDeviceJsonOutput = "{}";
	char* passJson(const char* funcname,const char* json_ptr){
		nlohmann::json j = nlohmann::json::parse(json_ptr);
		CxxDeviceJsonFuncList(funcname,j);  // practical implementation 
		CxxDeviceJsonOutput = j.dump();
		return &CxxDeviceJsonOutput[0];
	}//endhandleJson

	
	std::vector<float> CxxDeviceFloatVectorInput;
	std::vector<float> CxxDeviceFloatVectorOutput;
	float* passFloatPointer(const char* funcname,float* f,size_t n){
		CxxDeviceFloatVectorInput.assign(f,f+n);
		CxxDeviceFloatVectorOutput = CxxDeviceFloatVectorFuncList(funcname,CxxDeviceFloatVectorInput);
		return CxxDeviceFloatVectorOutput.data();
	}//end_


};
