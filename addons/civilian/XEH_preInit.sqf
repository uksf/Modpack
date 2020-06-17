#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

["CBA_settingsInitialized", {
    if (GVAR(enableGestures)) then {
        GVAR(vehicle_statemachine) = locationNull;
        GVAR(vehicle_statemachine_vehicles) = [];
        GVAR(unit_statemachine) = locationNull;
        GVAR(unit_statemachine_units) = [];

        if (hasInterface) then {
            GVAR(lastGesture) = 0;

            if (GVAR(allowDebug)) then {
                GVAR(debugDrawId) = -1;
                GVAR(debugPFHId) = -1;
                GVAR(debugBroadcastPFHId) = -1;
                GVAR(debugVehicles) = [];
                GVAR(debugUnits) = [];
                GVAR(debugVehicleSpheres) = [];
                GVAR(debugVehicleMoveCommandSpheres) = [];
                GVAR(debugVehicleFollowCommandSpheres) = [];
                GVAR(debugUnitSpheres) = [];
                GVAR(debugUnitMoveCommandSpheres) = [];
                GVAR(debugUnitFollowCommandSpheres) = [];
            };
        };
    };
}] call CBA_fnc_addEventHandler;

["ace_captives_doEscort", {
    if !(GVAR(enableEscort)) exitWith {};

    params ["", "_state"];

    call ([FUNC(captiveEscortStop), FUNC(captiveEscortStart)] select _state);
}] call CBA_fnc_addEventHandler;

["weapon", {
    if !(GVAR(enableEscort)) exitWith {};
    if !(ACE_player getVariable ["ace_captives_isEscorting", false]) exitWith {};

    ACE_player switchMove "HubSpectator_stand";

    [{
        params ["", "_newWeapon"];

        private _animState = configName (configFile >> getText (EGVAR(common,configVehicles) >> typeOf ACE_player >> "moves") >> "States" >> (animationState ACE_player));
        if (_newWeapon == primaryWeapon ACE_player) then {
            _animState = [_animState, "pst", "rfl"] call CBA_fnc_replace;
        } else {
            if (_newWeapon == handgunWeapon ACE_player) then {
                _animState = [_animState, "rfl", "pst"] call CBA_fnc_replace;
            };
        };

        private _holdAnim = [QGVAR(holdhvt), QGVAR(holdhvtpistol)] select (_newWeapon == (handgunWeapon ACE_player));
        ACE_player playActionNow _holdAnim;
        ACE_player switchMove "";
    }, _this, 2] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addPlayerEventHandler;

["loadout", {
    if !(GVAR(enableEscort)) exitWith {};
    if !(ACE_player getVariable ["ace_captives_isEscorting", false]) exitWith {};

    ACE_player switchMove "HubSpectator_stand";

    [{
        !ace_common_isReloading
    }, {
        private _holdAnim = [QGVAR(holdhvt), QGVAR(holdhvtpistol)] select ((currentWeapon ACE_player) == (handgunWeapon ACE_player));
        ACE_player playActionNow _holdAnim;
        ACE_player switchMove "";
    }, []] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addPlayerEventHandler;

ADDON = true;
