import os
import platform
import json
import ctypes


ThisFileDIR = os.path.dirname(os.path.abspath(__file__))
#=======================================================================================================
if platform.system() == "Windows":
	cxxFunc = ctypes.cdll.LoadLibrary(ThisFileDIR+"/../lib/cxxDevice.dll")
else:
	cxxFunc = ctypes.cdll.LoadLibrary(ThisFileDIR+"/../lib/cxxDevice.so")
print("load {}/cxxDevice(.dll/.so)".format(ThisFileDIR))
cxxFunc.passJson.argtypes = [ctypes.c_char_p,ctypes.c_char_p]
cxxFunc.passJson.restype = ctypes.c_char_p
#========================================================================================================
def passJson(funcname,d):
	return json.loads(
		cxxFunc.passJson(
			funcname.encode('utf-8'),
			json.dumps(d).encode('utf-8')
		).decode("utf-8")
	)




