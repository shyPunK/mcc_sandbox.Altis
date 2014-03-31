class mcc_test
{
	idd = 9999999;
	movingEnable = true;
	onLoad ="";

	controlsBackground[] = 
	{
	};


	//---------------------------------------------
	objects[] = 
	{ 	//(0.671875 * safezoneW + safezoneX) / safezoneW -X
	};	//(0.478009 * safezoneH + safezoneY) / safezoneH - Y

	class controls 
	{
//---------------------- ZONES --------------------------------	
		class MCC_zoneTittle: MCC_RscText 
		{
			idc = -1;	
			text = "Zone:";
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";

			x = 0.184896 * safezoneW + safezoneX;
			y = 0.57697 * safezoneH + safezoneY;
			w = 0.0458333 * safezoneW;
			h = 0.0219914 * safezoneH;
		};
		
		class MCC_zone: MCC_RscCombo 
		{
			idc = 1023;	
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			onLBSelChanged = __EVAL("[0,0,0] execVM '"+MCCPATH+"mcc\pop_menu\zones.sqf'");
			
			x = 0.236458 * safezoneW + safezoneX;
			y = 0.57697 * safezoneH + safezoneY;
			w = 0.0572917 * safezoneW;
			h = 0.0219914 * safezoneH;	
		};
		
		class MCC_zoneUpdate: MCC_RscButton 
		{
			idc = -1;	
			text = "Update Zone"; 
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			tooltip = "Click and drag on the minimap to make a zone"; 
			onButtonClick = "if (mcc_missionmaker == (name player)) then {MCC_zone_drawing= true;} else {player globalchat 'Access Denied'};";
			
			x = 0.299479 * safezoneW + safezoneX;
			y = 0.57697 * safezoneH + safezoneY;
			w = 0.120313 * safezoneW;
			h = 0.0219914 * safezoneH;
		};
		
		class MCC_gaiaBehaviorTittle: MCC_RscText
		{
			idc = -1;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			text = "Behavior:"; //--- ToDo: Localize;
					
			x = 0.184896 * safezoneW + safezoneX;
			y = 0.609957 * safezoneH + safezoneY;
			w = 0.045 * safezoneW;
			h = 0.0219914 * safezoneH;
		};
		
		class MCC_gaiaBehaviorCombo: MCC_RscCombo
		{
			idc = 1;
			onLBSelChanged = "MCC_behavior_index = (lbcurSel (_this select 0))";

			x = 0.236458 * safezoneW + safezoneX;
			y = 0.609957 * safezoneH + safezoneY;
			w = 0.0572917 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
		};
		
		class MCC_gaiaBehaviorButton: MCC_RscButton
		{
			idc = -1;
			onButtonClick = "if (!isnil 'MCC_GroupGenGroupSelected') then {if (count MCC_GroupGenGroupSelected > 0) then {{_x setVariable ['GAIA_ZONE_INTEND',[mcc_zone_markername,((MCC_spawn_behaviors select MCC_behavior_index) select 1)], true]}foreach MCC_GroupGenGroupSelected}};";

			text = "Give to Gaia"; //--- ToDo: Localize;
			x = 0.299479 * safezoneW + safezoneX;
			y = 0.609957 * safezoneH + safezoneY;
			w = 0.0572917 * safezoneW;
			h = 0.0219914 * safezoneH;
			tooltip = "Give the selected groups to GAIA control with the selected zone and behavior"; //--- ToDo: Localize;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		
		class MCC_giveToPlayer: MCC_RscButton
		{
			idc = -1;
			onButtonClick = "if (!isnil 'MCC_GroupGenGroupSelected') then {if (count MCC_GroupGenGroupSelected > 0) then {{_x setVariable ['MCC_canbecontrolled',true,true]; _x setVariable ['GAIA_ZONE_INTEND',[],true]}foreach MCC_GroupGenGroupSelected}};";

			text = "Give to Player"; //--- ToDo: Localize;
			x = 0.3625 * safezoneW + safezoneX;
			y = 0.609957 * safezoneH + safezoneY;
			w = 0.0572917 * safezoneW;
			h = 0.0219914 * safezoneH;
			tooltip = "Give the selected groups to player's control via the M-Tac MCC handheld console"; //--- ToDo: Localize;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
	};
};