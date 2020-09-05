#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create attack heli group

    Parameters:
        0: Spawn position <ARRAY>
        1: Callback <CODE> (Optional)
        2: Callback arguments <ARRAY> (Optional)

    Return value:
        Nothing
*/
params ["_spawnPosition", ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

[getPos _spawnPosition, 1, 0, EAST, EGVAR(gear,gearHeliPilot), EGVAR(gear,gearAttackHeli), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["_callback", "_callbackArgs", "_group", "_vehicle"];

    _vehicle flyInHeight 150;
    _callbackArgs pushBack _group;
    _callbackArgs call _callback;
}, [_callback, _callbackArgs]] call EFUNC(common,spawnGroup);
