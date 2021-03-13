/*==================================================
	implement c++ code here !! 
====================================================*/

#ifndef __CXXDEVICE_IMPL_HPP__
#define __CXXDEVICE_IMPL_HPP__


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


inline std::vector<float> CxxDeviceFloatVectorFuncList(const std::string funcname,std::vector<float> &v){
	
	if(funcname == "print"){
		for(int i=0;i<v.size();i++){
			std::cout << "[" << i << "] = " << v[i] << "\n";
		}//endfor
	}

	if(funcname == "zero"){
		for(int i=0;i<v.size();i++){
			v[i] = 0.0;
		}//endfor
	}

	return v;
}



//======================================================================================================================

#endif