#include "pch.h"
#include "IniFile.hpp"

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

//Options
enum KindofTextureDX { LikeDream, OriginalDX, DreamcastT };
enum KindofTextureDC { OriginalDC, LikeDX };
enum DXSuperS { LikeDreamSS, OriginalDXSS, DreamcastTSS, Upgraded };
enum DCSuperS { OriginalDCSS, LikeDXSS, UpgradedDC };
enum EmeraldText { New, SA1, SA2 };
enum Mural { Vanilla, Preview };

static bool EnableSonic = true;
static bool EnableTails = true;
static bool EnableKnuckles = true;
static bool EnableAmy = true;
static bool EnableBig = true;
static bool EnableMetal = true;
static int KindofTextDX = LikeDream;
static int KindofTextDC = OriginalDC;
static int DCSS = UpgradedDC;
static int DXSS = Upgraded;
static int Emerald = New;
static int LWMural = Vanilla;

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		//Enabling or disabling HD textures
		EnableSonic = config->getBool("Characters", "EnableSonic", true);
		EnableTails = config->getBool("Characters", "EnableTails", true);
		EnableKnuckles = config->getBool("Characters", "EnableKnuckles", true);
		EnableAmy = config->getBool("Characters", "EnableAmy", true);
		EnableBig = config->getBool("Characters", "EnableBig", true);
		EnableMetal = config->getBool("Characters", "EnableMetal", true);

		//Choosing kind of textures
		std::string KindofTextDX_String = "LikeDream";
		KindofTextDX_String = config->getString("Textures", "DXChars", "LikeDream");
		std::string DXSS_String = "Upgraded";
		DXSS_String = config->getString("Textures", "DXSS", "Upgraded");
		std::string KindofTextDC_String = "OriginalDC";
		KindofTextDC_String = config->getString("Textures", "DreamcastChars", "OriginalDC");
		std::string DCSS_String = "UpgradedDC";
		DCSS_String = config->getString("Textures", "DreamcastSS", "OriginalDCSS");
		std::string Emerald_String = "New";
		Emerald_String = config->getString("Misc", "Emeralds", "New");
		std::string LWMural_String = "Vanilla";
		LWMural_String = config->getString("Misc", "Mural", "Vanilla");

		if (KindofTextDX_String == "LikeDream") KindofTextDX = LikeDream;
		if (KindofTextDX_String == "DreamcastT") KindofTextDX = DreamcastT;
		if (KindofTextDX_String == "OriginalDX") KindofTextDX = OriginalDX;
		if (KindofTextDC_String == "OriginalDC") KindofTextDC = OriginalDC;
		if (KindofTextDC_String == "LikeDX") KindofTextDC = LikeDX;
		if (DXSS_String == "Upgraded") DXSS = Upgraded;
		if (DXSS_String == "LikeDreamSS") DXSS = LikeDreamSS;
		if (DXSS_String == "DreamcastTSS") DXSS = DreamcastTSS;
		if (DXSS_String == "OriginalDXSS") DXSS = OriginalDXSS;
		if (DCSS_String == "OriginalDCSS") DCSS = OriginalDCSS;
		if (DCSS_String == "LikeDXSS") DCSS = LikeDXSS;
		if (DCSS_String == "UpgradedDC") DCSS = UpgradedDC;
		if (Emerald_String == "SA1") Emerald = SA1;
		if (Emerald_String == "SA2") Emerald = SA2;
		if (Emerald_String == "New") Emerald = New;
		if (LWMural_String == "Vanilla") LWMural = Vanilla;
		if (LWMural_String == "Preview") LWMural = Preview;

		//Compatiblity with other mods
		HMODULE DCcharacters = GetModuleHandle(L"SA1_Chars");
		HMODULE DCconversion = GetModuleHandle(L"DCMods_Main");
		HMODULE DXcharsR = GetModuleHandle(L"SADXR");
		HMODULE Hyper = GetModuleHandle(L"sadx-hyper-sonic");
		
		if (EnableSonic)
		{
			if (KindofTextDX == LikeDream)
			{
				ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_ld");
				ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_ld");
				ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_ld");
				ReplacePVM("shooting1", "shooting1_ld");
				ReplacePVM("shooting2", "shooting2_ld");
				ReplacePVM("sonic", "sonic_ld");
			}

			if (KindofTextDX == DreamcastT)
			{
				ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dxd");
				ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dxd");
				ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dxd");
				ReplacePVM("shooting1", "shooting1_dxd");
				ReplacePVM("shooting2", "shooting2_dxd");
				ReplacePVM("SONIC", "SONIC_dxd");
			}

			if (DXSS == Upgraded)
			{
				ReplacePVM("supersonic", "supersonic_n");
				ReplacePVM("supersonic_dxr", "supersonic_n");
			}

			if (DXSS == DreamcastTSS)
			{
				ReplacePVM("supersonic", "supersonic_dxd");
				ReplacePVM("supersonic_dxr", "supersonic_n");
			}

			if (DXSS == LikeDreamSS)
			{
				ReplacePVM("supersonic", "supersonic_ld");
				ReplacePVM("supersonic_dxr", "supersonic_n");
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_ldx");
					ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_ldx");
					ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_ldx");
					ReplacePVM("shooting1", "shooting1_ldx");
					ReplacePVM("shooting2", "shooting2_ldx");
					ReplacePVM("SONIC", "SONIC_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dc");
					ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dc");
					ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dc");
					ReplacePVM("shooting1", "shooting1_dc");
					ReplacePVM("shooting2", "shooting2_dc");
					ReplacePVM("SONIC", "SONIC_DC");
				}

				if (DCSS == UpgradedDC)
				{
					ReplacePVM("supersonic", "supersonic_dcn");
				}

				if (DCSS == LikeDXSS)
				{
					ReplacePVM("supersonic", "supersonic_ldx");
				}

				if (DCSS == OriginalDCSS)
				{
					ReplacePVM("supersonic", "supersonic_dc");
				}
			}
		}

		if (EnableTails)
		{
			if (DXcharsR)
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("m_head_1", "m_head_1_ld");
					ReplacePVM("m_tr_p", "m_tr_p_ld");
					ReplacePVM("Miles", "Miles_ldr");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("m_head_1", "m_head_1_dxd");
					ReplacePVM("m_tr_p", "m_tr_p_dxd");
					ReplacePVM("Miles", "Miles_dxdr");
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("m_head_1", "m_head_1_ld");
					ReplacePVM("m_tr_p", "m_tr_p_ld");
					ReplacePVM("Miles", "Miles_ld");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("m_head_1", "m_head_1_dxd");
					ReplacePVM("m_tr_p", "m_tr_p_dxd");
					ReplacePVM("Miles", "Miles_dxd");
				}
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("m_head_1", "m_head_1_ldx");
					ReplacePVM("m_tr_p", "m_tr_p_ldx");
					ReplacePVM("Miles", "Miles_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("m_head_1", "m_head_1_dc");
					ReplacePVM("m_tr_p", "m_tr_p_dc");
					ReplacePVM("Miles", "Miles_DC");
				}
			}
		}

		if (EnableKnuckles)
		{
			if (KindofTextDX == LikeDream)
			{
				ReplacePVM("Knuckles", "Knuckles_ld");
			}

			if (KindofTextDX == DreamcastT)
			{
				ReplacePVM("Knuckles", "Knuckles_dxd");
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Knuckles", "Knuckles_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Knuckles", "Knuckles_DC");
				}
			}
		}

		if (EnableAmy)
		{
			if (DXcharsR)
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Amy", "Amy_ldr");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Amy", "Amy_dxdr");
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Amy", "Amy_ld");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Amy", "Amy_dxd");
				}
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Amy", "Amy_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Amy", "Amy_DC");
				}
			}
		}

		if (EnableBig)
		{
			if (KindofTextDX == LikeDream)
			{
				ReplacePVM("Big", "Big_ld");
			}

			if (KindofTextDX == DreamcastT)
			{
				ReplacePVM("Big", "Big_dxd");
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Big", "Big_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Big", "Big_DC");
				}
			}
		}

		if (EnableMetal)
		{
			if (KindofTextDX == LikeDream)
			{
				ReplacePVM("Metalsonic", "Metalsonic_ld");
			}

			if (KindofTextDX == DreamcastT)
			{
				ReplacePVM("Metalsonic", "Metalsonic_dxd");
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Metalsonic", "Metalsonic_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Metalsonic", "Metalsonic_DC");
				}
			}
		}

		if (DCconversion)
		{
			if (Emerald == SA2)
			{
				ReplacePVM("KAOS_EME", "KAOS_EME_sa2");
				ReplacePVM("M_EM_BLACK", "M_EM_BLACK_sa2");
				ReplacePVM("M_EM_BLUE", "M_EM_BLUE_sa2");
				ReplacePVM("M_EM_GREEN", "M_EM_GREEN_sa2");
				ReplacePVM("M_EM_PURPLE", "M_EM_PURPLE_sa2");
				ReplacePVM("M_EM_RED", "M_EM_RED_sa2");
				ReplacePVM("M_EM_SKY", "M_EM_SKY_sa2");
				ReplacePVM("M_EM_WHITE", "M_EM_WHITE_sa2");
				ReplacePVM("M_EM_YELLOW", "M_EM_YELLOW_sa2");
				ReplacePVM("MROBJ", "MROBJ_sa2");
				ReplacePVM("OBJ_PAST", "OBJ_PAST_sa2");
			}

			if (Emerald == New)
			{
				ReplacePVM("KAOS_EME", "KAOS_EME_new");
				ReplacePVM("M_EM_BLACK", "M_EM_BLACK_new");
				ReplacePVM("M_EM_BLUE", "M_EM_BLUE_new");
				ReplacePVM("M_EM_GREEN", "M_EM_GREEN_new");
				ReplacePVM("M_EM_PURPLE", "M_EM_PURPLE_new");
				ReplacePVM("M_EM_RED", "M_EM_RED_new");
				ReplacePVM("M_EM_SKY", "M_EM_SKY_new");
				ReplacePVM("M_EM_WHITE", "M_EM_WHITE_new");
				ReplacePVM("M_EM_YELLOW", "M_EM_YELLOW_new");
				ReplacePVM("MROBJ", "MROBJ_new");
				ReplacePVM("OBJ_PAST", "OBJ_PAST_new");
			}

			if (Emerald == SA1)
			{
				ReplacePVM("KAOS_EME", "KAOS_EME_DC");
				ReplacePVM("M_EM_BLACK", "M_EM_BLACK_DC");
				ReplacePVM("M_EM_BLUE", "M_EM_BLUE_DC");
				ReplacePVM("M_EM_GREEN", "M_EM_GREEN_DC");
				ReplacePVM("M_EM_PURPLE", "M_EM_PURPLE_DC");
				ReplacePVM("M_EM_RED", "M_EM_RED_DC");
				ReplacePVM("M_EM_SKY", "M_EM_SKY_DC");
				ReplacePVM("M_EM_WHITE", "M_EM_WHITE_DC");
				ReplacePVM("M_EM_YELLOW", "M_EM_YELLOW_DC");
				ReplacePVM("MROBJ", "MROBJ_DC");
				ReplacePVM("OBJ_PAST", "OBJ_PAST_DC");
			}

			if (LWMural == Vanilla)
			{
				ReplacePVM("RUIN03", "RUIN03_DC");
			}

			if (LWMural == Preview)
			{
				ReplacePVM("RUIN03", "RUIN03_DCP");
			}
		}
		ReplacePVM("DXR_AMY", "amy_r");
		ReplacePVM("DXR_AMY_EFF", "AMY_EFF");
		ReplacePVM("DXR_MILES", "miles_r");
		ReplacePVM("DXR_HYPER", "HYPERSONIC");
		ReplacePVM("DXR_KNU_EFF", "KNU_EFF_HD");
		ReplacePVM("DXR_SON_EFF", "SON_EFF");
		ReplacePVM("HYPERBASIC_DXR", "HYPERSONIC");
		ReplacePVM("HYPERSONIC_DXR", "HYPERSONIC");
		ReplacePVM("HYPERSONICG_DXR", "HYPERSONIC");
		if (Hyper)
		{
			ReplacePVM("HYPERSONIC_DC", "HYPERSONIC_DCHD");
			ReplacePVM("HYPERSONIC", "HYPERSONIC_HD")
		}

	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}