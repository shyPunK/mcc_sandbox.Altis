class MCC_Module_createArmedCivilian : MCC_Module_Base
{
	scopeCurator = 2;
	category = "MCC";
	displayName = "Armed Civilian";
	function = "MCC_fnc_curatorSetArmedCivilian";
	scope = 2;
	isGlobal = 0;

	class Arguments
	{
		class side
		{
			displayName = "Attack Side";
			typeName = "NUMBER";
			class values
			{
				class BLUFOR
				{
					name = "$STR_WEST";
					value = 1;
					default = 1;
				};
				class OPFOR
				{
					name = "$STR_EAST";
					value = 0;
				};
				class Independent
				{
					name = "$STR_GUERRILA";
					value = 2;
				};
				class Civilian
				{
					name = "$STR_CIVILIAN";
					value = 3;
				};
			};
		};

		class patrol
		{
			displayName = "Random Patrol";
			typeName = "NUMBER";
			class values
			{
				class yes
				{
					name = "Yes";
					value = 1;
					default = 1;
				};
				class no
				{
					name = "No";
					value = 0;
				};
			};
		};
	};

	class ModuleDescription: ModuleDescription
	{
		description = "Make unit act as armed civilian - the unit will randomly draw weapons on units from its rival faction";
		sync[] = {"AnyAI"};

		class AnyAI
		{
			description = "Any AI unit. Not players or empty objects.";
			displayName = "Any AI";
			icon = "iconMan";
			side = 4;
			position = 1;
			direction = 1;
			optional = 0;
			duplicate = 1;
		};
	};
};