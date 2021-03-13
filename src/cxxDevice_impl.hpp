/*==================================================
	implement c++ code here !! 
====================================================*/

#ifndef __CXXDEVICE_IMPL_HPP__
#define __CXXDEVICE_IMPL_HPP__
#include <iostream>

//=====================================================================================================================

inline nlohmann::json CxxDeviceJsonFuncList(const std::string funcname,nlohmann::json &j){
	if(funcname == "print"){
		std::cout << "=====================================================" << "\n";
		std::cout << j  << "\n";
		std::cout << "=====================================================" << "\n";
	}//endif

	if (funcname == "test"){
		j["test"] = "ok";
	}//endifs
	return j;
}//end

//==================================================================================================================

inline std::string CxxDeviceStringFuncList(const std::string funcname,std::string &str){
	if(funcname == "print"){
		str = "[ pass this string to c++ ]";
		std::cout  << str << std::endl;
	}//endif
	return str;
}//end

//======================================================================================================================

#endif