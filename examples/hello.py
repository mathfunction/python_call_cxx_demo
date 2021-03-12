import sys
sys.path.append("../src/")
import cxxDevice as cxx




if __name__ == '__main__':

	d = {
		"apple":1,
		"banana":2.0
	}
	cxx.passJson("print",d)