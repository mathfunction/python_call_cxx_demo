
import sys
sys.path.append("../build/")
import cxxDeviceModule as cxx

if __name__ == '__main__':

	d = {
		"apple":1,
		"banana":2.0
	}
	d = cxx.passJson("test",d)
	cxx.passJson("print",d)
	