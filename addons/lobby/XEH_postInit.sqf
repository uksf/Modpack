#include "script_component.hpp"

private _respawn = (getMissionConfigValue ["respawn", "NONE"]);

if (!isMultiplayer || {_respawn isEqualTo "NONE"}) exitWith {
    [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
};

if (_respawn != "NONE") then {
    private _unitNameConfigs = configFile >> "CfgUnitNames";
    if (isArray (_unitNameConfigs >> (roleDescription player))) then {
        startLoadingScreen ["Loading"];
        private _unitConfig = (getArray (_unitNameConfigs >> (roleDescription player)));
        [QGVAR(addGroup), [_unitConfig select 0]] call CBA_fnc_serverEvent;
        [{
            params ["_groupName"];
            ({(groupId _x) isEqualTo _groupName} count GVAR(unitGroups)) != 0;
        }, {
            params ["_groupName", "", "_class"];
            progressLoadingScreen 0.5;
            private _group = (GVAR(unitGroups) select {(groupId _x) isEqualTo _groupName}) select 0;
            private _unit = _group createUnit [_class, [-1000, -1000, 0], [], 10, "NONE"];
            [QEGVAR(common,waitAndDelete), [player, 5]] call CBA_fnc_serverEvent;
            selectPlayer _unit;
            endLoadingScreen;
            [] spawn {
                sleep 1;
                forceRespawn player;
                [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
            };
        }, _unitConfig] call CBA_fnc_waitUntilAndExecute;        
    } else {
        [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
    };
};
