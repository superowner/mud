#pragma once

#include <mud/frame.h>
#include <mud/refl.h>
#include <mud/infra.h>


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

namespace mud
{
	
}

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif


#ifndef MUD_FRAME_REFL_EXPORT
#define MUD_FRAME_REFL_EXPORT MUD_IMPORT
#endif

namespace mud
{
	export_ class MUD_FRAME_REFL_EXPORT mud_frame : public Module
	{
	private:
		mud_frame();
		
	public:
		static mud_frame& m() { static mud_frame instance; return instance; }
	};
}

#ifdef MUD_FRAME_MODULE
extern "C"
MUD_FRAME_REFL_EXPORT Module& getModule();
#endif
