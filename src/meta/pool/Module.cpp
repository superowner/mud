#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module mud.pool;
#else
#include <type/Vector.h>
#include <type/Any.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/infra/Module.h>
#include <meta/type/Module.h>
#include <meta/pool/Module.h>
#include <meta/pool/Convert.h>
#endif

#include <pool/Api.h>

namespace mud
{
	void mud_pool_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	// mud::HandlePool
	{
		Type& t = type<mud::HandlePool>();
		static Meta meta = { t, &namspc({ "mud" }), "HandlePool", sizeof(mud::HandlePool), TypeClass::Object };
		// defaults
		static Class cls = { t,
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::HandlePool>();
	}
	// mud::Pool
	{
		Type& t = type<mud::Pool>();
		static Meta meta = { t, &namspc({ "mud" }), "Pool", sizeof(mud::Pool), TypeClass::Object };
		// defaults
		static Class cls = { t,
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::Pool>();
	}
		m.m_types.push_back(&type<mud::HandlePool>());
		m.m_types.push_back(&type<mud::Pool>());
	}
}

namespace mud
{
	mud_pool::mud_pool()
		: Module("mud::pool", { &mud_infra::m(), &mud_type::m() })
	{
		// setup reflection meta data
		mud_pool_meta(*this);
	}
}

#ifdef MUD_POOL_MODULE
extern "C"
Module& getModule()
{
		return mud_pool::m();
}
#endif
