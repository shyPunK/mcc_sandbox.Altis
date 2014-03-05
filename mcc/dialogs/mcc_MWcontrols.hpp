#define FACTIONCOMBO 1001
#define MCC_MWPlayersIDC 6001
#define MCC_MWATMinesIDC 6002
#define MCC_MWAPMinesIDC 6003
#define MCC_MWStealthIDC 6004
#define MCC_MWReinforcementIDC 6005
#define MCC_MWDifficultyIDC 6006
#define MCC_MWObjective1IDC 6007
#define MCC_MWObjective2IDC 6008
#define MCC_MWObjective3IDC 6009
#define MCC_MWVehiclesIDC 6010
#define MCC_MWArmorIDC 6011
#define MCC_MWIEDIDC 6012
#define MCC_MWSBIDC 6013
#define MCC_MWArmedCiviliansIDC 6014
#define MCC_MWCQBIDC 6015
#define MCC_MWRoadBlocksIDC 6016
#define MCC_MWWeatherComboIDC 6017
#define MCC_MCC_MWAreaComboIDC 6018
#define MCC_MWDebugComboIDC 6019
#define MCC_MWPreciseMarkersComboIDC 6020
#define MCC_MWArtilleryIDC 6021

class MCC_MWControls: MCC_RscControlsGroup
{
	idc = -1;
	x = 0.230729 * safezoneW + safezoneX;
	y = 0.5 * safezoneH + safezoneY;
	w = 0.538542 * safezoneW;
	h = 0.296884 * safezoneH;

	class Controls
	{
		class MCC_MWControlsFrame: MCC_RscText
		{
			idc = -1;
			text = "";
			colorBackground[] = { 0.150, 0.150, 0.150,1};
			
			x = 0.270833 * safezoneW + safezoneX;
			y = 0.225107 * safezoneH + safezoneY;
			w = 0.538542 * safezoneW;
			h = 0.296884 * safezoneH;
		};
		
		class MCC_MWTittle: MCC_RscText
		{
			idc = -1;

			text = "Missions Wizard"; //--- ToDo: Localize;
			x = 0.459896 * safezoneW + safezoneX;
			y = 0.236103 * safezoneH + safezoneY;
			w = 0.15 * safezoneW;
			h = 0.0329871 * safezoneH;
			colorText[] = {0,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		};
		class MCC_MWPlayersTittle: MCC_RscText
		{
			idc = -1;

			text = "# Players:"; //--- ToDo: Localize;
			x = 0.276563 * safezoneW + safezoneX;
			y = 0.313073 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWRoadBlockTittle: MCC_RscText
		{
			idc = -1;

			text = "Roadblocks:"; //--- ToDo: Localize;
			x = 0.643229 * safezoneW + safezoneX;
			y = 0.379047 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWStealthTittle: MCC_RscText
		{
			idc = -1;

			text = "Stealth:"; //--- ToDo: Localize;
			x = 0.276563 * safezoneW + safezoneX;
			y = 0.412034 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		
		class MCC_MWRivalFactionTittle: MCC_RscText
		{
			idc = -1;

			text = "Rival Faction:"; //--- ToDo: Localize;
			x = 0.276563 * safezoneW + safezoneX;
			y = 0.280086 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		
		class MCC_factionCombo: MCC_RscCombo
		{
			idc = FACTIONCOMBO;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			onLBSelChanged = __EVAL("[0] execVM '"+MCCPATH+"mcc\pop_menu\mcc_guiTab1Change.sqf'");

			x = 0.351042 * safezoneW + safezoneX;
			y = 0.280086 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
		};
		
		class MCC_MWPlayersCombo: MCC_RscCombo
		{
			idc = MCC_MWPlayersIDC;

			x = 0.351042 * safezoneW + safezoneX;
			y = 0.313073 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		
		class MCC_MWRoadBlockCombo: MCC_RscCombo
		{
			idc = MCC_MWRoadBlocksIDC;

			x = 0.717708 * safezoneW + safezoneX;
			y = 0.379047 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWStealthCombo: MCC_RscCombo
		{
			idc = MCC_MWStealthIDC;

			x = 0.351042 * safezoneW + safezoneX;
			y = 0.412034 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWObjective1Tittle: MCC_RscText
		{
			idc = -1;

			text = "Objective 1:"; //--- ToDo: Localize;
			x = 0.459896 * safezoneW + safezoneX;
			y = 0.280086 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWObjective2Tittle: MCC_RscText
		{
			idc = -1;

			text = "Objective 2:"; //--- ToDo: Localize;
			x = 0.459896 * safezoneW + safezoneX;
			y = 0.313073 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWObjective3Tittle: MCC_RscText
		{
			idc = -1;

			text = "Objective 3:"; //--- ToDo: Localize;
			x = 0.459896 * safezoneW + safezoneX;
			y = 0.34606 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWVehiclesTittle: MCC_RscText
		{
			idc = -1;

			text = "Vehicles:"; //--- ToDo: Localize;
			x = 0.459896 * safezoneW + safezoneX;
			y = 0.379047 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWDifficultyTittle: MCC_RscText
		{
			idc = -1;

			text = "Difficulty:"; //--- ToDo: Localize;
			x = 0.276563 * safezoneW + safezoneX;
			y = 0.34606 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWDifficultyCombo: MCC_RscCombo
		{
			idc = MCC_MWDifficultyIDC;

			x = 0.351042 * safezoneW + safezoneX;
			y = 0.34606 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWObjective1Combo: MCC_RscCombo
		{
			idc = MCC_MWObjective1IDC;

			x = 0.534375 * safezoneW + safezoneX;
			y = 0.280086 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWObjective2Combo: MCC_RscCombo
		{
			idc = MCC_MWObjective2IDC;

			x = 0.534375 * safezoneW + safezoneX;
			y = 0.313073 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWObjective3Combo: MCC_RscCombo
		{
			idc = MCC_MWObjective3IDC;

			x = 0.534375 * safezoneW + safezoneX;
			y = 0.34606 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWVehiclesCombo: MCC_RscCombo
		{
			idc = MCC_MWVehiclesIDC;

			x = 0.534375 * safezoneW + safezoneX;
			y = 0.379047 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWArmorTittle: MCC_RscText
		{
			idc = -1;

			text = "Armor:"; //--- ToDo: Localize;
			x = 0.459896 * safezoneW + safezoneX;
			y = 0.412034 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWArmorCombo: MCC_RscCombo
		{
			idc = MCC_MWArmorIDC;

			x = 0.534375 * safezoneW + safezoneX;
			y = 0.412034 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWReinforcementTittle: MCC_RscText
		{
			idc = -1;

			text = "Reinforcement:"; //--- ToDo: Localize;
			x = 0.459896 * safezoneW + safezoneX;
			y = 0.445021 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWReinforcementCombo: MCC_RscCombo
		{
			idc = MCC_MWReinforcementIDC;

			x = 0.534375 * safezoneW + safezoneX;
			y = 0.445021 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWArtilleryTittle: MCC_RscText
		{
			idc = -1;

			text = "Artillery:"; //--- ToDo: Localize;
			x = 0.459896 * safezoneW + safezoneX;
			y = 0.478009 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWArtilleryCombo: MCC_RscCombo
		{
			idc = MCC_MWArtilleryIDC;

			x = 0.534375 * safezoneW + safezoneX;
			y = 0.478009 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWPreciseMarkersText: MCC_RscText
		{
			idc = -1;

			text = "Precise Locations:"; //--- ToDo: Localize;
			x = 0.276563 * safezoneW + safezoneX;
			y = 0.445021 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.6)";
		};
		class MCC_MWPreciseMarkersCombo: MCC_RscCombo
		{
			idc = MCC_MWPreciseMarkersComboIDC;

			x = 0.351042 * safezoneW + safezoneX;
			y = 0.445021 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWDebugText: MCC_RscText
		{
			idc = -1;

			text = "Show Markers:"; //--- ToDo: Localize;
			x = 0.276563 * safezoneW + safezoneX;
			y = 0.478009 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWDebugCombo: MCC_RscCombo
		{
			idc = MCC_MWDebugComboIDC;

			x = 0.351042 * safezoneW + safezoneX;
			y = 0.478009 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWIEDTittle: MCC_RscText
		{
			idc = -1;

			text = "IEDs:"; //--- ToDo: Localize;
			x = 0.643229 * safezoneW + safezoneX;
			y = 0.280086 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWSBTittle: MCC_RscText
		{
			idc = -1;

			text = "Suicide Bombers:"; //--- ToDo: Localize;
			x = 0.643229 * safezoneW + safezoneX;
			y = 0.313073 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.65)";
		};
		class MCC_MWArmedCiviliansTittle: MCC_RscText
		{
			idc = -1;

			text = "Armed Civilians:"; //--- ToDo: Localize;
			x = 0.643229 * safezoneW + safezoneX;
			y = 0.34606 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.65)";
		};
		class MCC_MWCQBTittle: MCC_RscText
		{
			idc = -1;

			text = "CQB:"; //--- ToDo: Localize;
			x = 0.276563 * safezoneW + safezoneX;
			y = 0.379047 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWIEDCombo: MCC_RscCombo
		{
			idc = MCC_MWIEDIDC;

			x = 0.717708 * safezoneW + safezoneX;
			y = 0.280086 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWSBCombo: MCC_RscCombo
		{
			idc = MCC_MWSBIDC;

			x = 0.717708 * safezoneW + safezoneX;
			y = 0.313073 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWArmedCiviliansCombo: MCC_RscCombo
		{
			idc = MCC_MWArmedCiviliansIDC;

			x = 0.717708 * safezoneW + safezoneX;
			y = 0.34606 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWCQBCombo: MCC_RscCombo
		{
			idc = MCC_MWCQBIDC;

			x = 0.351042 * safezoneW + safezoneX;
			y = 0.379047 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWWeatherText: MCC_RscText
		{
			idc = -1;

			text = "Time/Weather:"; //--- ToDo: Localize;
			x = 0.643229 * safezoneW + safezoneX;
			y = 0.412034 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWWeatherCombo: MCC_RscCombo
		{
			idc = MCC_MWWeatherComboIDC;

			x = 0.717708 * safezoneW + safezoneX;
			y = 0.412034 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWAreaText: MCC_RscText
		{
			idc = -1;

			text = "Area:"; //--- ToDo: Localize;
			x = 0.643229 * safezoneW + safezoneX;
			y = 0.445021 * safezoneH + safezoneY;
			w = 0.06875 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWAreaCombo: MCC_RscCombo
		{
			idc = MCC_MCC_MWAreaComboIDC;

			x = 0.717708 * safezoneW + safezoneX;
			y = 0.445021 * safezoneH + safezoneY;
			w = 0.0859375 * safezoneW;
			h = 0.0219914 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
		class MCC_MWGenerate: MCC_RscButton
		{
			idc = -1;
			onButtonClick = __EVAL("[0] execVM '"+MCCPATH+"mcc\general_scripts\missionWizard\missionWizardInit.sqf'");

			text = "Generate Mission"; //--- ToDo: Localize;
			x = 0.671875 * safezoneW + safezoneX;
			y = 0.478009 * safezoneH + safezoneY;
			w = 0.101985 * safezoneW;
			h = 0.0340016 * safezoneH;
			tooltip = "Generate a mission "; //--- ToDo: Localize;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
		};
	};
};
