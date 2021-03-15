/*==================================================
	implement c++ code connection here !!! 
====================================================*/

#ifndef __CXXDEVICE_IMPL_HPP__
#define __CXXDEVICE_IMPL_HPP__


//=====================================================================================================================
namespace CxxDevice{

	inline nlohmann::json JsonFuncList(const std::string funcname,nlohmann::json &j){
		if(funcname == "print"){
			std::cout << "=====================================================\n";
			std::cout << j  << "\n";
			std::cout << "=====================================================\n";
			return j;
		}else{
			return j; // default return 
		}//end_else
	}//end

	//==================================================================================================================

	inline std::string StringFuncList(const std::string funcname,std::string &str){
		if(funcname == "print"){
			std::cout << "=====================================================\n";
			std::cout  << str << std::endl;
			std::cout << "=====================================================\n";
			return str;
		}else{
			return str; // default return 
		}//end_else
	}//end


	inline std::vector<float> FloatVectorFuncList(const std::string funcname,std::vector<float> &v){
		if(funcname == "print"){
			std::cout << "=====================================================\n";
			for(int i=0;i<v.size();i++){
				std::cout << "[" << i << "] = " << v[i] << "\n";
			}//endfor
			std::cout << "=====================================================\n";
			return v;
		}else if(funcname == "sum->1"){
			float _sum = 0.0;
			for(int i=0;i<v.size();i++){
				_sum += v[i];
			}//endfor
			return {_sum};
		}else{
			return v; // default return 
		}//end_else
	}


	inline std::vector<int> IntVectorFuncList(const std::string funcname,std::vector<int> &v){
		if(funcname == "print"){
			std::cout << "=====================================================\n";
			for(int i=0;i<v.size();i++){
				std::cout << "[" << i << "] = " << v[i] << "\n";
			}//endfor
			std::cout << "=====================================================\n";
			return v;
		}else{
			return v; // default return 
		}//end_else
	}//end_IntVectorFuncList



};
//======================================================================================================================

#endif