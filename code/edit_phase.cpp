//
// Created by johannesjumpertz on 15.03.2025.
//

#include "edit_phase.h"

#include "state.h"
#include "math.h"

void UpdateEditPhase()
{
    Vector2 hovered = GetScreenToWorld2D(GetMousePosition(), state.camera);
    state.editor.hovered_pos = v2i(floor(hovered.x), floor(hovered.y));
}
