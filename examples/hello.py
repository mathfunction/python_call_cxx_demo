
import sys
sys.path.append("../build/")
import cxxDeviceModule as cxx
import numpy as np
if __name__ == '__main__':

	d = [
		{"apple":1,"banana":2.0},
		{"abc":2,"casd":3.0,"3094":4.0}
	]
	d = cxx.passJson("print",d)
	cxx.passStr("print","testABC");
	



	print(cxx.passFloatNumpySameShape("print",np.array([[1.012,2.34,3.56,4.678,5.123,6.345],[4.345,5.35,6.45,7.545,8.5,9.66]])))
	print(cxx.passIntNumpySameShape("print",np.array([[1,2,3,4,5,6],[1,5,2,7,8,9]])))
	print(cxx.passFloatNumpy("sum->1",np.array([1.0,2.0,3.0,4.0,5.0]),[1]))


	
	