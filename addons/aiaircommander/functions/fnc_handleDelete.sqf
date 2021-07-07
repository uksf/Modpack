#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Delete the AI and vehicles that have finished their task

    Parameters:
        0: Group leader <OBJECT>

    Return value:
        Nothing
*/
params ["_leader"];

(vehicle _leader) call CBA_fnc_deleteEntity;
(group _leader) call CBA_fnc_deleteEntity;
