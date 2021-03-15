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
cxxDevice.passIntPointer.argtypes = [ctypes.c_char_p,ctypes.POINTER(ctypes.c_int),ctypes.c_size_t]
cxxDevice.passIntPointer.restype = ctypes.POINTER(ctypes.c_int)


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


def passIntNumpySameShape(funcname,np_array):
	iptr = cxxDevice.passIntPointer(
		funcname.encode('utf-8'),
		np_array.astype(np.int32).ctypes.data_as(ctypes.POINTER(ctypes.c_int)),np_array.size
	)
	return np.ctypeslib.as_array(iptr,(np_array.size,)).copy().reshape(np_array.shape)

def passFloatNumpy(funcname,np_input,np_output_dim):
	fptr = cxxDevice.passFloatPointer(
		funcname.encode('utf-8'),
		np_input.astype(np.float32).ctypes.data_as(ctypes.POINTER(ctypes.c_float)),np_input.size
	)
	return np.ctypeslib.as_array(fptr,(np.prod(np_output_dim),)).copy().reshape(np_output_dim)



def passIntNumpy(funcname,np_input,np_output_dim):
	fptr = cxxDevice.passFloatPointer(
		funcname.encode('utf-8'),
		np_input.astype(np.int32).ctypes.data_as(ctypes.POINTER(ctypes.c_int)),np_input.size
	)
	return np.ctypeslib.as_array(fptr,(np.prod(np_output_dim),)).copy().reshape(np_output_dim)




def passStr(funcname,_str):
	return cxxDevice.passString(
		funcname.encode('utf-8'),
		_str.encode('utf-8')
	).decode("utf-8")




