#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<cstdlib>

using namespace std;

//Cut String
string cutString(string s, int start, int end){
	return(s.substr(start, end));
}

//Convert Int to String 
string ItoS(long i){
	stringstream s;
	s << i;
	return s.str();
}

//Multiple 
long multi(long X, long Y){
	int flags[2] = {1, 1};
	if(X < 0)
		flags[0] = -1;
	if(Y < 0)
		flags[1] = -1;
	
	string x = ItoS(abs(X));
	string y = ItoS(abs(Y));
	int lenX = x.length();
	int lenY = y.length();
	
	if(lenX > 2){
	
		long a = abs(atoi(cutString(x, 0, lenX/2).c_str()));
		long b = abs(atoi(cutString(x, lenX/2, lenX).c_str()));
		long c = abs(atoi(cutString(y, 0, lenY/2).c_str()));
		long d = abs(atoi(cutString(y, lenY/2, lenY).c_str()));
		long a_b = a - b;
		long d_c = d - c;

		return(flags[0]*flags[1]*(multi(a, c) * pow(10, lenX)
			   + (multi(a_b, d_c) + multi(a, c) + multi(b, d)) 
			   * pow(10, lenX/2) + multi(b, d)
				));
	}

	else
		return X * Y;
}

int main(){
	long X = 12345678;
	long Y = 12345678;
	cout<<multi(X, Y)<<endl;
	return 0;
}
