#include <mud/tree.refl.h>
#include <mud/geom.refl.h>
#include <mud/ui.refl.h>
#include <mud/gfx.refl.h>
#include <mud/infra.refl.h>
#include <mud/type.refl.h>
#include <mud/ctx.refl.h>
#include <mud/gfx.ui.refl.h>
#include <mud/refl.h>
#include <mud/math.refl.h>
#include <mud/gfx.ui.h>
#include <mud/infra.h>
#include <mud/type.h>

#ifdef MUD_MODULES
module mud.gfx-ui;
#else
#endif


namespace mud
{
	void mud_gfx_ui_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	{
		Type& t = type<mud::ui::OrbitMode>();
		static Meta meta = { t, &namspc({ "mud", "ui" }), "OrbitMode", sizeof(mud::ui::OrbitMode), TypeClass::Enum };
		static cstring ids[] = { "ThirdPerson", "Isometric", "PseudoIsometric" };
		static uint32_t values[] = { 0, 1, 2 };
		static mud::ui::OrbitMode vars[] = { mud::ui::OrbitMode::ThirdPerson, mud::ui::OrbitMode::Isometric, mud::ui::OrbitMode::PseudoIsometric};
		static void* refs[] = { &vars[0], &vars[1], &vars[2]};
		static Enum enu = { t, true, ids, values, refs };
		meta_enum<mud::ui::OrbitMode>();
	}
	
	// Sequences
	
	// mud::ViewerController
	{
		Type& t = type<mud::ViewerController>();
		static Meta meta = { t, &namspc({ "mud" }), "ViewerController", sizeof(mud::ViewerController), TypeClass::Object };
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
		meta_class<mud::ViewerController>();
	}
	// mud::OrbitController
	{
		Type& t = type<mud::OrbitController>();
		static Meta meta = { t, &namspc({ "mud" }), "OrbitController", sizeof(mud::OrbitController), TypeClass::Object };
		// defaults
		static mud::vec3 position_default = Zero3;
		static float yaw_default = 0.f;
		static float pitch_default = 0.f;
		static float distance_default = 1.f;
		static Class cls = { t,
			// bases
			{ &type<mud::ViewerController>() },
			{ base_offset<mud::OrbitController, mud::ViewerController>() },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
				{ t, member_address(&mud::OrbitController::m_position), type<mud::vec3>(), "position", Ref(&position_default), Member::Value, nullptr },
				{ t, member_address(&mud::OrbitController::m_yaw), type<float>(), "yaw", Ref(&yaw_default), Member::Value, nullptr },
				{ t, member_address(&mud::OrbitController::m_pitch), type<float>(), "pitch", Ref(&pitch_default), Member::Value, nullptr },
				{ t, member_address(&mud::OrbitController::m_distance), type<float>(), "distance", Ref(&distance_default), Member::Value, nullptr }
			},
			// methods
			{
				{ t, "set_eye", member_address<void(mud::OrbitController::*)(const mud::quat&)>(&mud::OrbitController::set_eye), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<mud::OrbitController>(object).set_eye(val<mud::quat>(args[0])); }, { { "rotation", var(mud::quat()) } }, Var() },
				{ t, "set_target", member_address<void(mud::OrbitController::*)(const mud::vec3&)>(&mud::OrbitController::set_target), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<mud::OrbitController>(object).set_target(val<mud::vec3>(args[0])); }, { { "position", var(mud::vec3()) } }, Var() }
			},
			// static members
			{
			}
		};
		meta_class<mud::OrbitController>();
	}
	// mud::FreeOrbitController
	{
		Type& t = type<mud::FreeOrbitController>();
		static Meta meta = { t, &namspc({ "mud" }), "FreeOrbitController", sizeof(mud::FreeOrbitController), TypeClass::Object };
		// defaults
		static Class cls = { t,
			// bases
			{ &type<mud::OrbitController>() },
			{ base_offset<mud::FreeOrbitController, mud::OrbitController>() },
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
		meta_class<mud::FreeOrbitController>();
	}
	// mud::SpaceSheet
	{
		Type& t = type<mud::SpaceSheet>();
		static Meta meta = { t, &namspc({ "mud" }), "SpaceSheet", sizeof(mud::SpaceSheet), TypeClass::Object };
		// defaults
		static Class cls = { t,
			// bases
			{ &type<mud::Ui>() },
			{ base_offset<mud::SpaceSheet, mud::Ui>() },
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
		meta_class<mud::SpaceSheet>();
	}
	// mud::Viewer
	{
		Type& t = type<mud::Viewer>();
		static Meta meta = { t, &namspc({ "mud" }), "Viewer", sizeof(mud::Viewer), TypeClass::Object };
		// defaults
		static Class cls = { t,
			// bases
			{ &type<mud::Widget>() },
			{ base_offset<mud::Viewer, mud::Widget>() },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
				{ t, member_address(&mud::Viewer::m_scene), type<mud::Scene>(), "scene", Ref(), Member::Flags(Member::Pointer|Member::Link), nullptr },
				{ t, member_address(&mud::Viewer::m_viewport), type<mud::Viewport>(), "viewport", Ref(), Member::NonMutable, nullptr },
				{ t, member_address(&mud::Viewer::m_position), type<mud::vec2>(), "position", Ref(), Member::Value, nullptr },
				{ t, member_address(&mud::Viewer::m_size), type<mud::vec2>(), "size", Ref(), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::Viewer>();
	}
	// mud::SceneViewer
	{
		Type& t = type<mud::SceneViewer>();
		static Meta meta = { t, &namspc({ "mud" }), "SceneViewer", sizeof(mud::SceneViewer), TypeClass::Object };
		// defaults
		static Class cls = { t,
			// bases
			{ &type<mud::Scene>(), &type<mud::Viewer>() },
			{ base_offset<mud::SceneViewer, mud::Scene>(), base_offset<mud::SceneViewer, mud::Viewer>() },
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
		meta_class<mud::SceneViewer>();
	}
		m.m_types.push_back(&type<mud::ui::OrbitMode>());
		m.m_types.push_back(&type<mud::ViewerController>());
		m.m_types.push_back(&type<mud::OrbitController>());
		m.m_types.push_back(&type<mud::FreeOrbitController>());
		m.m_types.push_back(&type<mud::SpaceSheet>());
		m.m_types.push_back(&type<mud::Viewer>());
		m.m_types.push_back(&type<mud::SceneViewer>());
		{
			auto func = [](array<Var> args, Var& result) {  result = Ref(&mud::ui::viewer(val<mud::Widget>(args[0]), val<mud::Scene>(args[1]))); };
			vector<Param> params = { { "parent", Ref(type<mud::Widget>()) }, { "scene", Ref(type<mud::Scene>()) } };
			static Function f = { &namspc({ "mud", "ui" }), "viewer", funcptr<mud::Viewer&(*)(mud::Widget&, mud::Scene&)>(&mud::ui::viewer), func, params, Ref(type<mud::Viewer>()) };
			m.m_functions.push_back(&f);
		}
		{
			auto func = [](array<Var> args, Var& result) {  result = Ref(&mud::ui::scene_viewer(val<mud::Widget>(args[0]), val<mud::vec2>(args[1]))); };
			vector<Param> params = { { "parent", Ref(type<mud::Widget>()) }, { "size", var(mud::vec2(Zero2)), Param::Default } };
			static Function f = { &namspc({ "mud", "ui" }), "scene_viewer", funcptr<mud::SceneViewer&(*)(mud::Widget&, const mud::vec2&)>(&mud::ui::scene_viewer), func, params, Ref(type<mud::SceneViewer>()) };
			m.m_functions.push_back(&f);
		}
		{
			auto func = [](array<Var> args, Var& result) {  result = Ref(&mud::ui::orbit_controller(val<mud::Viewer>(args[0]), val<float>(args[1]), val<float>(args[2]), val<float>(args[3]))); };
			vector<Param> params = { { "viewer", Ref(type<mud::Viewer>()) }, { "yaw", var(float()) }, { "pitch", var(float()) }, { "distance", var(float(10.f)), Param::Default } };
			static Function f = { &namspc({ "mud", "ui" }), "orbit_controller", funcptr<mud::OrbitController&(*)(mud::Viewer&, float, float, float)>(&mud::ui::orbit_controller), func, params, Ref(type<mud::OrbitController>()) };
			m.m_functions.push_back(&f);
		}
		{
			auto func = [](array<Var> args, Var& result) {  result = Ref(&mud::ui::free_orbit_controller(val<mud::Viewer>(args[0]))); };
			vector<Param> params = { { "viewer", Ref(type<mud::Viewer>()) } };
			static Function f = { &namspc({ "mud", "ui" }), "free_orbit_controller", funcptr<mud::FreeOrbitController&(*)(mud::Viewer&)>(&mud::ui::free_orbit_controller), func, params, Ref(type<mud::FreeOrbitController>()) };
			m.m_functions.push_back(&f);
		}
		{
			auto func = [](array<Var> args, Var& result) {  result = Ref(&mud::ui::isometric_controller(val<mud::Viewer>(args[0]), val<bool>(args[1]))); };
			vector<Param> params = { { "viewer", Ref(type<mud::Viewer>()) }, { "topdown", var(bool(false)), Param::Default } };
			static Function f = { &namspc({ "mud", "ui" }), "isometric_controller", funcptr<mud::OrbitController&(*)(mud::Viewer&, bool)>(&mud::ui::isometric_controller), func, params, Ref(type<mud::OrbitController>()) };
			m.m_functions.push_back(&f);
		}
		{
			auto func = [](array<Var> args, Var& result) {  result = Ref(&mud::ui::hybrid_controller(val<mud::Viewer>(args[0]), val<mud::ui::OrbitMode>(args[1]), val<mud::Transform>(args[2]), val<bool>(args[3]), val<mud::vec2>(args[4]), val<bool>(args[5]))); };
			vector<Param> params = { { "viewer", Ref(type<mud::Viewer>()) }, { "mode", var(mud::ui::OrbitMode()) }, { "entity", var(mud::Transform()) }, { "aiming", var(bool()) }, { "angles", var(mud::vec2()) }, { "modal", var(bool(false)), Param::Default } };
			static Function f = { &namspc({ "mud", "ui" }), "hybrid_controller", funcptr<mud::OrbitController&(*)(mud::Viewer&, mud::ui::OrbitMode, mud::Transform&, bool&, mud::vec2&, bool)>(&mud::ui::hybrid_controller), func, params, Ref(type<mud::OrbitController>()) };
			m.m_functions.push_back(&f);
		}
		{
			auto func = [](array<Var> args, Var& result) { UNUSED(result);  mud::ui::velocity_controller(val<mud::Viewer>(args[0]), val<mud::vec3>(args[1]), val<mud::vec3>(args[2]), val<float>(args[3])); };
			vector<Param> params = { { "viewer", Ref(type<mud::Viewer>()) }, { "linear", var(mud::vec3()) }, { "angular", var(mud::vec3()) }, { "speed", var(float(1.f)), Param::Default } };
			static Function f = { &namspc({ "mud", "ui" }), "velocity_controller", funcptr<void(*)(mud::Viewer&, mud::vec3&, mud::vec3&, float)>(&mud::ui::velocity_controller), func, params, Var() };
			m.m_functions.push_back(&f);
		}
	}
}

namespace mud
{
	mud_gfx_ui::mud_gfx_ui()
		: Module("mud::gfx-ui", { &mud_infra::m(), &mud_tree::m(), &mud_type::m(), &mud_math::m(), &mud_geom::m(), &mud_ctx::m(), &mud_ui::m(), &mud_gfx::m() })
	{
		// setup reflection meta data
		mud_gfx_ui_meta(*this);
	}
}

#ifdef MUD_GFX_UI_MODULE
extern "C"
Module& getModule()
{
		return mud_gfx_ui::m();
}
#endif
