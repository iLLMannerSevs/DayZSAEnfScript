#define _ARMA_

//(8 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	destructno = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class DZ_Vehicles_Wheeled
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class CarWheel: Inventory_Base
	{
		scope = 1;
		itemBehaviour = 0;
		physLayer = "item_large";
		itemSize[] = {6,6};
		weight = 12000;
		repairableWithKits[] = {6};
		repairCosts[] = {25.0};
		simulation = "carwheel";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset = "hatchbackwheel_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CarDoor: Inventory_Base
	{
		scope = 1;
		itemBehaviour = 0;
		physLayer = "item_large";
		itemSize[] = {10,10};
		weight = 20000;
		hiddenSelections[] = {"dmgZone_doors"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Window
				{
					class Health
					{
						hitpoints = 70;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{""}}};
					};
					componentNames[] = {"dmgZone_window"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Doors
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{""}}};
					};
					componentNames[] = {"dmgZone_doors"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp
				{
					soundSet = "hatchbackdoors_driver_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "hatchbackdoors_driver_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Car;
	class CarScript: Car
	{
		rotationFlags = 64;
		storageCategory = 4;
		insideSoundCoef = 0.9;
		fuelCapacity = 50;
		brakeFluidCapacity = 1;
		oilCapacity = 4;
		coolantCapacity = 6;
		brakeFluidLeakDebit[] = {0.0,0.0};
		oilLeakDebit[] = {0.0,0.0};
		coolantLeakDebit[] = {0.0,0.0};
		brakeFluidForceCoef[] = {0.0,1.0,1.0,1.0};
		damageFromOil[] = {0.0,0.0,1.0,0.0};
		damageFromCoolant[] = {0.0,0.0,1.0,0.0};
		engineBeltSlot = "EngineBelt";
		batterySlot = "CarBattery";
		electricPowerResName = "power";
		electricConsumptionIgnition = 3001;
		electricConsumptionEngine = 0.0;
		electricConsumptionLights = 0.0;
		electricOutputEngine = 5.0;
		selectionDashboard = "light_dashboard";
		selectionLightFrontL = "light_left";
		selectionLightFrontR = "light_right";
		selectionBrakeLights = "light_break";
		class Crew
		{
			class Driver
			{
				actionSel = "seat_driver";
				proxyPos = "crewDriver";
				getInPos = "pos_driver";
				getInDir = "pos_driver_dir";
				isDriver = 1;
			};
			class CoDriver
			{
				actionSel = "seat_coDriver";
				proxyPos = "crewCoDriver";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
			};
		};
		class SimulationModule
		{
			class Axles
			{
				class Front
				{
					class Wheels
					{
						class Left
						{
							inventorySlot = "";
							animTurn = "turnfrontleft";
							animRotation = "wheelfrontleft";
							animDamper = "damperfrontleft";
							wheelHub = "wheel_1_1_damper_land";
						};
						class Right
						{
							inventorySlot = "";
							animTurn = "turnfrontright";
							animRotation = "wheelfrontright";
							animDamper = "damperfrontright";
							wheelHub = "wheel_2_1_damper_land";
						};
					};
				};
				class Rear
				{
					class Wheels
					{
						class Left
						{
							inventorySlot = "";
							animTurn = "turnbackleft";
							animRotation = "wheelbackleft";
							animDamper = "damperbackleft";
							wheelHub = "wheel_1_2_damper_land";
						};
						class Right
						{
							inventorySlot = "";
							animTurn = "turnbackright";
							animRotation = "wheelbackright";
							animDamper = "damperbackright";
							wheelHub = "wheel_2_2_damper_land";
						};
					};
				};
			};
		};
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1"};
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
		hiddenSelectionsMaterials[] = {""};
		class AnimationSources
		{
			class DoorsDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCoDriver: DoorsDriver{};
			class DoorsHood: DoorsDriver{};
			class DoorsTrunk: DoorsDriver{};
			class HideDestroyed_1_1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class HideDestroyed_1_2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class HideDestroyed_2_1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class HideDestroyed_2_2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class AnimHitWheel_1_1
			{
				source = "Hit";
				hitpoint = "HitWheel_1_1";
				raw = 1;
			};
			class AnimHitWheel_1_2: AnimHitWheel_1_1
			{
				hitpoint = "HitWheel_1_2";
			};
			class AnimHitWheel_2_1: AnimHitWheel_1_1
			{
				hitpoint = "HitWheel_2_1";
			};
			class AnimHitWheel_2_2: AnimHitWheel_1_1
			{
				hitpoint = "HitWheel_2_2";
			};
			class HitDoorsHood: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsHood";
			};
			class HitDoorsTrunk: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsTrunk";
			};
			class HitDoorsDrivers: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsDriver";
			};
			class HitDoorsCoDrivers: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsCoDriver";
			};
			class HitDoorsCargo: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsCargo";
			};
		};
	};
	class HatchbackWheel: CarWheel
	{
		scope = 2;
		displayName = "$STR_HatchbackWheel0";
		descriptionShort = "$STR_hatchbackwheel1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaWheel.p3d";
		weight = 15000;
		inventorySlot[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
		rotationFlags = 4;
		repairableWithKits[] = {6};
		repairCosts[] = {30.0};
		radiusByDamage[] = {0,0.362,0.3,0.3,0.9998,0.25,0.9999,0.2};
		radius = 0.35;
		width = 0.18;
		tyreRollResistance = 0.015;
		tyreTread = 0.8;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel.rvmat"}},{0.7,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel.rvmat"}},{0.5,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_damage.rvmat"}},{0.3,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_damage.rvmat"}},{0.0,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_destruct.rvmat"}}};
				};
			};
		};
	};
	class HatchbackWheel_Ruined: CarWheel
	{
		scope = 2;
		displayName = "$STR_HatchbackWheel0";
		descriptionShort = "$STR_hatchbackwheel1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaWheel_destroyed.p3d";
		weight = 10000;
		inventorySlot[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
		rotationFlags = 4;
		radius = 0.2;
		width = 0.17;
		tyreRollResistance = 1;
		tyreRollDrag = 70;
		tyreRoughness = 1;
		tyreTread = 0.5;
	};
	class HatchbackDoors_Driver: CarDoor
	{
		scope = 2;
		displayName = "$STR_HatchbackDoors_Driver0";
		descriptionShort = "$STR_HatchbackDoors_Driver1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Driver.p3d";
		weight = 15000;
		inventorySlot = "NivaDriverDoors";
		rotationFlags = 8;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\green\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_CoDriver: HatchbackDoors_Driver
	{
		displayName = "$STR_HatchbackDoors_CoDriver0";
		descriptionShort = "$STR_HatchbackDoors_CoDriver1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_coDriver.p3d";
		inventorySlot = "NivaCoDriverDoors";
		rotationFlags = 4;
	};
	class HatchbackHood: CarDoor
	{
		scope = 2;
		displayName = "$STR_HatchbackHood0";
		descriptionShort = "$STR_HatchbackHood1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Hood.p3d";
		weight = 15000;
		inventorySlot = "NivaHood";
		rotationFlags = 2;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\green\niva_hood.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp
				{
					soundSet = "hatchbackdoors_driver_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "hatchbackhood_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class HatchbackTrunk: CarDoor
	{
		scope = 2;
		displayName = "$STR_HatchbackTrunk0";
		descriptionShort = "$STR_HatchbackTrunk1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Trunk.p3d";
		weight = 15000;
		inventorySlot = "NivaTrunk";
		rotationFlags = 1;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\green\niva_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class OffroadHatchback: CarScript
	{
		scope = 2;
		displayName = "$STR_OffroadHatchback0";
		descriptionShort = "$STR_OffroadHatchback1";
		model = "\dz\vehicles\wheeled\OffroadHatchback\OffroadHatchback.p3d";
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1","CarRadiator","SparkPlug","NivaDriverDoors","NivaCoDriverDoors","NivaHood","NivaTrunk","NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
		hiddenSelections[] = {"light_left","light_right","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","dmgZone_chassis","dmgZone_front","dmgZone_back","dmgZone_roof","dmgZone_fender_1_1","dmgZone_fender_1_2","dmgZone_fender_2_1","dmgZone_fender_2_2"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","","",""};
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat","dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
		dashboardMatOn = "dz\vehicles\wheeled\offroadhatchback\data\niva_dashboard_light.rvmat";
		dashboardMatOff = "dz\vehicles\wheeled\offroadhatchback\data\niva_dashboard.rvmat";
		frontReflectorMatOn = "dz\vehicles\wheeled\offroadhatchback\data\niva_lights.rvmat";
		frontReflectorMatOff = "dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat";
		brakeReflectorMatOn = "dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights_e.rvmat";
		brakeReflectorMatOff = "dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat";
		ReverseReflectorMatOn = "dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights_e.rvmat";
		ReverseReflectorMatOff = "dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat";
		TailReflectorMatOn = "dz\vehicles\wheeled\offroadhatchback\data\OffroadHatchback_lights_e.rvmat";
		TailReflectorMatOff = "dz\vehicles\wheeled\offroadhatchback\data\OffroadHatchback_lights.rvmat";
		fuelCapacity = 42;
		fuelConsumption = 11;
		class Crew: Crew
		{
			class Driver: Driver{};
			class CoDriver: CoDriver{};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewCargo1";
				getInPos = "pos_driver";
				getInDir = "pos_driver_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewCargo2";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_AWD";
			airDragCoefficient = 0.995;
			class Steering
			{
				increaseSpeed[] = {0,45,60,23,100,12};
				decreaseSpeed[] = {0,80,60,40,90,20};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 1.0;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 4.0;
				gentleCoef = 0.75;
			};
			class Engine
			{
				inertia = 0.15;
				torqueMax = 114;
				torqueRpm = 3400;
				powerMax = 53.7;
				powerRpm = 5400;
				rpmIdle = 850;
				rpmMin = 900;
				rpmClutch = 1350;
				rpmRedline = 6000;
				rpmMax = 8000;
			};
			class Gearbox
			{
				reverse = 3.526;
				ratios[] = {3.667,2.1,1.361,1.0};
				timeToUncoupleClutch = 0.3;
				timeToCoupleClutch = 0.45;
				maxClutchTorque = 260;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 30;
					finalRatio = 4.1;
					brakeBias = 0.6;
					brakeForce = 4000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 1700;
						stiffness = 40000;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.0833;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "NivaWheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "NivaWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					finalRatio = 4.1;
					brakeBias = 0.4;
					brakeForce = 3800;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 1800;
						stiffness = 40000;
						compression = 2200;
						damping = 7600;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1059;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_2";
							inventorySlot = "NivaWheel_1_2";
						};
						class Right: Right
						{
							animDamper = "damper_2_2";
							inventorySlot = "NivaWheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,30};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources: AnimationSources
		{
			class SeatDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.8;
			};
			class SeatCoDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.8;
			};
			class damper_1_1
			{
				source = "user";
				initPhase = 0.4857;
				animPeriod = 1;
			};
			class damper_2_1: damper_1_1{};
			class damper_1_2
			{
				source = "user";
				initPhase = 0.4002;
				animPeriod = 1;
			};
			class damper_2_2: damper_1_2{};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0;
					};
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgZone_chassis"};
					inventorySlots[] = {};
				};
				class Front
				{
					class Health
					{
						hitpoints = 1500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_front"};
					componentNames[] = {"dmgZone_front"};
					transferToZonesNames[] = {"Fender_1_1","Fender_2_1","Engine","WindowFront"};
					transferToZonesThreshold[] = {0.5,0.5,0.5,0.1};
					transferToZonesCoefs[] = {0.7,0.7,0.5,0.05};
					inventorySlots[] = {"NivaHood","CarRadiator"};
					inventorySlotsCoefs[] = {0.3,0.3};
				};
				class Reflector_1_1
				{
					class Health
					{
						hitpoints = 10;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\headlights_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\glass_i_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\glass_i_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_lights_1_1"};
					componentNames[] = {"dmgZone_lights_1_1"};
					transferToZonesNames[] = {"Front","Fender_1_1","Engine"};
					transferToZonesCoefs[] = {0.1,0.15,0.05};
					inventorySlots[] = {"Reflector_1_1"};
					inventorySlotsCoefs[] = {1.0};
				};
				class Reflector_2_1: Reflector_1_1
				{
					transferToZonesNames[] = {"Front","Fender_2_1","Engine"};
					transferToZonesCoefs[] = {0.1,0.15,0.05};
					memoryPoints[] = {"dmgZone_lights_2_1"};
					componentNames[] = {"dmgZone_lights_2_1"};
					inventorySlots[] = {"Reflector_2_1"};
					inventorySlotsCoefs[] = {1.0};
				};
				class Back
				{
					class Health
					{
						hitpoints = 1500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_back"};
					componentNames[] = {"dmgZone_back"};
					transferToZonesNames[] = {"Fender_1_2","Fender_2_2","WindowLR","WindowRR"};
					transferToZonesCoefs[] = {0.3,0.3,0.2,0.2};
					inventorySlots[] = {"NivaTrunk"};
					inventorySlotsCoefs[] = {0.8};
				};
				class Roof
				{
					class Health
					{
						hitpoints = 700;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_roof"};
					componentNames[] = {"dmgZone_roof"};
					inventorySlotsCoefs[] = {0.0};
					inventorySlots[] = {};
				};
				class Fender_1_1
				{
					class Health
					{
						hitpoints = 1200;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_fender_1_1"};
					componentNames[] = {"dmgZone_fender_1_1"};
					transferToZonesNames[] = {"Front","Engine","Reflector_1_1","WindowFront"};
					transferToZonesThreshold[] = {0.2,0.5,0.9,0.5};
					transferToZonesCoefs[] = {0.3,0.6,0.6,0.4};
					inventorySlots[] = {"NivaHood","NivaWheel_1_1","NivaDriverDoors"};
					inventorySlotsCoefs[] = {0.3,0.3,0.3};
				};
				class Fender_1_2: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_1_2"};
					componentNames[] = {"dmgZone_fender_1_2"};
					transferToZonesNames[] = {"Back","FuelTank","WindowLR"};
					transferToZonesThreshold[] = {0.2,0.2,0.2};
					transferToZonesCoefs[] = {0.3,0.2,0.7};
					inventorySlots[] = {"NivaTrunk","NivaWheel_1_2"};
					inventorySlotsCoefs[] = {0.3,0.1};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_1"};
					componentNames[] = {"dmgZone_fender_2_1"};
					transferToZonesNames[] = {"Front","Engine","Reflector_2_1","WindowFront","Battery"};
					transferToZonesThreshold[] = {0.2,0.5,0.9,0.5,0.5};
					transferToZonesCoefs[] = {0.3,0.6,0.6,0.4,0.7};
					inventorySlots[] = {"NivaHood","NivaWheel_2_1","NivaDriverDoors"};
					inventorySlotsCoefs[] = {0.3,0.2,3};
				};
				class Fender_2_2: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_2"};
					componentNames[] = {"dmgZone_fender_2_2"};
					transferToZonesNames[] = {"Back","FuelTank","WindowRR"};
					transferToZonesThreshold[] = {0.2,0.2,0.2};
					transferToZonesCoefs[] = {0.3,0.2,0.7};
					inventorySlots[] = {"NivaTrunk","NivaWheel_2_2"};
					inventorySlotsCoefs[] = {0.3,0.1};
				};
				class WindowFront
				{
					class Health
					{
						hitpoints = 150;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"}},{0.0,"hidden"}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_windowFront"};
					componentNames[] = {"dmgZone_windowFront"};
					inventorySlots[] = {};
				};
				class WindowLR
				{
					class Health
					{
						hitpoints = 150;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"}},{0.0,"hidden"}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_windowLeft"};
					componentNames[] = {"dmgZone_windowLeft"};
					inventorySlots[] = {};
				};
				class WindowRR: WindowLR
				{
					memoryPoints[] = {"dmgZone_windowRight"};
					componentNames[] = {"dmgZone_windowRight"};
				};
				class Engine
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_destruct.rvmat"}}};
					};
					fatalInjuryCoef = 0.001;
					memoryPoints[] = {"dmgZone_engine"};
					componentNames[] = {"dmgZone_engine"};
					inventorySlots[] = {"CarBattery","SparkPlug","EngineBelt","CarRadiator"};
					inventorySlotsCoefs[] = {0.2,0.2,0.01,0.4};
				};
				class FuelTank
				{
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
					};
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgZone_fuelTank"};
					inventorySlots[] = {};
				};
			};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,0.7};
					};
					class Cyl3
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,-0.7};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"CarBattery","CarRadiator","SparkPlug"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","NivaHood","NivaTrunk","NivaDriverDoors","NivaCoDriverDoors","NivaWheel_Spare_1"};
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2"};
			};
		};
	};
	class OffroadHatchback_Blue: OffroadHatchback
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_body.rvmat"};
		class DamageSystem: DamageSystem
		{
			class DamageZones: DamageZones
			{
				class Chassis: Chassis
				{
					class Health: Health{};
				};
				class Reflector_1_1: Reflector_1_1
				{
					class Health: Health{};
				};
				class Reflector_2_1: Reflector_2_1
				{
					class Health: Health{};
				};
				class WindowFront: WindowFront
				{
					class Health: Health{};
				};
				class Engine: Engine
				{
					class Health: Health{};
				};
				class Roof: Roof
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_destruct.rvmat"}}};
					};
				};
				class Front: Front
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_destruct.rvmat"}}};
					};
				};
				class Back: Back
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_destruct.rvmat"}}};
					};
				};
				class Fender_1_1: Fender_1_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_destruct.rvmat"}}};
					};
				};
				class Fender_1_2: Fender_1_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_destruct.rvmat"}}};
					};
				};
				class Fender_2_1: Fender_2_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_destruct.rvmat"}}};
					};
				};
				class Fender_2_2: Fender_2_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_destruct.rvmat"}}};
					};
				};
				class FuelTank: FuelTank
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_body_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_Driver_Blue: HatchbackDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_CoDriver_Blue: HatchbackDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackHood_Blue: HatchbackHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class HatchbackTrunk_Blue: HatchbackTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\blue\niva_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue\niva_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class OffroadHatchback_White: OffroadHatchback
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat","dz\vehicles\wheeled\OffroadHatchback\data\white\niva_body.rvmat"};
		class DamageSystem: DamageSystem
		{
			class DamageZones: DamageZones
			{
				class Chassis: Chassis
				{
					class Health: Health{};
				};
				class Reflector_1_1: Reflector_1_1
				{
					class Health: Health{};
				};
				class Reflector_2_1: Reflector_2_1
				{
					class Health: Health{};
				};
				class WindowFront: WindowFront
				{
					class Health: Health{};
				};
				class Engine: Engine
				{
					class Health: Health{};
				};
				class Roof: Roof
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_destruct.rvmat"}}};
					};
				};
				class Front: Front
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_destruct.rvmat"}}};
					};
				};
				class Back: Back
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_destruct.rvmat"}}};
					};
				};
				class Fender_1_1: Fender_1_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_destruct.rvmat"}}};
					};
				};
				class Fender_1_2: Fender_1_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_destruct.rvmat"}}};
					};
				};
				class Fender_2_1: Fender_2_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_destruct.rvmat"}}};
					};
				};
				class Fender_2_2: Fender_2_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_destruct.rvmat"}}};
					};
				};
				class FuelTank: FuelTank
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_body_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_Driver_White: HatchbackDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\white\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_CoDriver_White: HatchbackDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\white\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackHood_White: HatchbackHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\white\niva_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class HatchbackTrunk_White: HatchbackTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\white\niva_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white\niva_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_Driver_GreenRust: HatchbackDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\green_rust\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_CoDriver_GreenRust: HatchbackDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\green_rust\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackHood_GreenRust: HatchbackHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\green_rust\niva_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class HatchbackTrunk_GreenRust: HatchbackTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\green_rust\niva_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\green_rust\niva_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_Driver_BlueRust: HatchbackDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\blue_rust\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_CoDriver_BlueRust: HatchbackDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\blue_rust\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackHood_BlueRust: HatchbackHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\blue_rust\niva_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class HatchbackTrunk_BlueRust: HatchbackTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\blue_rust\niva_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\blue_rust\niva_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_Driver_WhiteRust: HatchbackDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\white_rust\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_CoDriver_WhiteRust: HatchbackDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\white_rust\niva_door.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_door.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackHood_WhiteRust: HatchbackHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\white_rust\niva_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class HatchbackTrunk_WhiteRust: HatchbackTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\OffroadHatchback\data\white_rust\niva_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\offroadhatchback\data\green\niva_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\white_rust\niva_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanWheel: CarWheel
	{
		scope = 2;
		displayName = "$STR_CivSedanWheel0";
		descriptionShort = "$STR_CivSedanWheel1";
		model = "\DZ\vehicles\wheeled\civiliansedan\proxy\sedanwheel.p3d";
		inventorySlot[] = {"CivSedanWheel_1_1","CivSedanWheel_1_2","CivSedanWheel_2_1","CivSedanWheel_2_2"};
		rotationFlags = 4;
		radiusByDamage[] = {0,0.34,0.3,0.3,0.9998,0.25,0.9999,0.2};
		radius = 0.34;
		friction = 0.96;
		width = 0.16;
		tyreRollResistance = 0.015;
		tyreTread = 1.0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\vehicles\wheeled\civiliansedan\data\gaz_wheel.rvmat"}},{0.7,{"DZ\vehicles\wheeled\civiliansedan\data\gaz_wheel.rvmat"}},{0.5,{"DZ\vehicles\wheeled\civiliansedan\data\gaz_wheel_damage.rvmat"}},{0.3,{"DZ\vehicles\wheeled\civiliansedan\data\gaz_wheel_damage.rvmat"}},{0.0,{"DZ\vehicles\wheeled\civiliansedan\data\gaz_wheel_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanWheel_Ruined: CivSedanWheel
	{
		scope = 2;
		displayName = "$STR_CivSedanWheel0";
		model = "\DZ\vehicles\wheeled\civiliansedan\proxy\sedanwheel_destroyed.p3d";
		radius = 0.238;
		width = 0.2;
		tyreRollResistance = 1;
		tyreRollDrag = 75;
		tyreRoughness = 1.2;
		tyreTread = 0.5;
	};
	class CivSedanDoors_Driver: CarDoor
	{
		scope = 2;
		displayName = "$STR_CivSedanDoors_Driver0";
		descriptionShort = "$STR_CivSedanDoors_Driver1";
		model = "\DZ\vehicles\wheeled\civilianSedan\proxy\sedanDoors_Driver.p3d";
		inventorySlot = "CivSedanDriverDoors";
		rotationFlags = 8;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\glass.rvmat","dz\vehicles\wheeled\civiliansedan\data\glass_i.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\glass.rvmat","dz\vehicles\wheeled\civiliansedan\data\glass_i_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\glass_destruct.rvmat","dz\vehicles\wheeled\civiliansedan\data\glass_i_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_CoDriver: CivSedanDoors_Driver
	{
		displayName = "$STR_CivSedanDoors_CoDriver0";
		descriptionShort = "$STR_CivSedanDoors_CoDriver1";
		model = "\DZ\vehicles\wheeled\civilianSedan\proxy\sedanDoors_coDriver.p3d";
		inventorySlot = "CivSedanCoDriverDoors";
		rotationFlags = 4;
	};
	class CivSedanDoors_BackLeft: CivSedanDoors_Driver
	{
		displayName = "$STR_CivSedanDoors_BackLeft0";
		descriptionShort = "$STR_CivSedanDoors_BackLeft1";
		model = "\DZ\vehicles\wheeled\civilianSedan\proxy\sedanDoors_cargo1.p3d";
		inventorySlot = "CivSedanCargo1Doors";
	};
	class CivSedanDoors_BackRight: CivSedanDoors_Driver
	{
		displayName = "$STR_CivSedanDoors_BackRight0";
		descriptionShort = "$STR_CivSedanDoors_BackRight1";
		model = "\DZ\vehicles\wheeled\civilianSedan\proxy\sedanDoors_cargo2.p3d";
		inventorySlot = "CivSedanCargo2Doors";
		rotationFlags = 4;
	};
	class CivSedanHood: CarDoor
	{
		scope = 2;
		displayName = "$STR_CivSedanHood0";
		descriptionShort = "$STR_CivSedanHood1";
		model = "\DZ\vehicles\wheeled\civilianSedan\proxy\sedanhood.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "CivSedanHood";
		rotationFlags = 4;
		physLayer = "item_large";
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanTrunk: CarDoor
	{
		scope = 2;
		displayName = "$STR_CivSedanTrunk0";
		descriptionShort = "$STR_CivSedanTrunk1";
		model = "\DZ\vehicles\wheeled\civilianSedan\proxy\sedanTrunk.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "CivSedanTrunk";
		rotationFlags = 4;
		physLayer = "item_large";
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivilianSedan: CarScript
	{
		scope = 2;
		displayName = "$STR_CivilianSedan0";
		descriptionShort = "$STR_CivilianSedan1";
		model = "\DZ\vehicles\wheeled\civiliansedan\CivilianSedan.p3d";
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1","CarRadiator","SparkPlug","CivSedanDriverDoors","CivSedanCoDriverDoors","CivSedanCargo1Doors","CivSedanCargo2Doors","CivSedanHood","CivSedanTrunk","CivSedanWheel_1_1","CivSedanWheel_1_2","CivSedanWheel_2_1","CivSedanWheel_2_2"};
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","dmgZone_chassis","dmgZone_front","dmgZone_back","dmgZone_roof","dmgZone_fender_1_1","dmgZone_fender_1_2","dmgZone_fender_2_1","dmgZone_fender_2_2"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","","",""};
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\civiliansedan.rvmat_cr","dz\vehicles\wheeled\civiliansedan\data\civiliansedan.rvmat_cr","dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
		dashboardMatOn = "dz\vehicles\wheeled\civiliansedan\data\civiliansedan_int2e_.rvmat";
		dashboardMatOff = "dz\vehicles\wheeled\civiliansedan\data\civiliansedan_int2e_off.rvmat";
		frontReflectorMatOn = "dz\vehicles\wheeled\civiliansedan\data\civiliansedan_lights.rvmat";
		frontReflectorMatOff = "dz\vehicles\wheeled\civiliansedan\data\civiliansedan.rvmat";
		brakeReflectorMatOn = "dz\vehicles\wheeled\civiliansedan\data\Sedan_TailLights_e.rvmat";
		brakeReflectorMatOff = "dz\vehicles\wheeled\civiliansedan\data\Sedan_TailLights.rvmat";
		ReverseReflectorMatOn = "dz\vehicles\wheeled\civiliansedan\data\Sedan_TailLights_e.rvmat";
		ReverseReflectorMatOff = "dz\vehicles\wheeled\civiliansedan\data\Sedan_TailLights.rvmat";
		TailReflectorMatOn = "dz\vehicles\wheeled\civiliansedan\data\Sedan_TailLights_e.rvmat";
		TailReflectorMatOff = "dz\vehicles\wheeled\civiliansedan\data\Sedan_TailLights.rvmat";
		fuelCapacity = 55;
		fuelConsumption = 13;
		class Crew: Crew
		{
			class Driver: Driver{};
			class CoDriver: CoDriver{};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewCargo1";
				getInPos = "pos_cargo1";
				getInDir = "pos_cargo1_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewCargo2";
				getInPos = "pos_cargo2";
				getInDir = "pos_cargo2_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_RWD";
			airDragCoefficient = 0.928;
			class Steering
			{
				increaseSpeed[] = {0,50,30,40,60,25,120,5};
				decreaseSpeed[] = {0,50,60,30,120,10};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 0.25;
				defaultThrust = 0.8;
				gentleThrust = 0.6;
				turboCoef = 5.0;
				gentleCoef = 0.7;
			};
			class Engine
			{
				inertia = 0.45;
				torqueMax = 187;
				torqueRpm = 2400;
				powerMax = 73.5;
				powerRpm = 4500;
				rpmIdle = 1000;
				rpmMin = 1050;
				rpmClutch = 1250;
				rpmRedline = 4700;
				rpmMax = 6800;
			};
			class Gearbox
			{
				reverse = 3.51;
				ratios[] = {3.5,2.26,1.45,1.0};
				timeToUncoupleClutch = 0.3;
				timeToCoupleClutch = 0.3;
				maxClutchTorque = 180;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 35;
					brakeBias = 0.7;
					brakeForce = 4500;
					wheelHubMass = 10;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 300;
						stiffness = 60000;
						compression = 2100;
						damping = 5500;
						travelMaxUp = 0.079;
						travelMaxDown = 0.06;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "CivSedanWheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "CivSedanWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					brakeBias = 0.3;
					brakeForce = 3500;
					finalRatio = 4.1;
					wheelHubMass = 10;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 275;
						stiffness = 34000;
						compression = 2000;
						damping = 5100;
						travelMaxUp = 0.086;
						travelMaxDown = 0.133;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_2";
							inventorySlot = "CivSedanWheel_1_2";
						};
						class Right: Right
						{
							animDamper = "damper_2_2";
							inventorySlot = "CivSedanWheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,40};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources: AnimationSources
		{
			class DoorsCargo1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCargo2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class damper_1_1
			{
				source = "user";
				initPhase = 0.4857;
				animPeriod = 1;
			};
			class damper_2_1: damper_1_1{};
			class damper_1_2
			{
				source = "user";
				initPhase = 0.5936;
				animPeriod = 1;
			};
			class damper_2_2: damper_1_2{};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_chassis"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Front
				{
					class Health
					{
						hitpoints = 1500;
						transferToGlobalCoef = 0;
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_front"};
					componentNames[] = {"dmgZone_front"};
					transferToZonesNames[] = {"Fender_1_1","Fender_2_1","Engine","WindowFront"};
					transferToZonesThreshold[] = {0.5,0.5,0.5,0.1};
					transferToZonesCoefs[] = {0.7,0.7,0.5,0.05};
					inventorySlots[] = {"CivSedanHood","CarRadiator"};
					inventorySlotsCoefs[] = {0.3,0.3};
				};
				class Reflector_1_1
				{
					class Health
					{
						hitpoints = 10;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\headlights_glass.rvmat"},{"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\glass_i_damage.rvmat"},{"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\glass_i_destruct.rvmat"},{"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_lights_1_1"};
					componentNames[] = {"dmgZone_lights_1_1"};
					transferToZonesNames[] = {"Front","Fender_1_1","Engine"};
					transferToZonesCoefs[] = {0.1,0.15,0.05};
					inventorySlots[] = {"Reflector_1_1"};
					inventorySlotsCoefs[] = {1.0};
				};
				class Reflector_2_1: Reflector_1_1
				{
					memoryPoints[] = {"dmgZone_lights_2_1"};
					componentNames[] = {"dmgZone_lights_2_1"};
					transferToZonesNames[] = {"Front","Fender_2_1","Engine"};
					transferToZonesCoefs[] = {0.1,0.15,0.05};
					inventorySlotsCoefs[] = {1.0};
					inventorySlots[] = {"Reflector_2_1"};
				};
				class Back
				{
					class Health
					{
						hitpoints = 1500;
						transferToGlobalCoef = 0;
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\civiliansedan_cr.rvmat"};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_back"};
					componentNames[] = {"dmgZone_back"};
					transferToZonesNames[] = {"Fender_1_2","Fender_2_2","WindowBack"};
					transferToZonesCoefs[] = {0.3,0.3,0.2};
					inventorySlots[] = {"CivSedanTrunk"};
				};
				class Roof
				{
					class Health
					{
						hitpoints = 700;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_roof"};
					componentNames[] = {"dmgZone_roof"};
					inventorySlots[] = {};
				};
				class Fender_1_1
				{
					class Health
					{
						hitpoints = 1200;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan_destruct.rvmat"}}};
					};
					fatalInjuryCoef = -1;
					transferToZonesNames[] = {"Front","Engine","Reflector_1_1","WindowFront"};
					transferToZonesThreshold[] = {0.2,0.5,0.9,0.5};
					transferToZonesCoefs[] = {0.3,0.6,0.6,0.4};
					memoryPoints[] = {"dmgZone_fender_1_1"};
					componentNames[] = {"dmgZone_fender_1_1"};
					inventorySlots[] = {"CivSedanHood","CivSedanWheel_1_1","CivSedanDriverDoors"};
					inventorySlotsCoefs[] = {0.3,0.3,0.3};
				};
				class Fender_1_2: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_1_2"};
					componentNames[] = {"dmgZone_fender_1_2"};
					transferToZonesNames[] = {"Back","FuelTank","WindowBack"};
					transferToZonesThreshold[] = {0.2,0.2,0.2};
					transferToZonesCoefs[] = {0.3,0.2,0.7};
					inventorySlotsCoefs[] = {0.3,0.1};
					inventorySlots[] = {"CivSedanTrunk","CivSedanWheel_1_2"};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_1"};
					componentNames[] = {"dmgZone_fender_2_1"};
					transferToZonesNames[] = {"Front","Engine","Reflector_2_1","WindowFront","Battery"};
					transferToZonesThreshold[] = {0.2,0.5,0.9,0.5,0.5};
					transferToZonesCoefs[] = {0.3,0.6,0.6,0.4,0.7};
					inventorySlots[] = {"CivSedanHood","CivSedanWheel_2_1","CivSedanDriverDoors"};
					inventorySlotsCoefs[] = {0.3,0.2,31};
				};
				class Fender_2_2: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_2"};
					componentNames[] = {"dmgZone_fender_2_2"};
					transferToZonesNames[] = {"Back","FuelTank","WindowBack"};
					transferToZonesThreshold[] = {0.2,0.2,0.2};
					transferToZonesCoefs[] = {0.3,0.2,0.7};
					inventorySlots[] = {"CivSedanTrunk","CivSedanWheel_2_2"};
					inventorySlotsCoefs[] = {0.3,0.1};
				};
				class WindowFront
				{
					class Health
					{
						hitpoints = 150;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\glass.rvmat","dz\vehicles\wheeled\civiliansedan\data\glass_i.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\glass.rvmat","dz\vehicles\wheeled\civiliansedan\data\glass_i_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\glass_destruct.rvmat","dz\vehicles\wheeled\civiliansedan\data\glass_i_destruct.rvmat"}},{0.0,"hidden"}};
					};
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_windowFront"};
					componentNames[] = {"dmgZone_windowFront"};
					inventorySlots[] = {};
				};
				class WindowBack: WindowFront
				{
					componentNames[] = {"dmgZone_windowBack"};
					memoryPoints[] = {"dmgZone_windowBack"};
				};
				class Engine
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_destruct.rvmat"}}};
					};
					fatalInjuryCoef = 0.001;
					memoryPoints[] = {"dmgZone_engine"};
					componentNames[] = {"dmgZone_engine"};
					inventorySlots[] = {"CarBattery","SparkPlug","EngineBelt","CarRadiator"};
					inventorySlotsCoefs[] = {0.2,0.2,0.01,0.4};
				};
				class FuelTank
				{
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
					};
					componentNames[] = {"dmgZone_fuelTank"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,0.8};
					};
					class Cyl3
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,-0.8};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"CarBattery","CarRadiator","SparkPlug"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","CivSedanHood","CivSedanTrunk","CivSedanDriverDoors","CivSedanCoDriverDoors","CivSedanCargo1Doors","CivSedanCargo2Doors"};
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"CivSedanWheel_1_1","CivSedanWheel_1_2","CivSedanWheel_2_1","CivSedanWheel_2_2","CivSedanWheel_Spare_1"};
			};
		};
	};
	class CivilianSedan_Wine: CivilianSedan
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\civiliansedan.rvmat_cr","dz\vehicles\wheeled\civiliansedan\data\civiliansedan.rvmat_cr","dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones: DamageZones
			{
				class Chassis: Chassis
				{
					class Health: Health{};
				};
				class WindowFront: WindowFront
				{
					class Health: Health{};
				};
				class WindowBack: WindowBack
				{
					class Health: Health{};
				};
				class Engine: Engine
				{
					class Health: Health{};
				};
				class FuelTank: FuelTank
				{
					class Health: Health{};
				};
				class Roof: Roof
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
				class Fender_1_1: Fender_1_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
				class Fender_1_2: Fender_1_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
				class Fender_2_1: Fender_2_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
				class Fender_2_2: Fender_2_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_Driver_Wine: CivSedanDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_CoDriver_Wine: CivSedanDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackLeft_Wine: CivSedanDoors_BackLeft
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackRight_Wine: CivSedanDoors_BackRight
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanHood_Wine: CivSedanHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanTrunk_Wine: CivSedanTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivilianSedan_Black: CivilianSedan
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\civiliansedan.rvmat_cr","dz\vehicles\wheeled\civiliansedan\data\civiliansedan.rvmat_cr","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat","dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones: DamageZones
			{
				class Chassis: Chassis
				{
					class Health: Health{};
				};
				class WindowFront: WindowFront
				{
					class Health: Health{};
				};
				class WindowBack: WindowBack
				{
					class Health: Health{};
				};
				class Engine: Engine
				{
					class Health: Health{};
				};
				class FuelTank: FuelTank
				{
					class Health: Health{};
				};
				class Roof: Roof
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
				class Fender_1_1: Fender_1_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
				class Fender_1_2: Fender_1_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
				class Fender_2_1: Fender_2_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
				class Fender_2_2: Fender_2_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_Driver_Black: CivSedanDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_CoDriver_Black: CivSedanDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackLeft_Black: CivSedanDoors_BackLeft
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackRight_Black: CivSedanDoors_BackRight
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanHood_Black: CivSedanHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanTrunk_Black: CivSedanTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanDoors_Driver_WhiteRust: CivSedanDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_CoDriver_WhiteRust: CivSedanDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackLeft_WhiteRust: CivSedanDoors_BackLeft
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackRight_WhiteRust: CivSedanDoors_BackRight
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanHood_WhiteRust: CivSedanHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanTrunk_WhiteRust: CivSedanTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\white_rust\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanDoors_Driver_WineRust: CivSedanDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_CoDriver_WineRust: CivSedanDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackLeft_WineRust: CivSedanDoors_BackLeft
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackRight_WineRust: CivSedanDoors_BackRight
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanHood_WineRust: CivSedanHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanTrunk_WineRust: CivSedanTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\wine_rust\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanDoors_Driver_BlackRust: CivSedanDoors_Driver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_CoDriver_BlackRust: CivSedanDoors_CoDriver
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackLeft_BlackRust: CivSedanDoors_BackLeft
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanDoors_BackRight_BlackRust: CivSedanDoors_BackRight
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class CivSedanHood_BlackRust: CivSedanHood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class CivSedanTrunk_BlackRust: CivSedanTrunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\civiliansedan\data\white\civiliansedan.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\black_rust\civiliansedan_destruct.rvmat"}}};
				};
			};
		};
	};
	class Hatchback_02_Wheel: CarWheel
	{
		scope = 2;
		displayName = "$STR_CivHatchbackWheel0";
		descriptionShort = "$STR_CivHatchbackWheel1";
		model = "\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Wheel.p3d";
		rotationFlags = 8;
		inventorySlot[] = {"Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2"};
		radiusByDamage[] = {0,0.34,0.3,0.3,0.9998,0.25,0.9999,0.2};
		radius = 0.304;
		friction = 0.96;
		width = 0.16;
		tyreRollResistance = 0.014;
		tyreTread = 0.95;
	};
	class Hatchback_02_Wheel_Ruined: Hatchback_02_Wheel
	{
		model = "\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Wheel_ruined.p3d";
		radius = 0.14;
		friction = -1.0;
		width = 0.2;
		tyreRollResistance = 1;
		tyreRollDrag = 80;
		tyreRoughness = 1.35;
		tyreTread = 0.45;
	};
	class Hatchback_02_Door_1_1: CarDoor
	{
		scope = 2;
		displayName = "$STR_CivHatchbackDoors_Driver0";
		descriptionShort = "$STR_CivHatchbackDoors_Driver1";
		model = "\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_1_1.p3d";
		inventorySlot = "Hatchback_02_Door_1_1";
		rotationFlags = 8;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat","dz\vehicles\wheeled\hatchback_02\data\glass_i.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat","dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.5,{"hidden","dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.3,{"hidden","dz\vehicles\wheeled\hatchback_02\data\glass_i_destruct.rvmat"}},{0.0,"hidden","hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_1: Hatchback_02_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_2_1.p3d";
		displayName = "$STR_CivHatchbackDoors_CoDriver0";
		descriptionShort = "$STR_CivHatchbackDoors_CoDriver1";
		inventorySlot = "Hatchback_02_Door_2_1";
		rotationFlags = 4;
	};
	class Hatchback_02_Door_1_2: Hatchback_02_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_1_2.p3d";
		displayName = "$STR_CivHatchbackDoors_RearLeft0";
		descriptionShort = "$STR_CivHatchbackDoors_RearLeft1";
		inventorySlot = "Hatchback_02_Door_1_2";
		rotationFlags = 8;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat","dz\vehicles\wheeled\hatchback_02\data\glass_i.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat","dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.5,{"hidden","dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.3,{"hidden","dz\vehicles\wheeled\hatchback_02\data\glass_i_destruct.rvmat"}},{0.0,"hidden","hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_2: Hatchback_02_Door_1_2
	{
		model = "\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_2_2.p3d";
		displayName = "$STR_CivHatchbackDoors_RearRight0";
		descriptionShort = "$STR_CivHatchbackDoors_RearRight1";
		inventorySlot = "Hatchback_02_Door_2_2";
		rotationFlags = 4;
	};
	class Hatchback_02_Hood: Hatchback_02_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Hood.p3d";
		displayName = "$STR_CivHatchbackDoors_Hood0";
		descriptionShort = "$STR_CivHatchbackDoors_Hood1";
		inventorySlot = "Hatchback_02_Hood";
		rotationFlags = 2;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Hatchback_02_Trunk: Hatchback_02_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Trunk.p3d";
		displayName = "$STR_CivHatchbackDoors_Trunk0";
		descriptionShort = "$STR_CivHatchbackDoors_Trunk1";
		inventorySlot = "Hatchback_02_Trunk";
		rotationFlags = 2;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat","dz\vehicles\wheeled\hatchback_02\data\glass_i.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat","dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.5,{"hidden","dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.3,{"hidden","dz\vehicles\wheeled\hatchback_02\data\glass_i_destruct.rvmat"}},{0.0,"hidden","hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02: CarScript
	{
		scope = 2;
		displayName = "$STR_CivHatchback0";
		descriptionShort = "$STR_CivHatchback1";
		model = "\dz\vehicles\wheeled\Hatchback_02\Hatchback_02.p3d";
		frontReflectorMatDamaged = "";
		frontReflectorMatRuined = "";
		fuelCapacity = 55;
		fuelConsumption = 6.5;
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1","CarRadiator","SparkPlug","Hatchback_02_Door_1_1","Hatchback_02_Door_1_2","Hatchback_02_Door_2_1","Hatchback_02_Door_2_2","Hatchback_02_Trunk","Hatchback_02_Hood","Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2"};
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo_chassi"};
		hiddenSelectionsTextures[] = {"","","","","","","","","",""};
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
		dashboardMatOn = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_gauges_e.rvmat";
		dashboardMatOff = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_gauges.rvmat";
		frontReflectorMatOn = "dz\vehicles\wheeled\Hatchback_02\data\hatchback_02_lights.rvmat";
		frontReflectorMatOff = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_Body.rvmat";
		brakeReflectorMatOn = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights_e.rvmat";
		brakeReflectorMatOff = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights.rvmat";
		tailReflectorMatOn = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights_e.rvmat";
		tailReflectorMatOff = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights.rvmat";
		reverseReflectorMatOn = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights_e.rvmat";
		reverseReflectorMatOff = "dz\vehicles\wheeled\Hatchback_02\data\Hatchback_02_TailLights.rvmat";
		class Crew: Crew
		{
			class Driver: Driver{};
			class CoDriver: CoDriver{};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewCargo1";
				getInPos = "pos_driver";
				getInDir = "pos_driver_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewCargo2";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_FWD";
			airDragCoefficient = 0.79;
			class Steering
			{
				increaseSpeed[] = {0,50,60,30,100,15};
				decreaseSpeed[] = {0,90,60,45,100,20};
				centeringSpeed[] = {0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime = 0.7;
				defaultThrust = 0.75;
				gentleThrust = 0.5;
				turboCoef = 2.2;
				gentleCoef = 0.5;
			};
			class Engine
			{
				inertia = 0.27;
				torqueMax = 186;
				torqueRpm = 4400;
				powerMax = 100;
				powerRpm = 5800;
				rpmIdle = 1250;
				rpmMin = 1350;
				rpmClutch = 1500;
				rpmRedline = 6250;
				rpmMax = 7000;
			};
			class Gearbox
			{
				reverse = 3.167;
				ratios[] = {3.455,2.118,1.444,1.129,0.912};
				timeToUncoupleClutch = 0.25;
				timeToCoupleClutch = 0.35;
				maxClutchTorque = 225;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 35;
					finalRatio = 3.667;
					brakeBias = 0.75;
					brakeForce = 5000;
					wheelHubMass = 5;
					wheelHubRadius = 0.125;
					class Suspension
					{
						swayBar = 2000;
						stiffness = 27000;
						compression = 1650;
						damping = 6000;
						travelMaxUp = 0.16;
						travelMaxDown = 0.16;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "Hatchback_02_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "Hatchback_02_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					brakeBias = 0.45;
					brakeForce = 4000;
					wheelHubMass = 5;
					wheelHubRadius = 0.125;
					class Suspension
					{
						swayBar = 2000;
						stiffness = 27000;
						compression = 1650;
						damping = 6000;
						travelMaxUp = 0.16;
						travelMaxDown = 0.16;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_2";
							inventorySlot = "Hatchback_02_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper = "damper_2_2";
							inventorySlot = "Hatchback_02_Wheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,30};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources: AnimationSources
		{
			class DoorsCargo1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCargo2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class damper_1_1
			{
				source = "user";
				initPhase = 0.5;
				animPeriod = 1;
			};
			class damper_2_1: damper_1_1{};
			class damper_1_2: damper_1_1{};
			class damper_2_2: damper_1_2{};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_chassis"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Front
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_destruct.rvmat"}}};
					};
					componentNames[] = {"dmgZone_front"};
					memoryPoints[] = {"dmgZone_front","dmgZone_bumper_1"};
					fatalInjuryCoef = -1;
					transferToZonesNames[] = {"Fender_1_1","Fender_2_1","Engine","WindowFront"};
					transferToZonesThreshold[] = {0.5,0.5,0.5,0.1};
					transferToZonesCoefs[] = {0.7,0.7,0.5,0.05};
					inventorySlots[] = {"Hatchback_02_Hood","CarRadiator"};
					inventorySlotsCoefs[] = {0.3,0.3};
				};
				class Back
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_body_destruct.rvmat"}}};
					};
					componentNames[] = {"dmgZone_back"};
					memoryPoints[] = {"dmgZone_back","dmgZone_bumper_1"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class WindowFront
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat","dz\vehicles\wheeled\hatchback_02\data\glass_i.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\Hatchback_02_Windows.rvmat","dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.5,{"hidden","dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.3,{"hidden","dz\vehicles\wheeled\hatchback_02\data\glass_i_destruct.rvmat"}},{0.0,"hidden","hidden"}};
					};
					componentNames[] = {"dmgZone_windowFront"};
					memoryPoints[] = {"dmgZone_windowFront"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class Reflector_1_1
				{
					class Health
					{
						hitpoints = 10;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\hatchback_02_windows.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\glass_i_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\glass_i_destruct.rvmat"}}};
					};
					componentNames[] = {"dmgZone_lights_1_1"};
					memoryPoints[] = {"dmgZone_lights_1_1"};
					fatalInjuryCoef = -1;
					transferToZonesNames[] = {"Front","Fender_1_1","Engine"};
					transferToZonesCoefs[] = {0.1,0.15,0.05};
					inventorySlots[] = {"Reflector_1_1"};
					inventorySlotsCoefs[] = {1.0};
				};
				class Reflector_2_1: Reflector_1_1
				{
					componentNames[] = {"dmgZone_lights_2_1"};
					memoryPoints[] = {"dmgZone_lights_2_1"};
					transferToZonesNames[] = {"Front","Fender_2_1","Engine"};
					transferToZonesCoefs[] = {0.1,0.15,0.05};
					inventorySlots[] = {"Reflector_2_1"};
					inventorySlotsCoefs[] = {1.0};
				};
				class Roof
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_destruct.rvmat"}}};
					};
					componentNames[] = {"dmgZone_roof"};
					memoryPoints[] = {"dmgZone_roof"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Fender_1_1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body_destruct.rvmat"}}};
					};
					componentNames[] = {"dmgZone_fender_1_1"};
					memoryPoints[] = {"dmgZone_fender_1_1"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Fender_2_1: Fender_1_1
				{
					componentNames[] = {"dmgZone_fender_2_1"};
					memoryPoints[] = {"dmgZone_fender_2_1"};
				};
				class Fender_1_2: Fender_1_1
				{
					componentNames[] = {"dmgZone_fender_1_2"};
					memoryPoints[] = {"dmgZone_fender_1_2"};
				};
				class Fender_2_2: Fender_1_1
				{
					componentNames[] = {"dmgZone_fender_2_2"};
					memoryPoints[] = {"dmgZone_fender_2_2"};
				};
				class Engine
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 1;
					};
					componentNames[] = {"dmgZone_engine"};
					memoryPoints[] = {"dmgZone_engine"};
					fatalInjuryCoef = 0.001;
					inventorySlots[] = {};
				};
				class FuelTank
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = -1;
					};
					componentNames[] = {"dmgZone_fuelTank"};
					memoryPoints[] = {"dmgZone_fuelTank"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,0.7};
					};
					class Cyl3
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,-0.7};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"CarBattery","CarRadiator","SparkPlug"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","Hatchback_02_Door_1_1","Hatchback_02_Door_1_2","Hatchback_02_Door_2_1","Hatchback_02_Door_2_2","Hatchback_02_Hood","Hatchback_02_Trunk"};
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2"};
			};
		};
	};
	class Hatchback_02_Black: Hatchback_02
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones: DamageZones
			{
				class Chassis: Chassis
				{
					class Health: Health{};
				};
				class Front: Front
				{
					class Health: Health{};
				};
				class Back: Back
				{
					class Health: Health{};
				};
				class Reflector_1_1: Reflector_1_1
				{
					class Health: Health{};
				};
				class Reflector_2_1: Reflector_2_1
				{
					class Health: Health{};
				};
				class WindowFront: WindowFront
				{
					class Health: Health{};
				};
				class Engine: Engine
				{
					class Health: Health{};
				};
				class FuelTank: FuelTank
				{
					class Health: Health{};
				};
				class Roof: Roof
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
				class Fender_1_1: Fender_1_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
				class Fender_1_2: Fender_1_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
				class Fender_2_1: Fender_2_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
				class Fender_2_2: Fender_2_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_Body_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_1_Black: Hatchback_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_1_Black: Hatchback_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_2_Black: Hatchback_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_2_Black: Hatchback_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Hood_Black: Hatchback_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Hatchback_02_Trunk_Black: Hatchback_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black\Hatchback_02_Trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\hatchback_02\data\black\hatchback_02_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Blue: Hatchback_02
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones: DamageZones
			{
				class Chassis: Chassis
				{
					class Health: Health{};
				};
				class Front: Front
				{
					class Health: Health{};
				};
				class Back: Back
				{
					class Health: Health{};
				};
				class Reflector_1_1: Reflector_1_1
				{
					class Health: Health{};
				};
				class Reflector_2_1: Reflector_2_1
				{
					class Health: Health{};
				};
				class WindowFront: WindowFront
				{
					class Health: Health{};
				};
				class Engine: Engine
				{
					class Health: Health{};
				};
				class FuelTank: FuelTank
				{
					class Health: Health{};
				};
				class Roof: Roof
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
				class Fender_1_1: Fender_1_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
				class Fender_1_2: Fender_1_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
				class Fender_2_1: Fender_2_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
				class Fender_2_2: Fender_2_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Body_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_1_Blue: Hatchback_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_1_Blue: Hatchback_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_2_Blue: Hatchback_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_2_Blue: Hatchback_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Hood_Blue: Hatchback_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Hatchback_02_Trunk_Blue: Hatchback_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_Trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue\Hatchback_02_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_1_RedRust: Hatchback_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\red_rust\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_1_RedRust: Hatchback_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\red_rust\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_2_RedRust: Hatchback_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\red_rust\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_2_RedRust: Hatchback_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\red_rust\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Hood_RedRust: Hatchback_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_Hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Hatchback_02_Trunk_RedRust: Hatchback_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_Trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\red_rust\Hatchback_02_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_1_BlackRust: Hatchback_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black_rust\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_1_BlackRust: Hatchback_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black_rust\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_2_BlackRust: Hatchback_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black_rust\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_2_BlackRust: Hatchback_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black_rust\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Hood_BlackRust: Hatchback_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_Hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Hatchback_02_Trunk_BlackRust: Hatchback_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_Trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\black_rust\Hatchback_02_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_1_BlueRust: Hatchback_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_1_BlueRust: Hatchback_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\hatchback_02_frontdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_frontdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_frontdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_1_2_BlueRust: Hatchback_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Door_2_2_BlueRust: Hatchback_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\hatchback_02_backdoor.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_backdoor.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Hatchback_02_Hood_BlueRust: Hatchback_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_Hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Hatchback_02_Trunk_BlueRust: Hatchback_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_Trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\hatchback_02\data\red\hatchback_02_trunk.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Hatchback_02\data\blue_rust\Hatchback_02_trunk_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Wheel: CarWheel
	{
		scope = 2;
		displayName = "$STR_Sedan_02_Wheel0";
		descriptionShort = "$STR_Sedan_02_Wheel1";
		model = "\DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Wheel.p3d";
		inventorySlot[] = {"Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
		rotationFlags = 8;
		radiusByDamage[] = {0,0.33,0.3,0.29,0.9998,0.25,0.9999,0.21};
		radius = 0.33;
		friction = 0.96;
		width = 0.16;
		tyreRollResistance = 0.01;
		tyreTread = 0.95;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\vehicles\wheeled\Sedan_02\data\Sedan_02_wheel.rvmat"}},{0.7,{"DZ\vehicles\wheeled\Sedan_02\data\Sedan_02_wheel.rvmat"}},{0.5,{"DZ\vehicles\wheeled\Sedan_02\data\Sedan_02_wheel_damage.rvmat"}},{0.3,{"DZ\vehicles\wheeled\Sedan_02\data\Sedan_02_wheel_damage.rvmat"}},{0.0,{"DZ\vehicles\wheeled\Sedan_02\data\Sedan_02_wheel_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Wheel_Ruined: Sedan_02_Wheel
	{
		model = "\DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Wheel_ruined.p3d";
		radius = 0.22;
		friction = -1.0;
		width = 0.2;
		tyreRollResistance = 1;
		tyreRollDrag = 80;
		tyreRoughness = 1.2;
		tyreTread = 0.4;
	};
	class Sedan_02_Door_1_1: CarDoor
	{
		scope = 2;
		displayName = "$STR_Sedan_02_Door_1_10";
		descriptionShort = "$STR_Sedan_02_Door_1_11";
		model = "\DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Door_1_1.p3d";
		inventorySlot = "Sedan_02_Door_1_1";
		rotationFlags = 8;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\glass_interior.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\Sedan_02\data\glass_i_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Sedan_02\data\glass_i_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_1: Sedan_02_Door_1_1
	{
		displayName = "$STR_Sedan_02_Door_2_10";
		descriptionShort = "$STR_Sedan_02_Door_2_11";
		model = "\DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Door_2_1.p3d";
		inventorySlot = "Sedan_02_Door_2_1";
	};
	class Sedan_02_Door_1_2: Sedan_02_Door_1_1
	{
		displayName = "$STR_Sedan_02_Door_1_20";
		descriptionShort = "$STR_Sedan_02_Door_1_21";
		model = "\DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Door_1_2.p3d";
		inventorySlot = "Sedan_02_Door_1_2";
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\glass_interior.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\Sedan_02\data\glass_i_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Sedan_02\data\glass_i_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_2: Sedan_02_Door_1_1
	{
		displayName = "$STR_Sedan_02_Door_2_20";
		descriptionShort = "$STR_Sedan_02_Door_2_21";
		model = "\DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Door_2_2.p3d";
		inventorySlot = "Sedan_02_Door_2_2";
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\glass_interior.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\Sedan_02\data\glass_i_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Sedan_02\data\glass_i_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Hood: CarDoor
	{
		scope = 2;
		displayName = "$STR_Sedan_02_Hood0";
		descriptionShort = "$STR_Sedan_02_Hood1";
		model = "\DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Hood.p3d";
		inventorySlot = "Sedan_02_Hood";
		rotationFlags = 8;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Trunk: CarDoor
	{
		scope = 2;
		displayName = "$STR_Sedan_02_Trunk0";
		descriptionShort = "$STR_Sedan_02_Trunk1";
		model = "\DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Trunk.p3d";
		inventorySlot = "Sedan_02_Trunk";
		rotationFlags = 8;
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02: CarScript
	{
		scope = 2;
		displayName = "$STR_Sedan_020";
		model = "\DZ\vehicles\wheeled\Sedan_02\Sedan_02.p3d";
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1","CarRadiator","EngineBelt","SparkPlug","Sedan_02_Hood","Sedan_02_Trunk","Sedan_02_Door_1_1","Sedan_02_Door_2_1","Sedan_02_Door_1_2","Sedan_02_Door_2_2","Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","dmgZone_chassis","dmgZone_front","dmgZone_back","dmgZone_roof","dmgZone_fender_1_1","dmgZone_fender_1_2","dmgZone_fender_2_1","dmgZone_fender_2_2"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","",""};
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
		dashboardMatOn = "dz\vehicles\wheeled\sedan_02\data\sedan_02_int2e.rvmat";
		dashboardMatOff = "dz\vehicles\wheeled\sedan_02\data\sedan_02_int2.rvmat";
		frontReflectorMatOn = "dz\vehicles\wheeled\sedan_02\data\sedan_02_chrome_e.rvmat";
		frontReflectorMatOff = "dz\vehicles\wheeled\sedan_02\data\sedan_02_chrome.rvmat";
		brakeReflectorMatOn = "dz\vehicles\wheeled\sedan_02\data\sedan_02_lights_e.rvmat";
		brakeReflectorMatOff = "dz\vehicles\wheeled\sedan_02\data\sedan_02_lights.rvmat";
		ReverseReflectorMatOn = "dz\vehicles\wheeled\sedan_02\data\sedan_02_lights_e.rvmat";
		ReverseReflectorMatOff = "dz\vehicles\wheeled\sedan_02\data\sedan_02_lights.rvmat";
		TailReflectorMatOn = "dz\vehicles\wheeled\sedan_02\data\sedan_02_lights_e.rvmat";
		TailReflectorMatOff = "dz\vehicles\wheeled\sedan_02\data\sedan_02_lights.rvmat";
		fuelCapacity = 38;
		fuelConsumption = 7;
		class Crew: Crew
		{
			class Driver: Driver{};
			class CoDriver: CoDriver{};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewCargo1";
				getInPos = "pos_cargo1";
				getInDir = "pos_cargo1_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewCargo2";
				getInPos = "pos_cargo2";
				getInDir = "pos_cargo2_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_RWD";
			airDragCoefficient = 0.73;
			class Steering
			{
				increaseSpeed[] = {0,45,60,25,100,10};
				decreaseSpeed[] = {0,80,60,40,100,15};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 0.8;
				defaultThrust = 0.9;
				gentleThrust = 0.8;
				turboCoef = 2.8;
				gentleCoef = 0.5;
			};
			class Engine
			{
				inertia = 0.23;
				torqueMax = 82;
				torqueRpm = 3000;
				powerMax = 37.0;
				powerRpm = 5000;
				rpmIdle = 900;
				rpmMin = 1000;
				rpmRedline = 5750;
				rpmMax = 7000;
				rpmClutch = 1500;
			};
			class Gearbox
			{
				reverse = 3.27;
				ratios[] = {3.8,2.12,1.41,0.96};
				timeToUncoupleClutch = 0.1;
				timeToCoupleClutch = 0.3;
				maxClutchTorque = 165;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 30;
					finalRatio = 4.1;
					brakeBias = 0.6;
					brakeForce = 3400;
					wheelHubMass = 5;
					wheelHubRadius = 0.17;
					class Suspension
					{
						swayBar = 800;
						stiffness = 25000;
						compression = 1600;
						damping = 5200;
						travelMaxUp = 0.07;
						travelMaxDown = 0.08;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "Sedan_02_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "Sedan_02_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					finalRatio = 4.22;
					brakeBias = 0.4;
					brakeForce = 3200;
					wheelHubMass = 5;
					wheelHubRadius = 0.17;
					class Suspension
					{
						swayBar = 600;
						stiffness = 21500;
						compression = 1800;
						damping = 5600;
						travelMaxUp = 0.1;
						travelMaxDown = 0.1;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_2";
							inventorySlot = "Sedan_02_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper = "damper_2_2";
							inventorySlot = "Sedan_02_Wheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,30};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources: AnimationSources
		{
			class DoorsCargo1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCargo2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgZone_chassis"};
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0;
					};
					inventorySlots[] = {};
				};
				class Front
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_front"};
					componentNames[] = {"dmgZone_front","dmgZone_bumper_1"};
					class Health
					{
						hitpoints = 1500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\civiliansedan\data\yellow\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\civiliansedan\data\yellow\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\civiliansedan\data\yellow\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\civiliansedan\data\yellow\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\civiliansedan\data\yellow\sedan_02_body_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Fender_1_1","Fender_2_1"};
					transferToZonesThreshold[] = {0.5,0.5};
					transferToZonesCoefs[] = {0.7,0.7};
					inventorySlotsCoefs[] = {0.3,0.3};
					inventorySlots[] = {"CivSedanHood","CarRadiator"};
				};
				class Reflector_1_1
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_lights_1_1"};
					componentNames[] = {"dmgZone_lights_1_1"};
					class Health
					{
						hitpoints = 10;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\headlights_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\glass_i_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\glass_i_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Front","Fender_1_1","Engine"};
					transferToZonesCoefs[] = {0.1,0.15,0.05};
					inventorySlotsCoefs[] = {1.0};
					inventorySlots[] = {"Reflector_1_1"};
				};
				class Reflector_2_1: Reflector_1_1
				{
					memoryPoints[] = {"dmgZone_lights_2_1"};
					componentNames[] = {"dmgZone_lights_2_1"};
					transferToZonesNames[] = {"Front","Fender_2_1","Engine"};
					transferToZonesCoefs[] = {0.1,0.15,0.05};
					inventorySlotsCoefs[] = {1.0};
					inventorySlots[] = {"Reflector_2_1"};
				};
				class Back
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_back"};
					componentNames[] = {"dmgZone_back"};
					class Health
					{
						hitpoints = 1500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Fender_1_2","Fender_2_2","Engine"};
					transferToZonesCoefs[] = {0.3,0.3,0.1};
					inventorySlots[] = {"Sedan_02_Trunk"};
				};
				class Roof
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_roof"};
					componentNames[] = {"dmgZone_roof"};
					class Health
					{
						hitpoints = 700;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_destruct.rvmat"}}};
					};
					inventorySlots[] = {};
				};
				class Fender_1_1
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_fender_1_1"};
					componentNames[] = {"dmgZone_fender_1_1"};
					class Health
					{
						hitpoints = 1200;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Front","Reflector_1_1"};
					transferToZonesThreshold[] = {0.2,0.5};
					transferToZonesCoefs[] = {0.3,0.6};
					inventorySlotsCoefs[] = {0.3,0.3,0.3};
					inventorySlots[] = {"Sedan_02_Hood","Sedan_02_Wheel_1_1","Sedan_02_Door_1_1"};
				};
				class Fender_1_2: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_1_2"};
					componentNames[] = {"dmgZone_fender_1_2"};
					transferToZonesNames[] = {"Back","Engine","FuelTank"};
					transferToZonesThreshold[] = {0.2,0.2,0.2};
					transferToZonesCoefs[] = {0.3,0.2,0.7};
					inventorySlotsCoefs[] = {0.3,0.1};
					inventorySlots[] = {"Sedan_02_Trunk","Sedan_02_Door_1_2"};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_1"};
					componentNames[] = {"dmgZone_fender_2_1"};
					transferToZonesNames[] = {"Front","Reflector_2_1"};
					transferToZonesThreshold[] = {0.2,0.5};
					transferToZonesCoefs[] = {0.3,0.6};
					inventorySlotsCoefs[] = {0.3,0.2,0.3};
					inventorySlots[] = {"Sedan_02_Hood","Sedan_02_Wheel_2_1","Sedan_02_Door_2_1"};
				};
				class Fender_2_2: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_2"};
					componentNames[] = {"dmgZone_fender_2_2"};
					transferToZonesNames[] = {"Back","Engine","FuelTank"};
					transferToZonesThreshold[] = {0.2,0.2,0.2};
					transferToZonesCoefs[] = {0.3,0.2,0.7};
					inventorySlotsCoefs[] = {0.3,0.1};
					inventorySlots[] = {"Sedan_02_Trunk","Sedan_02_Wheel_2_2"};
				};
				class WindowFront
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_windowFront"};
					componentNames[] = {"dmgZone_windowFront"};
					class Health
					{
						hitpoints = 150;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\glass_interior.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\glass_i_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\glass_i_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class WindowBack: WindowFront
				{
					componentNames[] = {"dmgZone_windowBack"};
					memoryPoints[] = {"dmgZone_windowBack"};
				};
				class Engine
				{
					fatalInjuryCoef = 0.001;
					memoryPoints[] = {"dmgZone_engine"};
					componentNames[] = {"dmgZone_engine"};
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\engine_sedan_02.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\engine_sedan_02.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\engine_sedan_02_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\engine_sedan_02_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\engine_sedan_02_destruct.rvmat"}}};
					};
					inventorySlotsCoefs[] = {0.2,0.2,0.01,0.4};
					inventorySlots[] = {"CarBattery","SparkPlug","EngineBelt","CarRadiator"};
				};
				class FuelTank
				{
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgZone_fuelTank"};
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
					};
					inventorySlots[] = {};
				};
			};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,0.8};
					};
					class Cyl3
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,-0.8};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"CarBattery","CarRadiator","SparkPlug"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","Sedan_02_Door_1_1","Sedan_02_Door_2_1","Sedan_02_Door_1_2","Sedan_02_Door_2_2","Sedan_02_Hood","Sedan_02_Trunk"};
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
			};
		};
	};
	class Sedan_02_Red: Sedan_02
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\Sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health{};
			};
			class DamageZones: DamageZones
			{
				class Chassis: Chassis
				{
					class Health: Health{};
				};
				class Front: Front
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Reflector_1_1: Reflector_1_1
				{
					class Health: Health{};
				};
				class Reflector_2_1: Reflector_2_1{};
				class Back: Back
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Roof: Roof
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Fender_1_1: Fender_1_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Fender_1_2: Fender_1_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Fender_2_1: Fender_2_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Fender_2_2: Fender_2_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class WindowFront: WindowFront{};
				class WindowBack: WindowBack{};
				class Engine: Engine
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\engine_sedan_02.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\engine_sedan_02.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\engine_sedan_02_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\engine_sedan_02_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\engine_sedan_02_destruct.rvmat"}}};
					};
				};
				class FuelTank: FuelTank{};
			};
		};
	};
	class Sedan_02_Door_1_1_Red: Sedan_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_1_Red: Sedan_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_1_2_Red: Sedan_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_2_Red: Sedan_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Hood_Red: Sedan_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Trunk_Red: Sedan_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red\sedan_02_trunk_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Grey: Sedan_02
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat","dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health{};
			};
			class DamageZones: DamageZones
			{
				class Chassis: Chassis
				{
					class Health: Health{};
				};
				class Front: Front
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Reflector_1_1: Reflector_1_1
				{
					class Health: Health{};
				};
				class Reflector_2_1: Reflector_2_1{};
				class Back: Back
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Roof: Roof
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Fender_1_1: Fender_1_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Fender_1_2: Fender_1_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Fender_2_1: Fender_2_1
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class Fender_2_2: Fender_2_2
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_body.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_body_destruct.rvmat"}}};
					};
				};
				class WindowFront: WindowFront{};
				class WindowBack: WindowBack{};
				class Engine: Engine
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\engine_sedan_02.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\engine_sedan_02.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\engine_sedan_02_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\engine_sedan_02_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\engine_sedan_02_destruct.rvmat"}}};
					};
				};
				class FuelTank: FuelTank{};
			};
		};
	};
	class Sedan_02_Door_1_1_Grey: Sedan_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_1_Grey: Sedan_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_1_2_Grey: Sedan_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_2_Grey: Sedan_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Hood_Grey: Sedan_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Trunk_Grey: Sedan_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey\sedan_02_trunk_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Door_1_1_YellowRust: Sedan_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_1_YellowRust: Sedan_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_1_2_YellowRust: Sedan_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_2_YellowRust: Sedan_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Hood_YellowRust: Sedan_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Trunk_YellowRust: Sedan_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\yellow_rust\sedan_02_trunk_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Door_1_1_RedRust: Sedan_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_1_RedRust: Sedan_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_1_2_RedRust: Sedan_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_2_RedRust: Sedan_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Hood_RedRust: Sedan_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Trunk_RedRust: Sedan_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\red_rust\sedan_02_trunk_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Door_1_1_GreyRust: Sedan_02_Door_1_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_1_GreyRust: Sedan_02_Door_2_1
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_fore.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_fore_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_1_2_GreyRust: Sedan_02_Door_1_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Door_2_2_GreyRust: Sedan_02_Door_2_2
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health{};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_door_aft.rvmat"};
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_door_aft_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class Sedan_02_Hood_GreyRust: Sedan_02_Hood
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_hood.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_hood.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_hood.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_hood.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_hood_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_hood_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class Sedan_02_Trunk_GreyRust: Sedan_02_Trunk
	{
		hiddenSelectionsMaterials[] = {"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_trunk.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\vehicles\wheeled\sedan_02\data\yellow\sedan_02_trunk.rvmat"};
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_trunk.rvmat"}},{0.7,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_trunk.rvmat"}},{0.5,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_trunk_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_trunk_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\sedan_02\data\grey_rust\sedan_02_trunk_destruct.rvmat"}}};
				};
			};
		};
	};
	class Truck_01_Wheel: CarWheel
	{
		scope = 2;
		displayName = "$STR_V3SWheel0";
		model = "\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Wheel.p3d";
		weight = 30000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot[] = {"Truck_01_Wheel_1_1","Truck_01_Wheel_2_1","Truck_01_Wheel_Spare_1","Truck_01_Wheel_Spare_2"};
		rotationFlags = 12;
		physLayer = "item_large";
		radiusByDamage[] = {0,0.465,0.3,0.38,0.9998,0.35,0.9999,0.28};
		radius = 0.465;
		width = 0.2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire.rvmat","DZ\vehicles\wheeled\Truck_01\data\v3s_rim.rvmat"}},{0.7,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire.rvmat","DZ\vehicles\wheeled\Truck_01\data\v3s_rim.rvmat"}},{0.5,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire_damage.rvmat","DZ\vehicles\wheeled\Truck_01\data\v3s_rim_damage.rvmat"}},{0.3,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire_damage.rvmat","DZ\vehicles\wheeled\Truck_01\data\v3s_rim_damage.rvmat"}},{0.0,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire_destruct.rvmat","DZ\vehicles\wheeled\Truck_01\data\v3s_rim_destruct.rvmat"}}};
				};
			};
		};
	};
	class Truck_01_Wheel_Ruined: Truck_01_Wheel
	{
		model = "\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Wheel_ruined.p3d";
		weight = 25000;
		tyreRollResistance = 1;
		tyreRollDrag = 80;
		tyreRoughness = 1.35;
		tyreTread = 0.45;
		radius = 0.3;
		friction = -1.0;
		width = 0.2;
	};
	class Truck_01_WheelDouble: Truck_01_Wheel
	{
		displayName = "$STR_V3SWheelDouble0";
		model = "\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_WheelDouble.p3d";
		weight = 50000;
		inventorySlot[] = {"Truck_01_Wheel_1_2","Truck_01_Wheel_1_3","Truck_01_Wheel_2_2","Truck_01_Wheel_2_3"};
		width = 0.4;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = {{1.0,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire.rvmat","DZ\vehicles\wheeled\Truck_01\data\Truck_01_rim.rvmat"}},{0.7,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire.rvmat","DZ\vehicles\wheeled\Truck_01\data\Truck_01_rim.rvmat"}},{0.5,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire_damage.rvmat","DZ\vehicles\wheeled\Truck_01\data\Truck_01_rim_damage.rvmat"}},{0.3,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire_damage.rvmat","DZ\vehicles\wheeled\Truck_01\data\Truck_01_rim_damage.rvmat"}},{0.0,{"DZ\vehicles\wheeled\Truck_01\data\Truck_01_tire_destruct.rvmat","DZ\vehicles\wheeled\Truck_01\data\Truck_01_rim_destruct.rvmat"}}};
				};
			};
		};
	};
	class Truck_01_WheelDouble_Ruined: Truck_01_WheelDouble
	{
		model = "\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_WheelDouble_ruined.p3d";
		tyreRollResistance = 1;
		tyreRollDrag = 80;
		tyreRoughness = 1.35;
		tyreTread = 0.45;
		radius = 0.3;
		friction = -1.0;
	};
	class Truck_01_Door_1_1: CarDoor
	{
		scope = 2;
		displayName = "$STR_V3SDoors_Driver0";
		model = "\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Door_1_1.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		inventorySlot = "Truck_01_Door_1_1";
		rotationFlags = 8;
		hiddenSelections[] = {"camo_Door"};
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Window
				{
					class Health
					{
						hitpoints = 50;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\data\auta_skla_damage.rvmat"}},{0.3,{}},{0.0,{""}}};
					};
					componentNames[] = {"dmgZone_window"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Doors
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_door.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_door_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_door_destruct.rvmat"}}};
					};
					componentNames[] = {"dmgZone_doors"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
	};
	class Truck_01_Door_2_1: Truck_01_Door_1_1
	{
		displayName = "$STR_V3SDoors_CoDriver0";
		model = "\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Door_2_1.p3d";
		inventorySlot = "Truck_01_Door_2_1";
		rotationFlags = 4;
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_co.paa"};
	};
	class Truck_01_Door_1_1_Orange: Truck_01_Door_1_1
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_orange_co.paa"};
	};
	class Truck_01_Door_2_1_Orange: Truck_01_Door_2_1
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_orange_co.paa"};
	};
	class Truck_01_Door_1_1_Blue: Truck_01_Door_1_1
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_blue_co.paa"};
	};
	class Truck_01_Door_2_1_Blue: Truck_01_Door_2_1
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_blue_co.paa"};
	};
	class Truck_01_Door_1_1_Grey: Truck_01_Door_1_1
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_grey_co.paa"};
	};
	class Truck_01_Door_2_1_Grey: Truck_01_Door_2_1
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_grey_co.paa"};
	};
	class Truck_01_Hood: CarDoor
	{
		scope = 2;
		displayName = "$STR_V3SHood0";
		model = "\DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Hood.p3d";
		inventorySlot = "Truck_01_Hood";
		rotationFlags = 2;
		hiddenSelections[] = {"camo_Door"};
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_green_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_green.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_green_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_green_destruct.rvmat"}}};
				};
				componentNames[] = {"dmgZone_doors"};
			};
		};
	};
	class Truck_01_Hood_Orange: Truck_01_Hood
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_orange_co.paa"};
	};
	class Truck_01_Hood_Blue: Truck_01_Hood
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_Blue_co.paa"};
	};
	class Truck_01_Hood_Grey: Truck_01_Hood
	{
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_Grey_co.paa"};
	};
	class Truck_01_Chassis: CarScript
	{
		scope = 2;
		displayName = "$STR_v3s_chassis0";
		model = "\dz\vehicles\wheeled\Truck_01\Truck_01_Chassis.p3d";
		attachments[] = {"TruckBattery","Reflector_1_1","Reflector_2_1","Truck_01_Door_1_1","Truck_01_Door_2_1","Truck_01_Hood","Truck_01_Wheel_1_1","Truck_01_Wheel_1_2","Truck_01_Wheel_1_3","Truck_01_Wheel_2_1","Truck_01_Wheel_2_2","Truck_01_Wheel_2_3","Truck_01_Wheel_Spare_1","Truck_01_Wheel_Spare_2"};
		dashboardMatOn = "dz\vehicles\wheeled\Truck_01\data\Truck_01_dashboard_light.rvmat";
		dashboardMatOff = "dz\vehicles\wheeled\Truck_01\data\Truck_01_dashboard.rvmat";
		frontReflectorMatOn = "dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_lights.rvmat";
		frontReflectorMatOff = "dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_chrome.rvmat";
		frontReflectorMatDamaged = "dz\vehicles\wheeled\Truck_01\data\vTruck_01_cab_damage.rvmat";
		frontReflectorMatRuined = "dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_destruct.rvmat";
		fuelCapacity = 120;
		fuelConsumption = 30;
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_642";
			airDragCoefficient = 0.51;
			class Steering
			{
				increaseSpeed[] = {0,25,50,15};
				decreaseSpeed[] = {0,50,50,40};
				centeringSpeed[] = {0,25,50.0,15};
			};
			class Throttle
			{
				reactionTime = 1.0;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 3.0;
				gentleCoef = 0.5;
			};
			class Engine
			{
				inertia = 1.5;
				powerMax = 72;
				powerRpm = 2100;
				torqueMax = 360;
				torqueRpm = 1400;
				rpmIdle = 600;
				rpmMin = 650;
				rpmClutch = 700;
				rpmRedline = 2600;
				rpmMax = 3000;
			};
			class Gearbox
			{
				reverse = 6.28;
				ratios[] = {6.19,3.13,1.75,1.0};
				timeToUncoupleClutch = 0.4;
				timeToCoupleClutch = 0.2;
				maxClutchTorque = 400;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 35;
					finalRatio = 6.84;
					brakeBias = 0.5;
					brakeForce = 8000;
					wheelHubMass = 25;
					wheelHubRadius = 0.3;
					wheelHubRatio = 2.14;
					class Suspension
					{
						stiffness = 550000;
						compression = 6000;
						damping = 11500;
						travelMaxUp = 0.14;
						travelMaxDown = 0.15;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "Truck_01_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "Truck_01_Wheel_2_1";
						};
					};
				};
				class Middle: Rear
				{
					maxSteeringAngle = 0;
					finalRatio = 6.84;
					brakeBias = 0.25;
					brakeForce = 7500;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					wheelHubRatio = 2.14;
					class Suspension
					{
						swayBar = 1700;
						stiffness = 360000;
						compression = 7000;
						damping = 12000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
					class Wheels: Wheels
					{
						class Left
						{
							inventorySlot = "Truck_01_Wheel_1_2";
							animTurn = "turnmiddleleft";
							animRotation = "wheelmiddleleft";
							animDamper = "damper_1_2";
							wheelHub = "wheel_1_2_damper_land";
						};
						class Right
						{
							inventorySlot = "Truck_01_Wheel_2_2";
							animTurn = "turnmiddletright";
							animRotation = "wheelmiddleright";
							animDamper = "damper_2_2";
							wheelHub = "wheel_2_2_damper_land";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					finalRatio = 6.84;
					brakeBias = 0.25;
					brakeForce = 7500;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					wheelHubRatio = 2.14;
					class Suspension
					{
						stiffness = 360000;
						compression = 7000;
						damping = 12000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_3";
							inventorySlot = "Truck_01_Wheel_1_3";
							wheelHub = "wheel_1_3_damper_land";
						};
						class Right: Right
						{
							animDamper = "damper_2_3";
							inventorySlot = "Truck_01_Wheel_2_3";
							wheelHub = "wheel_2_3_damper_land";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,30};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources: AnimationSources
		{
			class WheelSidePlate1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1.3;
			};
			class WheelSidePlate2: WheelSidePlate1{};
			class Damper_1_1
			{
				source = "user";
				initPhase = 0.4828;
				animPeriod = 1;
			};
			class Damper_2_1: Damper_1_1{};
			class Damper_1_2
			{
				source = "user";
				initPhase = 0.4318;
				animPeriod = 1;
			};
			class Damper_2_2: Damper_1_2{};
			class Damper_1_3: Damper_1_2{};
			class Damper_2_3: Damper_1_2{};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 1;
					};
					componentNames[] = {"dmgZone_chassis"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Front
				{
					class Health
					{
						hitpoints = 2500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab.rvmat"}},{0.7,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab.rvmat"}},{0.5,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Fender_1_1","Fender_2_1","Engine"};
					transferToZonesThreshold[] = {0.2,0.2,0.0};
					transferToZonesCoefs[] = {0.6,0.6,0.8};
					memoryPoints[] = {"dmgZone_front"};
					componentNames[] = {"dmgZone_front"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"NivaHood"};
				};
				class Back
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cargo.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Fender_1_2","Fender_2_2","WindowLR","WindowRR"};
					transferToZonesCoefs[] = {0.3,0.3,0.2,0.2};
					memoryPoints[] = {"dmgZone_back"};
					componentNames[] = {"dmgZone_back"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Roof
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cabin_a.rvmat"}},{0.7,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cabin_a.rvmat"}},{0.5,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cabin_a_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cabin_a_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cabin_a_destruct.rvmat"}}};
					};
					memoryPoints[] = {"dmgZone_roof"};
					componentNames[] = {"dmgZone_roof"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Fender_1_1
				{
					class Health
					{
						hitpoints = 800;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab.rvmat"}},{0.7,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab.rvmat"}},{0.5,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Front","Engine","Lights"};
					transferToZonesThreshold[] = {0.5,0.25,1.0};
					transferToZonesCoefs[] = {0.3,0.6,0.8};
					memoryPoints[] = {"dmgZone_fender_1_1"};
					componentNames[] = {"dmgZone_fender_1_1"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Truck_01_Wheel_1_1"};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_1"};
					componentNames[] = {"dmgZone_fender_2_1"};
					inventorySlots[] = {"V3SWheel_2_1"};
				};
				class WindowFrontLeft
				{
					class Health
					{
						hitpoints = 50;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\data\auta_skla_damage.rvmat"}},{0.3,{}},{0.0,{""}}};
					};
					memoryPoints[] = {"dmgZone_windowFrontLeft"};
					componentNames[] = {"dmgZone_windowFrontLeft"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class WindowFrontRight: WindowFrontLeft
				{
					memoryPoints[] = {"dmgZone_windowFrontRight"};
					componentNames[] = {"dmgZone_windowFrontRight"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Engine
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_chassis.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_destruct.rvmat"}}};
					};
					memoryPoints[] = {"dmgZone_engine"};
					componentNames[] = {"dmgZone_engine"};
					fatalInjuryCoef = 0.001;
					inventorySlots[] = {};
				};
				class FuelTank
				{
					class Health
					{
						hitpoints = 300;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_chassis.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\Truck_01\data\Truck_01_destruct.rvmat"}}};
					};
					componentNames[] = {"dmgZone_fuelTank"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Reflector_1_1
				{
					class Health
					{
						hitpoints = 50;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
					};
					transferToZonesNames[] = {"Front","Fender_1_1"};
					transferToZonesCoefs[] = {1.0,1.0};
					memoryPoints[] = {"dmgZone_lights_1_1"};
					componentNames[] = {"dmgZone_lights_1_1"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Reflector_1_1"};
				};
				class Reflector_2_1: Reflector_1_1
				{
					transferToZonesNames[] = {"Front","Fender_2_1"};
					transferToZonesCoefs[] = {1.0,1.0};
					memoryPoints[] = {"dmgZone_lights_2_1"};
					componentNames[] = {"dmgZone_lights_2_1"};
					inventorySlots[] = {"Reflector_2_1"};
				};
			};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,1.5};
					};
					class Cyl2
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,0};
					};
					class Cyl3
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,-1.5};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"TruckBattery"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","Truck_01_Door_1_1","Truck_01_Door_2_1","Truck_01_Hood"};
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"Truck_01_Wheel_1_1","Truck_01_Wheel_1_2","Truck_01_Wheel_1_3","Truck_01_Wheel_2_1","Truck_01_Wheel_2_2","Truck_01_Wheel_2_3","Truck_01_Wheel_Spare_1","Truck_01_Wheel_Spare_2"};
			};
		};
	};
	class Truck_01_Chassis_Blue: Truck_01_Chassis
	{
		scope = 2;
		hiddenSelections[] = {"hood","cabin","doors_Driver","doors_coDriver"};
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_blue_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_blue_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_blue_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_blue_CO.paa"};
	};
	class Truck_01_Chassis_Orange: Truck_01_Chassis
	{
		scope = 2;
		hiddenSelections[] = {"spare_wheels","hood","cabin","doors_Driver","doors_coDriver"};
		hiddenSelectionsTextures[] = {"","\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_orange_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_orange_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_orange_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_orange_CO.paa"};
	};
	class Truck_01_Chassis_Grey: Truck_01_Chassis
	{
		scope = 2;
		hiddenSelections[] = {"hood","cabin","doors_Driver","doors_coDriver"};
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_grey_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_grey_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_grey_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_grey_CO.paa"};
	};
	class Truck_01_Cargo: Truck_01_Chassis
	{
		displayName = "$STR_v3s_cargo0";
		model = "\dz\vehicles\wheeled\Truck_01\Truck_01_Cargo.p3d";
		class Cargo
		{
			itemsCargoSize[] = {10,60};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources: AnimationSources
		{
			class DoorsTrunk
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
		};
	};
	class Truck_01_Cargo_Blue: Truck_01_Cargo
	{
		hiddenSelections[] = {"hood","cabin","doors_Driver","doors_coDriver"};
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_blue_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_blue_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_blue_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_blue_CO.paa"};
	};
	class Truck_01_Cargo_Orange: Truck_01_Cargo
	{
		hiddenSelections[] = {"hood","cabin","doors_Driver","doors_coDriver"};
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_orange_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_orange_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_orange_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_orange_CO.paa"};
	};
	class Truck_01_Cargo_Grey: Truck_01_Cargo
	{
		hiddenSelections[] = {"hood","cabin","doors_Driver","doors_coDriver"};
		hiddenSelectionsTextures[] = {"\dz\vehicles\wheeled\Truck_01\data\Truck_01_hood_grey_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_cab_grey_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_grey_CO.paa","\dz\vehicles\wheeled\Truck_01\data\Truck_01_door_grey_CO.paa"};
	};
	class Truck_02_Wheel: CarWheel
	{
		scope = 2;
		displayName = "Utility Vehicle Wheel";
		descriptionShort = "Wheel";
		model = "\DZ\vehicles\wheeled\Truck_02\proxy\Truck_02_Wheel.p3d";
		rotationFlags = 4;
		inventorySlot[] = {"Truck_02_Wheel_1_1","Truck_02_Wheel_1_2","Truck_02_Wheel_2_1","Truck_02_Wheel_2_2"};
		radiusByDamage[] = {0,0.34,0.3,0.3,0.9998,0.25,0.9999,0.2};
		radius = 0.34;
		friction = 0.96;
		width = 0.16;
		tyreRollResistance = 0.014;
		tyreTread = 0.7;
	};
	class Truck_02_Wheel_Ruined: Truck_02_Wheel
	{
		scope = 2;
		model = "\DZ\vehicles\wheeled\Truck_02\proxy\Truck_02_ruined.p3d";
		radius = 0.15;
		friction = -1.0;
		width = 0.2;
		tyreRollResistance = 1;
		tyreRollDrag = 80;
		tyreRoughness = 1.35;
		tyreTread = 0.45;
	};
	class Truck_02_Door_1_1: CarDoor
	{
		scope = 2;
		displayName = "Left Door";
		descriptionShort = "Door";
		model = "\DZ\vehicles\wheeled\Truck_02\proxy\Truck_02_Door_1_1.p3d";
		inventorySlot = "Truck_02_Door_1_1";
		rotationFlags = 2;
	};
	class Truck_02_Door_2_1: Truck_02_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Truck_02\proxy\Truck_02_Door_2_1.p3d";
		displayName = "Right Door";
		descriptionShort = "Door";
		inventorySlot = "Truck_02_Door_2_1";
	};
	class Truck_02: CarScript
	{
		scope = 2;
		displayName = "Utility Vehicle";
		descriptionShort = "Utility Vehicle";
		model = "\dz\vehicles\wheeled\Truck_02\Truck_02.p3d";
		dashboardMatOn = "";
		dashboardMatOff = "";
		frontReflectorMatOn = "";
		frontReflectorMatOff = "";
		frontReflectorMatDamaged = "";
		frontReflectorMatRuined = "";
		fuelCapacity = 42;
		fuelConsumption = 11;
		attachments[] = {"TruckBattery","Reflector_1_1","Reflector_2_1","Truck_02_Door_1_1","Truck_02_Door_2_1","Truck_02_Wheel_1_1","Truck_02_Wheel_1_2","Truck_02_Wheel_2_1","Truck_02_Wheel_2_2"};
		class Crew: Crew
		{
			class Driver: Driver{};
			class CoDriver: CoDriver{};
		};
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_RWD";
			airDragCoefficient = 1.195;
			class Steering
			{
				increaseSpeed[] = {0,45,60,25,100,15};
				decreaseSpeed[] = {0,90,60,45,100,15};
				centeringSpeed[] = {0,0,15,28,60,45,100,60};
			};
			class Throttle
			{
				reactionTime = 1.0;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 2.5;
				gentleCoef = 0.75;
			};
			class Engine
			{
				inertia = 0.15;
				torqueMax = 114;
				torqueRpm = 3400;
				powerMax = 53.7;
				powerRpm = 5400;
				rpmIdle = 850;
				rpmMin = 900;
				rpmClutch = 1350;
				rpmRedline = 6000;
				rpmMax = 8000;
			};
			class Gearbox
			{
				reverse = 3.526;
				ratios[] = {3.667,2.1,1.361,1.0};
				timeToUncoupleClutch = 0.35;
				timeToCoupleClutch = 0.45;
				maxClutchTorque = 75;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 30;
					finalRatio = 4.1;
					brakeBias = 0.5;
					brakeForce = 4500;
					wheelHubMass = 5;
					wheelHubRadius = 0.12;
					class Suspension
					{
						swayBar = 1700;
						stiffness = 42000;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.0833;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "Truck_02_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "Truck_02_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					finalRatio = 4.1;
					brakeBias = 0.4;
					brakeForce = 3800;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 1800;
						stiffness = 43000;
						compression = 2300;
						damping = 7900;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1059;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_2";
							inventorySlot = "Truck_02_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper = "damper_2_2";
							inventorySlot = "Truck_02_Wheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {7,10};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class DamageZones
			{
				class Front
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_front"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Back
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_back"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Roof
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_roof"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Fender_LF
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_fenderLF"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Fender_LR: Fender_LF
				{
					componentNames[] = {"dmgZone_fenderLR"};
				};
				class Fender_RF: Fender_LF
				{
					componentNames[] = {"dmgZone_fenderRF"};
				};
				class Fender_RR: Fender_LF
				{
					componentNames[] = {"dmgZone_fenderRR"};
				};
				class Engine
				{
					class Health
					{
						hitpoints = 400;
						transferToGlobalCoef = 1;
					};
					componentNames[] = {"dmgZone_engine"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Chassis
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = -1;
					};
					componentNames[] = {"dmgZone_chassis"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class FuelTank
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = -1;
					};
					componentNames[] = {"dmgZone_fuelTank"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
		class Sounds
		{
			thrust = 0.6;
			thrustTurbo = 1;
			thrustGentle = 0.3;
			thrustSmoothCoef = 0.02;
			camposSmoothCoef = 0.03;
			soundSetsFilter[] = {"offroad_Engine_Offload_Ext_Rpm1_SoundSet","offroad_Engine_Offload_Ext_Rpm2_SoundSet","offroad_Engine_Offload_Ext_Rpm3_SoundSet","offroad_Engine_Offload_Ext_Rpm4_SoundSet","offroad_Engine_Offload_Ext_Rpm5_SoundSet","offroad_Engine_Ext_Rpm0_SoundSet","offroad_Engine_Ext_Rpm1_SoundSet","offroad_Engine_Ext_Rpm2_SoundSet","offroad_Engine_Ext_Rpm3_SoundSet","offroad_Engine_Ext_Rpm4_SoundSet","offroad_Engine_Ext_Rpm5_SoundSet","offroad_Engine_Ext_Broken_SoundSet","offroad_Tires_rock_slow_Ext_SoundSet","offroad_Tires_rock_fast_Ext_SoundSet","offroad_Tires_grass_slow_Ext_SoundSet","offroad_Tires_grass_fast_Ext_SoundSet","offroad_Tires_gravel_slow_Ext_SoundSet","offroad_Tires_gravel_fast_Ext_SoundSet","offroad_Tires_gravel_dust_fast_Ext_SoundSet","offroad_Tires_asphalt_slow_Ext_SoundSet","offroad_Tires_asphalt_fast_Ext_SoundSet","offroad_Tires_water_slow_Ext_SoundSet","offroad_Tires_water_fast_Ext_SoundSet","Offroad_skid_dirt_SoundSet","offroad_dirt_turn_SoundSet","offroad_Rain_Ext_SoundSet","offroad_damper_left_SoundSet","offroad_damper_right_SoundSet"};
			soundSetsInt[] = {"Offroad_Tires_Asphalt_Fast_General_Int_SoundSet","Offroad_Wind_SoundSet"};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,0.7};
					};
					class Cyl3
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,-0.7};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"CarBattery","CarRadiator","SparkPlug"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","Truck_02_Door_1_1","Truck_02_Door_2_1"};
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"Truck_02_Wheel_1_1","Truck_02_Wheel_1_2","Truck_02_Wheel_2_1","Truck_02_Wheel_2_2"};
			};
		};
	};
	class Van_01_Wheel: CarWheel
	{
		scope = 2;
		displayName = "$STR_CivVanWheel0";
		descriptionShort = "$STR_CivVanWheel1";
		model = "\DZ\vehicles\wheeled\Van_01\proxy\Van_01_wheel.p3d";
		rotationFlags = 4;
		inventorySlot[] = {"Van_01_Wheel_1_1","Van_01_Wheel_1_2","Van_01_Wheel_2_1","Van_01_Wheel_2_2"};
		radiusByDamage[] = {0,0.34,0.3,0.3,0.9998,0.25,0.9999,0.2};
		radius = 0.34;
		friction = 0.96;
		width = 0.16;
	};
	class Van_01_Wheel_Ruined: Van_01_Wheel
	{
		scope = 2;
		displayName = "$STR_CivVanWheel_Ruined0";
		descriptionShort = "$STR_CivVanWheel_Ruined1";
		model = "\DZ\vehicles\wheeled\Van_01\proxy\Van_01_Wheel_ruined.p3d";
		inventorySlot[] = {"Van_01_Wheel_1_1","Van_01_Wheel_1_2","Van_01_Wheel_2_1","Van_01_Wheel_2_2"};
		radius = 0.15;
		friction = -1.0;
		width = 0.2;
		tyreRollResistance = 1;
		tyreRollDrag = 80;
		tyreRoughness = 1.35;
		tyreTread = 0.45;
	};
	class Van_01_Door_1_1: CarDoor
	{
		scope = 2;
		displayName = "$STR_CivVanDoors_Driver0";
		descriptionShort = "$STR_CivVanDoors_Driver1";
		model = "\DZ\vehicles\wheeled\Van_01\proxy\Van_01_Door_1_1.p3d";
		inventorySlot = "Van_01_Door_1_1";
		rotationFlags = 2;
	};
	class Van_01_Door_2_1: Van_01_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Van_01\proxy\Van_01_Door_2_1.p3d";
		displayName = "$STR_CivVanDoors_CoDriver0";
		inventorySlot = "Van_01_Door_2_1";
		rotationFlags = 2;
	};
	class Van_01_Door_2_2: Van_01_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Van_01\proxy\Van_01_Door_2_2.p3d";
		displayName = "$STR_CivVanDoors_BackRight0";
		inventorySlot = "Van_01_Door_2_2";
	};
	class Van_01_Trunk_1: Van_01_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Van_01\proxy\Van_01_Trunk_1.p3d";
		displayName = "$STR_CivVanDoors_TrunkUp0";
		inventorySlot = "Van_01_Trunk_1";
		rotationFlags = 2;
	};
	class Van_01_Trunk_2: Van_01_Door_1_1
	{
		model = "\DZ\vehicles\wheeled\Van_01\proxy\Van_01_Trunk_2.p3d";
		displayName = "$STR_CivVanDoors_TrunkDown0";
		inventorySlot = "Van_01_Trunk_2";
		rotationFlags = 2;
	};
	class Van_01: CarScript
	{
		scope = 2;
		displayName = "$STR_CivilianVan0";
		model = "\dz\vehicles\wheeled\Van_01\Van_01.p3d";
		dashboardMatOn = "dz\vehicles\wheeled\CivilianVan\data\niva_dashboard_light.rvmat";
		dashboardMatOff = "dz\vehicles\wheeled\CivilianVan\data\niva_dashboard.rvmat";
		frontReflectorMatOn = "dz\vehicles\wheeled\CivilianVan\data\niva_lights.rvmat";
		frontReflectorMatOff = "dz\vehicles\wheeled\CivilianVan\data\niva.rvmat";
		frontReflectorMatDamaged = "dz\vehicles\wheeled\CivilianVan\data\niva_damage.rvmat";
		frontReflectorMatRuined = "dz\vehicles\wheeled\CivilianVan\data\niva_destruct.rvmat";
		fuelCapacity = 42;
		fuelConsumption = 11;
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1","CarRadiator","SparkPlug","Van_01_Door_1_1","Van_01_Door_2_1","Van_01_Door_2_2","Van_01_Trunk_1","Van_01_Trunk_2","Van_01_Wheel_1_1","Van_01_Wheel_1_2","Van_01_Wheel_2_1","Van_01_Wheel_2_2"};
		class Crew: Crew
		{
			class Driver: Driver{};
			class CoDriver: CoDriver{};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewCargo1";
				getInPos = "pos_driver";
				getInDir = "pos_driver_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewCargo2";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
			};
			class Cargo3
			{
				actionSel = "seat_cargo3";
				proxyPos = "crewCargo3";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_RWD";
			airDragCoefficient = 1.195;
			class Steering
			{
				increaseSpeed[] = {0,45,60,25,100,15};
				decreaseSpeed[] = {0,90,60,45,100,15};
				centeringSpeed[] = {0,0,15,28,60,45,100,60};
			};
			class Throttle
			{
				reactionTime = 1.0;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 2.5;
				gentleCoef = 0.75;
			};
			class Engine
			{
				inertia = 0.15;
				torqueMax = 114;
				torqueRpm = 3400;
				powerMax = 53.7;
				powerRpm = 5400;
				rpmIdle = 850;
				rpmMin = 900;
				rpmClutch = 1350;
				rpmRedline = 6000;
				rpmMax = 8000;
			};
			class Gearbox
			{
				reverse = 3.526;
				ratios[] = {3.667,2.1,1.361,1.0};
				timeToUncoupleClutch = 0.35;
				timeToCoupleClutch = 0.45;
				maxClutchTorque = 75;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 30;
					finalRatio = 4.1;
					brakeBias = 0.5;
					brakeForce = 4500;
					wheelHubMass = 5;
					wheelHubRadius = 0.12;
					class Suspension
					{
						swayBar = 1700;
						stiffness = 42000;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.0833;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "Van_01_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "Van_01_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					finalRatio = 4.1;
					brakeBias = 0.4;
					brakeForce = 3800;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 1800;
						stiffness = 43000;
						compression = 2300;
						damping = 7900;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1059;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_2";
							inventorySlot = "Van_01_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper = "damper_2_2";
							inventorySlot = "Van_01_Wheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {7,10};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class DamageZones
			{
				class Front
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_front"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Back
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_back"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Roof
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_roof"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Fender_LF
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"dmgZone_fenderLF"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Fender_LR: Fender_LF
				{
					componentNames[] = {"dmgZone_fenderLR"};
				};
				class Fender_RF: Fender_LF
				{
					componentNames[] = {"dmgZone_fenderRF"};
				};
				class Fender_RR: Fender_LF
				{
					componentNames[] = {"dmgZone_fenderRR"};
				};
				class Engine
				{
					class Health
					{
						hitpoints = 400;
						transferToGlobalCoef = 1;
					};
					componentNames[] = {"dmgZone_engine"};
					fatalInjuryCoef = 1;
					inventorySlots[] = {};
				};
				class Chassis
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = -1;
					};
					componentNames[] = {"dmgZone_chassis"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class FuelTank
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = -1;
					};
					componentNames[] = {"dmgZone_fuelTank"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class DoorsCargo1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCargo2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCargo3
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
		};
		class Sounds
		{
			thrust = 0.6;
			thrustTurbo = 1;
			thrustGentle = 0.3;
			thrustSmoothCoef = 0.02;
			camposSmoothCoef = 0.03;
			soundSetsFilter[] = {"offroad_Engine_Offload_Ext_Rpm1_SoundSet","offroad_Engine_Offload_Ext_Rpm2_SoundSet","offroad_Engine_Offload_Ext_Rpm3_SoundSet","offroad_Engine_Offload_Ext_Rpm4_SoundSet","offroad_Engine_Offload_Ext_Rpm5_SoundSet","offroad_Engine_Ext_Rpm0_SoundSet","offroad_Engine_Ext_Rpm1_SoundSet","offroad_Engine_Ext_Rpm2_SoundSet","offroad_Engine_Ext_Rpm3_SoundSet","offroad_Engine_Ext_Rpm4_SoundSet","offroad_Engine_Ext_Rpm5_SoundSet","offroad_Engine_Ext_Broken_SoundSet","offroad_Tires_rock_slow_Ext_SoundSet","offroad_Tires_rock_fast_Ext_SoundSet","offroad_Tires_grass_slow_Ext_SoundSet","offroad_Tires_grass_fast_Ext_SoundSet","offroad_Tires_gravel_slow_Ext_SoundSet","offroad_Tires_gravel_fast_Ext_SoundSet","offroad_Tires_gravel_dust_fast_Ext_SoundSet","offroad_Tires_asphalt_slow_Ext_SoundSet","offroad_Tires_asphalt_fast_Ext_SoundSet","offroad_Tires_water_slow_Ext_SoundSet","offroad_Tires_water_fast_Ext_SoundSet","Offroad_skid_dirt_SoundSet","offroad_dirt_turn_SoundSet","offroad_Rain_Ext_SoundSet","offroad_damper_left_SoundSet","offroad_damper_right_SoundSet"};
			soundSetsInt[] = {"Offroad_Tires_Asphalt_Fast_General_Int_SoundSet","Offroad_Wind_SoundSet"};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,0.7};
					};
					class Cyl3
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,-0.7};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				attachmentSlots[] = {"CarBattery","CarRadiator","SparkPlug"};
				icon = "cat_vehicle_engine";
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","Van_01_Door_1_1","Van_01_Door_2_1","Van_01_Door_2_2","Van_01_Trunk_1","Van_01_Trunk_2"};
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"Van_01_Wheel_1_1","Van_01_Wheel_1_2","Van_01_Wheel_2_1","Van_01_Wheel_2_2"};
			};
		};
	};
	class TransitBusWheel: CarWheel
	{
		scope = 2;
		model = "\DZ\vehicles\wheeled\TransitBus\proxy\ikarusWheel.p3d";
		displayName = "$STR_TransitBusWheel0";
		itemSize[] = {6,6};
		weight = 25000;
		physLayer = "item_large";
		rotationFlags = 12;
		inventorySlot[] = {"BusWheel_1_1","BusWheel_2_1"};
		simulation = "carwheel";
		radiusByDamage[] = {0,0.51,0.3,0.45,0.9998,0.38,0.9999,0.3};
		radius = 0.51;
		friction = 0.999;
		width = 0.213;
	};
	class TransitBusWheel_Ruined: CarWheel
	{
		scope = 2;
		model = "\DZ\vehicles\wheeled\TransitBus\proxy\ikarusWheel_destroyed.p3d";
		displayName = "$STR_TransitBusWheel_Ruined0";
		itemSize[] = {6,6};
		weight = 25000;
		physLayer = "item_large";
		rotationFlags = 12;
		inventorySlot[] = {"BusWheel_1_1","BusWheel_2_1"};
		simulation = "carwheel";
		radius = 0.3;
		friction = -1.0;
		width = 0.213;
	};
	class TransitBusWheelDouble: TransitBusWheel
	{
		model = "\DZ\vehicles\wheeled\TransitBus\proxy\ikarusWheel_rear.p3d";
		displayName = "$STR_TransitBusWheelDouble0";
		width = 0.426;
		inventorySlot[] = {"BusWheel_1_2","BusWheel_2_2"};
	};
	class TransitBusWheelDouble_Ruined: TransitBusWheel_Ruined
	{
		model = "\DZ\vehicles\wheeled\TransitBus\proxy\ikarusWheel_rear_destroyed.p3d";
		displayName = "$STR_TransitBusWheelDouble_Ruined0";
		width = 0.426;
		inventorySlot[] = {"BusWheel_1_2","BusWheel_2_2"};
	};
	class BusDoors_Left: Inventory_Base
	{
		scope = 2;
		model = "\DZ\vehicles\wheeled\TransitBus\proxy\IkarusDoors_Left.p3d";
		displayName = "$STR_BusDoors_Left0";
		itemSize[] = {8,12};
		weight = 15000;
		physLayer = "item_large";
		inventorySlot[] = {"BusLeftDoors_1","BusLeftDoors_2","BusLeftDoors_3"};
		rotationFlags = 4;
	};
	class BusDoors_Right: BusDoors_Left
	{
		model = "\DZ\vehicles\wheeled\TransitBus\proxy\IkarusDoors_Right.p3d";
		displayName = "$STR_BusDoors_Right0";
		rotationFlags = 8;
		inventorySlot[] = {"BusRightDoors_1","BusRightDoors_2","BusRightDoors_3"};
	};
	class BusHood: Inventory_Base
	{
		scope = 2;
		model = "\DZ\vehicles\wheeled\TransitBus\proxy\ikarusHood.p3d";
		displayName = "$STR_BusHood0";
		itemSize[] = {8,8};
		weight = 15000;
		physLayer = "item_large";
		inventorySlot = "BusHood";
		rotationFlags = 8;
	};
	class TransitBus: CarScript
	{
		scope = 2;
		displayName = "$STR_TransitBus0";
		model = "\dz\vehicles\wheeled\TransitBus\TransitBus.p3d";
		dashboardMatOn = "dz\vehicles\wheeled\transitbus\data\ikarus_dashboarde.rvmat";
		dashboardMatOff = "dz\vehicles\wheeled\transitbus\data\ikarus_dashboard.rvmat";
		frontReflectorMatOn = "dz\vehicles\wheeled\transitbus\data\ikarus_ext_details_lights.rvmat";
		frontReflectorMatOff = "dz\vehicles\wheeled\transitbus\data\ikarus_ext_details_cr.rvmat";
		frontReflectorMatDamaged = "dz\vehicles\wheeled\transitbus\data\ikarus_ext_details_damage.rvmat";
		frontReflectorMatRuined = "dz\vehicles\wheeled\transitbus\data\ikarus_ext_details_destruct.rvmat";
		fuelCapacity = 180;
		fuelConsumption = 25;
		attachments[] = {"TruckBattery","TruckRadiator","LightBulb","EngineBelt","GlowPlug","BusLeftDoors_1","BusLeftDoors_2","BusLeftDoors_3","BusRightDoors_1","BusRightDoors_2","BusRightDoors_3","BusHood","BusWheel_1_1","BusWheel_1_2","BusWheel_2_1","BusWheel_2_2"};
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_AWD";
			airDragCoefficient = 0.995;
			class Steering
			{
				increaseSpeed[] = {0,45,60,23,100,12};
				decreaseSpeed[] = {0,80,60,40,90,20};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 1.0;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 4.0;
				gentleCoef = 0.75;
			};
			class Engine
			{
				inertia = 0.15;
				torqueMax = 114;
				torqueRpm = 3400;
				powerMax = 53.7;
				powerRpm = 5400;
				rpmIdle = 850;
				rpmMin = 900;
				rpmClutch = 1350;
				rpmRedline = 6000;
				rpmMax = 8000;
			};
			class Gearbox
			{
				reverse = 3.526;
				ratios[] = {3.667,2.1,1.361,1.0};
				timeToUncoupleClutch = 0.3;
				timeToCoupleClutch = 0.45;
				maxClutchTorque = 260;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 30;
					finalRatio = 4.1;
					brakeBias = 0.6;
					brakeForce = 4000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 1700;
						stiffness = 40000;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.0833;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "BusWheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "BusWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					finalRatio = 4.1;
					brakeBias = 0.4;
					brakeForce = 3800;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 1800;
						stiffness = 40000;
						compression = 2200;
						damping = 7600;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1059;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_2";
							inventorySlot = "BusWheel_1_2";
						};
						class Right: Right
						{
							animDamper = "damper_2_2";
							inventorySlot = "BusWheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {7,15};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources: AnimationSources
		{
			class DoorsHood: DoorsDriver
			{
				animPeriod = 0.8;
				initPhase = 1;
			};
			class Doors_Front: DoorsDriver
			{
				animPeriod = 0.8;
			};
			class Doors_Middle: Doors_Front{};
			class Doors_Rear: Doors_Front{};
		};
		class Sounds
		{
			soundSetsInt[] = {"v3s_Engine_Offload_Int_Rpm1_SoundSet","v3s_Engine_Offload_Int_Rpm2_SoundSet","v3s_Engine_Int_Open_Rpm0_SoundSet","v3s_Engine_Int_Open_Rpm1_SoundSet","v3s_Engine_Int_Open_Rpm2_SoundSet","v3s_Tires_Asphalt_Slow_General_Int_SoundSet","v3s_Tires_Asphalt_Fast_General_Int_SoundSet","v3s_Tires_rock_slow_Int_SoundSet","v3s_Tires_rock_fast_Int_SoundSet","v3s_Tires_grass_slow_Int_SoundSet","v3s_Tires_grass_fast_Int_SoundSet","v3s_Tires_gravel_slow_Int_SoundSet","v3s_Tires_gravel_fast_Int_SoundSet","v3s_Tires_asphalt_slow_Int_SoundSet","v3s_Tires_asphalt_fast_Int_SoundSet","v3s_Tires_water_slow_Int_SoundSet","v3s_Tires_water_fast_Int_SoundSet","offroad_skid_dirt_SoundSet","offroad_dirt_turn_SoundSet","v3s_Wind_SoundSet","v3s_Rain_Int_SoundSet","v3s_Rain_Int_Open_SoundSet"};
			soundSetsExt[] = {"v3s_Engine_Offload_Ext_Rpm1_SoundSet","v3s_Engine_Offload_Ext_Rpm2_SoundSet","v3s_Engine_Ext_Rpm0_SoundSet","v3s_Engine_Ext_Rpm1_SoundSet","v3s_Engine_Ext_Rpm2_SoundSet","v3s_Tires_rock_slow_Ext_SoundSet","v3s_Tires_rock_fast_Ext_SoundSet","v3s_Tires_grass_slow_Ext_SoundSet","v3s_Tires_grass_fast_Ext_SoundSet","v3s_Tires_gravel_slow_Ext_SoundSet","v3s_Tires_gravel_fast_Ext_SoundSet","v3s_Tires_asphalt_slow_Ext_SoundSet","v3s_Tires_asphalt_fast_Ext_SoundSet","v3s_Tires_water_slow_Ext_SoundSet","v3s_Tires_water_fast_Ext_SoundSet","offroad_skid_dirt_SoundSet","offroad_dirt_turn_SoundSet","v3s_Rain_Ext_SoundSet"};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.2;
						height = 1.5;
						center[] = {0,0,1.7};
					};
					class Cyl2
					{
						radius = 1.2;
						height = 1.5;
						center[] = {0,0,0};
					};
					class Cyl3
					{
						radius = 1.2;
						height = 1.5;
						center[] = {0,0,-1.7};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				attachmentSlots[] = {"TruckBattery","TruckRadiator","EngineBelt","GlowPlug"};
				icon = "cat_vehicle_engine";
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				attachmentSlots[] = {"LightBulb","BusLeftDoors_1","BusLeftDoors_2","BusLeftDoors_3","BusRightDoors_1","BusRightDoors_2","BusRightDoors_3","BusHood"};
				icon = "cat_vehicle_body";
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				attachmentSlots[] = {"BusWheel_1_1","BusWheel_1_2","BusWheel_2_1","BusWheel_2_2"};
				icon = "cat_vehicle_chassis";
			};
		};
	};
};
class CfgDestroy
{
	class EngineHit
	{
		sound[] = {};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyVehiclePart: ProxyAttachment
	{
		scope = 2;
		simulation = "ProxyInventory";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 0;
	};
	class ProxyTruck_01_Wheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Wheel.p3d";
		inventorySlot[] = {"Truck_01_Wheel_1_1","Truck_01_Wheel_2_1","Truck_01_Wheel_Spare_1","Truck_01_Wheel_Spare_2"};
	};
	class ProxyTruck_01_Wheel_ruined: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Wheel_ruined.p3d";
		inventorySlot[] = {"Truck_01_Wheel_1_1","Truck_01_Wheel_2_1","Truck_01_Wheel_Spare_1","Truck_01_Wheel_Spare_2"};
	};
	class ProxyTruck_01_WheelDouble: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_WheelDouble.p3d";
		inventorySlot[] = {"Truck_01_Wheel_1_2","Truck_01_Wheel_1_3","Truck_01_Wheel_2_2","Truck_01_Wheel_2_3"};
	};
	class ProxyTruck_01_WheelDouble_ruined: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_WheelDouble_ruined.p3d";
		inventorySlot[] = {"Truck_01_Wheel_1_2","Truck_01_Wheel_1_3","Truck_01_Wheel_2_2","Truck_01_Wheel_2_3"};
	};
	class ProxyTruck_01_Door_1_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Door_1_1.p3d";
		inventorySlot = "Truck_01_Door_1_1";
	};
	class ProxyTruck_01_Door_2_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Door_2_1.p3d";
		inventorySlot = "Truck_01_Door_2_1";
	};
	class ProxyTruck_01_Hood: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_01\proxy\Truck_01_Hood.p3d";
		inventorySlot = "Truck_01_Hood";
	};
	class ProxySedanWheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\civiliansedan\proxy\sedanWheel.p3d";
		inventorySlot[] = {"CivSedanWheel_1_1","CivSedanWheel_1_2","CivSedanWheel_2_1","CivSedanWheel_2_2"};
	};
	class ProxySedanWheel_destroyed: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\civiliansedan\proxy\sedanWheel_destroyed.p3d";
		inventorySlot[] = {"CivSedanWheel_1_1","CivSedanWheel_1_2","CivSedanWheel_2_1","CivSedanWheel_2_2"};
	};
	class ProxySedanHood: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\CivilianSedan\proxy\sedanhood.p3d";
		inventorySlot = "CivSedanHood";
	};
	class ProxySedanTrunk: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\CivilianSedan\proxy\sedanTrunk.p3d";
		inventorySlot = "CivSedanTrunk";
	};
	class ProxysedanDoors_Driver: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\CivilianSedan\proxy\sedanDoors_Driver.p3d";
		inventorySlot = "CivSedanDriverDoors";
	};
	class ProxysedanDoors_coDriver: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\CivilianSedan\proxy\sedanDoors_coDriver.p3d";
		inventorySlot = "CivSedanCoDriverDoors";
	};
	class ProxysedanDoors_cargo1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\CivilianSedan\proxy\sedanDoors_cargo1.p3d";
		inventorySlot = "CivSedanCargo1Doors";
	};
	class ProxysedanDoors_cargo2: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\CivilianSedan\proxy\sedanDoors_cargo2.p3d";
		inventorySlot = "CivSedanCargo2Doors";
	};
	class ProxyNivaWheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaWheel.p3d";
		inventorySlot[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
	};
	class ProxyNivaWheel_destroyed: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaWheel_destroyed.p3d";
		inventorySlot[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
	};
	class ProxyNivaDoors_Hood: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Hood.p3d";
		inventorySlot = "NivaHood";
	};
	class ProxyNivaDoors_Trunk: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Trunk.p3d";
		inventorySlot = "NivaTrunk";
	};
	class ProxynivaDoors_Driver: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Driver.p3d";
		inventorySlot = "NivaDriverDoors";
	};
	class ProxynivaDoors_coDriver: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_coDriver.p3d";
		inventorySlot = "NivaCoDriverDoors";
	};
	class ProxyIkarusWheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\TransitBus\proxy\IkarusWheel.p3d";
		inventorySlot[] = {"BusWheel_1_1","BusWheel_2_1"};
	};
	class ProxyIkarusWheel_destroyed: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\TransitBus\proxy\ikarusWheel_destroyed.p3d";
		inventorySlot[] = {"BusWheel_1_1","BusWheel_2_1"};
	};
	class ProxyIkarusWheel_rear: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\TransitBus\proxy\ikarusWheel_rear.p3d";
		inventorySlot[] = {"BusWheel_1_2","BusWheel_2_2"};
	};
	class ProxyIkarusWheel_rear_destroyed: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\TransitBus\proxy\ikarusWheel_rear_destroyed.p3d";
		inventorySlot[] = {"BusWheel_1_2","BusWheel_2_2"};
	};
	class ProxyikarusHood: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\TransitBus\proxy\ikarusHood.p3d";
		inventorySlot = "BusHood";
	};
	class ProxyIkarusDoors_Left: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\TransitBus\proxy\IkarusDoors_Left.p3d";
		inventorySlot[] = {"BusLeftDoors_1","BusLeftDoors_2","BusLeftDoors_3"};
	};
	class ProxyIkarusDoors_Right: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\TransitBus\proxy\IkarusDoors_Right.p3d";
		inventorySlot[] = {"BusRightDoors_1","BusRightDoors_2","BusRightDoors_3"};
	};
	class ProxyVan_01_Wheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Van_01\proxy\Van_01_Wheel.p3d";
		inventorySlot[] = {"Van_01_Wheel_1_1","Van_01_Wheel_1_2","Van_01_Wheel_2_1","Van_01_Wheel_2_2"};
	};
	class ProxyVan_01_Wheel_ruined: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Van_01\proxy\Van_01_Wheel_ruined.p3d";
		inventorySlot[] = {"Van_01_Wheel_1_1","Van_01_Wheel_1_2","Van_01_Wheel_2_1","Van_01_Wheel_2_2"};
	};
	class ProxyVan_01_Door_1_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Van_01\proxy\Van_01_Door_1_1.p3d";
		inventorySlot = "Van_01_Door_1_1";
	};
	class ProxyVan_01_Door_2_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Van_01\proxy\Van_01_Door_2_1.p3d";
		inventorySlot = "Van_01_Door_2_1";
	};
	class ProxyVan_01_Door_2_2: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Van_01\proxy\Van_01_Door_2_2.p3d";
		inventorySlot = "Van_01_Door_2_2";
	};
	class ProxyVan_01_Trunk_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Van_01\proxy\Van_01_Trunk_1.p3d";
		inventorySlot = "Van_01_Trunk_1";
	};
	class ProxyVan_01_Trunk_2: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Van_01\proxy\Van_01_Trunk_2.p3d";
		inventorySlot = "Van_01_Trunk_2";
	};
	class ProxyHatchback_02_Wheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Wheel.p3d";
		inventorySlot[] = {"Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2"};
	};
	class ProxyHatchback_02_Wheel_destroyed: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_.p3d";
		inventorySlot[] = {"Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2"};
	};
	class ProxyHatchback_02_Hood: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Hood.p3d";
		inventorySlot = "Hatchback_02_Hood";
	};
	class ProxyHatchback_02_Trunk: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Trunk.p3d";
		inventorySlot = "Hatchback_02_Trunk";
	};
	class ProxyHatchback_02_Door_1_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_1_1.p3d";
		inventorySlot = "Hatchback_02_Door_1_1";
	};
	class ProxyHatchback_02_Door_2_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_2_1.p3d";
		inventorySlot = "Hatchback_02_Door_2_1";
	};
	class ProxyHatchback_02_Door_1_2: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_1_2.p3d";
		inventorySlot = "Hatchback_02_Door_1_2";
	};
	class ProxyHatchback_02_Door_2_2: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Hatchback_02\proxy\Hatchback_02_Door_2_2.p3d";
		inventorySlot = "Hatchback_02_Door_2_2";
	};
	class ProxyTruck_02_Wheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_02\proxy\Truck_02_Wheel.p3d";
		inventorySlot[] = {"Truck_02_Wheel_1_1","Truck_02_Wheel_1_2","Truck_02_Wheel_2_1","Truck_02_Wheel_2_2"};
	};
	class ProxyTruck_02_Wheel_ruined: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_02\proxy\Truck_02_Wheel_ruined.p3d";
		inventorySlot[] = {"Truck_02_Wheel_1_1","Truck_02_Wheel_1_2","Truck_02_Wheel_2_1","Truck_02_Wheel_2_2"};
	};
	class ProxyTruck_02_Door_1_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_02\proxy\Truck_02_Door_1_1.p3d";
		inventorySlot = "Truck_02_Door_1_1";
	};
	class ProxyTruck_02_Door_2_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Truck_02\proxy\Truck_02_Door_2_1.p3d";
		inventorySlot = "Truck_02_Door_2_1";
	};
	class ProxySedan_02_Wheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Wheel.p3d";
		inventorySlot[] = {"Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
	};
	class ProxySedan_02_Wheel_ruined: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Wheel_ruined.p3d";
		inventorySlot[] = {"Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
	};
	class ProxySedan_02_Door_1_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Door_1_1.p3d";
		inventorySlot = "Sedan_02_Door_1_1";
	};
	class ProxySedan_02_Door_2_1: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Door_2_1.p3d";
		inventorySlot = "Sedan_02_Door_2_1";
	};
	class ProxySedan_02_Door_1_2: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Door_1_2.p3d";
		inventorySlot = "Sedan_02_Door_1_2";
	};
	class ProxySedan_02_Door_2_2: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Door_2_2.p3d";
		inventorySlot = "Sedan_02_Door_2_2";
	};
	class ProxySedan_02_Hood: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Hood.p3d";
		inventorySlot = "Sedan_02_Hood";
	};
	class ProxySedan_02_Trunk: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\Sedan_02\proxy\Sedan_02_Trunk.p3d";
		inventorySlot = "Sedan_02_Trunk";
	};
};
