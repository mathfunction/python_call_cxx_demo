/*==================================================
	implement c++ code here !! 
====================================================*/

#ifndef __CXXDEVICE_IMPL_HPP__
#define __CXXDEVICE_IMPL_HPP__
#include <iostream>


inline nlohmann::json CxxDeviceFuncList(const std::string funcname,nlohmann::json &j){
	if (funcname == "print"){
		std::cout << "=====================================================" << "\n";
		std::cout << j  << "\n";
		std::cout << "=====================================================" << "\n";
	}

	if (funcname == "test"){
		j["test"] = "ok";
	}

	return j;
}//endPyCableFuncList



#endif