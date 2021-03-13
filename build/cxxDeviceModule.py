import os
import json
import ctypes


ThisFileDIR = os.path.dirname(os.path.abspath(__file__))
#=======================================================================================================
cxxFunc = ctypes.cdll.LoadLibrary(ThisFileDIR+"/cxxDevice.so")
print("load {}/cxxDevice.so".format(ThisFileDIR))


cxxFunc.passJson.argtypes = [ctypes.c_char_p,ctypes.c_char_p]
cxxFunc.passJson.restype = ctypes.c_char_p
cxxFunc.passString.argtypes = [ctypes.c_char_p,ctypes.c_char_p]
cxxFunc.passString.restype = ctypes.c_char_p
#========================================================================================================
def passJson(funcname,d):
	return json.loads(
		cxxFunc.passJson(
			funcname.encode('utf-8'),
			json.dumps(d).encode('utf-8')
		).decode("utf-8")
	)


def passStr(funcname,_str):
	return cxxFunc.passString(
		funcname.encode('utf-8'),
		_str.encode('utf-8')
	).decode("utf-8")


