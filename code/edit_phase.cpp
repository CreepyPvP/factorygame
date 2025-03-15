//
// Created by johannesjumpertz on 15.03.2025.
//

#include "edit_phase.h"

#include "state.h"
#include "math.h"

void UpdateEditPhase()
{
    Vector2 hovered = GetScreenToWorld2D(GetMousePosition(), state.camera);
    state.editor.hovered_pos = v2i(floorf(hovered.x), floorf(hovered.y));

    bool select_active = state.editor.hovered_type == MachineType_None;

    if (IsKeyPressed(KEY_A))
    {
        if (state.editor.hovered_type != MachineType_None)
        {
            state.editor.hovered_type = (MachineType)(state.editor.hovered_type - 1);
        }
    }
    if (IsKeyPressed(KEY_D))
    {
        if (state.editor.hovered_type != MachineType_Count - 1) state.editor.hovered_type = (MachineType)(state.editor.
            hovered_type + 1);
    }

    if (state.editor.hovered_pos.x < 0 || state.editor.hovered_pos.y < 0) return;
    if (state.editor.hovered_pos.x > state.width || state.editor.hovered_pos.y > state.height) return;

    Machine *machine = state.machine + state.editor.hovered_pos.x + state.editor.hovered_pos.y * state.width;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (select_active)
        {
            if (machine->action.type == ActionType_Destroy)
            {
                machine->action.type == ActionType_None;
                // todo: Play undo destroy
            } else
            {
                // todo: Play tile shake animation
            }
        } else
        {
            machine->action.type = ActionType_Place;
            machine->action.placement_type = state.editor.hovered_type;
            machine->action.facing = state.editor.hovered_direction;
            // todo: Play holo place animation
        }
    }
    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        if (machine->action.type == ActionType_None || machine->action.type == ActionType_Rotate)
        {
            machine->action.type == ActionType_Destroy;
            // todo: Play destroy anim
        } else if (machine->action.type == ActionType_Place)
        {
            machine->action.type == ActionType_None;
            // todo: Play destroy blueprint
        } else if (machine->action.type == ActionType_Destroy)
        {
            machine->action.type == ActionType_None;
            // todo: Play undo destroy
        }
    }
}
