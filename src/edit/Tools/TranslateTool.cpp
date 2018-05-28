//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.


#include <edit/Generated/Types.h>
#include <edit/Tools/TranslateTool.h>

#include <geom/Shapes.h>
#include <geom/Intersect.h>
#include <math/Axes.h>

#include <edit/Viewer/Viewer.h>

#include <gfx/Gfx.h>
#include <gfx/Item.h>

namespace mud
{
	TranslateAction::TranslateAction(const std::vector<Transform*>& targets)
		: TransformAction(targets)
		, m_translation(Zero3)
	{}

	void TranslateAction::apply(Transform& transform)
	{
		transform.m_position += m_translation;
	}

	void TranslateAction::undo(Transform& transform)
	{
		transform.m_position += -m_translation;
	}

	void TranslateAction::update(const vec3& start, const vec3& end)
	{
		m_translation = end - start;
	}

 	TranslateTool::TranslateTool(ToolContext& context)
		: TransformTool(context, "Translate", type<TranslateTool>())
	{
		m_gizmos.push_back(linear_gizmo(Axis::X, 0.f));
		m_gizmos.push_back(linear_gizmo(Axis::Y, 1.f / 3.f));
		m_gizmos.push_back(linear_gizmo(Axis::Z, 2.f / 3.f));
		m_gizmos.push_back(planar_gizmo(Axis::X, 0.f));
		m_gizmos.push_back(planar_gizmo(Axis::Y, 1.f / 3.f));
		m_gizmos.push_back(planar_gizmo(Axis::Z, 2.f / 3.f));
		m_current = &m_gizmos.front();
	}

	Item& translate_1d_gizmo(Gnode& parent, Axis axis, Colour colour, float radius, uint32_t flags = 0U)
	{
		Gnode& node = gfx::transform(parent, {}, to_vec3(axis), ZeroQuat);
		return gfx::shape(node, Cylinder(radius, 1.f, axis), Symbol(Colour::None, colour, true), flags);
	}

	Item& translate_2d_gizmo(Gnode& parent, Axis axis, Colour colour, uint32_t flags = 0U)
	{
		Gnode& node = gfx::transform(parent, {}, 0.5f * (c_tangents[uint(axis)] + c_binormals[uint(axis)]), ZeroQuat);
		return gfx::shape(node, Quad(0.3f, c_tangents[uint(axis)], c_binormals[uint(axis)]), Symbol(Colour::None, colour, true, true), flags);
	}

	Gizmo TranslateTool::linear_gizmo(Axis axis, float hue)
	{
		auto grab_point = [this, axis](Viewer& viewer, const vec2& pos) { UNUSED(pos); return gizmo_grab_linear(viewer, m_transform, axis); };

		auto draw_handle = [=](Gnode& parent) { return &translate_1d_gizmo(parent, axis, Colour::Invisible, 0.05f, ITEM_UI); };
		auto draw_gizmo = [=](Gnode& parent, bool active) { translate_1d_gizmo(parent, axis, gizmo_colour(hue, active), 0.02f); };
		return { draw_handle, draw_gizmo, nullptr, false, grab_point };
	}

	Colour to_rgba(const Colour& colour, float a)
	{
		return Colour(colour.m_r, colour.m_g, colour.m_b, a);
	}

	Gizmo TranslateTool::planar_gizmo(Axis normal, float hue)
	{
		auto grab_point = [this, normal](Viewer& viewer, const vec2& pos) { UNUSED(pos); return gizmo_grab_planar(viewer, m_transform, normal); };

		auto draw_handle = [=](Gnode& parent) { return &translate_2d_gizmo(parent, normal, Colour::Invisible, ITEM_UI); };
		auto draw_gizmo = [=](Gnode& parent, bool active) { translate_2d_gizmo(parent, normal, gizmo_colour(hue, active)); };
		return { draw_handle, draw_gizmo, nullptr, false, grab_point };
	}

	object_ptr<TransformAction> TranslateTool::create_action(const std::vector<Transform*>& targets)
	{
		return make_object<TranslateAction>(targets);
	}

}
