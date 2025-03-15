//
// Created by johannesjumpertz on 15.03.2025.
//

#include "edit_phase.h"

#include "state.h"


void UpdateEditPhase()
{
    state.editor.hovered_pos = GetScreenToWorld2D(GetMousePosition(), state.camera);
}
