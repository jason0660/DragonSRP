
#ifndef DSRP_OSSL_SHA512_HPP
#define DSRP_OSSL_SHA512_HPP

#include "dsrp/common.hpp"
#include "dsrp/hashinterface.hpp"

namespace DragonSRP
{
	class OsslSha512 : public HashInterface
	{
		public:
			~OsslSha512();
			bytes hash(const bytes &in);
			unsigned int outputLen();
	};
}


#endif