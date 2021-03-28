#include "script_component.hpp"
/*
    Author:
        Tim Beswick, Bridgford

    Description:
        Gets resupply actions for container

    Parameter(s):
        0: Resupply container <OBJECT>

    Return Value:
        Array of actions <ARRAY>
*/
params ["_target"];

private _resupplyTypes = [
    ["UKSF_S_Empty", "Empty", "Empty Crate"],
    ["UKSF_S_R1", "R1", "Ammo | Launchers"],
    ["UKSF_S_R2", "R2", "Explosives | Launchers"],
    ["UKSF_S_R3", "R3", "Vehicle Ammo | M6 Ammo"],
    ["UKSF_S_R4", "R4", "M6 | M6 Ammo"],
    ["UKSF_S_R5", "R5", "Medical (Cargo)"],
    ["UKSF_S_R6", "R6", "L16 | L16 Ammo"],
    ["UKSF_S_R7", "R7", "Sniper Equipment"],
    ["UKSF_S_RT", "RT", "6x Tyres"],
    ["CargoNet_01_barrels_F", "RF", "Fuel"],
    ["UKSF_S_MedicalBox", "Medical", "Medical Supplies"]
];

private _actions = [];

private _action = [QGVAR(reviewTypes), "Review Resupply Types", "", {
    params ["", "", "_actionParams"];
    _actionParams params ["_resupplyTypes"];

    private _descriptions = _resupplyTypes apply {[_x#1, _x#2] joinString " - "};
    private _text = _descriptions joinString "\n";
    hint format ["Available Resupply Types: \n\n %1", _text];
}, {true}, {}, [_resupplyTypes]] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _target];

{
    _x params ["_class", "_name", "_description"];

    private _action = [format [QUOTE(GVAR(create)_%1), _name], _name, "", {
        params ["_container", "_player", "_actionParams"];
        _actionParams params ["_class", "_name"];

        [2, [_container, _class, _name, _player], {
            params ["_args"];
            _args params ["_container", "_class", "", "_player"];

            private _position = [_container, "_class", _player, 10, true] call ace_common_fnc_findUnloadPosition;
            if (_position isNotEqualTo []) then {
                createVehicle [_class, _position, [], 0, "CAN_COLLIDE"];
            } else {
                createVehicle [_class, _player, [], 0, "NONE"];
            };
        }, {
            params ["_args"];
            _args params ["", "_class", "_name"];

            hint format ["Failed to unload %1", _name];
        }, format ["Unloading %1 from container", _name]] call ace_common_fnc_progressBar;
    }, {true}, {}, [_class, _name]] call ace_interact_menu_fnc_createAction;

    _actions pushBack [_action, [], _target];
} forEach _resupplyTypes;

_actions
