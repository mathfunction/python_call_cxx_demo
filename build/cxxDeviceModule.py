import os
import json
import ctypes
import numpy as np


ThisFileDIR = os.path.dirname(os.path.abspath(__file__))
#=======================================================================================================
cxxDevice = ctypes.cdll.LoadLibrary(ThisFileDIR+"/cxxDevice.so")
print("load {}/cxxDevice.so".format(ThisFileDIR))


cxxDevice.passJson.argtypes = [ctypes.c_char_p,ctypes.c_char_p]
cxxDevice.passJson.restype = ctypes.c_char_p
cxxDevice.passString.argtypes = [ctypes.c_char_p,ctypes.c_char_p]
cxxDevice.passString.restype = ctypes.c_char_p
cxxDevice.passFloatPointer.argtypes = [ctypes.c_char_p,ctypes.POINTER(ctypes.c_float),ctypes.c_size_t]
cxxDevice.passFloatPointer.restype = ctypes.POINTER(ctypes.c_float)
#========================================================================================================
def passJson(funcname,d):
	return json.loads(
		cxxDevice.passJson(
			funcname.encode('utf-8'),
			json.dumps(d).encode('utf-8')
		).decode("utf-8")
	)


def passFloatNumpySameShape(funcname,np_array):
	fptr = cxxDevice.passFloatPointer(
		funcname.encode('utf-8'),
		np_array.astype(np.float32).ctypes.data_as(ctypes.POINTER(ctypes.c_float)),np_array.size
	)
	return np.ctypeslib.as_array(fptr,(np_array.size,)).copy().reshape(np_array.shape)



def passStr(funcname,_str):
	return cxxDevice.passString(
		funcname.encode('utf-8'),
		_str.encode('utf-8')
	).decode("utf-8")




