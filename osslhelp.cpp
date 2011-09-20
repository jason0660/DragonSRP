

#include <string.h>
#include <stdlib.h>
#include "osslhelp.hpp"

namespace Dsrp
{
	void bytes2bignum(const bytes &in, BIGNUM *out)
	{
		unsigned char *bytesIn = (unsigned char*) malloc(sizeof(unsigned char) * in.size());
		// should check if bytesIn==NULL !!!!!
		copy(in.begin(), in.end(), bytesIn);
		BN_bin2bn(bytesIn, in.size(), out);
		free(bytesIn);
	}
	
	void bignum2bytes(BIGNUM *in, bytes& out)
	{
		int len = BN_num_bytes(in);
		unsigned char *bytes = (unsigned char *) malloc(sizeof(unsigned char) * len);
		out.resize(len); // important, otherwise SIGSEGV
		// should check if bytesIn==NULL !!!!!
		copy(bytes, bytes + len, out.begin());
		free(bytes);
	}
	
	// return value must be deallocated with free!
	unsigned char *bytes2array(const bytes &in, int *lenout)
	{
		unsigned char *bytesIn = (unsigned char*) malloc(sizeof(unsigned char) * in.size());
		// should check if bytesIn==NULL !!!!!
		copy(in.begin(), in.end(), bytesIn);
		*lenout = in.size();
		return bytesIn;
	}
	
	// returns without \0
	void string2bytes(const std::string &str, bytes &out)
	{
		const char *s = str.c_str();
		out.resize(str.size()); // important, otherwise SIGSEGV
		copy(s, s + str.size(), out.begin());
	}
	
	// returns without \0
	bytes string2bytes(const std::string &str)
	{
		bytes out;
		const char *s = str.c_str();
		out.resize(str.size()); // important, otherwise SIGSEGV
		copy(s, s + str.size(), out.begin());
		return out;
	}
	
	// returns without \0
	bytes string2bytes(const char *str)
	{
		bytes out;
		out.resize(strlen(str)); // important, otherwise SIGSEGV
		copy(str, str + strlen(str), out.begin());
		return out;
	}
	
}
