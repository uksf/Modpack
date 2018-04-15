class CfgAmmo{
    class B_762x51_Ball;
    class UK3CB_BAF_762_Ball: B_762x51_Ball {
        ACE_bulletMass = 10.0438;
        hit = 14;
        caliber = 1.6;
    };
    class B_762x51_Tracer_Red;
    class UK3CB_BAF_762_Ball_Tracer_Red: B_762x51_Tracer_Red {
        ACE_bulletMass = 10.0438;
        hit = 14;
        caliber = 1.6;
    };
    class UK3CB_BAF_762_Ball_EL: UK3CB_BAF_762_Ball {
        hit = 12;
        tracerEndTime = 4.15957;
    };
    class UK3CB_BAF_762_Ball_Tracer_Red_EL: UK3CB_BAF_762_Ball_Tracer_Red {
        hit = 12;
        tracerEndTime = 4.15957;
    };
    class BulletBase;
    class UK3CB_BAF_B_12Gauge_Pellets: BulletBase {
        hit = 5; // Increased from 2, 4, 10
    };
    class B_408_Ball;
    class UK3CB_BAF_338_Ball_Tracer_Red: B_408_Ball {
        tracerEndTime = 3; // 1
    };

    class Chemlight_red;
    class ACE_G_Chemlight_HiRed: Chemlight_red {
        timeToLive = 3600;
    };
    class Chemlight_yellow;
    class ACE_G_Chemlight_HiYellow: Chemlight_yellow {
        timeToLive = 3600;
    };
    class ACE_G_Chemlight_Orange;
    class ACE_G_Chemlight_HiOrange: ACE_G_Chemlight_Orange {
        timeToLive = 3600;
    };
    class ACE_G_Chemlight_White;
    class ACE_G_Chemlight_HiWhite: ACE_G_Chemlight_White {
        timeToLive = 3600;
    };
    class ACE_G_Chemlight_HiBlue: ACE_G_Chemlight_HiWhite {
        effectsSmoke = "ACE_ChemlightEffect_HiBlue";
    };
    class ACE_G_Chemlight_HiGreen: ACE_G_Chemlight_HiWhite {
        effectsSmoke = "ACE_ChemlightEffect_HiGreen";
    };
    class Chemlight_base;
    class ACE_G_Chemlight_IR: Chemlight_base {
        timeToLive = 3600;
    };

    class MissileCore;
    class MissileBase: MissileCore {
        timeToLive = 30;
    };
    class M_PG_AT: MissileBase {
        class Components;
    };
    class ACE_Hellfire_AGM114K: M_PG_AT {
        SoundSetExplosion[] = { "DS_Ex_rocket_big_SoundSet", "DS_exploBig_Tail_placeholder_SoundSet" };
        class Components: Components {
            class SensorsManagerComponent {
                class Components {
                    class IRSensorComponent: SensorTemplateIR {
                        class AirTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        maxTrackableSpeed = 35;
                        angleRangeHorizontal = 45;
                        angleRangeVertical = 35;
                    };
                    class LaserSensorComponent: SensorTemplateLaser {
                        class AirTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        maxTrackableSpeed = 55;
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                    };
                };
            };
        };
        model = QPATHTOF(data\AGM114\AGM114Hellfire.p3d);
        proxyShape = QPATHTOF(data\AGM114\AGM114Hellfire_proxy.p3d);
        ace_rearm_dummy = QGVAR(ACE_Hellfire_AGM114);
        timeToLive = 120;
        effectsMissileInit = "PylonBackEffects";
        CraterEffects = "Hellfire_Smoke";
        explosionEffects = "Hellfire_Explode";
        missileLockMaxDistance = 8000;
        class ace_missileguidance {
            seekerMaxRange = 8000;
        };
    };
    class ACE_Hellfire_AGM114L: ACE_Hellfire_AGM114K {
        displayName = "AGM-114L";
        displayNameShort = "AGM-114L";
        description = "AGM-114L";
        descriptionShort = "AGM-114L";
        weaponLockSystem = "8 + 16";
        cmImmunity = 0.95;
        class ace_missileguidance {
            enabled = 0;
        };
        missileLockCone = 90;
        missileKeepLockedCone = 180;
        missileLockMaxDistance = 8000;
        missileLockMinDistance = 500;
        missileLockMaxSpeed = 55;
        class Components: Components {
            class SensorsManagerComponent {
                class Components {
                    class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
                        class AirTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        angleRangeHorizontal = 90;
                        angleRangeVertical = 90;
                        maxFogSeeThrough = 1;
                        maxGroundNoiseDistance = -1;
                        groundNoiseDistanceCoef = -1;
                        minSpeedThreshold = 0;
                        maxSpeedThreshold = 0;
                        maxTrackableSpeed = 55;
                    };
                };
            };
        };
    };
    class ACE_Hellfire_AGM114K_drone: ACE_Hellfire_AGM114K {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            seekerAngle = 360;
            minDeflection = 0.0005; // Minium flap deflection for guidance
            maxDeflection = 0.02; // Maximum flap deflection for guidance
            incDeflection = 0.0005; // The incrmeent in which deflection adjusts.
        };
    };
    class ACE_Hellfire_AGM114N: ACE_Hellfire_AGM114K {
        class ace_missileguidance;
    };
    class ACE_Hellfire_AGM114N_drone: ACE_Hellfire_AGM114N {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            seekerAngle = 360;
            minDeflection = 0.0005; // Minium flap deflection for guidance
            maxDeflection = 0.02; // Maximum flap deflection for guidance
            incDeflection = 0.0005; // The incrmeent in which deflection adjusts.
        };
    };
    class CUP_B_30x113mm_M789_HEDP_Red_Tracer: BulletBase {
        SoundSetExplosion[] = { "DS_Ex_small_impact_SoundSet", "DS_exploSmall_Tail_placeholder_SoundSet", "Explosion_Debris_SoundSet" };
        CraterEffects = "ExploAmmoCrater";
        explosionEffects = "ExploAmmoExplosion";
        class HitEffects {
            hitWater = "ImpactEffectsWater";
        };
        hit = 105;
        indirectHit = 10;
        indirectHitRange = 2;
        tracerEndTime = 30;
        timeToLive = 30;
        caliber = 4.2;
    };
    class M_Titan_AA;
    class UKSF_Dummy_Missile: M_Titan_AA {
        indirectHitRange = 1;
        fusedistance = 0.01;
        inittime = 0.01;
        timetolive = 0.01;
        ace_frag_enabled = 1;
        ace_frag_classes[] = { "ACE_frag_medium", "ACE_frag_medium_HD" };
        ace_frag_metal = 8000;
        ace_frag_charge = 2400;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = "1/2";
    };
    class DemoCharge_Remote_Ammo;
    class BreachCharge_Remote_Ammo: DemoCharge_Remote_Ammo {
        hit = 200;
        indirectHit = 200;
        indirectHitRange = 1;
        defaultMagazine = "BreachCharge_Remote_Mag";
        mineInconspicuousness = 4;
        mineTrigger = "RemoteTrigger";
        explosionEffectsRadius = 5;
        CraterEffects = "GrenadeCrater";
        CraterWaterEffects = "ImpactEffectsWaterExplosion";
        explosionEffects = "GrenadeExplosion";
        SoundSetExplosion[] = { "DS_Ex_Grenade_SoundSet", "DS_Grenade_ExploTail_SoundSet", "DS_exploSmall_Tail_placeholder_SoundSet" };
        ace_explosives_magazine = "BreachCharge_Remote_Mag";
        ace_explosives_Explosive = "BreachCharge_Remote_Ammo_Scripted";
    };
    class BreachCharge_Remote_Ammo_Scripted: BreachCharge_Remote_Ammo {};

    class B_556x45_Ball;
    class B_556x45_Ball_Rubber: B_556x45_Ball {
        hit = 0.25;
        cost = 1;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
    };
    class CUP_B_762x51_Tracer_White;
    class CUP_B_762x51_Tracer_White_Rubber: CUP_B_762x51_Tracer_White {
        hit = 0.25;
        cost = 1;
    };
    class B_127x99_Ball_Tracer_Red;
    class B_127x99_Ball_Tracer_White_Rubber: B_127x99_Ball_Tracer_Red {
        hit = 0.25;
        cost = 1;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
    };
    class CUP_R_SMAW_HEAA_N;
    class CUP_R_SMAW_HEAT_N_Rubber: CUP_R_SMAW_HEAA_N {
        hit = 0.5;
        indirecthit = 0;
        indirecthitrange = 0;
        cost = 1;
        ace_frag_enabled = 0;
        mass = 20;
    };
    class CUP_M_Stinger_AA;
    class CUP_M_Stinger_AA_Rubber: CUP_M_Stinger_AA {
        hit = 31;
        indirecthit = 10;
        indirecthitrange = 1;
        cost = 1;
        ace_frag_enabled = 0;
    };
    class Sh_120mm_APFSDS;
    class Sh_120mm_APFSDS_Tracer_White_Rubber: Sh_120mm_APFSDS {
        hit = 0.5;
        indirectHit = 0;
        indirectHitRange = 0;
        dangerRadiusHit = 0;
        suppressionRadiusHit = 0;
        cost = 1;
    };
    class Sh_120mm_HE;
    class Sh_120mm_HE_Tracer_White_Rubber: Sh_120mm_HE {
        hit = 0.5;
        indirectHit = 0;
        indirectHitRange = 0;
        dangerRadiusHit = 0;
        suppressionRadiusHit = 0;
        cost = 1;
        ace_frag_enabled = 0;
    };
    class CUP_B_25mm_HE_White_Tracer;
    class CUP_B_25mm_HE_White_Tracer_Rubber: CUP_B_25mm_HE_White_Tracer {
        hit = 0.5;
        indirectHit = 0;
        indirectHitRange = 0;
        cost = 1;
        ace_frag_enabled = 0;
    };
    class CUP_B_25mm_APFSDS_White_Tracer;
    class CUP_B_25mm_APFSDS_White_Tracer_Rubber: CUP_B_25mm_APFSDS_White_Tracer {
        hit = 0.5;
        indirectHit = 0;
        indirectHitRange = 0;
        cost = 1;
        ace_frag_enabled = 0;
    };
};