/*===================================================================================
 	Python Call C++ Passsing Json 
======================================================================================*/
#include "json.hpp"  // https://github.com/nlohmann/json/tree/develop/include/nlohmann
#include "cxxDevice_impl.hpp"

extern "C"{
	std::string CxxDeviceJsonOutput = "{}";
	char* passJson(const char* funcname,const char* json_ptr){
		std::string json_str(json_ptr);
		nlohmann::json j = nlohmann::json::parse(json_str);
		CxxDeviceFuncList(funcname,j);  // practical implementation 
		CxxDeviceJsonOutput = j.dump();
		return &CxxDeviceJsonOutput[0];
	}//endhandleJson
	
};
